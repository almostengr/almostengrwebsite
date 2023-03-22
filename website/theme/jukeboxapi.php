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
            )
        );
        exit();
    }
}

final class WebUserRequest
{
    private int $code;
    private string $message;

    public function __construct(int $code, string $message)
    {
        $this->code = $code;
        $this->message = $message;
    }

    public function toResponse()
    {
        http_response_code($this->code);
        header("refresh:5;url=https://thealmostengineer.com/jukebox");
        exit($this->message);
    }
}

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

function handleGetRequest()
{
    validateApiKey();
    $mysqli = connectToDatabase();

    // Get the first unplayed song
    $query = "SELECT id, sequencename, createdtime FROM SongRequest WHERE played = 0 ORDER BY createdTime ASC LIMIT 1";
    $stmt = $mysqli->prepare($query);
    if (!$stmt) {
        (new JsonResponse(500, "Error preparing statement"))->toJsonEncode();
    }

    if (!$stmt->execute()) {
        (new JsonResponse(500, "Error executing statement"))->toJsonEncode();
    }

    $result = $stmt->get_result();
    if ($result->num_rows == 0) {
        (new JsonResponse(200, ""))->toJsonEncode();
    }

    $row = $result->fetch_assoc();

    // Update the song as played
    $now = date('Y-m-d H:i:s');
    $ipAddress = $_SERVER['REMOTE_ADDR'];
    $updateQuery = "UPDATE SongRequest SET played = 1, modifiedTime = ?, modifiedIpAddress = ? WHERE id = ?";
    $updateStmt = $mysqli->prepare($updateQuery);
    if (!$updateStmt) {
        (new JsonResponse(500, "Error preparing statement"))->toJsonEncode();
    }

    $updateStmt->bind_param('ssi', $now, $ipAddress, $row['id']);
    if (!$updateStmt->execute()) {
        (new JsonResponse(500, "Error updating song"))->toJsonEncode();
    }

    $mysqli->close();

    (new JsonResponse(200, "", $row))->toJsonEncode();
}

function getCodeForToday()
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
            echo "";
    }
}

function handlePostRequest($sequenceName, $code)
{
    if (empty($sequenceName) || empty($code)) {
        // http_response_code(400);
        // header("refresh:5;url=https://thealmostengineer.com/jukebox");
        // exit("Error: Sequence Name and Code are required.");
        (new WebUserRequest(400, "Error: Sequence Name and code are required."))->toResponse();
    }
    
    // Check if the code is valid for the current day of the week
    $validCodeForToday = getCodeForToday();
    if ($code !== $validCodeForToday) {
        // http_response_code(400);
        // header("refresh:5;url=https://thealmostengineer.com/jukebox");
        // exit("Error: Invalid code. Please listen to the show announcement for today's code.");
        (new WebUserRequest(400, "Error: Invalid code. Please listen to the show announcement for today's code."))->toResponse();
    }
    
    // Check if the sequence name already exists and has not been played
    $mysqli = connectToDatabase();
    $stmt = $mysqli->prepare("SELECT * FROM SongRequest WHERE sequenceName = ? AND played = 0");
    $stmt->bind_param("s", $sequenceName);
    $stmt->execute();
    $result = $stmt->get_result();
    if ($result->num_rows > 0) {
        $mysqli->close();
        // http_response_code(400);
        // header("refresh:5;url=https://thealmostengineer.com/jukebox");
        // exit("Error: Song has already been requested. Please wait for the song to play.");
        (new WebUserRequest(400, "Error: Song has already been requested. Please wait for the song to play."))->toResponse();
    }
    
    $stmt = $mysqli->prepare("SELECT * FROM SongRequest WHERE played = 0");
    $stmt->execute();
    $result = $stmt->get_result();
    $songsAhead = $result->num_rows;

    $ipAddress = $_SERVER['REMOTE_ADDR'];
    $stmt = $mysqli->prepare("INSERT INTO SongRequest (sequenceName, createdIpAddress, modifiedIpAddress) VALUES (?, ?,?)");
    $stmt->bind_param("sss", $sequenceName, $ipAddress, $ipAddress);
    $stmt->execute();
    $mysqli->close();

    // http_response_code(201);
    // header("refresh:5;url=https://thealmostengineer.com/jukebox");
    // exit("Success: Your song request has been submitted. There are " . $songsAhead . " song(s) ahead of your request.");
    (new WebUserRequest(201, "Success: Your song request has been submitted. There are " . $songsAhead . " song(s) ahead of your request."))->toResponse();
}

function handleDeleteRequest()
{
    validateApiKey();
    $mysqli = connectToDatabase();

    $now = date('Y-m-d H:i:s');
    $ipAddress = $_SERVER['REMOTE_ADDR'];
    $updateQuery = "UPDATE SongRequest SET played = 1, modifiedTime = ?, modifiedIpAddress = ? where played = 0";
    $updateStmt = $mysqli->prepare($updateQuery);
    if (!$updateStmt) {
        (new JsonResponse(500, "Error updating data"))->toJsonEncode();
    }

    $updateStmt->bind_param('ss', $now, $ipAddress);
    if (!$updateStmt->execute()) {
        (new JsonResponse(500, "Error updating data"))->toJsonEncode();
    }

    $updateStmt->close();
    $mysqli->close();

    (new JsonResponse(200, ""))->toJsonEncode();
}

function handlePutRequest()
{
    validateApiKey();
    $mysqli = connectToDatabase();

    $requestBody = json_decode(file_get_contents('php://input'));

    switch ($requestBody["status"]) {
        case "on":
            break;

        case "off":
            break;

        default:
            exit("Bad request.");
    }
}


switch ($_SERVER['REQUEST_METHOD']) {
    case 'GET':
        handleGetRequest();
        break;
    case 'POST':
        handlePostRequest($_POST["sequenceName"], $_POST["code"]);
        break;
    case 'DELETE':
        handleDeleteRequest();
        break;
    default:
        (new JsonResponse(405, "Method not allowed"))->toJsonEncode();
}