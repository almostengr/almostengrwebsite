---
title: System Service
---

This application is designed to be run as a system service. Below are the steps to install or 
remove it.

## Create System Service

To install the system service, run the below commands. Note that the commands are designed to be ran from 
the directory that you have copied the application files to.

```bash
sudo cp falconpitwitter.service /lib/systemd/system
sudo systemctl daemon-reload
sudo systemctl enable falconpitwitter
sudo systemctl start falconpitwitter
sudo systemctl status falconpitwitter
```

## Remove System Service

To uninstall the system service, run the below commands

```sh
sudo systemctl disable falconpitwitter
sudo systemctl stop falconpitwitter
sudo systemctl status falconpitwitter
sudo systemctl daemon-reload
sudo rm /lib/systemd/system/falconpitwitter.service
```

## System Service Logs

To see the output from the logs, visit the [Troubleshooting](/falconpitwitter/troubleshooting) page.
