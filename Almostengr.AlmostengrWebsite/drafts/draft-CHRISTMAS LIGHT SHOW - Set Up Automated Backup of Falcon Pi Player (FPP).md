---
title: Set up AUtomated Backup of Falcon Pi Player (FPP)
posted: 2021-07-21
category: technology
author: Kenny Robinson
---

## Create SSH Key

```sh
ssh-keygen

# answer prompts as they appear

# files should be created in the /home/fpp/.ssh directory
```

## Cron Job Command

Run the command

```sh
crontab -e
```

Then in the file add in the following. Update the file path as necesary.

```sh
4 */4 * * * /bin/bash /home/fpp/ubuntu-automation/git_scripts/autocommit.sh /home/fpp/media > /home/fpp/media/logs/autocommit.log 2>&1
```

Then save and exit the editor and confirm that the

``sh
crontab: installing new crontab
```

message appears after exiting.
