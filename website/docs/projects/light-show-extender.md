---
title: Light Show Extender
---

## Problem

While having a Christmas light show is fun, having one that the viewers can interact with is even better. 
I created this project to allow users to pick the song that they want to hear, see the current song 
information, and to see the current temperature and weather information.

## Solution

The solution was to create a custom application that would do all of the above and more.
Originally this project started as the Falcon Pi Twitter project, which would post the song 
information and countdown to Christmas to the Twitter account created for the show. 
However, due to changes made by Twitter with their API, this project was modified to 
not use that platform, create a custom solution that would offer the same if not more 
benefit, and to add additional features that users could interact with.

Current functionality includes allowing visitors to select the song(s) that they would 
like to play. This has been dubbed the Jukebox feature as you request the song, 
and the show plays it. Additional information, including the current weather and system temperatures 
are displayed on the website. This makes it easier to check on the status of the system and provides 
some additional information to the user about the show.

### Phase One

I found a project called 
<a href="https://remotefalcon.com" target="_blank">Remote Falcon</a>
that allows visitors to do some of the similar things that I wanted. 
However, it did lack some features. 
Remote Falcon is maintained by one of the individuals in the light show community. It is a personal project
of his and he does not charge fees for the service.
I debated with whether to fork the existing repository and make changes 
to the existing code, but it was apprehensive about doing so. 

What I decided to do was to create my own jukebox implementation of the light show using my website. 
My implementation of this project, was designed to have only the features that I desired
to be included. This mainly consisted of users being able pick one of the songs that 
that they wanted to hear.

The first phase of this project was to set up a page on the website that could accept 
requests from the viewers. It also included setting up an API (Application 
Programmable Interface) that the Falcon Pi Player could interact with and get the 
requests songs and perform other actions.

### Phase Two 

The second phase of this project was to build a standalone application using C# that 
will serve as a "middle man" system between the website and the Falcon Player.
This application connects to the Falcon Player and The Almost Engineer website via 
their APIs. 

Additional features of the project have been considered, but are still in the planning 
phases. Those features include getting and displaying temperature information on the 
website, using weather information to automatically shut down the show, and tracking 
how many times a song plays during the light show season.

## Road Map 

Project road map is tracked via issues on the project repository. Visit the 
<a href="https://github.com/almostengr/light-show-extender/issues" target="_blank">project repository</a>
on Github.

## Technology

* Bootstrap 4
* C# (C-sharp)
* CSS
* Falcon Pi Player
* HTML
* Javascript
* Linux
* MkDocs
* MySQL
* PHP

## Source Code

Source code for this project can be found on 
<a href="https://github.com/almostengr/light-show-extender" target="_blank">Github</a>.
