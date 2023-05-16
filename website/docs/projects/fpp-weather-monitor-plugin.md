---
title: Weather Monitor Plugin
---

## Problem

Being a member of the Falcon Pi Player and Official Xlights Support Group groups, one recurring
discussion that I see is that people ask the group
whether they run their lights during the rain, snow, or high winds.
Manually having to check the weather every day to know whether you can start your show can be additional task that could easily be delegated to the technology running the show.

## Solution

Created a plugin for Falcon Pi Player (FPP) that will periodically get the latest weather observations from
the National Weather Service (NWS). When the weather conditions match or exceeds the user's specified thresholds,
such has the wind being too high, the plugin will stop the currently running playlist.

FPP already accepts the longitude and latitude coordinates for the show. Leveraging
this information, the plugin will find the nearest NWS weather station and use
the information from that weather station to make sure the show is not running
the configured weather events, such as rain, thunderstorms, or high winds.

### Example

Some users have inflatables as part of their light show. If the wind were to get above 20 MPH, those
inflatables could be picked up and carried away by the wind. This plugin could prevent the inflatables
from being blown away by stopping the show.

As part of the show playlist, the blower on the inflatables are turned off when the playlist is stopped.
Thus reducing the chance that the inflatables would be blown away during moderate or high winds.

## Technology

* Falcon Pi Player
* PHP
* Bash (Shell) Scripts

## Source Code and Documentation

Code and documentation for this project can be found on
<a href=”https://github.com/almostengr/fpp-weather-monitor-plugin” target=”_blank”>Github repository</a>.