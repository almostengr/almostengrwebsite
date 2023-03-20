<?php

final class AppSettingController extends BaseController
{
    private AppSettingServiceInterface $service;

    public function __construct(AppSettingServiceInterface $service)
    {
        $this->service = $service;
    }
}