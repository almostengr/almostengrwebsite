---
title: Birmingham Black Techies Presentation
posted: 2022-02-09
keywords: raspberry pi, c-sharp, .net 5, programming, coding
hide:
  - navigation
  - toc
  - 
---

<p>&nbsp;</p>
<p>&nbsp;</p>
<p>&nbsp;</p>
<p>&nbsp;</p>

## Problem

### Live in multi-story house with single HVAC system; thermostat is on lower floor
### Upstairs is always hotter

<p>&nbsp;</p>
<p>&nbsp;</p>

## Initial Solution

### Window AC was connected to timer
### Ran when not needed; higher power bill

<p>&nbsp;</p>
<p>&nbsp;</p>

## Current Solution

### Thermometer reading available via API
### Smart Outlets (WeMo) that control window AC units
### Home automation to control outlets based on temperature
### Only runs when needed; lower power bill

## Code Review

### <a href="https://github.com/almostengr/thermometerpi" target="_blank">Source Code</a>

### [http://osmc:8005/api/v1/thermometer](http://osmc:8005/api/v1/thermometer)
### Returns JSON data 
```json
{"fahrenheit":72.95,"celsius":22.75}
```

## Home Automation Review

### Automation rules 
### <a href="https://home-assistant.io" target="_blank">Home Assistant Website</a>

<p>&nbsp;</p>
<p>&nbsp;</p>

## Project Information 

### [Project Documentation](/projects/thermometer-pi)

<p>&nbsp;</p>
<p>&nbsp;</p>
<p>&nbsp;</p>

## Kenny Robinson

### Programmer Analyst
### @almostengr
### [thealmostengineer.com](/)
### <a href="https://www.linkedin.com/in/krobinsontech" target="_blank">https://www.linkedin.com/in/krobinsontech</a>

## Notes

### presentation given to the Birmingham Black Techies group on February 9, 2022
