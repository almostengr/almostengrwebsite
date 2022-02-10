#!/bin/bash

########################################################################
# name:         resize_images.sh
# author:       Kenny Robinson, @almostengr
# description:  Batch resize images to be used on websites.
########################################################################

echo "Resizing images"

CENTERED="x=(w-text_w)/2:y=(h-text_h)/2"

for i in $(ls *jpg);
do 
    echo $i
    
    convert -resize 25% "${i}" "/var/tmp/${i}"

    ffmpeg -i "/var/tmp/${i}" -vf "drawtext=fontfile=arial.ttf:text='thealmostengineer.com':fontcolor=black@0.3:fontsize=h/10:${CENTERED}" -y "resized/${i}"

    rm "/var/tmp/${i}"
done

echo "Done resizing images"
