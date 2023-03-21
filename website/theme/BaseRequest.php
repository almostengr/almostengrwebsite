<?php

abstract class BaseRequest
{
    private string $apiKey;
    
    public function __construct(string $apiKey)
    {
        $this->apiKey = $apiKey;
    }


    private function validateApiKey()
    {
        if (!isset($_SERVER['HTTP_X_API_KEY'])) {
            // $response = new SequenceResponse(400, array('message' => 'API key is missing'));
            $response = new JukeboxResponse(400, "Invalid API key");
            echo $response->to_json();
            exit;
        }
    }
}


final class JukeboxResponse
{
    private int $responseCode;
    private string $message;
    private $data;

    public function __construct(int $responseCode, string $message, $data)
    {
        $this->responseCode = $responseCode;
        $this->message = $message;
        $this->data = $data;
    }
}