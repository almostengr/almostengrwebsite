---
title: Home Automation with C#
description: Built a custom application with C# that extends home automation system
---

## Purpose

There are limitations that exist with Home Assistant. One of those limitations was that 
I had issues with my home router and the wifi going offline due to system process crashing. 
Since this check was not available to be done by Home Assistant, I decided to create an automation
using Selenium WebDriver that would login to the router's web interface and perform various 
checks. Then based on the data shown the automation can then reboot the router to make sure
the Wifi comes back online. 

Other automations have been added to this project, to further extend Home Assistant. 
Automations are trigger via an API call from Home Assistant to the custom application.

* Technology: C#, Selenium WebDriver
* Year Started: 2021
