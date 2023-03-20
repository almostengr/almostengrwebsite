<?php

require_once '../config.php';

// post - insert request 
// delete - mark all requests as played
// get - get first unplayed request, mark as played

final class SongRequest{
    private int $id;
    private string $sequenceName;
    private bool $played;
    private DateTime $createdTime;
    private string $ipAddress;
    private DateTime $lastModifiedTime;

    public function __construct()
    {

    }

    public function MarkAsPlayed() : void
    {
        $this->played = true;
        // $this->lastModifiedTime=  $
    }
}

function getDbConnection() : mysqli
{
    return mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME);
}

function insertRequest()
{
    // 
}

function markAllRequestsAsPlayed()
{
    $dbConnection = getDbConnection();
    $updateStatement = "updated jukebox_requests set played = 1";
    $dbconnection->query($updateStatement);
}

function getNextUnplayedRequest()
{
    isValidApiKey();
    
    $dbConnection  = getDbConnection();
    $selectStatement = 'SELECT * FROM jukebox_requests WHERE played = 0 ORDER BY createdTime ASC LIMIT 1';
    $result = $dbConnection->query($selectStatement);

    if ((!$result) ||($result->num_rows === 0)) {
        return null;
    }

    $nextSequence = $result->fetch_assoc();
    $updateStatement = "UPDATE jukebox_requests SET played = 1 WHERE id = {$nextSequence['id']}";
    $dbConnection->query($updateStatement);

    return $nextSequence;
}

function getApiKeyFromHeaders(): string
{
    $headers = getallheaders();
    return $headers['API-Key'] ?? '';
}

function isValidApiKey(string $apiKey): bool
{
    return $apiKey === $this->apiKey;
}


switch($_SERVER['REQUEST_METHOD'])
{
    case 'GET':
        getNextUnplayedRequest();
        break;
        
    case 'POST':
        insertRequest();
        break;

    case 'DELETE':
        markAllRequestsAsPlayed();
        break;

    default:
        http_response_code(404);
        return http_response_code();
}