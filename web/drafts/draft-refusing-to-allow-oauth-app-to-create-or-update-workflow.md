---
title: Refusing to Allow an OAuth App To Create or Update Workflow
description: If you attempt to push a branch that does not have the proper permissions and a workflow to GitHub, then you may receive an error message.
posted: 2021-05-25
author: Kenny Robinson
category: technology
keywords: github, github actions, github workflow, git push, unable to push commits, git remote rejected
---

## Problem

I recently attempted to push some commits up to
<a href="https://github.com" target="_blank">GitHub</a>. One of the recent commits included a newly created
<a href="https://github.com/features/actions" target="_blank">GitHub Actions Workflow</a> file.
For those of you who are not familiar with workflow files, when they are included
in your repository, GitHub will perform the actions in those files when certain conditions are met, like
pushing commits to main branch.

### Error Message

This is the error message that I received when attempting to push the commit with the new workflow
file.

```sh
almostengineer@aeoffice:~/trafficpi$ git push origin cicdrelease
Enumerating objects: 103, done.
Counting objects: 100% (103/103), done.
Delta compression using up to 4 threads
Compressing objects: 100% (60/60), done.
Writing objects: 100% (72/72), 10.04 KiB | 1.43 MiB/s, done.
Total 72 (delta 44), reused 0 (delta 0)
remote: Resolving deltas: 100% (44/44), completed with 17 local objects.
To https://github.com/almostengr/trafficpi.git
 ! [remote rejected] cicdrelease -> cicdrelease (refusing to allow an OAuth App to create or update workflow `.github/workflows/release.yaml.old` without `workflow` scope)
error: failed to push some refs to 'https://github.com/almostengr/trafficpi.git'
```

This message does not tell you how to address it. However, I did do some research and figured out how
to address it. Continue reading.

Early in 2021 or late 2020,
<a href="https://github.com" target="_blank">GitHub</a>
started showing messages about how they would stop allowing some
features to work with commits that were pushed via HTTPS protocol. I do not recall why they chose to stop
allowing this from being done, but it probably has something to do with security.

## Solution

### Update Remotes

To fix this problem, you will need to update your remotes to point to the SSH path of the repository
instead of using the HTTPS path of the repository.

Before I made the update, the remote to my repository source was

```sh
almostengineer@aeoffice:~/trafficpi$ git remote -v
origin  https://github.com/almostengr/trafficpi.git (fetch)
origin  https://github.com/almostengr/trafficpi.git (push)
```

Then I ran the command to update the repository source. To get the SSH remote path, go to the
repository page, click the green "Code" button, select the "SSH" option, and then copy the entire
path from the textbox. Then use it in the example command below:

```sh
almostengineer@aeoffice:~/trafficpi$ git remote set-url origin git@github.com:almostengr/trafficpi.git
```

If the command above has been done correctly, then run ```git remote -v``` and you should see
the updated path as the destination of the remote.

```sh
almostengineer@aeoffice:~/trafficpi$ git remote -v
origin  git@github.com:almostengr/trafficpi.git (fetch)
origin  git@github.com:almostengr/trafficpi.git (push)
```

### Final Push

Once you have completed the above step, then you can do ```git push``` again. This time, your commits
should succeed in reaching origin.

```sh
almostengineer@aeoffice:~/trafficpi$ git push origin cicdrelease
Enumerating objects: 103, done.
Counting objects: 100% (103/103), done.
Delta compression using up to 4 threads
Compressing objects: 100% (60/60), done.
Writing objects: 100% (72/72), 10.04 KiB | 1.12 MiB/s, done.
Total 72 (delta 44), reused 0 (delta 0)
remote: Resolving deltas: 100% (44/44), completed with 17 local objects.
remote:
remote: Create a pull request for 'cicdrelease' on GitHub by visiting:
remote:      https://github.com/almostengr/trafficpi/pull/new/cicdrelease
remote:
To github.com:almostengr/trafficpi.git
 * [new branch]      cicdrelease -> cicdrelease
```