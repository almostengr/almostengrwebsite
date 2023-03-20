<?php

final class SongRequest
{
    private int $id;
    private string $sequenceName;
    private DateTime $createdTime;
    private DateTime $lastModifiedTime;
    private string $ipAddress;
    private bool $played;

    private function __construct()
    {}

    public function Create()
    { 
        $this->played = false;
    }

    public function MarkAsPlayed()
    {
        $this->played = true;
        $this->lastModifiedTime; 
    }
}