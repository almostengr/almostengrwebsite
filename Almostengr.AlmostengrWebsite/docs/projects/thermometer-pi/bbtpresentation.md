---
title: Birmingham Black Techies Presentation
posted: 2022-02-09
keywords: raspberry pi, c-sharp, .net 5, programming, coding
---

## Problem

* Live in multi-story house with single HVAC system; thermostat is on lower floor
* Upstairs is always hotter

## Solution

### Initial Solution

* Window AC was connected to timer

### Current Solution

* Thermometer available via API
* Smart Outlets (WeMo) that control window AC
* Home automation to control outlets based on temperature;
* uses API

## Code Review

* <a href="https://github.com/almostengr/thermometerpi" target="_blank">Source Code</a>

* [http://osmc:8005/api/v1/thermometer](http://osmc:8005/api/v1/thermometer)
* Returns JSON data 
```json
{"fahrenheit":72.95,"celsius":22.75}
```

## Home Automation Review

* Automation rules 
* <a href="https://home-assistant.io" target="_blank">Home Assistant Website</a>

## Project Information 

* [Project Documentation](/projects/thermometer-pi)


## Notes

* presentation given to the Birmingham Black Techies group on February 9, 2022
