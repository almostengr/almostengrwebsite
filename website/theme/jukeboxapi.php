<?php

require_once('../config.php');

function connectToDatabase()
{
    $conn = mysqli_connect(DB_HOST, DB_USER, DB_PASS, DB_NAME);

    if (mysqli_connect_errno()) {
        http_response_code(500);
        echo json_encode(array('error' => 'Failed to connect to database: ' . mysqli_connect_error()));
        exit();
    }

    return $conn;
}

function validateApiKey()
{
    $headers = apache_request_headers();

    if (!isset($headers['api_key']) || $headers['api_key'] !== API_KEY) {
        http_response_code(401);
        echo json_encode(array('error' => 'Invalid API key'));
        // exit();
        //   http_response_code(401);
        die("Unauthorized");
    }
}

function handleGetRequest()
{
    // Check API key
    // $headers = apache_request_headers();
    // if (!isset($headers['Authorization']) || $headers['Authorization'] !== API_KEY) {
    //     http_response_code(401);
    //     die("Unauthorized");
    // }
    validateApiKey();

    $mysqli = connectToDatabase();
    // if ($mysqli->connect_errno) {
    //     http_response_code(500);
    //     die("Failed to connect to MySQL: " . $mysqli->connect_error);
    // }

    // Get the first unplayed song
    $query = "SELECT * FROM SongRequest WHERE played = 0 ORDER BY createdTime ASC LIMIT 1";
    $stmt = $mysqli->prepare($query);
    if (!$stmt) {
        http_response_code(500);
        die("Error preparing statement: " . $mysqli->error);
    }

    if (!$stmt->execute()) {
        http_response_code(500);
        die("Error executing statement: " . $stmt->error);
    }

    // Check if there's a result
    $result = $stmt->get_result();
    if ($result->num_rows == 0) {
        // http_response_code(404);
        // die("No unplayed songs found");
        http_response_code(200);
        return json_encode("");
    }

    // Fetch the row as an associative array
    $row = $result->fetch_assoc();

    // Update the song as played
    $now = date('Y-m-d H:i:s');
    $ipAddress = $_SERVER['REMOTE_ADDR'];
    $updateQuery = "UPDATE SongRequest SET played = 1, modifiedTime = ?, modifiedIpAddress = ? WHERE id = ?";
    $updateStmt = $mysqli->prepare($updateQuery);
    if (!$updateStmt) {
        http_response_code(500);
        die("Error preparing statement: " . $mysqli->error);
    }

    $updateStmt->bind_param('ssi', $now, $ipAddress, $row['id']);
    if (!$updateStmt->execute()) {
        http_response_code(500);
        die("Error updating song: " . $updateStmt->error);
    }

    // Close the database connection
    $mysqli->close();

    // Return the song as a JSON object
    header('Content-Type: application/json');
    echo json_encode($row);
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
            return SATURDAYDAY_CODE;
        case 'Sunday':
            return SUNDAY_CODE;
        default:
            echo "";
    }
}

function handlePostRequest($sequenceName, $code)
{
    // Check if both fields are present
    if (empty($sequenceName) || empty($code)) {
        // Redirect to error page after 5 seconds
        header("refresh:5;url=https://thealmostengineer.com/jukebox");
        die("Error: Sequence name and code are required.");
    }

    // Check if the code is valid for the current day of the week
    // $validCodeForToday = $validCodes[date('N')];
    $validCodeForToday = getCodeForToday();
    if ($code !== $validCodeForToday) {
        // Redirect to error page after 5 seconds
        header("refresh:5;url=https://thealmostengineer.com/jukebox");
        die("Error: Invalid code for today.");
    }

    // Check if the sequence name already exists and has not been played
    // $conn = new mysqli("localhost", "username", "password", "database_name");
    $conn = connectToDatabase();
    $stmt = $conn->prepare("SELECT * FROM SongRequest WHERE sequenceName = ? AND played = 0");
    $stmt->bind_param("s", $sequenceName);
    $stmt->execute();
    $result = $stmt->get_result();
    if ($result->num_rows > 0) {
        // Redirect to error page after 5 seconds
        header("refresh:5;url=https://thealmostengineer.com/jukebox");
        die("Error: Song has already been requested. Please wait for the song to play.");
    }

    // Insert the new request into the database
    $ipAddress = $_SERVER['REMOTE_ADDR'];
    $stmt = $conn->prepare("INSERT INTO SongRequest (sequenceName, createdIpAddress, modifiedIpAddress) VALUES (?, ?,?)");
    $stmt->bind_param("sss", $sequenceName, $ipAddress, $ipAddress);
    $stmt->execute();

    // Redirect to success page after 5 seconds
    header("refresh:5;url=https://thealmostengineer.com/jukebox");
    die("Success: Your song request has been submitted.");
}

function handleDeleteRequest()
{
    // Get user's IP address
    $userIpAddress = $_SERVER['REMOTE_ADDR'];

    // // Create a connection to the database
    // $conn = new mysqli("localhost", "username", "password", "database_name");

    // // Check connection
    // if ($conn->connect_error) {
    //     http_response_code(500);
    //     die("Connection failed: " . $conn->connect_error);
    // }
    $conn = connectToDatabase();

    // Prepare the SQL statement
    $stmt = $conn->prepare("UPDATE SongRequest SET played = true, modifiedIpAddress = ?");

    // Bind parameters
    $stmt->bind_param("s", $userIpAddress);

    // Execute the statement
    if ($stmt->execute()) {
        http_response_code(200);
        // echo "All requests have been marked as played.";
        echo "Ok";
    } else {
        http_response_code(500);
        echo "Error: " . $stmt->error;
    }

    // Close the statement and the database connection
    $stmt->close();
    $conn->close();
}

function handlePutRequest()
{
    validateApiKey();
    $conn  = connectToDatabase();

    // get the body of the request
    $requestBody = json_decode(file_get_contents('php://input'));
    
    switch($requestBody["status"])
    {
        // if the request turn on show, then remove the disabling row from the database
        case "on":
            break;

        // if the request turn off the show, then insert the disabling row into the database
        case "off":
            break;

            default:
                die("Bad request.");
        }
}

// Route the request based on the request method
switch ($_SERVER['REQUEST_METHOD']) {
    case 'GET':
        handleGetRequest();
        break;
    case 'POST':
        handlePostRequest($_POST["sequenceName"], $_POST["code"]);
        break;
    case 'PUT':
        // handlePutRequest();
        break;
    case 'DELETE':
        handleDeleteRequest();
        break;
    default:
        http_response_code(405);
        echo json_encode(array('error' => 'Method not allowed'));
        exit();
}