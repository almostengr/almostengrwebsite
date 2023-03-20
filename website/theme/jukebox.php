<?php

require_once '../config.php';

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// RESPONSE
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

final class JukeboxResponse
{
    private int $responseCode;
    private string $message;
    private $data;

    public function __construct(int $responseCode, string $message, $data = null)
    {
        $this->responseCode = $responseCode;
        $this->message = $message;
        $this->data = $data;
    }

    public function toJson()
    {
        http_response_code($this->responseCode);
        echo json_encode(
            array(
                "responseCode" => $this->responseCode,
                "message" => $this->message,
                "data" => $this->data
            )
        );
        exit();
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// REQUEST
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

final interface BaseRequestInterface
{
    public function HandleRequest(); 
}

abstract class BaseRequest implements BaseRequestInterface
{
    public function getMysqlDbConnection(DB_HOST, DB_USER, DB_PASS, DB_NAME)
    {

    }
}

final class AddSongRequest extends BaseRequest
{
    private string $sequenceName;
    private string $code;
    private string $ipAddress;

    public function __construct(string $sequenceName, string $code, string $ipAddress)
    {
        $this->sequenceName = $sequenceName;
        $this->code = $code;
        $this->ipAddress = $ipAddress;
    }

    public function saveRequest()
    {
        $codeValid = $this->isCodeValid();
        if ($codeValid == false) {
            throw new BadRequestException();
        }

        $this->ensurePostRequestFromWebsite();

    }

    private function isCodeValid()
    {
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
        return isset($validCodes[$dayOfWeek]) && $validCodes[$dayOfWeek] === $this->code;
    }

    private function ensurePostRequestFromWebsite()
    {
        if ($_SERVER['HTTP_REFERER'] !== "https://thealmostengineer.com/jukebox" || $_SERVER['REQUEST_METHOD'] !== 'POST') {
            throw new BadRequestException();
        }
    }
}

final class NextSongInQueueRequest extends BaseRequest
{

}

final class JukeboxEnabledRequest extends BaseRequest
{

}

final class ClearQueueRequest extends BaseRequest
{

}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// EXCEPTIONS
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

final class BadRequestException extends Exception
{
    public function __construct(string $message = "Bad request")
    {
        http_response_code(404);
        (new JukeboxResponse(404, "Bad request"))->toJson();
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////////////
// MAIN
//////////////////////////////////////////////////////////////////////////////////////////////////////////////

// process request 

switch ($_POST['endpoint']) {
    case "newrequest":
        $sequence = $_POST['sequenceName'] ?? '';
        $code = $_POST['code'] ?? '';
        $ipAddress = $_SERVER['REMOTE_ADDR'];
        $song = new SongRequest($sequence, $code, $ipAddress);

        break;

    case 'getnext':
        // Code to handle GET request to retrieve data
        break;

    case 'clearrequests':
        // Code to handle POST request to update data
        break;

    case 'enable':
        break;

    case 'disable':
        break;

    // Additional cases for other API endpoints
    default:
        // http_response_code(404);
        // echo json_encode(array("message" => "Not found"));
        (new JukeboxResponse(404, "Not found"))->toJson();
}