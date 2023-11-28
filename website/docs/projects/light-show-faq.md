---
title: Light Show FAQ (Frequently Asked Questions)
description: Frequently asked questions about this and other light shows.
updated: 2022-10-23
---

Here are the most common questions that are asked about the light show.

## Basics

### How do you keep the lights from shorting or tripping breakers during wet weather?

Each connection that is in contact with the ground is wrapped in electrical tape. That prevents water from
reaching the connections, which would result in an electrical short, thus tripping the breaker.

Outlets and plugs that are not on the ground, are pointed downwards so that water cannot enter the
socket and taped to prevent water from getting in.

### Are there other residential light shows?

Yes, there are many that exist. There are also commercial light shows. See the list below.
*Those with "MGM" in parenthesis are located in or near the Montgomery, Alabama area.*
*Visit their respective pages for details about their show.*

* <a href="https://blinkygeek.com/" target="_blank">Blinky Geek</a>
* <a href="https://broomfieldlights.com/" target="_blank">Broomfield Lights</a>
* <a href="https://www.facebook.com/Burtonfamilylightshow" target="_blank">Burton Family Light Show</a>
* <a href="https://www.youtube.com/c/CanispaterChristmas" target="_blank">Canispater Christmas</a>
* <a href="https://www.christmaslightfinder.com/" target="_blank">Christmas Light Finder</a>
* <a href="https://www.christmasoncandleflower.com" target="_blank">Christmas on Candleflower</a>
* <a href="https://www.cityofwetumpka.com/Default.asp?ID=452&pg=Decorations+Contest" target="_blank">Christmas on the Coosa (MGM)</a>
* <a href="https://www.facebook.com/ChristmasWonderlandAlabama/" target="_blank">Christmas Wonderland</a>
* <a href="https://www.davislights.org/" target="_blank">Davis Family Christmas Light Show</a>
* <a href="http://thehormanns.net/" target="_blank">The Hormanns</a>
* <a href="http://www.lightinguppaxton.com/" target="_blank">Lighting Up Paxton</a>
* <a href="https://www.lightstoabeat.com" target="_blank">Lights To A Beat</a>
* <a href="https://sites.google.com/site/listentoourlights/home" target="_blank">Listen To Our Lights</a>
* <a href="https://ldplights.com/" target="_blank">Lucy Depp Park Light Show</a>
* <a href="https://www.zeemaps.com/map?group=3242152" target="_blank">Map of Light Displays</a>
* <a href="https://mkelights.com/" target="_blank">MKE Lights</a>
* <a href="https://www.facebook.com/LocateMGMLights" target="_blank">Montgomery Christmas Lights (MGM)</a>
* <a href="http://www.mosslights.com" target="_blank">Moss Lights</a>
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
during 2020, I had extra funds on hand since I was not doing much travelling during this time. I decided
to leverage my technology and Electrical Engineering skills and build a Christmas light show.

### What does your HOA say about the show?

I do not live in a neighborhood with an HOA. From what I have seen though, those that do live in neighborhoods
with HOAs, when their show gains too much popularity or causes traffic issues, the HOA usually issues 
"cease and desist letters" or threaten the owners with fines if they continue with their animated displays. 
Thus they either stop doing their show or they move their show to another location that does not have an HOA 
or do not have close neighbors.


## Money

### How much does it cost to run the light show? Your electric bill must be high!

#### Short Answer

Since LEDs are used for the entire light show, it is not high at all. To run the show for 5 weeks,
with all the lights on (2,130 LEDs used in 2020) would cost a maximum of $38.90.
Given that all the lights are not all the entire time and
the equipment is not running at max capacity (which hardly ever happens), the actual cost is less than this.

