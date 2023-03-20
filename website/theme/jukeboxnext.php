<?php

final class SequenceResponse
{
    private int $id;
    private string $sequenceName;
    private string $requestedTime;
    private int $responseCode;
    private array $errors;

    public function __construct(int $id, string $sequenceName, string $requestedTime, int $responseCode, array $errors = [])
    {
        $this->id = $id;
        $this->sequenceName = $sequenceName;
        $this->requestedTime = $requestedTime;
        $this->responseCode = $responseCode;
        $this->errors = $errors;
    }

    public function getId(): int
    {
        return $this->id;
    }

    public function getSequenceName(): string
    {
        return $this->sequenceName;
    }

    public function getRequestedTime(): string
    {
        return $this->requestedTime;
    }

    public function getResponseCode(): int
    {
        return $this->responseCode;
    }

    public function getErrors(): array
    {
        return $this->errors;
    }

    public function setErrors(string $errorMessage): void
    {
        $this->errors[] = $errorMessage;
    }
}

final class NextSelectionApiResponse
{
    private const BAD_REQUEST_CODE = 400;
    private const INTERNAL_SERVER_ERROR_CODE = 500;
    private const OK_CODE = 200;

    private string $apiKey;
    private mysqli $mysqli;

    public function __construct(string $apiKey, mysqli $mysqli)
    {
        $this->apiKey = $apiKey;
        $this->mysqli = $mysqli;
    }

    public function getApiResponse(): string
    {
        if ($_SERVER['REQUEST_METHOD'] !== 'GET') {
            return json_encode(new SequenceResponse(0, '', '', self::BAD_REQUEST_CODE, ['Bad Request']));
        }

        $apiKey = $this->getApiKeyFromHeaders();
        if (!$this->isValidApiKey($apiKey)) {
            return json_encode(new SequenceResponse(0, '', '', self::BAD_REQUEST_CODE, ['Invalid API Key']));
        }

        $nextSequence = $this->getNextSequence();
        if ($nextSequence === null) {
            return json_encode(new SequenceResponse(0, '', '', self::INTERNAL_SERVER_ERROR_CODE, ['Internal Server Error']));
        }

        return json_encode(new SequenceResponse($nextSequence['id'], $nextSequence['sequenceName'], $nextSequence['requestedTime'], self::OK_CODE));
    }

    private function getApiKeyFromHeaders(): string
    {
        $headers = getallheaders();
        return $headers['API-Key'] ?? '';
    }

    private function isValidApiKey(string $apiKey): bool
    {
        return $apiKey === $this->apiKey;
    }

    private function getNextSequence(): ?array
    {
        $selectStatement = 'SELECT * FROM jukebox_requests WHERE played = 0 ORDER BY id ASC LIMIT 1';
        $result = $this->mysqli->query($selectStatement);

        if (!$result) {
            return null;
        }

        if ($result->num_rows === 0) {
            return null;
        }

        $nextSequence = $result->fetch_assoc();
        $updateStatement = "UPDATE jukebox_requests SET played = 1 WHERE id = {$nextSequence['id']}";
        $this->mysqli->query($updateStatement);

        return $nextSequence;
    }
}

$dbConnection = new mysqli(DB_HOST, DB_USER, DB_PASS, DB_NAME);
$apiRepsonse = new NextSelectionApiResponse(API_KEY, $dbConnection);
header('Content-Type: application/json');
$apiRepsonse->getApiResponse();
