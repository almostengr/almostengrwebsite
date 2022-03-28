---
title: Raspberry Pi Traffic Light Controller (TrafficPi)
description: Project build using a Raspberry Pi to control a retired traffic light.
updated: 2022-03-28
---

![Traffic light](/images/portfolio_trafficlight2.jpg)

## Purpose

The purpose of this project is to educate children about the STEM (Science, Technology,
Engineering, and Mathematics) fields. Through the use of low cost devices and effective
teaching, children are able to associate what they are learning with interactions with
everyday items. For example, most future engineers are aware of the purpose of a traffic light,
but most are not aware of a traffic lights' internal workings. This project is designed
to educate future engineers about the impact that computers and computer programming has with
society. This project targets the "T, E, and M" of "STEM" by using electronic circuits
for controlling the lights, software for controlling the electronic circuits, and
mathematical calculations for making timing decisions.

### Teach Software Versioning

One of the goals of this project is to be able to teach the next generation of
engineers about the programming, software versioning, and how valuable engineers and
technologists are to society and the impact that they have.
A game was developed to be combined with this project to teach about software versioning,
how sometimes Software Developers don't get it right the first time, and the
negative impact that can occur if they don't get it right the first time.

Below is the image of a group of future engineers working their way to developing the
psuedocode for a normal traffic cycle. As shown in the first version, all of the lights turned
on but never turned off.  In the final version, they figured out that they had to turn on
and turn off each light as well as include a delay in between each light change.

![Image of Versioning](/images/versioning.jpg)


## Parts List

Below are the list of parts used for this project. You'll need to choose one of
the mentioned options below depending on your budget. Using LEDs is cheaper than
getting an actual traffic light.

* <a href="https://www.amazon.com/gp/product/B07BC7BMHY/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B07BC7BMHY&linkId=b51d201ecdca3bed2a84249448d0dd4f" target="_blank">Raspiberry Pi 3 Kit</a> (May work on other models, but has only been tested on Raspberry Pi 3)
* <a href="https://www.amazon.com/gp/product/B08GYKNCCP/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B08GYKNCCP&linkId=1e440b7afda77da0a25f2af4d65b8b6a" target="_blank">Micro SD card</a> (to run the OS and store project files)
* <a href="https://www.amazon.com/gp/product/B07RQVB3HQ/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B07RQVB3HQ&linkId=8452f5455a39f35597424dcc8a2ae388" target="_blank">USB keyboard</a> (mouse optional)
* HDMI display
* <a href="https://www.amazon.com/gp/product/B07GD25V8D/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B07GD25V8D&linkId=ea5fb3393909abe778b518e808e674d5" target="_blank">Breadboard Jumper Cables</a>
* <a href="https://www.amazon.com/gp/product/B07PCJP9DY/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B07PCJP9DY&linkId=dca65d5d374944f5c1d213924d2fb183" target="_blank">Breadboard</a> (optional)
* Python 2.7.9 (May work with later versions, but has only been tested with 2.7.9)
* Raspberry Pi OS Jessie, Stretch, or Buster (May work on other OSs, but has only been tested with Raspberry Pi OS Jessie)

### LED Option

* <a href="https://www.amazon.com/gp/product/B06XPV4CSH/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B06XPV4CSH&linkId=ab8747a23cf5b35f3e83190c54cacd36" target="_blank">Red LED</a>
* <a href="https://www.amazon.com/gp/product/B06XPV4CSH/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B06XPV4CSH&linkId=ab8747a23cf5b35f3e83190c54cacd36" target="_blank">Yellow LED</a>
* <a href="https://www.amazon.com/gp/product/B06XPV4CSH/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B06XPV4CSH&linkId=ab8747a23cf5b35f3e83190c54cacd36" target="_blank">Green LED</a>

### Real Traffic Light Option

* <a href="https://www.amazon.com/gp/product/B00KTEN3TM/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B00KTEN3TM&linkId=581b0fc60dcc9f3ddc5645b8eb20029a" target="_blank">Relay board(s) with at least 3 channels</a>
* Traffic Light


## Video Demonstration

Video demonstration of version 1.0 of the project is available to be watched at
<a href="https://www.youtube.com/watch?v=lr_ZJNX0viM" target="_blank">https://www.youtube.com/watch?v=lr_ZJNX0viM</a>.
This version of the demonstration of the traffic light working
with an LCD screen connected.

