---
title: ESP32 Radio Sign Controller
description: Tune To sign LED controller
---

## Problem

In years past, I have used Christmas lights on the border of the Tune To sign for my Christmas Light Show. 
The issue that has occurred is that because the lights are in direct contact with the ground, the lights 
usually short out when it rains. As a result the entire show shuts down.

## Solution

Using an ESP32 and relays, I created a controller for the LED strip lights that are mounted on the border of 
the Tune To sign. When powered on, the ESP32 picks a random interval to change colors. Since this sign 
is used for Christmas, it has been programmed to cycle through red, green, and white colors.

To change the random interval for color changing, the ESP32 needs to be power cycled. This is done by the 
light show controller and is programmed in as part of the songs that play.

## Technology

This project uses an ESP32 with relays to control the colors of the lights. 

* Technologies: C++
* Year Started: 2022

### Materials

* ESP32-WROOM development board
* 4 channel solid state relays
* custom Tune To sign made from wood
* custom stencils for radio station information
* 18/2 lamp wire
* 120VAC outlet with 5VDC USB connection

## Source Code

The source code for the project can be found at the 
<a href="https://github.com/almostengr/esp32radiosign" target="_blank">GitHub repository</a>.
