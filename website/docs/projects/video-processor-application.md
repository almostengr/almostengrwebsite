---
title: Video Processor Application
---

## Problem

I wanted to have a way to render and batch process the videos that I create for my YouTube channels and 
other platforms without having to do a lot of manual editing. As you may or may not know, video editing 
takes a lot of time. Time that I could be using to complete more projects and creating more videos 
for the channel. The [previous version](/projects/kdenlive-to-youtube) of this application was written 
in Java. 

## Solution

When I changed jobs to doing work in C#, I decided to refactor the application to C#. 
The previous generation of this application was written in Java. Thus this was one of several projects that 
I refactored to improve and become more competent with C#. 

After learning more about 
[Domain Driven Design](#)
and other design patterns that exist within C#, I decided to create the new version of the application 
by using a worker service. Given that the videos would be automated, also meant that the structure of the
videos would have to be standardized, which improved the completion speed of the video creation process.

The first refactored version of this application was released in 2023.

## Technologies

* C# (for the application)
* FFMPEG (for video editing)
* Selenium Webdriver (for creating video thumbnails)
* MkDocs (static site generator that is used to create video thumbnails)
* Github (for version control)
* ChatGPT (assisted with coding)

## Source

* <a href="https://github.com/almostengr/videoprocessor" target="_blank">Github Repository</a>
