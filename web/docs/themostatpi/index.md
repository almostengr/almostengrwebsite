---
title: Thermometer Pi
description: Used a Raspberry Pi to be a thermometer that can be access by home automation system.
---

## Project Background

A common 
problem that exists is US construction is that multiple story homes were bult with a single zoned system. 
Often times, that thermostat is on the first floor and can properly manage the temperature on the first 
floor. However the second floor often times gets too hot because heat rises and cold air sinks. 

Other houses in the neighborhood have installed window AC units in the rooms on their upper floor of their 
house and so do I. The thing about the window units is that they do not have thermometers on them that will 
accurately keep the room cool. Thus I built a .NET Core application that will create an API that allows the 
home automation system to access the data provided by the Raspberry Pi.

I have several Rapsberry Pi that are used in my home and used as set top boxes for television. Instead of 
purchasing additional devices to detect temperature, I decided to get some one-wire temperature sensors that 
can be connected to the Raspberry Pi that is already in the rooms that I want to monitor.