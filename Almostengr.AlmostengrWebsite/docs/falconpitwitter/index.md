# Falcon Pi Twitter

![](/lightshow/images/20201220presentation/twittertweets.jpg)

This project is designed for Falcon Pi Player to provide updates via Twitter on the light show that 
you are running. Those updates include posting the current song and providing alerts when problems
are detected.

This application is ONLY designed to run on Falcon Pi Players that are installed on Raspberry Pi, but it 
may be possible to run it on Beagle Bone Black (BBB).

## Table of Contents

* [Twitter Example](#twitter-example)
* [Installation and Setup](/falconpitwitter/installation)
    * [System Requirements](/falconpitwitter/installation#system-requirements)
    * [Installation Steps](/falconpitwitter/installation#installation-steps)
* [Configuration](/falconpitwitter/configuration)
* [System Service](/falconpitwitter/systemservice)
    * [Create System Service](#create-system-service)
    * [Remove System Service](#remove-system-service)
    * [System Service Logs](#system-service-logs)
* [Troubleshooting](/falconpitwitter/troubleshooting)
* [Source Code](https://github.com/almostengr/falconpitwitter)
* [FAQs (Frequently Asked Questions)](/falconpitwitter/faq)

## Problem

I wanted to have a way for the visitors to my light show are able to find out the information about the 
song that was currently playing.

Some other Light Show Creators use screens or equipment that will display the song information on a 
visitor's radio using RDS (Radio Data System). 

## Solution

I did not want to have to invest heavy into this project, so after I found out that Falcon Pi Player
came with an API, I decided to build a .NET Core application that would post the song information to Twitter. 
Then create a PSA (Public Service Announcement) in my show that lets visitors know about the Twitter page
and that song and show information is available on this page.

While most of the plugins for Falcon Pi Player are written in PHP or Shell (Bash) Script, this application 
is written in .NET Core 3.1. While I do know how to program in PHP and Bash, C# and .NET Core is what 
I primarily use. Thus using this language and framework for the application.

### Twitter Example

Follow my Light Show account [@hplightshow](https://twitter.com/hplightshow) to see what this 
application can do.
