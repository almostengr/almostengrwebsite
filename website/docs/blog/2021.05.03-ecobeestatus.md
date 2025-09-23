---
title: Ecobee Status Monitor
description: Provide project details about the Ecobee status automation
---

## Problem

Home Assistant would report that there was a problem connecting to the Ecobee servers when a change
was made to the thermostat from Home Assistant. Home Assistant does not (in May 2021) have the ability
to check the status of the Ecobee API. It only just makes calls to the API.

## Solution

Since Ecobee had a couple of issues within the last couple of weeks when I attempted to make
changes to the thermostat, I decided to build an automation that would update an indicator in 
Home Assistant to whether the Ecobee API status page was showing that everything is operational. 

If the "All Systems Operational" message is not shown on the Ecobee status page, then the Ecobee API 
Status indicator in Home Assistant is set to false. From there, automations can be triggered based on the state
of the API. If the previously stated message is shown on the page, then the Home Assistant
sensor will show true.

## Technology

* .NET Core 3.1  C#
* Selenium WebDriver

Using Webdriver, it goes to the Ecobee API Status website and checks the text on the page. Then it updates
the local Home Assistant instance based on whether it is true or false. This automation runs
once per 10 minutes, but can be configured to run at other intervals.

## Documentation

The project documentation can be found on the 
<a href="https://github.com/almostengr/ecobeestatus" target="_blank">code repository</a>.
