---
title: Thermometer Pi
description: Used a Raspberry Pi to be a thermometer that can be access by home automation system.
---

## Table of Contents

[Project Background](#project-background)
[Components Used](#components-used)
[Code](#code)
[The Setup](#the-setup)

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

## Components Used

* [Raspberry Pi](https://www.amazon.com/gp/product/B07BC7BMHY/ref=as_li_qf_asin_il_tl?ie=UTF8&tag=rhtservicesll-20&creative=9325&linkCode=as2&creativeASIN=B07BC7BMHY&linkId=eae8899ccbef0eb26acf71cb65bef39a)
* [DS18S20 Temperature Sensor](https://www.amazon.com/gp/product/B07MR71WVS/ref=as_li_qf_asin_il_tl?ie=UTF8&tag=rhtservicesll-20&creative=9325&linkCode=as2&creativeASIN=B07MR71WVS&linkId=bfd830515da10f922afff9a79cc33e58)
* [Serial to USB Cable](https://www.amazon.com/gp/product/B07D9R5JFK/ref=as_li_qf_asin_il_tl?ie=UTF8&tag=rhtservicesll-20&creative=9325&linkCode=as2&creativeASIN=B07D9R5JFK&linkId=e35fd9d313f055ab778e60783564078b)
* [Home Assistant (on same or different device)](https://homeassistant.io)
* [Belkin Wemo Smart Outlet](https://www.amazon.com/gp/product/B0776YH29B/ref=as_li_qf_asin_il_tl?ie=UTF8&tag=rhtservicesll-20&creative=9325&linkCode=as2&creativeASIN=B0776YH29B&linkId=34342060eb6bea8006e0dbbefb376fcf)
* [Window AC Unit](https://www.amazon.com/gp/product/B085797ZFF/ref=as_li_qf_asin_il_tl?ie=UTF8&tag=rhtservicesll-20&creative=9325&linkCode=as2&creativeASIN=B085797ZFF&linkId=e38e0ec46bdea5e4c32950d147003cc8)

## Code

The application was build using .NET Core 3.1 Worker Service. The application will run the command to get the 
data from the temperature sensor. After getting the data, then it makes a call to Home Assistant API that
provides the temperature as a state to a sensor named of your chosing.

The code is available on my [GitHub repository](https://github.com/almostengr/themometerpi).

## The Setup 

Here's how I did it...

* Connect the DS18S20 sensor to the Serial to USB Cable
* Install an operating system of your choosing on your Raspberry Pi (OSMC was installed on mine)
* Copy the ThermometerPi files to the Raspberry Pi
* Configure the appsettings.json file to point to your Home Assistant instance. Also need the HA Token
* Set up the ThermometerPi as a system service
* Start the service
* Set up automations in Home Assistant using the sensor

Eventually will do a walkthrough video on how I did my setup.
