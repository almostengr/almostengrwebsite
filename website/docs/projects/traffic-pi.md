---
title: Raspberry Pi Traffic Light Controller (TrafficPi)
description: Project build using a Raspberry Pi to control a retired traffic light.
updated: 2022-03-28
---

![Traffic light](/images/portfolio_trafficlight2.jpg)

## Solution

The purpose of this project is to educate children about the STEM (Science, Technology,
Engineering, and Mathematics) fields. Through the use of low cost devices and effective
teaching, children are able to associate what they are learning with interactions with
everyday items. For example, most future engineers are aware of the purpose of a traffic light,
but most are not aware of a traffic lights' internal workings. This project is designed
to educate future engineers about the impact that computers and computer programming has with
society. This project targets the "T, E, and M" of "STEM" by using electronic circuits
for controlling the lights, software for controlling the electronic circuits, and
mathematical calculations for making timing decisions.

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


## Technology

Below are the list of parts used for this project. You'll need to choose one of
the mentioned options below depending on your budget. Using LEDs is cheaper than
getting an actual traffic light.

* <a href="https://www.amazon.com/gp/product/B07BC7BMHY/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B07BC7BMHY&linkId=b51d201ecdca3bed2a84249448d0dd4f" target="_blank">Raspiberry Pi</a>
* <a href="https://www.amazon.com/gp/product/B08GYKNCCP/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B08GYKNCCP&linkId=1e440b7afda77da0a25f2af4d65b8b6a" target="_blank">Micro SD card</a> (to run the OS and store project files)
* <a href="https://www.amazon.com/gp/product/B07RQVB3HQ/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B07RQVB3HQ&linkId=8452f5455a39f35597424dcc8a2ae388" target="_blank">USB keyboard</a> (mouse optional)
* HDMI display
* <a href="https://www.amazon.com/gp/product/B07GD25V8D/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B07GD25V8D&linkId=ea5fb3393909abe778b518e808e674d5" target="_blank">Breadboard Jumper Cables</a>
* <a href="https://www.amazon.com/gp/product/B07PCJP9DY/ref=as_li_tl?ie=UTF8&tag=rhtservicesll-20&camp=1789&creative=9325&linkCode=as2&creativeASIN=B07PCJP9DY&linkId=dca65d5d374944f5c1d213924d2fb183" target="_blank">Breadboard</a> (optional)
* .NET 5
* Raspberry Pi OS (has been tested with Raspberry Pi OS Jessie)

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


## Controller Software

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

## Controller Hardware

### Relays

Relays are used when devices of different voltages or amperages are being used together. One common example
of this is relays that are used to control headlights on a car. The switch inside the vehicle has a lower
amperage and is considered to be a "signal wire". When the switch is turned on, a relay is closed
which then connects a different circuit to turn on and off the headlights.

In the Traffic Pi project, relays are used in a similar manner. The Raspberry Pi outputs 3.3VDC from the
GPIO pins. Those pins are connected to a relay board. The relay board is also connected to a 120VAC which is
needed by each of the signals. When the Pi sends an "on" signal to the relay board, the relay activates, thus
sending 120VAC from the source (in this case a wall outlet) to the signal and then corresponding signal then
turns on.

### Wiring

The color of each wire always denotes its purpose. When using different color wires, you don't need to
have a tag on each wire. Instead, you create a service manual or other documentation that lists the purpose
of each wire based on its color.

For example, if you look a wiring harness on a car, you will notice that it has a number of wires that are
bundled together. Each of those wires has a purpose. The vehicle manufacturers create a document, often
referred to as a service manual, that lists each of the colors of the wire in the harness and their purpose.

With an AC circuit, there are commonly 3 wires. Black, white, and bare copper or green.
Black wire in AC circuit represents the "hot" or supply voltage.
White wire in AC Circuit represents the neutral.
Green or bare copper wire in AC Circuit represents the ground.

With a DC Circuit, there are two wires. Red and black.
Red wire in DC circuit represents the positive. This is the voltage that comes from the power source.
Black wire in DC circuits represents the negative. This is the voltage that goes back to the power source.

### AC vs DC

The current in an AC
system alternates between the hot and neutral wires. The frequency at which this occurs varies. In
North America (including the United States), the alternation takes place at 60 Hertz (Hz) or 60 times per second.
In other parts of the world, this alternation takes place at 50 Hz per second.
AC circuits are commonly used for items that require a lot of power to operate. These include large motors,
like the ones used in AC refrigeration and industrial machines.

DC circuits are commonly used for battery powered systems, electronics, and other devices
that do not require a lot of power to operate. If a device, such as a cell phone or streaming player, 
has a "power brick", then that device runs on DC power. The power brick converts the AC power to DC power 
and at the same time reduces the voltage to what the device needs.


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

Ebay. Found a seller that own a salvage company that was selling it in 2018. The item that he 
had listed, included a controller, but the controller only had like 5 programs. I opted 
to get the light without the controller as I was going to build my own using the Raspberry Pi.

### Will you share the source code for the application?

The source code for this project is available on GitHub at
<a href="https://github.com/almostengr/trafficpi" target="_blank">https://github.com/almostengr/trafficpi</a>.

### Is the traffic light heavy?

This one is made from plastic and weighs 25 pounds. Metal traffic lights weigh between 50 and 75 pounds.

### How big is the traffic light?

Traffic lights come in two common sizes, 12 inch (30.48 centimeters) and 8 inch (20.32 centimeters). 
This is a 12 inch traffic light. It is about 14 inches wide and about 38 inches tall (with the base 
attached). 


## Traffic Control Classroom Activity

### Objective

Programmers will have to come up with code to control the traffic lights and not cause an accident.
While doing so, they learn programming concepts and how mistakes in their programs, can impact
others significantly.

### People Needed

* 1 volunteer as Traffic Light 1
* 1 volunteer as Traffic Light 2
* 1+ volunteers as programmers
* 3+ volunteers as vehicles

### Placement of People

![Positioning of voluters](/images/positioning.jpg)

* Blue is programmers (control box). Audience should positioned so that they see both traffic lights.
* Red is Traffic Light 1
* Green is Traffic Light 2

### Goals and Instructions

* Programmers are to come up with the code to control the traffic lights.
* Vehicles will go through one light and circle back around to the other light.
* Each mistake (or traffic collision) that they make means that they take the previous version of code and make corrections in the next version.
    * To make this more challenging, programmers can be fired (and replaced with new programmers) if they make too many mistakes (or cause too many collisions).
* Ideally use a chalkboard or dry erase board for this so that the versioning differences can be seen.
    * If running out of board space, previous versions can be erased. Do not erase the very first version. Once completed, this will allow a full comparison and what was done between the first and final version.
* Instructor will be “the internet”. If the programmers get stuck, they can ask the internet the question that they have.
    * To make this more challenging, limit the number of questions that can be asked.
* Traffic lights will perform one action per command.
    * To make this more challenging, “Light on” and “Light off” can be two separate commands.


----
----

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
-- | -- | --------
04 | -- | Relay Board VCC (+5V)
19 | 11 | Red Signal
21 | 09 | Yellow Signal
23 | 10 | Green Signal
34 | -- | Relay Board GND
15 | 22 | Button (Car Sensor)

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
