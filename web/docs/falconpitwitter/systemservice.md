---
title: System Service
---

## Table of Contents

* [Create System Service](#create-system-service)
* [Remove System Service](#remove-system-service)
* [System Service Logs](#system-service-logs)

This application is designed to be run as a system service. Below are the steps to install or 
remove it.

## Create System Service

To install the system service, run the below commands. Note that the commands are designed to be ran from 
the directory that you have copied the application files to.

```bash
cp Almostengr.FalconPiTwitter.service /lib/systemd/system
sudo systemctl daemon-reload
sudo systemctl enable Almostengr.FalconPiTwitter
sudo systemctl start Almostengr.FalconPiTwitter
sudo systemctl status Almostengr.FalconPiTwitter
```

## Remove System Service

To uninstall the system service, run the below commands

```sh
sudo systemctl disable Almostengr.FalconPiTwitter
sudo systemctl stop Almostengr.FalconPiTwitter
sudo systemctl status Almostengr.FalconPiTwitter
```

## System Service Logs

To see the output from the logs, visit the [Troubleshooting](/falconpitwitter/troubleshooting) page.