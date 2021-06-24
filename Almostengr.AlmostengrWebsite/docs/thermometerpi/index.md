---
title: Thermometer Pi
description: Used a Raspberry Pi to be a thermometer that provides data to home automation system
---

## Table of Contents

To read more about the project, select a section below to navigate to.

* [Project Background](#project-background)
* [Components Used](#components-used)
* [Installation and Setup](#installation-and-setup)
* [Application as System Service](#application-as-system-service)
* [Source Code](#source-code)
* [Additional Resources](#additional-resources)

## Project Background

A common problem that exists with US home construction
is that multiple story homes were built with a single zoned system.
Often times, that thermostat is on the first floor and can properly manage the temperature on the first
floor. However, the second floor often times gets too hot because heat rises and cold air sinks.

Several houses in the neighborhood have window AC units installed in the rooms on the upper floor of their
house and so do I. The thing about the window units is that they do not have thermometers on them that will
accurately keep the room cool. Thus I built a .NET Core application that will read the temperature
from a sensor connected to a Raspberry Pi and post it to the Home Assistant API. Home Assistant will then
use that data to trigger automations, like turning on an off the window AC unit.

I have several Rapsberry Pi that are used in my home and used as television set top boxes. Instead of
purchasing additional devices to detect temperature, I decided to get some one-wire temperature sensors that
can be connected to the Raspberry Pi that is already in the rooms that I want to monitor.

The application was build using .NET Core 3.1 Worker Service. The application will run the command to get the
data from the temperature sensor. After getting the data, then it makes a call to Home Assistant API that
provides the temperature as a state to a sensor named of your chosing.

[Back to Top](#)

## Components Used

* [Raspberry Pi](https://www.amazon.com/gp/product/B07BC7BMHY/ref=as_li_qf_asin_il_tl?ie=UTF8&tag=rhtservicesll-20&creative=9325&linkCode=as2&creativeASIN=B07BC7BMHY&linkId=eae8899ccbef0eb26acf71cb65bef39a)
* [DS18S20 Temperature Sensor](https://www.amazon.com/gp/product/B07MR71WVS/ref=as_li_qf_asin_il_tl?ie=UTF8&tag=rhtservicesll-20&creative=9325&linkCode=as2&creativeASIN=B07MR71WVS&linkId=bfd830515da10f922afff9a79cc33e58)
* [Serial to USB Cable](https://www.amazon.com/gp/product/B07D9R5JFK/ref=as_li_qf_asin_il_tl?ie=UTF8&tag=rhtservicesll-20&creative=9325&linkCode=as2&creativeASIN=B07D9R5JFK&linkId=e35fd9d313f055ab778e60783564078b)
* [Home Assistant (on same or different device)](https://homeassistant.io)
* [Belkin Wemo Smart Outlet](https://www.amazon.com/gp/product/B0776YH29B/ref=as_li_qf_asin_il_tl?ie=UTF8&tag=rhtservicesll-20&creative=9325&linkCode=as2&creativeASIN=B0776YH29B&linkId=34342060eb6bea8006e0dbbefb376fcf)
* [Window AC Unit](https://www.amazon.com/gp/product/B085797ZFF/ref=as_li_qf_asin_il_tl?ie=UTF8&tag=rhtservicesll-20&creative=9325&linkCode=as2&creativeASIN=B085797ZFF&linkId=e38e0ec46bdea5e4c32950d147003cc8)

[Back to Top](#)

## Installation and Setup

* Connect the [DS18S20 sensor](https://www.amazon.com/gp/product/B07MR71WVS/ref=as_li_qf_asin_il_tl?ie=UTF8&tag=rhtservicesll-20&creative=9325&linkCode=as2&creativeASIN=B07MR71WVS&linkId=bfd830515da10f922afff9a79cc33e58) to the [Serial to USB Cable](https://www.amazon.com/gp/product/B07D9R5JFK/ref=as_li_qf_asin_il_tl?ie=UTF8&tag=rhtservicesll-20&creative=9325&linkCode=as2&creativeASIN=B07D9R5JFK&linkId=e35fd9d313f055ab778e60783564078b)
* Install an operating system of your choosing on your Raspberry Pi (<a href="https://osmc.tv/" target="_blank">OSMC</a> was installed on mine)
* Copy the ThermometerPi files to the Raspberry Pi. They can be downloaded from the 
[project repo](https://github.com/almostengr/thermometerpi).
* Configure the appsettings.json file to point to your Home Assistant instance. Also need the HA Token
* Perform the [first run steps](#first-run) to configure the temperature sensor
* Set up the ThermometerPi as a system service
* Start the service
* Set up automations in Home Assistant using the sensor

Eventually will do a walkthrough video on how I did my setup.

[Back to Top](#)

### First Run

This is the full output when running the commands that are listed on the external resource website.
Note that I did have to use sudo as it state that my user ID did not have permission to
access /dev/ttyUSB0

```sh
almostengineer@aeoffice:/tmp$ sudo   digitemp_DS9097 -i -s /dev/ttyUSB0 -c /etc/digitemp.conf
DigiTemp v3.7.2 Copyright 1996-2018 by Brian C. Lane
GNU General Public License v2.0 - http://www.digitemp.com
Turning off all DS2409 Couplers

Searching the 1-Wire LAN
28711E92070000F3 : DS18B20 Temperature Sensor
ROM #0 : 28711E92070000F3
Wrote /etc/digitemp.conf
almostengineer@aeoffice:/tmp$ sudo   digitemp_DS9097 -a -q -c /etc/digitemp.conf
Apr 10 13:05:42 Sensor 0 C: 29.81 F: 85.66
almostengineer@aeoffice:/tmp$
```

To be able to read the sensor data without using sudo, then you will need to add the user(s)
to the dialout group.

```sh
sudo usermod -a -G dialout $USER
```

Replace "$USER" with the username(s) that need to be added to the group. May need to logout or
restart the system for the changes to take effect.

To check to see what groups that the user has been added to, you can run the command

```sh
groups $USER
```

replacing $USER with the username that you want to see.

[Back to Top](#)

## Application as System Service

### Create System Service

```bash
sudo cp thermometerpi.service /lib/systemd/system
sudo systemctl daemon-reload
sudo systemctl enable thermometerpi
sudo systemctl start thermometerpi
sudo systemctl status thermometerpi
```

### Remove System Service

```sh
sudo systemctl disable thermometerpi
sudo systemctl stop thermometerpi
sudo systemctl status thermometerpi
sudo rm /lib/systemd/system/thermometerpi.service
```

### Application Logs

Application logs will look similar to the below to show what the application is doing.

```sh
Jun 01 17:50:42 osmc Almostengr.ThermometerPi.Worker[380]: Almostengr.ThermometerPi.Worker.ThermometerWorker[0] Updated: 2021-06-01T22:50:42.086745+00:00
Jun 01 17:55:43 osmc Almostengr.ThermometerPi.Worker[380]: Almostengr.ThermometerPi.Worker.ThermometerWorker[0] OK
Jun 01 17:55:43 osmc Almostengr.ThermometerPi.Worker[380]: Almostengr.ThermometerPi.Worker.ThermometerWorker[0] Updated: 2021-06-01T22:55:43.415774+00:00
Jun 01 18:00:44 osmc Almostengr.ThermometerPi.Worker[380]: Almostengr.ThermometerPi.Worker.ThermometerWorker[0] OK
Jun 01 18:00:44 osmc Almostengr.ThermometerPi.Worker[380]: Almostengr.ThermometerPi.Worker.ThermometerWorker[0] Updated: 2021-06-01T23:00:44.755279+00:00
Jun 01 18:05:46 osmc Almostengr.ThermometerPi.Worker[380]: Almostengr.ThermometerPi.Worker.ThermometerWorker[0] OK
Jun 01 18:05:46 osmc Almostengr.ThermometerPi.Worker[380]: Almostengr.ThermometerPi.Worker.ThermometerWorker[0] Updated: 2021-06-01T23:05:46.085342+00:00
```

[Back to Top](#)

## Source Code

The source code is available on my 
<a href="https://github.com/almostengr/themometerpi" target="_blank">GitHub Repository</a>.

[Back to Top](#)

## Additional Resources

Below are resources that were used in completing the project.

[https://martybugs.net/electronics/tempsensor/usb.cgi](https://martybugs.net/electronics/tempsensor/usb.cgi)

[Back to Top](#)
