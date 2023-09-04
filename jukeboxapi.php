<?php

require_once('../config.php');
date_default_timezone_set("America/Chicago");
ini_set('display_errors', 'Off');

abstract class BaseResponse
{
    public int $responseCode;
    public string $message;
}

final class JsonResponse extends BaseResponse
{
    public array $data;

    public function __construct(int $responseCode, string $message, $data = array())
    {
        $this->responseCode = $responseCode;
        $this->message = $message;
        $this->data = $data;
    }

    public function toJsonEncode()
    {
        // header('Content-Type: application/json');
        http_response_code($this->responseCode);
        $output = array(
            "code" => $this->responseCode,
            "message" => $this->message,
        );

        if ($this->data !== array()) {
            $output = array(
                "code" => $this->responseCode,
                "message" => $this->message,
                "data" => $this->data,
            );
        }

        echo json_encode($output);
        exit();
    }
}

abstract class BaseRequestService
{
    public mysqli $mysqli;
    public string $currentDateTime;
    public string $visitorIpAddress;

    public function __construct()
    {
        $this->currentDateTime = date('Y-m-d H:i:s');
        $this->visitorIpAddress = $_SERVER['REMOTE_ADDR'];
    }

    public function connectToDatabase()
    {
        $this->mysqli = mysqli_connect(DB_HOST, DB_USER, DB_PASS, DB_NAME);

        if (mysqli_connect_errno()) {
            throw new Exception("Failed to connect to database.", 500);
        }
    }
}

final class PostRequestService extends BaseRequestService
{
    public string $sequenceName;
    public string $code;
    public string $ipAddress;

    public function __construct(string $json)
    {
        if (empty($json)) {
            throw new Exception("Song and Code are required.", 400);
        }

        $decodedJson = json_decode($json, false);
        $this->sequenceName = $decodedJson->sequenceName;
        $this->code = $decodedJson->code;
        $this->ipAddress = $_SERVER['REMOTE_ADDR'];
    }

    public function maxUnplayedSongsPerDevice(): int
    {
        return 2;
    }

    public function preventSpamAndFloodRequests(): void
    {
        $statement = $this->mysqli->prepare("SELECT * FROM songrequest WHERE createdIpaddress = ? AND played = 0");
        $statement->bind_param("s", $this->ipAddress);
        if (!$statement->execute()) {
            throw new Exception("Unexpected error.", 500);
        }

        $result = $statement->get_result();
        if ($result->num_rows >= $this->maxUnplayedSongsPerDevice()) {
            $this->mysqli->close();
            throw new Exception("Whoa there! Let someone else pick a song. Once your requests have been played, you may pick more songs.", 400);
        }
    }

    public function getCodeForToday(): string
    {
        switch (date('l')) {
            case 'Monday':
                return MONDAY_CODE;
            case 'Tuesday':
                return TUESDAY_CODE;
            case 'Wednesday':
                return WEDNESDAY_CODE;
            case 'Thursday':
                return THURSDAY_CODE;
            case 'Friday':
                return FRIDAY_CODE;
            case 'Saturday':
                return SATURDAY_CODE;
            default:
                return SUNDAY_CODE;
        }
    }

    public function validateCode(): void
    {
        $validCodeForToday = $this->getCodeForToday();
        if ($this->code !== $validCodeForToday) {
            throw new Exception("Invalid code. Please listen to the show announcement for todays code.", 400);
        }
    }

    public function validateRequestNotAlreadyInQueue(): void
    {
        $query = "SELECT * FROM songrequest WHERE sequenceName = ? AND played = 0";
        $statement = $this->mysqli->prepare($query);
        $statement->bind_param("s", $this->sequenceName);
        $statement->execute();
        $result = $statement->get_result();
        if ($result->num_rows > 0) {
            $this->mysqli->close();
            throw new Exception("Song has already been requested. Please wait for the song to play.", 400);
        }
    }

    public function getNumberOfRequestsInQueue(): int
    {
        $statement = $this->mysqli->prepare("SELECT * FROM songrequest WHERE played = 0");
        $statement->execute();
        $result = $statement->get_result();
        return $result->num_rows;
    }

    public function addRequestToQueue(int $songsAhead): void
    {
        $statement = $this->mysqli->prepare("INSERT INTO songrequest (sequenceName, createdIpAddress, modifiedIpAddress) VALUES (?, ?, ?)");
        $statement->bind_param("sss", $this->sequenceName, $this->ipAddress, $this->ipAddress);
        $statement->execute();
        (new JsonResponse(201, "Your request has been submitted. There are " . $songsAhead . " song(s) ahead of your request."))->toJsonEncode();
    }
}

final class GetRequestService extends BaseRequestService
{
    public function getPlayingSong(): void
    {
        $query = "SELECT value from songsetting where identifier = 'currentsong'";
        $statement = $this->mysqli->prepare($query);
        if (!$statement->execute()) {
            throw new Exception("Error updating data.", 500);
        }

        $result = $statement->get_result();
        $song = $result->fetch_assoc();
        $song = str_replace(".fseq", "", $song['value']);
        (new JsonResponse(200, $song))->toJsonEncode();
    }

    public function getAllSettings()
    {
        $query = "SELECT identifier, value from songsetting";
        $statement = $this->mysqli->prepare($query);
        if (!$statement->execute()) {
            throw new Exception("Error updating data.", 500);
        }

        $result = $statement->get_result();
        $settings = [];
        while ($row = $result->fetch_assoc()) {
            $settings[] = $row;
        }

        echo json_encode($settings);
        http_response_code(200);
        exit();
    }
}

$requestMethod = $_SERVER['REQUEST_METHOD'] ?? null;
$phpInput = "php://input";

try {
    switch ($requestMethod) {
        case 'GET':
            $request = new GetRequestService();
            $request->connectToDatabase();
            $request->getAllSettings();
            break;

        case 'POST':
            $json = file_get_contents($phpInput);
            $request = new PostRequestService($json);
            $request->validateCode();
            $request->connectToDatabase();
            $request->preventSpamAndFloodRequests();
            $request->validateRequestNotAlreadyInQueue();
            $songsAhead = $request->getNumberOfRequestsInQueue();
            $request->addRequestToQueue($songsAhead);
            break;

        default:
            (new JsonResponse(405, "Method not allowed."))->toJsonEncode();
    }
} catch (Exception $exception) {
    $jsonResponse = new JsonResponse($exception->getCode(), $exception->getMessage());
    $jsonResponse->toJsonEncode();
}