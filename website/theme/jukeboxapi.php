<?php

require_once('../config.php');

date_default_timezone_set("America/Chicago");

final class JsonResponse
{
    private int $responseCode;
    private string $errorMessage;
    private array $data;

    public function __construct(int $responseCode, string $errorMessage, array $data = array())
    {
        $this->responseCode = $responseCode;
        $this->errorMessage = $errorMessage;
        $this->data = $data;
    }

    public function toJsonEncode()
    {
        header('Content-Type: application/json');
        http_response_code($this->responseCode);
        echo json_encode(
            array(
                "code" => $this->responseCode,
                "error" => $this->errorMessage,
                "data" => $this->data
            ));
        exit();
    }
}

final class WebUserRequest
{
    private int $responseCode;
    private string $message;

    public function __construct(int $responseCode, string $message)
    {
        $this->responseCode = $responseCode;
        $this->message = $message;
    }

    public function toResponse()
    {
        http_response_code($this->responseCode);
        header("refresh:5;url=https://thealmostengineer.com/jukebox");
        exit($this->message);
    }
}

abstract class BaseRequestService
{
    abstract function processRequest(): void;

    function connectToDatabase()
    {
        $mysqli = mysqli_connect(DB_HOST, DB_USER, DB_PASS, DB_NAME);

        if (mysqli_connect_errno()) {
            (new JsonResponse(500, 'Failed to connect to database: ' . mysqli_connect_error()))->toJsonEncode();
        }

        return $mysqli;
    }

    function validateApiKey()
    {
        $headers = apache_request_headers();
        if (!isset($headers['X-Auth-Token']) || $headers['X-Auth-Token'] !== API_KEY) {
            (new JsonResponse(401, "Unauthorized"))->toJsonEncode();
        }
    }
}

final class GetRequestService extends BaseRequestService
{
    private mysqli $mysqli;

    public function processRequest(): void
    {
        $this->validateApiKey();
        $this->mysqli = $this->connectToDatabase();
        $song = $this->getFirstUnplayedSong();
        $this->updateSongAsPlayed($song);
    }

    private function getFirstUnplayedSong(): array
    {
        $query = "SELECT id, sequencename, createdtime FROM SongRequest WHERE played = 0 ORDER BY createdTime ASC LIMIT 1";
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
        $updateQuery = "UPDATE SongRequest SET played = 1, modifiedTime = ?, modifiedIpAddress = ? WHERE id = ?";
        $updateStmt = $this->mysqli->prepare($updateQuery);
        if (!$updateStmt) {
            (new JsonResponse(500, "Error preparing statement"))->toJsonEncode();
        }

        $now = date('Y-m-d H:i:s');
        $ipAddress = $_SERVER['REMOTE_ADDR'];
        $updateStmt->bind_param('ssi', $now, $ipAddress, $row['id']);
        if (!$updateStmt->execute()) {
            (new JsonResponse(500, "Error updating song"))->toJsonEncode();
        }

        $this->mysqli->close();

        (new JsonResponse(200, "", $row))->toJsonEncode();
    }
}

final class PostRequestService extends BaseRequestService
{
    private string $sequenceName;
    private string $code;
    private mysqli $mysqli;

    public function __construct(string $sequenceName, string $code)
    {
        if (empty($sequenceName) || empty($code)) {
            (new WebUserRequest(400, "Error: Sequence Name and code are required."))->toResponse();
        }

        $this->sequenceName = $sequenceName;
        $this->code = $code;
    }

    public function processRequest(): void
    {
        $this->validateCode();
        $this->mysqli = $this->connectToDatabase();
        $this->validateSequenceNotAlreadyInQueue();
        $songsAhead = $this->getNumberOfSongsInQueue();

        $ipAddress = $_SERVER['REMOTE_ADDR'];
        $this->addSongToQueue($ipAddress);

        (new WebUserRequest(201, "Success: Your song request has been submitted. There are " . $songsAhead . " song(s) ahead of your request."))->toResponse();
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
            (new WebUserRequest(400, "Error: Invalid code. Please listen to the show announcement for today's code."))->toResponse();
        }
    }

    private function validateSequenceNotAlreadyInQueue(): void
    {
        $stmt = $this->mysqli->prepare("SELECT * FROM SongRequest WHERE sequenceName = ? AND played = 0");
        $stmt->bind_param("s", $sequenceName);
        $stmt->execute();
        $result = $stmt->get_result();
        if ($result->num_rows > 0) {
            $this->mysqli->close();
            (new WebUserRequest(400, "Error: Song has already been requested. Please wait for the song to play."))->toResponse();
        }
    }

    private function getNumberOfSongsInQueue(): int
    {
        $stmt = $this->mysqli->prepare("SELECT * FROM SongRequest WHERE played = 0");
        $stmt->execute();
        $result = $stmt->get_result();
        return $result->num_rows;
    }

    private function addSongToQueue(string $ipAddress): void
    {
        $stmt = $this->mysqli->prepare("INSERT INTO SongRequest (sequenceName, createdIpAddress, modifiedIpAddress) VALUES (?, ?,?)");
        $stmt->bind_param("sss", $this->sequenceName, $ipAddress, $ipAddress);
        $stmt->execute();
        $this->mysqli->close();
    }
}

final class DeleteRequestService extends BaseRequestService
{
    private mysqli $mysqli;

    public function processRequest(): void
    {
        $this->validateApiKey();
        $this->mysqli = $this->connectToDatabase();
        $this->markAllRequestsAsPlayed();
    }

    private function markAllRequestsAsPlayed(): void
    {
        $updateQuery = "UPDATE SongRequest SET played = 1, modifiedTime = ?, modifiedIpAddress = ? where played = 0";
        $updateStmt = $this->mysqli->prepare($updateQuery);
        if (!$updateStmt) {
            (new JsonResponse(500, "Error updating data"))->toJsonEncode();
        }

        $now = date('Y-m-d H:i:s');
        $ipAddress = $_SERVER['REMOTE_ADDR'];
        $updateStmt->bind_param('ss', $now, $ipAddress);
        if (!$updateStmt->execute()) {
            (new JsonResponse(500, "Error updating data"))->toJsonEncode();
        }

        $updateStmt->close();
        $this->mysqli->close();

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