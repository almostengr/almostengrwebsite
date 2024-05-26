---
title: Landscape Lighting
# imagealt: 2024 Christmas Light Show
# image: /images/2020 Christmas Light Show 20201211-f000000.jpg
---

## Problem

A number of people have seen the lights on my house during Christmas time and thought they 
were cool.  I wanted to light up the house to be festive during the various holidays of the year. 


## Solution

During the 2023 Christmas season, I added RGB flood lights to my light show.  Since I already had 
the lights made and working, I decided to use them throughout the year. This meant leaving the 
controller for the light show on all the time, but that was not a problem as it is a Raspberry Pi 3B+. 

The RGB flood lights that I use are 120V lights that you can get from any home improvement 
retailer. These lights are controlled using relays that are connected to an ESP32 running WLED. 
WLED receives data from the Falcon Pi Player instance, which is the show controller. 

Also on the Falcon Pi Player, is a script that runs shortly after sunset. This PHP script, determines
which sequence should be ran. Based on the sequence, the flood lights illuminate with the 
appropriate colors for the holiday, special weekend, or special month. 

## Technology

* ESP32
* Falcon Pi Player (FPP)
* PHP
* Raspberry Pi 3B+
* Solid State Relays
* WLED

## Source Code

I created a separate post about the [holiday lighting script](/technology/2024.04.18-holiday-lighting-script-for-fpp)
that I use to start the sequences for the special lighting.
