<?php

// Import the configuration file
require_once('config.php');

final class JukeboxEnableRequest
{
    private bool $showActive;

    public function __construct(bool $showActive)
    {
        $this->showActive = $showActive;
    }

    public function getShowActive()
    {
        return $this->showActive;
    }
}



// Import the SequenceResponse and JukeboxApi classes
require_once('SequenceResponse.php');
require_once('JukeboxApi.php');

// Start the session
session_start();

// Check if the request is a POST request
if ($_SERVER['REQUEST_METHOD'] !== 'POST') {
    $response = new SequenceResponse(400, array('message' => 'Bad Request'));
    echo $response->to_json();
    exit;
}

// Check if the API key is set in the headers
if (!isset($_SERVER['HTTP_X_API_KEY'])) {
    $response = new SequenceResponse(400, array('message' => 'API key is missing'));
    echo $response->to_json();
    exit;
}

// Validate the API key
$api_key = $_SERVER['HTTP_X_API_KEY'];
$query = "SELECT value FROM jukebox_settings WHERE setting = 'api_key' LIMIT 1";
$result = $mysqli->query($query);

if ($result->num_rows == 0) {
    $response = new SequenceResponse(500, array('message' => 'Internal server error'));
    echo $response->to_json();
    exit;
}

$row = $result->fetch_assoc();
$stored_api_key = $row['value'];

if ($api_key !== $stored_api_key) {
    $response = new SequenceResponse(403, array('message' => 'Unauthorized'));
    echo $response->to_json();
    exit;
}

// Update the "enabled" row to 1 (true)
$query = "UPDATE jukebox_settings SET value = '0' WHERE setting = 'enabled'";
$result = $mysqli->query($query);

if ($result === false) {
    $response = new SequenceResponse(500, array('message' => 'Internal server error'));
    echo $response->to_json();
    exit;
}

// Return a success response
$response = new SequenceResponse(200, array('message' => 'Success'));
echo $response->to_json();
exit;
