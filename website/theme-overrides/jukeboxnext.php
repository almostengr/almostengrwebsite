<?php
require_once '../config.php';

// Check for valid API key
$headers = apache_request_headers();
if (!isset($headers['X-API-Key']) || $headers['X-API-Key'] !== API_KEY) {
    http_response_code(401);
    exit("Unauthorized");
}

// Only allow GET requests
if ($_SERVER['REQUEST_METHOD'] !== 'GET') {
    http_response_code(400);
    exit("Bad Request");
}

// Connect to the database
$pdo = new PDO(
    "mysql:host=" . DB_HOST . ";dbname=" . DB_NAME . ";charset=utf8mb4",
    DB_USER,
    DB_PASSWORD
);

// Get the first unplayed song
$stmt = $pdo->prepare("SELECT * FROM jukebox_requests WHERE hasPlayed = 0 ORDER BY requestedTime ASC LIMIT 1");
$stmt->execute();
$song = $stmt->fetch(PDO::FETCH_ASSOC);

// If no unplayed songs were found, return an empty response
if (!$song) {
    exit("{}");
}

// Mark the song as played
$stmt = $pdo->prepare("UPDATE jukebox_requests SET hasPlayed = 1 WHERE id = :id");
$stmt->bindValue(":id", $song['id']);
$stmt->execute();

// Return the song info as JSON
$response = [
    'id' => $song['id'],
    'sequenceName' => $song['sequenceName'],
    'requestedTime' => $song['requestedTime']
];
header('Content-Type: application/json');
echo json_encode($response);
