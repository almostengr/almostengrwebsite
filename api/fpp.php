<?php

require_once('../config.php');
date_default_timezone_set("America/Chicago");
ini_set('display_errors', 'Off');

final class SettingRequestDto
{
    public string $key;
    public string $value;

    public function __construct(string $json)
    {
        $decodedJson = json_decode($json, false);
        $this->key = $decodedJson->key;
        $this->value = $decodedJson->value;
    }
}

class ResponseDto
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
            "code" => $this->code,
            "message" => $this->message
        );

        echo json_encode($output);
        exit();
    }
}

final class SettingResponseDto extends ResponseDto
{
    public string $key;
    public string $value;

    public function __construct(int $code, string $message, string $key, string $value)
    {
        $this->code = $code;
        $this->message = $message;
        $this->key = $key;
        $this->value = $value;
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

function updateSetting($dbConnection, SettingRequestDto $settingRequestDto)
{
    $isKeyValid = false;
    $acceptableKeys = ["currentsong", "cputempc", "outdoortempc"];
    foreach ($acceptableKeys as $key) {
        if ($key == $settingRequestDto->key) {
            $isKeyValid = true;
            break;
        }
    }

    if (!$isKeyValid) {
        throw new Exception("Invalid key", 400);
    }

    $query = "update songsetting set value = ? where identifier = ?";
    $statement = $dbConnection->prepare($query);
    $statement->bind_param("ss", $settingRequestDto->value, $settingRequestDto->key);

    if (!$statement->execute()) {
        throw new Exception("Error updating setting", 500);
    }

    $response = new SettingResponseDto(200, "", $settingRequestDto->key, $settingRequestDto->value);
    $response->toJsonEncode();
}

function getNextUnplayedRequest($dbConnection)
{
    $query = "SELECT id, sequencename FROM songrequest WHERE played = 0 ORDER BY createdTime ASC LIMIT 1";
    $statement = $dbConnection->prepare($query);

    if (!$statement->execute()) {
        throw new Exception("Error getting song", 500);
    }

    $result = $statement->get_result();
    if ($result->num_rows == 0) {
        $response = new ResponseDto(200, "");
        $response->toJsonEncode();
    }

    $query = "UPDATE songrequest SET played = 1, modifiedTime = ?, modifiedIpAddress = ? WHERE id = ?";
    $statement = $dbConnection->prepare($query);

    $ipAddress = $_SERVER['REMOTE_ADDR'];
    $statement->bind_param('ssi', date('Y-m-d H:i:s'), $ipAddress, $result['id']);
    if (!$statement->execute()) {
        throw new Exception("Error updating song", 500);
    }

    $response = new ResponseDto(200, $result['sequenceName']);
    $response->toJsonEncode();
}


try {
    validateApiKey();
    $dbConnection = connectToDatabase();

    switch ($requestMethod) {
        case 'DELETE':
            deleteAllRequests($dbConnection);
            break;

        case 'GET':
            getNextUnplayedRequest($dbConnection);
            break;

        case 'PUT':
            $json = file_get_contents($phpInput);
            $request = new SettingRequestDto($json);
            updateSetting($dbConnection, $request);
            break;

        default:
            $response = new ResponseDto(405, "Method not allowed");
            $response->toJsonEncode();
    }
} catch (Exception $exception) {
    $response = new ResponseDto($exception->getCode(), $exception->getMessage());
    $response->toJsonEncode();
}