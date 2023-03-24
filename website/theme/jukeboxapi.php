<?php

require_once('../config.php');
date_default_timezone_set("America/Chicago");

abstract class BaseResponse
{
    private int $responseCode;
    private string $message;
}

final class JsonResponse extends BaseResponse
{
    private array $data;

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

final class WebUserResponse extends BaseResponse
{
    public function __construct(int $responseCode, string $message)
    {
        $this->responseCode = $responseCode;
        $this->message = $message;
    }

    public function toResponse()
    {
        http_response_code($this->responseCode);
        header("refresh:5;url=https://thealmostengineer.com/jukebox");
        exit($this->message . " Redirecting in 5 seconds...");
    }
}

abstract class BaseRequestService
{
    protected mysqli $mysqli;
    protected string $currentDateTime;
    protected string $visitorIpAddress;

    public function __construct()
    {
        $this->currentDateTime = date('Y-m-d H:i:s');
        $this->visitorIpAddress = $_SERVER['REMOTE_ADDR'];
    }

    abstract function processRequest(): void;

    protected function connectToDatabase()
    {
        $this->mysqli = mysqli_connect(DB_HOST, DB_USER, DB_PASS, DB_NAME);

        if (mysqli_connect_errno()) {
            (new JsonResponse(500, 'Failed to connect to database: ' . mysqli_connect_error()))->toJsonEncode();
        }
    }

    protected function validateApiKey()
    {
        $headers = apache_request_headers();
        if (!isset($headers['X-Auth-Token']) || $headers['X-Auth-Token'] !== API_KEY) {
            (new JsonResponse(401, "Unauthorized"))->toJsonEncode();
        }
    }
}

final class GetRequestService extends BaseRequestService
{
    public function processRequest(): void
    {
        $this->validateApiKey();
        $this->connectToDatabase();
        $song = $this->getFirstUnplayedSong();
        $this->updateSongAsPlayed($song);
    }

    private function getFirstUnplayedSong(): array
    {
        $query = "SELECT id, sequencename, createdtime FROM song_request WHERE played = 0 ORDER BY createdTime ASC LIMIT 1";
        $stmt = $this->mysqli->prepare($query);

        if (!$stmt->execute()) {
            (new JsonResponse(500, "Error executing statement"))->toJsonEncode();
        }

        $result = $stmt->get_result();
        if ($result->num_rows == 0) {
            (new JsonResponse(200, ""))->toJsonEncode();
        }

        return $result->fetch_assoc();
    }

    private function updateSongAsPlayed(array $row): void
    {
        $updateQuery = "UPDATE song_request SET played = 1, modifiedTime = ?, modifiedIpAddress = ? WHERE id = ?";
        $updateStmt = $this->mysqli->prepare($updateQuery);

        $updateStmt->bind_param('ssi', $this->currentDateTime, $this->visitorIpAddress, $row['id']);
        if (!$updateStmt->execute()) {
            (new JsonResponse(500, "Error updating song"))->toJsonEncode();
        }

        (new JsonResponse(200, "", $row))->toJsonEncode();
    }
}

final class PostRequestService extends BaseRequestService
{
    private string $sequenceName;
    private string $code;
    private int $MAX_UNPLAYED_SONGS_PER_DEVICE = 2;
    private string $UNEXPECTED_ERROR_MESSAGE = "Error: Unexpected error";

    public function __construct(string $sequenceName, string $code)
    {
        if (empty($sequenceName) || empty($code)) {
            (new WebUserResponse(400, "Error: Sequence Name and Code are required."))->toResponse();
        }

        $this->sequenceName = $sequenceName;
        $this->code = $code;
    }

    public function processRequest(): void
    {
        $this->validateCode();
        $this->connectToDatabase();
        $this->preventSpamAndFloodRequests();
        $this->validateSequenceNotAlreadyInQueue();
        $songsAhead = $this->getNumberOfSongsInQueue();
        $this->addSongToQueue($songsAhead);
    }

    private function preventSpamAndFloodRequests(): void
    {
        $stmt = $this->mysqli->prepare("SELECT * FROM song_request WHERE createdIpaddress = ? AND played = 0");
        $stmt->bind_param("s", $this->visitorIpAddress);
        if (!$stmt->execute()) {
            (new WebUserResponse(500, $this->UNEXPECTED_ERROR_MESSAGE))->toResponse();
        }

        $result = $stmt->get_result();
        if ($result->num_rows >= $this->MAX_UNPLAYED_SONGS_PER_DEVICE) {
            $this->mysqli->close();
            (new WebUserResponse(500, $this->UNEXPECTED_ERROR_MESSAGE))->toResponse();
        }
    }

    private function getCodeForToday(): string
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
            case 'Sunday':
                return SUNDAY_CODE;
            default:
                return "";
        }
    }

    private function validateCode(): void
    {
        $validCodeForToday = $this->getCodeForToday();
        if ($this->code !== $validCodeForToday) {
            (new WebUserResponse(400, "Error: Invalid code. Please listen to the show announcement for today's code."))->toResponse();
        }
    }

    private function validateSequenceNotAlreadyInQueue(): void
    {
        $stmt = $this->mysqli->prepare("SELECT * FROM song_request WHERE sequenceName = ? AND played = 0");
        $stmt->bind_param("s", $sequenceName);
        $stmt->execute();
        $result = $stmt->get_result();
        if ($result->num_rows > 0) {
            $this->mysqli->close();
            (new WebUserResponse(400, "Error: Song has already been requested. Please wait for the song to play."))->toResponse();
        }
    }

    private function getNumberOfSongsInQueue(): int
    {
        $stmt = $this->mysqli->prepare("SELECT * FROM song_request WHERE played = 0");
        $stmt->execute();
        $result = $stmt->get_result();
        return $result->num_rows;
    }

    private function addSongToQueue(int $songsAhead): void
    {
        $stmt = $this->mysqli->prepare("INSERT INTO song_request (sequenceName, createdIpAddress, modifiedIpAddress) VALUES (?, ?, ?)");
        $stmt->bind_param("sss", $this->sequenceName, $this->visitorIpAddress, $this->visitorIpAddress);
        $stmt->execute();
        (new WebUserResponse(201, "Success: Your song request has been submitted. There are " . $songsAhead . " song(s) ahead of your request."))->toResponse();
    }
}

final class DeleteRequestService extends BaseRequestService
{
    public function processRequest(): void
    {
        $this->validateApiKey();
        $this->connectToDatabase();
        $this->markAllRequestsAsPlayed();
    }

    private function markAllRequestsAsPlayed(): void
    {
        $updateQuery = "UPDATE song_request SET played = 1, modifiedTime = ?, modifiedIpAddress = ? where played = 0";
        $updateStmt = $this->mysqli->prepare($updateQuery);
        $updateStmt->bind_param('ss', $this->currentDateTime, $this->visitorIpAddress);
        if (!$updateStmt->execute()) {
            (new JsonResponse(500, "Error updating data"))->toJsonEncode();
        }

        (new JsonResponse(200, ""))->toJsonEncode();
    }
}

switch ($_SERVER['REQUEST_METHOD']) {
    case 'GET':
        (new GetRequestService())->processRequest();
        break;
    case 'POST':
        $postRequest = new PostRequestService($_POST["sequenceName"], $_POST["code"]);
        $postRequest->processRequest();
        break;
    case 'DELETE':
        (new DeleteRequestService())->processRequest();
        break;
    default:
        (new JsonResponse(405, "Method not allowed"))->toJsonEncode();
}