---
title: FAQ (Frequently Asked Questions)
description: Frequently asked questions about this and other light shows.
---

Here are the most common questions that are asked about the light show. Please use the navigation to jump
to the question that you are looking for or use the search feature.

## Table of Contents

* [Basics](#basics)
* [Money](#money)
* [Technology](#technology)
* [Resources](#resources)

## Basics

### How do you keep the lights from shorting or tripping breakers during wet weather?

Each connection that is on the ground is wrapped in electrical tape. That prevents water from
reaching the connections, which would result in an electrical short, thus tripping the breaker and
shutting down the show.

Outlets and plugs that are not on the ground, are pointed downwards so that water cannot enter the
socket and taped to prevent water from getting in.

### What have you done in previous years?

For previous year show information, see the [Resources](#resources) section.

### Are there other residential light shows?

Yes, there are many that exist. See the list below.

*Those with "MGM" in parenthesis are located in or near the Montgomery, Alabama area.*
*Visit their respective pages for details about their show.*

* <a href="https://www.cityofwetumpka.com/Default.asp?ID=452&pg=Decorations+Contest" target="_blank">Christmas on the Coosa (MGM)</a>
* <a href="http://www.lightinguppaxton.com/" target="_blank">Lighting Up Paxton</a>
* <a href="https://www.lightstoabeat.com" target="_blank">Lights To A Beat</a>
* <a href="https://sites.google.com/site/listentoourlights/home" target="_blank">Listen To Our Lights</a>
* <a href="https://www.zeemaps.com/map?group=3242152" target="_blank">Map of Light Displays</a>
* <a href="http://www.mosslights.com" target="_blank">Moss Lights</a>
* <a href="https://www.christmaslightfinder.com/displays/display-details/?id=2529" target="_blank">Percivals Christmas Lights and Santaland & Clark Wannabe (MGM)</a>
* <a href="https://riparianlights.com/" target="_blank">Riparian Lights</a>
* <a href="http://sjlights.com" target="_blank">San Jose Lights</a>
* <a href="https://taralights.com" target="_blank">Tara Lights (MGM)</a>
* <a href="https://www.thechristmaslightshow.com/" target="_blank">The Christmas Light Show</a>
* <a href="https://www.facebook.com/theminionhouse334" target="_blank">The Minion House (MGM)</a>
* <a href="https://tzchristmas.com" target="_blank">Thyno Zgouvas' Christmas Wonderland (MGM)</a>
* <a href="https://www.wayoffbroadwaylights.com/" target="_blank">Way Off Broadway Lights (MGM)</a>
* <a href="https://www.wsfa.com/video/2020/11/30/wetumpka-family-puts-griswold-christmas-display-th-year/" target="_blank">Wetumpka Griswold Christmas (MGM)</a>
* <a href="https://woodardfamilylights.weebly.com/" target="_blank">Woodard Family Lights</a>

### Why did you start doing this?

I wanted to do something different for Christmas. Given that the COVID-19 (Coronavirus) pandemic was happening
during this time, I had extra funds on hand since I was not doing much travelling during this time. I decided
to leverage my tech and Electrical Engineering skills and build a Christmas light show.

## Money

### How much does it cost to run the light show? Your electric bill must be high!

#### Short Answer

Since LEDs are used for the light show, it is not high at all. To run the show for 5 weeks,
with all the lights on (2,130 LEDs) would cost a maximum of $38.90.  Given that all the lights are not all the entire time and
the equipment is not running at max capacity (which hardly ever happens), the actual cost is less than this.

See [Do The Math](#long-answer-do-the-math) for the breakout and how this cost was derived.

#### Long Answer - Do The Math

With all lights turned on (2,130 LEDs were used for the 2020 Light Show), it pulls 130 Watts.
The show controller and components can pull a maximum of 305 Watts.
Thus the show in total can use 435 (130 + 305) Watts maximum.

The lights run for 33.5 hours per week (Sunday through Thursday, 4.5 hours; Friday and Saturday, 5.5 hours).
The show runs for 5 weeks during the Christmas season.
The controller runs 168 hours per week (24 hours per day).

Electric companies measure the amount of electricity that you use in kilowatt-hours.
To convert W (Watts) to kWh (kilowatt-hours), you have to compute the lights and controller separately
since they are on for different durations.

```text
E(kWh lights) = P(W) × t(hr) / 1000 = 130 Watts * 33.5 hours / 1000 = 4.355 kWh

E(kWh controller) = P(W) × t(hr) / 1000 = 435 Watts * 168 hours / 1000 = 73.08 kWh
```

The rate for electricity (in 2020) during the winter months (Oct-May) is $0.100511 per kWh.

```text
Cost for lights = 0.100511 * 4.355 kWh = 0.44

Cost for controller = 0.100511 * 73.08 kWh = 7.34
```

Since we have the cost for each group of components, we can compute the cost per week and per season.

```text
Cost per week = $0.44 + $7.34 = $7.78

Cost per season (5 weeks) = $7.78 * 5 = $38.90
```

That means the maximum total cost of the show per week is $7.78 and cost for the season is $38.90.

Now given that the light show does not have all of the lights on at any given point during the show and
the controller is not running at maximum capacity all of the time, the
actual cost is less than the above mentioned amount.

### You built a control box for your show. How much did that cost?

A total of $332.59 (all purchased in 2020).
I did have some items already on hand from existing projects that I was able
to use for this project. For those items, I used the current cost for those items.
This doesn't include the wood, nails, or paint that I used to build the control box
or the AC lights that I already had on hand.

### What are the parts that I need to build my own control box?

![Photo of control box](/images/lightshow/20201220presentation/20201204_120013.jpg)

This is the list of the electrical related components. The full list of components will vary depending
upon how to you choose to design your control box. The prices were how much the items costed in 2020.

* Fuse holders (x24) = $7.50
* Fuses (rated 2 Amps) (x30) = $17.97
* 8-channel solid state relays (x2) = $9.33
* SPT-2 male plugs (x25) = $23.99
* SPT-2 female plugs (x25) = $23.99
* FM transmitter = $12.49
* Raspberry Pi 3 = $40.00
* Assorted breadboard wires (x40) = $7.49
* 3.5mm audio cable = $5.99
* Outlets (used) (x12) = $6.00
* Outlet boxes and outlet faceplates (x6) = $12.00
* 14 gauge wire (25 ft) = $12.73
* 16 gauge wire (25 ft) = $8.98
* SPT-2 18 gauge 150 ft spools (x2) = $94.13
* Additional AC lights (10 strands, 100 lights each) = $50.00

Total = $332.59

*All prices are listed in USD. Does not include taxes or shipping fees.*

## Technology

### What kind of hardware do you use?

#### Raspbery Pi

The Falcon Pi Player is installed on the Raspberry Pi. The Rasberry Pi controls the relays, which in turn
controls all of the lights. The Pi controls each of the 24 channels of relays via the GPIO pins that it has.

#### Christmas Lights

All of the lights are LED. Only two colors are used for the light show, white and red.

#### Solid State Relays

All of the relays are Solid State Relays (SSR). SSRs were used because they have no mechanical or moving
parts and having greater reliability for being switched on and off frequently.

Mechanical relays heat up from switching on an off. When done repeatedly, like during a song, the relay can
actually over heat and weld itself closed.

#### FM Radio Transmitter

Music is transmitted over radio via a low-power FM transmitter. Music goes into the transmitter directly from
the Raspberry Pi and broadcasted on an open frequency. Radio Locator
[mentioned below](/lightshow/faq#where-can-i-find-out-more-information-or-ask-questions)
was used to locate the best frequency.

### What kind of software do you use?

#### Xlights

The music and light sequences are timed together using Xlights. This software is open source
and runs on most operating systems, including Windows, Linux, and Mac. You can download the latest
release <a href="https://github.com/smeighan/xLights" target="_blank">from the repository</a>.

For assistance with configuring or issues with xLights, you can post in the
<a href="https://www.facebook.com/groups/xLights" target="_blank">Official xLights Support Group</a>.

#### Falcon Pi Player (FPP)

Once the sequences have been created in Xlights, those files are copied over to FPP. From there, the
show data files, music files, and scheduling are all connected within this software. You can download
the latest release <a href="https://github.com/FalconChristmas/fpp" target="_blank">from the repository</a>.

For assistance with configuring or issues with Falcon Pi Player, you can post in the
<a href="https://www.facebook.com/groups/FalconPlayer/" target="_blank">FPP, Falcon Player</a>.

#### Kdenlive

Kdenlive is a video editing tool. It can also be used to modify audio files. The show intro audio file was
modified with Kdenlive to have the voice over and background music on the same track. You can download
the latest version from <a href="https://kdenlive.org/" target="_blank">its website</a>.

#### Falcon Pi Twitter

[Falcon Pi Twitter](/falconpitwitter)
is a custom .NET Core application written in C#. The application serves as a bridge
between the Falcon Pi Player and Twitter. As the show plays, the song information is pulled from the
Falcon Pi Player and then posted as a tweet on Twitter. You can find out more information about this
project by visiting the [project page](/falconpitwitter).

### Song updates are posted to Twitter. How does that work?

See the [Falcon Pi Twitter](/falconpitwitter) page for more information about
that project.

## Resources

### Where can I find out more information or ask questions?

Below are resources to additional information about various products and tools.

* <a href="https://www.youtube.com/channel/UCby1v6Kbi8AHMkV2yMyF1MQ" target="_blank">Canispater Christmas</a>
* <a href="https://www.falconchristmas.com" target="_blank">Falcon Christmas</a>
* <a href="https://www.facebook.com/groups/FalconPlayer/" target="_blank">FPP, Falcon Player Group</a>
* <a href="https://www.facebook.com/groups/xLights" target="_blank">Official xLights Support Group</a>
* <a href="https://radio-locator.com/cgi-bin/vacant" target="_blank">Radio Locator, find vacant radio channels</a>
* <a href="https://ttstool.com" target="_blank">TTS Tool, for text to speech recordings</a>
