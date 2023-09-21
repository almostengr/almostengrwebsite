<?php

require_once('../config.php');
date_default_timezone_set("America/Chicago");
ini_set('display_errors', 'On');

final class ResponseDto
{
    public int $code;
    public string $message;

    public function __construct(int $responseCode, string $message)
    {
        $this->code = $responseCode;
        $this->message = $message;
    }

    public function toJsonEncode()
    {
        http_response_code($this->code);
        $output = array(
            "message" => $this->message
        );

        echo json_encode($output);
        exit();
    }
}

function validateApiKey()
{
    $xAuthToken = 'X-Auth-Token';
    $headers = apache_request_headers();
    if (!isset($headers[$xAuthToken]) || $headers[$xAuthToken] !== API_KEY) {
        throw new Exception("Unauthorized", 401);
    }
}

function connectToDatabase()
{
    $dbConnection = mysqli_connect(DB_HOST, DB_USER, DB_PASS, DB_NAME);
    if (mysqli_connect_errno()) {
        throw new Exception("Database connection error", 500);
    }

    return $dbConnection;
}

function deleteAllRequests($dbConnection)
{
    $query = "UPDATE songrequest SET played = 1, modifiedTime = ?, modifiedIpAddress = ? where played = 0";
    $statement = $dbConnection->prepare($query);
    $ipAddress = $_SERVER['REMOTE_ADDR'];
    $statement->bind_param('ss', date('Y-m-d H:i:s'), $ipAddress);
    if (!$statement->execute()) {
        throw new Exception("Error clearing queue", 500);
    }

    $response = new ResponseDto(200, "");
    $response->toJsonEncode();
}

function getNextUnplayedRequest($dbConnection)
{
    $query = "SELECT id, sequencename FROM songrequest WHERE played = 0 ORDER BY createdTime ASC LIMIT 1";
    $statement = $dbConnection->prepare($query);

    if (!$statement->execute()) {
        throw new Exception("Error getting next song request", 500);
    }

    $result = $statement->get_result();
    if ($result->num_rows == 0) {
        $response = new ResponseDto(200, "");
        $response->toJsonEncode();
    }

    $requestId = 0;
    $requestSequence = "";
    while ($row = $result->fetch_assoc()) {
        $requestId = $row['id'];
        $requestSequence = $row['sequencename'];
    }

    $query = "UPDATE songrequest SET played = 1, modifiedTime = ?, modifiedIpAddress = ? WHERE id = ?";
    $statement = $dbConnection->prepare($query);

    $ipAddress = $_SERVER['REMOTE_ADDR'];
    $currentTime = date('Y-m-d H:i:s');
    $statement->bind_param('ssi', $currentTime, $ipAddress, $requestId);
    if (!$statement->execute()) {
        throw new Exception("Error updating song played status", 500);
    }

    $response = new ResponseDto(200, $requestSequence);
    $response->toJsonEncode();
}

function insertCurrentVitals($dbConnection, $json)
{
    $query = "insert into lightshowdisplay (windchill, nwstemp, cputemp, title, artist, createdipaddress) values (?,?,?,?,?,?)";
    $statement = $dbConnection->prepare($query);
    $ipAddress = $_SERVER['REMOTE_ADDR'];

    $statement->bind_param(
        'ssssss',
        $json->WindChill, $json->NwsTemperature, $json->CpuTemp, $json->Title, $json->Artist,
        $ipAddress
    );

    if (!$statement->execute()) {
        throw new Exception("Unable to save display details", 500);
    }

    $response = new ResponseDto(201, "Created");
    $response->toJsonEncode();
}

try {
    validateApiKey();
    $dbConnection = connectToDatabase();

    $requestMethod = $_SERVER['REQUEST_METHOD'];
    switch ($requestMethod) {
        case 'DELETE':
            deleteAllRequests($dbConnection);
            break;

        case 'GET':
            getNextUnplayedRequest($dbConnection);
            break;

        case 'POST':
            $input = file_get_contents("php://input");
            $json = json_decode($input);
            insertCurrentVitals($dbConnection, $json);
            break;

        default:
            $response = new ResponseDto(405, "Method not allowed");
            $response->toJsonEncode();
    }
} catch (Exception $exception) {
    $response = new ResponseDto($exception->getCode(), $exception->getMessage());
    $response->toJsonEncode();
}