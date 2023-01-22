---
title: Home Automation with C#
description: Built a custom application with C# that extends home automation system
---

## Problem

There are limitations that exist with Home Assistant. One of those limitations was that 
I had issues with my home router and the wifi going offline due to system process crashing. 
Since this check was not available to be done by Home Assistant, I decided to create an automation
using Selenium WebDriver that would login to the router's web interface and perform various 
checks. Then based on the data shown the automation can then reboot the router to make sure
the Wifi comes back online. 

## Solution

Other automations have been added to this project, to further extend Home Assistant. 
Automations are trigger via an API call from Home Assistant to the custom application.

In addition, rules that are difficult to implement in Home Assistant, can be coded in a 
language that I am familiar with. Then the application can send a API response back to 
<a href="https://home-assistant.io" target="_blank">Home Assistant</a>
to perform the appropriate action.

Project was started in 2021

## Technology

* C#
* Selenium WebDriver
