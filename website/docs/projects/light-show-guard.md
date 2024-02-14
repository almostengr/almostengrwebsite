---
title: Light Show Guard
---

## Problem

Hobbyist that run Christmas and Halloween Light Shows, often have to be at home to monitor their
show for any and potential issues. One of which is when rain or snow starts falling, which can result in electrical shorts
occurring. Another is when winds get high, the risk of inflatables and taller props like mega trees 
can be knocked over or blown away. 

Someone had posted in one of the lighting groups about how people monitor their show when they are not at home. 
I shared some information about the [Light Show Extender](/projects/light-show-extender) project and what it 
looks like. I got a few responses saying that they wanted to use the software that I created for the show. However, 
I did not design that software to be used by the general public, although it was open source.

## Solution

After posting about this interaction online, several of my followers said that I should find a way to monetize 
this software solution. Thus this project was born. 

### System Architecture

The primary light show controller provides a status of what it is doing to the website. 
The Light Show Guard website receives said status and determines what the controller should do next, based 
upon the user selected options.
If there is rain, severe, or other adverse weather conditions 
where the show is located, the user will be notified of this when their show is running.


## Technology

* PHP
* HTML
* CSS
* JavaScript (Vanilla Javascript)
* MySQL
* Falcon Pi Player
* National Weather Service API
