<?php

final interface AppSettingService
{
    private AppSettingRepositoryInterface repository;
    
    public function __construct(AppSettingRepositoryInterface repository)
    {
        $this->repository = repository;
    }

    
}