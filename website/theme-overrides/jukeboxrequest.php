<?php

if($_SERVER['HTTP_REFERER'] !== "https://thealmostengineer.com/"){
    http_response_code(400);
    echo "Bad Request";
    exit;
}

if ($_SERVER['REQUEST_METHOD'] !== 'POST') {
    http_response_code(400);
    echo "Bad Request";
    exit;
}

$sequenceName = trim($_POST['sequenceName'] ?? '');
$code = trim($_POST['code'] ?? '');

// validate that required fields are not empty
if (empty($sequenceName) || empty($code)) {
    http_response_code(400);
    echo "Invalid input";
    exit;
}

// validate the code
$dayOfWeek = strtolower(date('l'));
$validCodes = [
    'sunday' => '1234',
    'monday' => '5678',
    'tuesday' => '9012',
    'wednesday' => '3456',
    'thursday' => '7890',
    'friday' => '1234',
    'saturday' => '5678',
];

if (!isset($validCodes[$dayOfWeek]) || $code !== $validCodes[$dayOfWeek]) {
    http_response_code(401);
    echo "Invalid code. Please try again.";
    exit;
}

// connect to database
$servername = "localhost";
$username = "username";
$password = "password";
$dbname = "database_name";

$conn = new mysqli($servername, $username, $password, $dbname);

if ($conn->connect_error) {
    die("Connection failed: " . $conn->connect_error);
}

$statement = $conn->prepare("select * from jukebox_requests where sequenceName = ? and hasPlayed = 0");
$statement->bind_param("s", $sequenceName);
$statement->execute();


if ($statement->num_rows() > 0)
{
    die("This song has already been requested. Please be patient for it to play.");   
}

// save request to database
$requestedTime = date('Y-m-d H:i:s');
$ipAddress = $_SERVER['REMOTE_ADDR'];

$stmt = $conn->prepare("INSERT INTO jukebox_requests (sequenceName, requestedTime, hasPlayed, ipAddress) VALUES (?, ?, 0, ?)");

$stmt->bind_param("sss", $sequenceName, $requestedTime, $ipAddress);

if (!$stmt->execute()) {
    http_response_code(500);
    echo "Error saving request to database";
    exit;
}

// echo "Request saved successfully";
echo "<p>Your request has been added to the Jukebox!</p>";
header("refresh:5;url=https://thealmostengineer.com/jukebox");

$stmt->close();
$conn->close();