See [Do The Math](#long-answer-do-the-math) for the breakout and how this cost was derived.

#### Long Answer - Do The Math

With all lights turned on (2,130 LEDs were used for the 2020 Light Show), it pulls 130 Watts.
The show controller and components can pull a maximum of 305 Watts.
Thus the show in total can use 435 (130 + 305) Watts maximum.

The lights run for 33.5 hours per week (Sunday through Thursday, 4.5 hours; Friday and Saturday, 5.5 hours).

```text
Sun through Thurs hours = 4.5 hours * 5 days = 22.5 hours

Fri and Sat hours = 5.5 hours * 2 days = 11 hours

11 + 22.5 = 33.5 hours
```

The show runs for 5 weeks during the Christmas season.
The controller runs 168 hours per week (24 hours per day).

Electric companies measure the amount of electricity that you use in kilowatt-hours.
To convert W (Watts) to kWh (kilowatt-hours), you have to compute the lights and controller separately
since they are on for different durations.

```text
E(kWh lights) = P(W) × t(hr) / 1000 = 130 Watts * 33.5 hours / 1000 = 4.355 kWh

E(kWh controller) = P(W) × t(hr) / 1000 = 435 Watts * 168 hours / 1000 = 73.08 kWh
```

The rate for electricity (in 2020) during the winter months (Oct-May) is $0.100511 USD per kWh.

```text
Cost for lights = USD per kWh * kWh = 0.100511 USD per kWh * 4.355 kWh = 0.44 USD

Cost for controller = USD per kWh * kWh = 0.100511 USD per kWh * 73.08 kWh = 7.34 USD
```

Since we have the cost for each group of components, we can compute the cost per week and per season.

```text
Cost per week = $0.44 + $7.34 = $7.78 USD per week

Cost per season (5 weeks) = $7.78 USD per week * 5 weeks = $38.90 USD
```

That means the **maximum** total cost of the show per week is $7.78 and cost for the season is $38.90.

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

![Photo of control box](/images/20201220presentation/20201204_120013.jpg)

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

#### 120 Volt Outlets

Relays control the flow of power to the outlets. In turn, each outlet is mapped to a channel of lights and
is connected to the 120 Volt lights that are used in the show.

#### Christmas Lights

All of the lights are LED, 120 volt strings. Only two colors are used for the light show, white and red. 
Lights used are the same ones that you can get at a big box retailer.

#### FM Radio Transmitter

Music is transmitted over radio via a low-power FM transmitter. Music goes into the transmitter directly from
the Raspberry Pi and broadcasted via the radio. Radio Locator
[mentioned below](/projects/light-show-faq#where-can-i-find-out-more-information-or-ask-questions)
was used to locate the best frequency based on the area.

#### GFCI (Ground Fault Circuit Interrupter)

Because the lights are replaced outside in the weather elements, a GFCI outlet is used inside the control box. 
This outlet provides protection to the entire box and if a fault is detected, will shut off the entire show.

#### Raspberry Pi 3B+

The Falcon Pi Player is installed on the Raspberry Pi. The Rasberry Pi controls the relays, which in turn
controls all of the lights. The Pi controls each of the 24 channels of relays via the GPIO pins that it has.

#### Solid State Relays

All of the relays are Solid State Relays (SSR). SSRs are used because they have no mechanical or moving
parts and having greater reliability for being switched on and off frequently.
Each relay is protected from overcurrent by a 2 Amp fuse between the wall outlet and the relay.

Mechanical relays heat up from switching on an off. When done repeatedly and rapidly, like during a song, 
the relay can
actually over heat and weld itself together. Once welded shut, the relay will no longer function and 
will have to be replaced.


### What kind of software do you use?

#### Falcon Pi Player (FPP)

Once the sequences have been created in Xlights, those files are copied over to FPP. From there, the
show data files, music files, and scheduling are all connected within this software. You can download
the latest release <a href="https://github.com/FalconChristmas/fpp" target="_blank">from the repository</a>.

For assistance with configuring or issues with Falcon Pi Player, you can post in the
<a href="https://www.facebook.com/groups/FalconPlayer/" target="_blank">FPP, Falcon Player</a> group.

#### Light Show Extender

The [Light Show Extender](/projects/light-show-extender) is a custom C# application that provides additional 
functionality for the light show. This application serves as an interface between the Falcon Pi Player that 
runs the show, the National Weather Service for getting weather information, and thealmostengineer.com 
website where users make their song requests and see current show information.

#### Ffmpeg

<a href="https://ffmpeg.org/" target="_blank">Ffmpeg</a>
is a multimedia editing software application. Using the command line, it is used to merge and sync the 
audio to the video for the songs in the Christmas Light Show. It is also used to display the graphic 
overlays that are used to display the song information and channel branding information.

#### Xlights

The music and light sequences are timed together using Xlights. This software is open source
and runs on most operating systems, including Windows, Linux, and Mac. You can download the latest
release <a href="https://github.com/smeighan/xLights" target="_blank">from the repository</a>.

For assistance with configuring or issues with xLights, you can post in the
<a href="https://www.facebook.com/groups/xLights" target="_blank">Official xLights Support Group</a>.

### Song updates used to be posted to Twitter. How does that work?

See the [Falcon Pi Twitter](/projects/falcon-pi-twitter) page for more information about
that project.
 
### What is the legality of using an FM transmitter for light shows?

The answers will vary depending on who you ask in the light show community. From my understanding and 
online research regarding the matter, it breaks down to following these guidelines:

#### Don't broadcast on a frequency that another station is already broadcasting on in your area. 

This will get 
you in immediate trouble as those who listen to the licensed station will report the interference. If an 
investigation is done and you are caught, you will be in hot water with the FCC and subject to fines 
and imprisonment.

#### Don't broadcast further than necessary

Nobody is going to be watching your light show 1/2 mile
away from your house, especially if you live inside of city limits or in a subdivision.
When you set up your transmitter, drive around and see how far the signal reaches. If you are 
two streets over and can still hear it clearly, but cannot see your house, then you need to lower the
amplification of your signal or position your antenna so that the signal does not travel as far.

#### Turn it off when not being used (non-light show season)

It does not make sense to leave a light on in 
a room with nobody in it. The same goes for your FM transmitter. When it is not being used, turn it off.

### How do you store backups of the show files and music?

Backups are done automatically using Shell Scripts that run periodically via Cron Jobs. The same scripts 
are done for both the Xlights directory files on the computer and the Falcon Pi Player files on the 
Raspberry Pi. 
What the shell script does is commits the files that have changed in the specified location, commits 
those files to a git repository, and then pushes the latest commit to Github. 

If a previous version
of a file needs to be restored, a checkout of a previous commit can be done to restore that file to a 
previous state. I provide the steps to set up automatic backup of your Falcon Pi Player in a 
<a href="https://www.youtube.com/watch?v=l-xUcvMyn2Q" target='_blank'>YouTube video I created</a>.

### The music is a few seconds behind the lights. Why is that?

Some radios buffer the radio signal or do additional processing of the audio that is being played before 
you hear it. This causes the delay between the lights and sound. Some radios have a way that you can disable 
this feature by turning on "live mode". Check your vehicle's owners manual for how to do this.

## Jukebox

### How does the jukebox work?

When you submit your request on the [Light Show Jukebox Page](https://lightshow.thealmostengineer.com), the request is placed in 
a queue. As a song is finishing, the light show system will check to see if a new request has been submitted. 
If a new song has been requested, it will then prepare to and play that song.

### What technology runs the jukebox?

The jukebox uses C#, HTML, CSS, PHP, and MySQL. More infomration about the jukebox set up and how it 
operates can be found on the [Light Show Extender project page](/projects/light-show-extender).

## Resources

### Where can I find out more information or ask questions?

Below are resources to additional information about various products and tools that were not 
previously mentioned.

* <a href="https://www.facebook.com/groups/189136458482844" target="_blank">Alabama Christmas Light Enthusiasts</a> (Facebook Group)
* <a href="https://www.youtube.com/channel/UCby1v6Kbi8AHMkV2yMyF1MQ" target="_blank">Canispater Christmas</a>, YouTube tutorials
* <a href="https://www.facebook.com/groups/233516775330" target="_blank">Do It Yourself Christmas</a> (Facebook Group)
* <a href="https://www.falconchristmas.com" target="_blank">Falcon Christmas</a>
* <a href="https://www.facebook.com/groups/FalconPlayer" target="_blank">FPP, Falcon Player</a> (Facebook Group)
* <a href="https://www.facebook.com/groups/985841198231733/" target="_blank">Holiday Lighting Think Tank</a> (Facebook Group)
* <a href="https://www.facebook.com/groups/628061113896314" target="_blank">Official Xlights Support Group</a> (Facebook Group)
* <a href="https://ttstool.com" target="_blank">TTS Tool</a>, for text to speech recordings
* <a href="https://www.facebook.com/groups/351083649266539/" target="_blank">Xlights Wireless Support Group</a> (Facebook Group)
