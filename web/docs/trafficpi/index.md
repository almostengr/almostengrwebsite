---
title: Raspberry Pi Traffic Light Controller (TrafficPi)
description: Project build using a Raspberry Pi to control a retired traffic light.
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

## Table of Contents

* [Purpose](#purpose)
* [Classroom Activity](/trafficpi/activity)
* [Parts List](#parts-list)
* [Source Code](#source-code)
* [Pin Setup](#pin-setup)
* [Initial Setup](#initial-setup)
* [Running the Scripts](#running-the-scripts)
* [Uninstall Script](#uninstall-script)
* [Acknowledgements](/trafficpi/acknowledgements)

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

![Image of Versioning](/images/trafficpi/versioning.jpg)

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
* Raspbian Jessie, Stretch, or Buster (May work on other OSs, but has only been tested with Raspbian Jessie)

### LED Option

* <a href="https://www.amazon.com/gp/product/B06XPV4CSH/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B06XPV4CSH&linkId=ab8747a23cf5b35f3e83190c54cacd36" target="_blank">Red LED</a>
* <a href="https://www.amazon.com/gp/product/B06XPV4CSH/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B06XPV4CSH&linkId=ab8747a23cf5b35f3e83190c54cacd36" target="_blank">Yellow LED</a>
* <a href="https://www.amazon.com/gp/product/B06XPV4CSH/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B06XPV4CSH&linkId=ab8747a23cf5b35f3e83190c54cacd36" target="_blank">Green LED</a>

### Real Traffic Light Option

* <a href="https://www.amazon.com/gp/product/B00KTEN3TM/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B00KTEN3TM&linkId=581b0fc60dcc9f3ddc5645b8eb20029a" target="_blank">Relay board(s) with at least 3 channels</a>
* Traffic Light

## Source Code

The source code for this project can be downloaded from GitHub at
<a href="https://github.com/almostengr/raspitraffic-stem" target="_blank">
https://github.com/almostengr/raspitraffic-stem</a>.

## Pin Setup

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

Visual of Pin Connections to Relay Board

![Image of connections on Raspberry Pi board](/images/trafficpi/circuitry.jpg)

## Initial Setup

### Install Raspbian

You will need to install Raspbian on your SD. Once you have completed this install,
Then you can insert the SD card into the Raspberry Pi and power it on.

To install Raspbian using Ubuntu, I made a video tutorial which you can watch
at [https://www.youtube.com/watch?v=Wy1_MWWlkNI](https://www.youtube.com/watch?v=Wy1_MWWlkNI).

### Install Script

In the ```scripts``` directory, run the ```install.sh``` script
as root user. This will install of the required software and python packages.

### Update Apache Configuration

Search for the file containing "PrivateTmp=true". This file should be in your /etc
directory. Change this value to ```PrivateTmp=false```. Then restart Apache.
You may use

```sh
cd /etc/
grep -R "PrivateTmp=true" *
```

to search for the file that contains this value. Once grep returns the file name,
edit the file and make the stated change.

## Running The Scripts

To control the traffic light, run the raspitraffic.py script via command line.

```sh
python raspitraffic.py
```

Then visit the webpage to your TrafficPi in a web browser. A form will be
presented with a list of programs to select from. Select the program you wish to
run and click the "Submit" button.

If a program is already running, the newly selected program will start once the end of
the current program has been reached. If no program has been selected, the newly
selected program will start immediately.

### Pseudocode Program

The Pseudocode Program allows you to write your own program for controlling the traffic
light. On the Control Panel webpage, enter each command that you want the light
to perform on a line by itself in the "Pseudocode Commands" textbox. The list of
commands are listed on the Control Panel webpage below the textbox.

## Move and Run Code on the Pi

### Software to Install on Pi

Run these commands to install the necessary software on the Pi. You only need to do them once.

```sh
sudo apt-get update
sudo apt-get install curl libunwind8 gettext apt-transport-https
```

### Publish Your App

Then run the publish command on your app

```sh
dotnet publish -r linux-arm
```

### Copy the Files

Then copy the files from your computer to the Pi. I used SSH for this.

```sh
scp -pr bin/Debug/netcoreapp3.1/linux-arm/publish/* pi@trafficpi://home/pi/rpidotnet
```

### Run App On Pi

Run the program by calling the executable. This filename will be the name of your project.

```sh
./rpidotnet
```

## Troubleshooting

* If your app does not run, make sure that execute permissions have been set for all roles (755).