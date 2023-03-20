<?php

final class JukeboxService implements JukeboxServiceInterface
{
    private JukeboxRepositoryInterface $repository;

    public function __construct(JukeboxRepositoryInterface repository)
    {
        $this->repository = repository;
    }

    public function AddRequest(SongRequest request)
    {
        $result = $this->repository.GetAllUplayedRequests($request->GetSequenceName());
    }

    public function GetNextRequest()
    {
        $result = $this->repository.GetFirstUnplayedRequest();
        _repository.UpdateRequest($request);
    }

    public function ClearExistingRequests()
    {
        $requests = $this->repository.GetAllUnplayedRequests();
        foreach($request in $requests)
        {
            $request->MarkAsPlayed();
            $this->repository.UpdateRequest($request);
        }
    }
}