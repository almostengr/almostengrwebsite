<?php
require_once('../config.php');

//////////////////////////////////////////////////////////
// <?php
// return [
//     1 => "MONDAY_CODE",
//     2 => "TUESDAY_CODE",
//     3 => "WEDNESDAY_CODE",
//     4 => "THURSDAY_CODE",
//     5 => "FRIDAY_CODE",
//     6 => "SATURDAY_CODE",
//     7 => "SUNDAY_CODE",
// ];
//////////////////////////////////////////////////////////

function connectToDatabase() {
    $conn = mysqli_connect(DB_HOST, DB_USER, DB_PASS, DB_NAME);

    if (mysqli_connect_errno()) {
        http_response_code(500);
        echo json_encode(array('error' => 'Failed to connect to database: '.mysqli_connect_error()));
        exit();
    }

    return $conn;
}

function checkApiKey() {
    $headers = apache_request_headers();

    if (!isset($headers['api_key']) || $headers['api_key'] !== API_KEY) {
        http_response_code(401);
        echo json_encode(array('error' => 'Invalid API key'));
        exit();
    }
}



// Define the function to handle GET requests
function handleGetRequest() {
    // Code to handle GET request
}

// Define the function to handle POST requests
function handlePostRequest($sequenceName, $code) {
    // Check if both fields are present
    if (empty($sequenceName) || empty($code)) {
        // Redirect to error page after 5 seconds
        header("refresh:5;url=https://thealmostengineer.com/jukebox");
        die("Error: Sequence name and code are required.");
    }

    // Check if the code is valid for the current day of the week
    $validCodes = include '../config.php';
    $validCodeForToday = $validCodes[date('N')];
    if ($code !== $validCodeForToday) {
        // Redirect to error page after 5 seconds
        header("refresh:5;url=https://thealmostengineer.com/jukebox");
        die("Error: Invalid code for today.");
    }

    // Check if the sequence name already exists and has not been played
    $conn = new mysqli("localhost", "username", "password", "database_name");
    $stmt = $conn->prepare("SELECT * FROM SongRequest WHERE sequenceName = ? AND played = 0");
    $stmt->bind_param("s", $sequenceName);
    $stmt->execute();
    $result = $stmt->get_result();
    if ($result->num_rows > 0) {
        // Redirect to error page after 5 seconds
        header("refresh:5;url=https://thealmostengineer.com/jukebox");
        die("Error: Song has already been requested.");
    }

    // Insert the new request into the database
    $ipAddress = $_SERVER['REMOTE_ADDR'];
    $stmt = $conn->prepare("INSERT INTO SongRequest (sequenceName, createdIpAddress) VALUES (?, ?)");
    $stmt->bind_param("ss", $sequenceName, $ipAddress);
    $stmt->execute();

    // Redirect to success page after 5 seconds
    header("refresh:5;url=https://thealmostengineer.com/jukebox");
    die("Success: Song request has been submitted.");
}


// Define the function to handle PUT requests
function handlePutRequest() {
    // Code to handle PUT request
}

// Define the function to handle DELETE requests
function handleDeleteRequest() {
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
        echo "All SongRequest rows have been marked as played.";
    } else {
        http_response_code(500);
        echo "Error: " . $stmt->error;
    }

    // Close the statement and the database connection
    $stmt->close();
    $conn->close();
}
  

// Route the request based on the request method
switch ($_SERVER['REQUEST_METHOD']) {
    case 'GET':
        handleGetRequest();
        break;
    case 'POST':
        handlePostRequest($_POST["sequenceName"], $_POST["code"]);
        break;
    // case 'PUT':
    //     handlePutRequest();
    //     break;
    case 'DELETE':
        handleDeleteRequest();
        break;
    default:
        http_response_code(405);
        echo json_encode(array('error' => 'Method not allowed'));
        exit();
}


try {
    $conn = connectToDatabase();
    // use $conn to interact with the database
} catch(Exception $e) {
    // handle the exception
}