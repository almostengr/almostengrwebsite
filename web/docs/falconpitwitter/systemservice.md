---
title: System Service
---

This application is designed to be run as a system service.

## Table of Contents

* [Create System Service](#create-system-service)
* [Remove System Service](#remove-system-service)
* [System Service Output/Log](#system-service-output-log)

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

## System Service Output / Log

To see the logged output from the system service, run the command: 

```sh
journalctl -u Almostengr.FalconPiTwitter -b
```

or

```sh
journalctl -u Almostengr.FalconPiTwitter -b -f
```

If an error occurs in the application, the exception message will show here.