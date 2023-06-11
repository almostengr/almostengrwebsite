<?php

require_once('../config.php');
date_default_timezone_set("America/Chicago");

abstract class BaseResponse
{
    public int $responseCode;
    public string $message;
}

final class JsonResponse extends BaseResponse
{
    public array $data;

    public function __construct(int $responseCode, string $message, array $data = array())
    {
        $this->responseCode = $responseCode;
        $this->message = $message;
        $this->data = $data;
    }

    public function toJsonEncode()
    {
        header('Content-Type: application/json');
        http_response_code($this->responseCode);
        echo json_encode(
            array(
                "code" => $this->responseCode,
                "message" => $this->message,
                "data" => $this->data
            )
        );
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

final class PutRequestService extends BaseRequestService
{
    private string $action;
    private string $songName;

    public function __construct(string $json)
    {
        if (empty($json)) {
            throw new Exception("Bad request.", 400);
        }

        $decodedJson = json_decode($json, false);
        $this->action = $decodedJson->action;
        $this->songName = $decodedJson->songName;
    }

    public function getAction(): string
    {
        return $this->action;
    }

    public function updatePlayingRequestToPlayed(): void
    {
        $query = "update songrequest set played = 2 where played = 1";
        $statement = $this->mysqli->prepare($query);
        $statement->execute();
    }

    public function getFirstUnplayedRequest(): array
    {
        $query = "SELECT id, sequencename, createdtime FROM SongRequest WHERE played = 0 ORDER BY createdTime ASC LIMIT 1";
        $stmt = $this->mysqli->prepare($query);

        if (!$stmt->execute()) {
            throw new Exception("Error getting song.", 500);
        }

        $result = $stmt->get_result();
        if ($result->num_rows == 0) {
            (new JsonResponse(200, ""))->toJsonEncode();
        }

        return $result->fetch_assoc();
    }

    public function updateCurrentSongPlaying()
    {
        $query = "update songsettings set value = ? where identifier = 'currentsong'";
        $statement = $this->mysqli->prepare($query);
        $statement->bind_param("ss", $this->songName);

        if (!$statement->execute()) {
            throw new Exception("Error updating song.", 500);
        }
    }

    public function updateRequestToPlaying(array $row): void
    {
        $updateQuery = "UPDATE SongRequest SET played = 1, modifiedTime = ?, modifiedIpAddress = ? WHERE id = ?";
        $updateStmt = $this->mysqli->prepare($updateQuery);

        $updateStmt->bind_param('ssi', $this->currentDateTime, $this->visitorIpAddress, $row['id']);
        if (!$updateStmt->execute()) {
            throw new Exception("Error updating song.", 500);
        }

        (new JsonResponse(200, "", $row))->toJsonEncode();
    }

    public function markAllRequestsAsPlayed(): void
    {
        $updateQuery = "UPDATE SongRequest SET played = 2, modifiedTime = ?, modifiedIpAddress = ? where played = 0 or played = 1";
        $updateStmt = $this->mysqli->prepare($updateQuery);
        $updateStmt->bind_param('ss', $this->currentDateTime, $this->visitorIpAddress);
        if (!$updateStmt->execute()) {
            throw new Exception("Error updating song.", 500);
        }

        (new JsonResponse(200, ""))->toJsonEncode();
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
        $stmt = $this->mysqli->prepare("SELECT * FROM SongRequest WHERE createdIpaddress = ? AND played = 0");
        $stmt->bind_param("s", $this->ipAddress);
        if (!$stmt->execute()) {
            throw new Exception("Unexpected error.", 500);
        }

        $result = $stmt->get_result();
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
                return TUEDAY_CODE;
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
        $stmt = $this->mysqli->prepare("SELECT * FROM SongRequest WHERE sequenceName = ? AND played = 0");
        $stmt->bind_param("s", $sequenceName);
        $stmt->execute();
        $result = $stmt->get_result();
        if ($result->num_rows > 0) {
            $this->mysqli->close();
            throw new Exception("Song has already been requested. Please wait for the song to play.", 400);
        }
    }

    public function getNumberOfRequestsInQueue(): int
    {
        $stmt = $this->mysqli->prepare("SELECT * FROM SongRequest WHERE played = 0");
        $stmt->execute();
        $result = $stmt->get_result();
        return $result->num_rows;
    }

    public function addRequestToQueue(int $songsAhead): void
    {
        $stmt = $this->mysqli->prepare("INSERT INTO SongRequest (sequenceName, createdIpAddress, modifiedIpAddress) VALUES (?, ?, ?)");
        $stmt->bind_param("sss", $this->sequenceName, $this->ipAddress, $this->ipAddress);
        $stmt->execute();
        (new JsonResponse("Your request has been submitted. There are " . $songsAhead . " song(s) ahead of your request.", 201))->toJsonEncode();
    }
}

final class DeleteRequestService extends BaseRequestService
{
    public function markAllRequestsAsPlayed(): void
    {
        $updateQuery = "UPDATE SongRequest SET played = 2, modifiedTime = ?, modifiedIpAddress = ? where played = 0 or played = 1";
        $updateStmt = $this->mysqli->prepare($updateQuery);
        $updateStmt->bind_param('ss', $this->currentDateTime, $this->visitorIpAddress);
        if (!$updateStmt->execute()) {
            throw new Exception("Error updating data.", 500);
        }

        (new JsonResponse(200, ""))->toJsonEncode();
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
}

$requestMethod = $_SERVER['REQUEST_METHOD'] ?? null;
$phpInput = "php://input";

try {
    switch ($requestMethod) {
        case 'PUT':
            $json = file_get_contents($phpInput);
            $request = new PutRequestService($json);
            $request->validateApiKey();
            $request->connectToDatabase();

            switch ($request->getAction()) {
                case "nextsong":
                    $request->updatePlayingRequestToPlayed();
                    $song = $request->getFirstUnplayedRequest();
                    break;

                case "clearqueue":
                    $request->markAllRequestsAsPlayed();
                    break;

                case "playing":
                    $request->updateCurrentSongPlaying();
                    break;

                default:
                    throw new Exception("Bad request.", 400);
            }
            break;

        case 'GET':
            $request = new GetRequestService();
            $request->connectToDatabase();
            $request->getPlayingSong();
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