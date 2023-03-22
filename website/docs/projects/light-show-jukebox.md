---
title: Light Show Jukeboxp
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

The second phase of this project will be creating the necessary scripts for the Falcon 
Pi Player to make calls to the API, get the next song information and to 
be able to clear the queue of previously requested songs.

## Technology

* CSS
* Falcon Pi Player
* HTML
* Mkdocs
* MySQL
* PHP

## Documentation

More information about this project can be found on the [Jukebox page](/jukebox) and on the 
[Light Show project page](/projects/light-show).
