#!/bin/bash

########################################################################
# name:         resize_images.sh
# author:       Kenny Robinson, @almostengr
# description:  Batch resize images to be used on websites.
########################################################################

echo "Resizing images"

CENTERED="x=(w-text_w)/2:y=(h-text_h)/2"

cd "/home/almostengineer/almostengrwebsite/Almostengr.AlmostengrWebsite/image_originals"

for i in  *jpg);
do
    echo "Working on file ${i}"

    # convert -resize 25% "${i}" "/var/tmp/${i}"

    cp "${i}" "/var/tmp/${i}"

    ffmpeg -y -hide_banner -loglevel error -i "/var/tmp/${i}" -vf "drawtext=fontfile=arial.ttf:text='thealmostengineer.com':fontcolor=black@0.2:fontsize=h/10:${CENTERED}" "/home/almostengineer/almostengrwebsite/Almostengr.AlmostengrWebsite/docs/images/${i}"

    rm "/var/tmp/${i}"
done

echo "Done resizing images"
