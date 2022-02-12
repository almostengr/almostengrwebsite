---
title: Building A Christmas Light Show Control Box (Presentation 2020-12-20)
imagealt: House with lights
image: /images/2020 Christmas Light Show 20201211-f000000.jpg
---

## About The Show

* 2,130 LED lights
* 16 channels
* Took about 1.5 months to build box and show
* Approximately 15 minute show duration

## Hardware

### Control Box

![Control box with relays, Rapsberry Pi, and outlets](/images/20201220presentation/20201204_120013.jpg)

* Incoming power
* Relays
* Control and audio
* Output/Lighting Connections

### Volts, Amps, and Watts 

<a href="https://www.youtube.com/watch?v=gOk3pl4hmeQ" target="_blank">Video Explaination</a>

#### Raspberry Pi and FM Transmitter

![Raspberry Pi and FM Transmitter](/images/20201220presentation/20201220_084747.jpg)

* 5 volt circuit, provided by the Raspberry Pi
* Used to control relays
* FM transmitter, broadcasts on signal of choosing
* low-power transmitter
* 24 channel capacity

### Solid State Relays

![8-Channel Solid State Relay board](/images/20201220presentation/20201220_084801.jpg)

* No moving parts
* Silent operation
* Connected to lights via outlets

## Software

### Xlights

![Screenshot of Xlights sequencing](/images/20201220presentation/xlights.jpg)

* Used to create a file that controls the lights
* Build model of house to preview show

### Falcon Pi Player (FPP)

![Screenshot of Falcon Pi Player homepage](/images/20201220presentation/falconpi.jpg)

* Runs on Raspberry Pi
* Reads the file created in xLights with the light data
* Plays the music
* Scheduling and show playlist
* Used to configure controller

## Updates Via Twitter

![Screenshot of C# application with code](/images/20201220presentation/fpptwitter.jpg)

* .NET Core application using C#
* Reads data from FPP and posts to Twitter
* <a href="https://twitter.com/hpchristmas" target="_blank">@hpchristmas on Twitter</a>
* <a href="https://github.com/almostengr/falconpitwitter" target="_blank">Source Code</a>

![Screenshot of tweets from the application](/images/20201220presentation/twittertweets.jpg)

## 2020 Christmas Light Show

<iframe width="560" height="315" src="https://www.youtube.com/embed/fs6Lx8ySL9Y" frameborder="0"
allow="accelerometer; autoplay; clipboard-write; encrypted-media; gyroscope; picture-in-picture" allowfullscreen></iframe>

<a href="https://www.youtube.com/watch?v=fs6Lx8ySL9Y" target="_blank">Watch on YouTube</a>
