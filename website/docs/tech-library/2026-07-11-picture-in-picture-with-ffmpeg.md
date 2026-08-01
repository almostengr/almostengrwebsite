---
title: Picture in Picture (PIP) with FFMPEG
author: Kenny Robinson
posted: 2026-07-11
categories: ffmpeg, automation, video editing
---

I post videos to my dash cam channel. Since upgrading the dash cam, I have 
front and rear cameras.  I wanted to be able to include the rear camera 
in the dash cam video that I post to the 
[Kenny Ram Dash Cam](#) YouTube Channel. 

For those that do not know, I do use automation with bash scripts to automate 
the majority of the video editing process.  I found that automating the video 
editing process, allowed me ot spend more time on doing other things. Like 
creating more videos. 

Since the dash cam can record front and rear, I wanted to able to have that 
in the video for viewers to see, but it still needed to be automated. Below 
is the code that I came up with in conjunction of using AI.

```bash
mergeFrontAndRearFiles() {
    ## merge front and rear files
    for frontVideo in *f*mp4
    do
        backVideo=$(echo $frontVideo | sed 's/f/b/g')

        /usr/bin/ffmpeg -i "${frontVideo}" -i "${backVideo}" -filter_complex "[1:v]scale=480:270[back];[0:v][back]overlay=W-w-20:H-h-20:format=auto" -c:v libx264 -preset veryfast -crf 23 -an -shortest "${frontVideo}.ts"
    done
}
```

In the script, I created a method called ```mergeFrontAndRearFiles()```. 
This is called later in the script.

The dash cam creates separate files for front and rear. Thus the script will 
loop over the front camera files. Because the front and rear camera files have 
almost the same file names, finding the rear camera file name is rather easy. 
In this case, the "f" is substituted with "b" to derive the rear camera file name.

Using ```ffmpeg```, those two separate files are combined into a single file. The output file 
is converted to the TS format, in case the resolution of the front and rear are different. 
I found that converting from MP4 format, to TS format, allows ffmpeg to merge videos together 
that have different frame rates.

It is an additional step in the rendering process, but it does allow for the video rendering 
to be fully automated.

## WNy not change the output file name?

Some will say that the front video file name should not be reused for the combined video file, 
and I would agree.  In this scenario, it is easier to use an existing file name with a different 
extension that to have to generate a new file name and make sure that the generated name is 
in the correct order when the file list is created. 

Later in the script, the files are added to a text file that is then used by FFMPEG to 
create a list of video files to concatenate. With the file name in the same order as the 
videos were recorded, reduces the possibility of the clips being put in the wrong order.
