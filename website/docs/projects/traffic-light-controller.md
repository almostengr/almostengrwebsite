---
title: ESP32 Traffic Light Controller
posted: 2022-08-14
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

This controller will be sold as a product that model railroad and traffic light enthusiasts
will enjoy. To purchase, visit 
<a href="https://rhtservices.net" target="_blank">rhtservices.net</a>.

## Technology 

* Technology: C++, ESP32

### Components Used

* ESP32-WROOM-32
* breadboard wires
* 4-channel mechanical relay board
* 14 gauge wire
* Econolite 12 inch traffic signal

