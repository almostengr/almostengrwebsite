---
title: Raspberry Pi Traffic Light Controller (TrafficPi)
description: Project build using a Raspberry Pi to control a retired traffic light.
---

![Traffic light](/images/portfolio_trafficlight2.jpg)

## Table of Contents

* [Purpose](#purpose)
* [Activities](#activities)
* [Parts List](#parts-list)
* [Source Code](#source-code)
* [Pin Setup](#pin-setup)
* [Initial Setup](#initial-setup)
* [Running the Scripts](#running-the-scripts)
* [Uninstall Script](#uninstall-script)
* [Bug Reports and Road Map](#bug-reports-and-road-map)
* [Known Bugs](#known-bugs)
* [Acknowledgements](#acknowledgements)

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

## Activities

There is a [classroom activity](/trafficpi/exercise)
that can be done with students to demonstrate the importance of programming coding the traffic light correctly.

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

### Video Demonstration

Video demonstration of version 1.0 of the project is available to be watched at
<a href="https://www.youtube.com/watch?v=lr_ZJNX0viM" target="_blank">https://www.youtube.com/watch?v=lr_ZJNX0viM</a>.
This version of the demonstration of the traffic light working
with an LCD screen connected.

## Parts List

Below are the list of parts used for this project. You'll need to choose one of
the mentioned options below depending on your budget. Using LEDs is cheaper than
getting an actual traffic light.

* <a href="https://www.amazon.com/gp/product/B01CD5VC92/ref=as_li_tl?ie=UTF8&camp=1789&creative=9325&creativeASIN=B01CD5VC92&linkCode=as2&tag=almostengr-20&linkId=b25e1b38c2c187404a50b967837af72b" target="_blank">Raspiberry Pi 3</a> (May work on other models, but has only been tested on Raspberry Pi 3)
* <a href="https://www.amazon.com/gp/product/B00MARDJZ4/ref=as_li_tl?ie=UTF8&tag=almostengr-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B00MARDJZ4&linkId=d8a07d1f200ba168b5fd5a49d4bb8afa" target="_blank">Raspiberry Pi power supply</a>
* <a href="https://amzn.to/2IcYREu" target="_blank">Micro SD card</a> (to run the OS and store project files)
* <a href="https://amzn.to/2tfNnpE" target="_blank">USB keyboard</a> (mouse optional)
* HDMI display
* <a href="https://www.amazon.com/gp/product/B07D83DY17/ref=as_li_tl?ie=UTF8&tag=almostengr-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B07D83DY17&linkId=e283038ab1f79e840b5d893586a38e19" target="_blank">I2C 16x2 LCD Display</a>
* <a href="https://www.amazon.com/gp/product/B07GD2BWPY/ref=as_li_tl?ie=UTF8&tag=almostengr-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B07GD2BWPY&linkId=c3042114933e20a073b88c0947756efd" target="_blank">Breadboard Jumper Cables</a>
* <a href="https://www.amazon.com/gp/product/B01EV6LJ7G/ref=as_li_tl?ie=UTF8&tag=almostengr-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B01EV6LJ7G&linkId=d6d36ad3de7629f3e963d620893c4ee3" target="_blank">Breadboard</a> (optional)
* Python 2.7.9 (May work with later versions, but has only been tested with 2.7.9)
* Raspbian Jessie, Stretch, or Buster (May work on other OSs, but has only been tested with Raspbian Jessie)

### LED Option

* <a href="https://www.amazon.com/gp/product/B0765NKCZ4/ref=as_li_tl?ie=UTF8&tag=almostengr-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B0765NKCZ4&linkId=0beb817f2435922b5666155b94430ecc" target="_blank">Red LED</a>
* <a href="https://www.amazon.com/gp/product/B0765NKCZ4/ref=as_li_tl?ie=UTF8&tag=almostengr-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B0765NKCZ4&linkId=0beb817f2435922b5666155b94430ecc" target="_blank">Yellow LED</a>
* <a href="https://www.amazon.com/gp/product/B0765NKCZ4/ref=as_li_tl?ie=UTF8&tag=almostengr-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B0765NKCZ4&linkId=0beb817f2435922b5666155b94430ecc" target="_blank">Green LED</a>

### Real Traffic Light Option

* <a href="https://www.amazon.com/gp/product/B00KTEN3TM/ref=as_li_tl?ie=UTF8&tag=almostengr-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B00KTEN3TM&linkId=1178d5b941f8f41f5bc23fc6da317cf0" target="_blank">Relay board(s) with at least 3 channels</a>
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

## Demostrations and Video Discusssions

These demostration videos show the traffic in one of several operating modes.

[Raspberry PI Traffic Light Controller Demonstration](https://www.youtube.com/watch?v=lr_ZJNX0viM)

[Discussing the Traffic Light Code](https://www.youtube.com/watch?v=ZyBnWOX3wGE)

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
