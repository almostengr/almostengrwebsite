---
title: Light Show Extender
---

## Problem

I wanted to have a way that visitors to the light show would be able to interact with the light show. 
While researching what others were doing, I found a way for this to be done.

## Solution

I found a project called Remote Falcon that allows visitors to do some of the similar things that I wanted. 
However, it did lack some features. 
Remote Falcon is maintained by one of the individuals in the light show community. It is a personal project
of his and he does not charge fees for the service.
I debated with whether to fork the existing repository and make changes 
to the existing code, but it was apprehensive about doing so. 

What I decided to do was to create my own jukebox implementation of the light show using my website. 
My implementation of this project, was designed to have only the features that I desired
to be included. This mainly consisted of users being able pick one of the songs that 
that they wanted to hear and the Falcon Pi Player, play those songs in the order
in which they were requested.

### Phase One

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
<a href="https://github.coma/almostengr/light-show-extender/issues" target="_blank">project repository</a>
on Github.

## Technology

* C# (C-sharp)
* CSS
* Falcon Player
* HTML
* Mkdocs
* MySQL
* PHP

## Source Code

Source code for this project can be found on 
<a href="https://github.com/almostengr/light-show-extender" target="_blank">Github</a>.