Further discussion of the traffic light code can be watched at 
[https://www.youtube.com/watch?v=ZyBnWOX3wGE](https://www.youtube.com/watch?v=ZyBnWOX3wGE).


## Controller Technology

The controller currently uses .NET 5. It is divided into two projects.

### User Interface (UI) / Front End

The user interface is a .NET MVC application. When you select the program that you want to run
from the application home page, the application then runs a linux command that runs the back
end program.
When the program is changed on the front end, the back end program is then terminated and the newly
select program is started.

### Relay Control / Back End

The back end of the application is a .NET Worker Service. The program modes are defined within
this worker service. The worker service will continue running until it is terminated by the front end
application or by a user via the command line or SSH.


## Acknowledgements

* LCD Display code for controlling the LCD display were provided from
<a href="https://github.com/the-raspberry-pi-guy/lcd" target="_blank">https://github.com/the-raspberry-pi-guy/lcd</a>.
* Attempts to replicate the Traffic Light Simulation created by Samuel Vidal
seen at
<a href="https://www.youtube.com/watch?v=xqZRDtX64UA" target="_blank">https://www.youtube.com/watch?v=xqZRDtX64UA</a>
influenced this project.
* Wifi AP configuration steps provided by
<a href="https://pimylifeup.com/raspberry-pi-wireless-access-point/"
target="_blank">https://pimylifeup.com/raspberry-pi-wireless-access-point/</a>


## Frequently Asked Questions (FAQs) 

### Where did you get the traffic light from? 

Ebay. Found a seller that ran a salvage company that was selling it in 2018. The item that he 
had listed, included a controller, but the controller only had like 5 programs. I opted 
to get the light without the controller as I was going to build my own using the Raspberry Pi.

### Will you share the source code for the application?

The source code for this project can be downloaded from GitHub at
<a href="https://github.com/almostengr/trafficpi" target="_blank">
https://github.com/almostengr/trafficpi</a>.


## Technical Information

The sections below this one, get into the technical details of the project. Those that are interested
in setting up their own traffic light with a Raspberry Pi using the code that I have built, can 
follow the instructions below.


## Installation and Setup

### Install Raspberry Pi Operating System (OS)

You will need to install Raspberry Pi OS on your SD. Once you have completed this install,
Then you can insert the SD card into the Raspberry Pi and power it on.

To install Raspberry Pi OS using Ubuntu, I made a video tutorial which you can watch
at [https://www.youtube.com/watch?v=Wy1_MWWlkNI](https://www.youtube.com/watch?v=Wy1_MWWlkNI).

### Pin Setup

Below is the mapping for the connections to the Raspberry Pi. The Pin numbers
listed are the physical pin numbers on the board, not the GPIO pin numbers. If
you are not using a relay board, the connections can be made directly to a
breadboard with LEDs connected.

Pi Pin (Board) | GPIO | Device Connection
-- |  | -
2 | -- | LCD Display VCC (+5V)
3 | -- | LCD Display SDA
4 | -- | Relay Board VCC (+5V)
5 | -- | LCD Display SLC
19 | 11 | Red Signal
21 | 9 | Yellow Signal
23 | 10 | Green Signal
30 | -- | LCD Display GND
34 | -- | Relay Board GND

#### Visual of Pin Connections to Relay Board

![Image of connections on Raspberry Pi board](/images/circuitry.jpg)

### System Service

To set up the application as a service, run the below commands. If you see error messages
when running the commands, you may need to run them with "sudo" privileges. See the
[System Service](/projects/traffic-pi/systemservice) page for details on how to add or remove the
application as a system service.

#### Create System Service

```sh
sudo cp almostengrtrafficpiweb.service /lib/systemd/system
sudo systemctl daemon-reload
sudo systemctl enable almostengrtrafficpiweb.service
sudo systemctl start almostengrtrafficpiweb.service
sudo systemctl status almostengrtrafficpiweb.service
```

#### Run App On Pi

To run the applicatoin via the command line (not using the system service), then you
can run the commands below.

```sh
cd trafficpi
./Almostengr.TrafficPi.Web
```

To exit the application after running it via command line, press Ctrl+C.


## Uninstall Traffic Pi

### Remove System Service

To remove the application as a system service, run each of the commands below.

```sh
sudo systemctl disable almostengrtrafficpiweb.service
sudo systemctl stop almostengrtrafficpiweb.service
sudo systemctl status almostengrtrafficpiweb.service
sudo rm /lib/systemd/system/almostengrtrafficpiweb.service
```

After running all of the commands above, then reboot the system.

### Application Files

To remove the application files, you can remove the entire trafficpi directory.

```sh
rm -rf trafficpi
```



## Troubleshooting 

### System Service Output / Log

To see the logged output from the system service, run the command:

```sh
journalctl -u almostengrtrafficpiweb.service -b
```

or

```sh
journalctl -u almostengrtrafficpiweb.service -b -f
```

If an error occurs in the application, the exception message will show here.
