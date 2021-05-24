# System Service

To set up the application as a service, run the below commands. If you see error messages 
when running the commands, you may need to run them with "sudo" privileges.

## Table of Contents

* [Create System Service](#create-system-service)
* [Remove System Service](#remove-system-service)
* [System Service Output/Log](#system-service-output-log)

## Create System Service

```sh
cp Almostengr.TrafficPi.Web.service /lib/systemd/system
sudo systemctl daemon-reload
sudo systemctl enable Almostengr.TrafficPi.Web
sudo systemctl start Almostengr.TrafficPi.Web
sudo systemctl status Almostengr.TrafficPi.Web
```

## Remove System Service

```sh
sudo systemctl disable Almostengr.TrafficPi.Web
sudo systemctl stop Almostengr.TrafficPi.Web
sudo systemctl status Almostengr.TrafficPi.Web
```

## System Service Output / Log

To see the logged output from the system service, run the command: 

```sh
journalctl -u Almostengr.TrafficPi.Web -b
```

or

```sh
journalctl -u Almostengr.TrafficPi.Web -b -f
```

If an error occurs in the application, the exception message will show here.