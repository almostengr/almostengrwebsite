<?php

// Include config file
require_once '../config.php';

// Connect to database
$conn = mysqli_connect(DB_HOST, DB_USER, DB_PASS, DB_NAME);

// Check connection
if (!$conn) {
    die("Connection failed: " . mysqli_connect_error());
}

// Update all rows in jukebox_requests table to set hasPlayed to 1
$sql = "UPDATE jukebox_requests SET hasPlayed = 1";

if (mysqli_query($conn, $sql)) {
    echo "All rows marked as played successfully";
} else {
    echo "Error updating rows: " . mysqli_error($conn);
}

// Close connection
mysqli_close($conn);
