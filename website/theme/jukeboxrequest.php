<?php
require_once('../config.php');

class JukeboxRequestValidator {
    public function validate() {
        $referer = isset($_SERVER['HTTP_REFERER']) ? $_SERVER['HTTP_REFERER'] : '';
        $code = isset($_POST['code']) ? $_POST['code'] : '';
        $sequenceName = isset($_POST['sequenceName']) ? $_POST['sequenceName'] : '';

        // Check if request is from the correct page and is a POST request
        if (strpos($referer, 'thealmostengineer.com/lightshow') === false || $_SERVER['REQUEST_METHOD'] !== 'POST') {
            $this->redirectToLightshowWithError('Bad request. Please try again.');
        }

        // Check if code and sequenceName fields are not empty
        if (empty($code) || empty($sequenceName)) {
            $this->redirectToLightshowWithError('Please fill in both fields and try again.');
        }

        // Check if the code entered is correct
        if (!$this->isCodeValid($code)) {
            $this->redirectToLightshowWithError('Invalid code. Please try again.');
        }

        // Check if the sequence name has already been requested and not played
        if ($this->isSequenceAlreadyRequested($sequenceName)) {
            $this->redirectToLightshowWithError('This sequence has already been requested and not played. Please continue watching the show.');
        }

        // If all validations pass, insert the request into the database and redirect to lightshow page
        $ipAddress = $_SERVER['REMOTE_ADDR'];
        $now = date('Y-m-d H:i:s');

        $stmt = $GLOBALS['db']->prepare("INSERT INTO jukebox_requests (sequenceName, createdDateTime, ipAddress) VALUES (?, ?, ?)");
        $stmt->bind_param('sss', $sequenceName, $now, $ipAddress);

        if (!$stmt->execute()) {
            $this->redirectToLightshowWithError('Error inserting jukebox request into database. Please try again later.');
        }

        $this->redirectToLightshowWithSuccess();
    }

    private function isCodeValid($code) {
        $validCodes = array(
            'Monday' => '1234',
            'Tuesday' => '5678',
            'Wednesday' => 'abcd',
            'Thursday' => 'efgh',
            'Friday' => 'ijkl',
            'Saturday' => 'mnop',
            'Sunday' => 'qrst',
        );

        $dayOfWeek = date('l');
        return isset($validCodes[$dayOfWeek]) && $validCodes[$dayOfWeek] === $code;
    }

    private function isSequenceAlreadyRequested($sequenceName) {
        $stmt = $GLOBALS['db']->prepare("SELECT COUNT(*) FROM jukebox_requests WHERE sequenceName = ? AND hasPlayed = 0");
        $stmt->bind_param('s', $sequenceName);
        $stmt->execute();
        $stmt->bind_result($count);
        $stmt->fetch();
        $stmt->close();

        return $count > 0;
    }

    private function redirectToLightshowWithError($errorMsg) {
        $this->redirectToLightshow($errorMsg, 'error');
    }

    private function redirectToLightshowWithSuccess() {
        $this->redirectToLightshow('Your request has been submitted. Thank you!', 'success');
    }

    private function redirectToLightshow($msg, $type) {
        $url = 'https://thealmostengineer.com/lightshow';
        $queryString = '?msg=' . urlencode($msg) . '&type=' . urlencode($type);
        // header('Refresh: 5;url=' . $
        header("refresh:5;url=thealmostengineer.com/lightshow");

    }



        // Check if sequence name has been submitted but not played
$checkQuery = "SELECT COUNT(*) FROM jukebox_requests WHERE sequenceName = ? AND hasPlayed = 0";
$stmt = $mysqli->prepare($checkQuery);
$stmt->bind_param("s", $sequenceName);
$stmt->execute();
$stmt->bind_result($count);
$stmt->fetch();
$stmt->close();

if ($count > 0) {
  $response = new LightshowResponse(400, "The song has already been requested. Please continue watching the light show.");
  echo $response->toJson();
  exit();
}

// Insert data into database
$insertQuery = "INSERT INTO jukebox_requests (sequenceName, createdDateTime, hasPlayed, ipAddress) VALUES (?, NOW(), 0, ?)";
$stmt = $mysqli->prepare($insertQuery);
$stmt->bind_param("ss", $sequenceName, $ipAddress);
$stmt->execute();
$stmt->close();

// Return success message
$response = new LightshowResponse(200, "Song request has been submitted. Please continue watching the light show.");
echo $response->toJson();
exit();
