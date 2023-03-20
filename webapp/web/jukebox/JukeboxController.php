<?php

final class JukeboxController extends BaseController implements JukeboxControllerInterface
{
    private JukeboxServiceInterface $jukeboxService;

    public function __construct(JukeboxServiceInterface $jukeboxService)
    {
        $this->jukeboxService  = $jukeboxService;
    }
}
