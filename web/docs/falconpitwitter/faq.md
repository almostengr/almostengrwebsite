---
title: Frequently Asked Questions (FAQs)
---

## How does this application work?

### Tweeting Song Information

This application calls the Falcon Pi Player API to get the meta data for the song that is current playing. 
Then it uses that information to compose a tweet. If the song that is playing does not have ID3 tag 
information entered, then will not display part or all of the song data. If you need to add the song 
meta data to the file, you can use a program like [Audacity](https://www.audacityteam.org/) to do so.

### Tweeting Alarms (or Alerts)

The application calls the Falcon Pi Player API to get the current temperature of the Raspberry Pi. 
If it is above the threshold that is specified in the [appsettings.json](/falconpitwitter/configuration)
file, then it will send a tweet
that mentions the users specified in the [appsettings.json](/falconpitwitter/configuration)
file a message to let them know if the 
current temperature.

## How frequently are checks done? 

Songs are checked every 15 seconds to see if it has changed. If the same song is playing from the
previous check, then no tweet is posted. 

Vitals are checked every 5 minutes. Alarms are based on the settings that you have defined in the
[configuration file](/falconpitwitter/configuration).

## I don't want certain playlists to post song information. How do I accomplish this? 

Any playlist that has "offline" or "testing" (case insensitive) in the name of it, will not post 
the song information to 
Twitter. The vitals alarms can still be triggered when "offline" or "testing playlists are active.

## Where is the source code?

Source code for this project is hosted on 
<a href="https://github.com/almostengr/falconpitwitter" target="_blank">Github</a>. The latest release
can also be downloaded from here.

## "Are you connected to internet? HttpRequest Exception occured" shows in the log. What does this mean? 

This means that your Falcon Pi Player instance attempted to connect to the internet or another device but 
was not able to do so. Double check your network and internet connection to ensure that data can be sent.
Also double check your configuration file as the hostname(s) may be incorrect or mistyped.

## Why did you build a standalone application instead of an FPP plugin?

I work as a software developer primarily building web-based applications in C#. 
Based on what I have seen, most (if not all) of the FPP plugins are build with PHP. While I do know PHP and
have worked with it in the past, I chose to go with building a C# application. 
as it gave me an opportunity to use my existing skills and 
expand them by applying them to something different than what I am used to.

## I have a question not answered. Where do I ask it?

Please file an [Issue on the repo](https://github.com/almostengr/falconpitwitter/issues)
with your comment, question, or bug report.
You may also reach out to the developer via Twitter [@almostengr](https://twitter.com/almostengr) or 
[@hplightshow](https://twitter.com/hplightshow).
