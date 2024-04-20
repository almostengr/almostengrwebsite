---
title: ESP32 Traffic Light Controller
posted: 2022-08-14
updated: 2024-04-20
---

## Problem

Pupose of this project was to replace the Raspberry Pi traffic light controller
([Traffic Pi](/projects/traffic-pi)) that I had created. Problem with using a Raspberry Pi 
for projects like this is that the operating system has to be constantly updated. In addition, 
Pis are known for having issues when they are not properly shut down. 

## Solution 

To reduce the risk of 
having an unexpected failure, I decided to change replace the Pi with a controller that 
ran on an ESP32. Microcontrollers are less likely to fail as they do not have the same flaws as a Raspberry 
Pi. That main flaw with a Raspberry Pi is that they have been known to corrupt the SD cards when a 
power failure occurs.

This project is used to tech students about software development, electrical engineering, and STEM.

## Technology 

* C++
* ESP32

### Components Used

* ESP32-WROOM-32
* breadboard wires
* 4-channel mechanical relay board
* 14 gauge wire
* Econolite 12 inch traffic signal

## Controller Software

The code for the controller is written in C++. It is compiled and loaded onto the ESP32 using the 
Arduino IDE. 

## Controller Hardware

### Relays

Relays are used when devices of different voltages or amperages are being used together. One common example
of this is relays that are used to control headlights on a car. The switch inside the vehicle has a lower
amperage and is considered to be a "signal wire". When the switch is turned on, a relay is closed
which then connects a different circuit to turn on and off the headlights.

In this project, relays are used in a similar manner. The ESP32 outputs 3.3VDC from the
GPIO pins. Those pins are connected to a relay board. The relay board is also connected to a 120VAC which is
needed by each of the signals. When the ESP32 sends an "on" signal to the relay board, the relay activates, thus
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