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

    public function validateApiKey()
    {
        $xAuthToken = 'X-Auth-Token';
        $headers = apache_request_headers();
        if (!isset($headers[$xAuthToken]) || $headers[$xAuthToken] !== API_KEY) {
            throw new Exception("Unauthorized.", 401);
        }
    }
}

final class FppRequestService extends BaseRequestService
{
    private string $action;
    private string $songname;

    public function __construct(string $json)
    {
        if (empty($json)) {
            throw new Exception("Bad request.", 400);
        }

        $decodedJson = json_decode($json, false);
        $this->action = $decodedJson->action;
        $this->songname = $decodedJson->songname ?? "";
    }

    public function getAction(): string
    {
        return $this->action;
    }

    public function updatePlayingRequestToPlayed(): void
    {
        $query = "update songrequest set played = 1 where played = 0";
        $statement = $this->mysqli->prepare($query);
        $statement->execute();
    }

    public function getFirstUnplayedRequest(): array
    {
        $query = "SELECT id, sequencename, createdtime FROM songrequest WHERE played = 0 ORDER BY createdTime ASC LIMIT 1";
        $statement = $this->mysqli->prepare($query);

        if (!$statement->execute()) {
            throw new Exception("Error getting song.", 500);
        }

        $result = $statement->get_result();
        if ($result->num_rows == 0) {
            $response = new JsonResponse(200, "");
            $response->toJsonEncode();
        }

        return $result->fetch_assoc();
    }

    public function updateCurrentSongPlaying()
    {
        $query = "update songsetting set value = ? where identifier = 'currentsong'";
        $statement = $this->mysqli->prepare($query);
        $statement->bind_param("s", $this->songname);

        if (!$statement->execute()) {
            throw new Exception("Error updating song.", 500);
        }

        $response = new JsonResponse(200, "");
        $response->toJsonEncode();
    }

    public function updateRequestToPlayed($row): void
    {
        $query = "UPDATE songrequest SET played = 1, modifiedTime = ?, modifiedIpAddress = ? WHERE id = ?";
        $statement = $this->mysqli->prepare($query);

        $ipAddress = $_SERVER['REMOTE_ADDR'];
        $statement->bind_param('ssi', date('Y-m-d H:i:s'), $ipAddress, $row['id']);
        // $statement->bind_param('ssi', $this->currentDateTime, $this->visitorIpAddress, $row['id']);
        if (!$statement->execute()) {
            throw new Exception("Error updating song.", 500);
        }

        $response = new JsonResponse(200, "", $row);
        $response->toJsonEncode();
    }

    public function markAllRequestsAsPlayed(): void
    {
        $query = "UPDATE songrequest SET played = 1, modifiedTime = ?, modifiedIpAddress = ? where played = 0";
        $statement = $this->mysqli->prepare($query);
        $ipAddress = $_SERVER['REMOTE_ADDR'];
        $statement->bind_param('ss', date('Y-m-d H:i:s'), $ipAddress);
        if (!$statement->execute()) {
            throw new Exception("Error updating song.", 500);
        }

        (new JsonResponse(200, ""))->toJsonEncode();
    }
}

$requestMethod = $_SERVER['REQUEST_METHOD'] ?? null;
$phpInput = "php://input";

try {
    $json = file_get_contents($phpInput);
    $request = new FppRequestService($json);
    $request->validateApiKey();
    $request->connectToDatabase();

    switch ($requestMethod) {
        case "DELETE":
            $request->markAllRequestsAsPlayed();
            break;

        case 'GET':
            $song = $request->getFirstUnplayedRequest();
            $request->updateRequestToPlayed($song);
            break;
            
        case 'PUT':

            // switch ($request->getAction()) {
                // case "nextsong":
                //     // $request->updatePlayingRequestToPlayed();
                //     $song = $request->getFirstUnplayedRequest();
                //     $request->updateRequestToPlayed($song);
                //     break;

                // case "clearqueue":
                //     break;

                // case "playing":
                //     $request->updateCurrentSongPlaying();
                //     break;

            //     default:
            //         throw new Exception("Bad request. Invalid action", 400);
            // }
            $request->updateCurrentSongPlaying();

            break;

        default:
            (new JsonResponse(405, "Method not allowed."))->toJsonEncode();
    }
} catch (Exception $exception) {
    $jsonResponse = new JsonResponse($exception->getCode(), $exception->getMessage());
    $jsonResponse->toJsonEncode();
}