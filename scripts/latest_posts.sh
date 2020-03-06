#!/bin/bash

TMPBLOGFILE="archives.tmp"
BLOGFILE="archives.md"
TMPINDEXFILE="index.tmp"
INDEXFILE="index.md"

TECHLISTFILE="technology.md"
TECHDESCRIPTION="All things related to computers, the internet, software, and web development."

LIFESTYLEFILE="lifestyle.md"
LIFESTYLEDESCRIPTION="Life is difficult enough. I feel that we can all learn from others and their experiences on this journey. I share stories and thoughts that I have learned along the way."

DIYFILE="diy.md"
DIYDESCRIPTION="I enjoy repairing and building things, including home improvement projects and car repairs."

GARDENINGFILE="gardening.md"
GARDENDESCRIPTION="Fresh food? Of course! Having a garden not only means that you have fresh food when you choose, but maintaining the garden is a great stress reliever."

EVENTFILE="events.md"
EVENTDESCRIPTION="List of upcoming and past events and presentations that I will be presenting at or hosting."

echo "INFO: Need to be in the docs directory for this script to work"

BLOGLISTING=$(grep -r -e "^# " * | grep -e '.md' | grep -e 'events/' -e 'technology/' -e 'diy/' -e 'gardening/' -e 'lifestyle/' | grep -v -i -e index.md -e "draft" | sed -e "s|# ||g" -e "s|:|/|g" -e "s|.md||g")

BLOGLISTMD=$(echo "${BLOGLISTING}" | awk -F '/' '{print "|### [" substr($2,0,11) " - " $3" ("$1")](/"$1"/"$2") "}' | sort -r | awk -F "|" '{print $2}')

BLOGLISTPAGE=$(echo "${BLOGLISTING}" | awk -F '/' '{print $2 "| * [" substr($2,0,11) " - " $3" ("$1")](/"$1"/"$2")"}' | sort -r | awk -F "|" '{print $2}')

##### update index page 

head -n +8 ${INDEXFILE} > ${TMPINDEXFILE}
echo "${BLOGLISTMD}" | head -15 >> ${TMPINDEXFILE}

mv ${TMPINDEXFILE} ${INDEXFILE}

##### Update archive page

head -n +17 ${BLOGFILE} > ${TMPBLOGFILE}
echo "${BLOGLISTPAGE}" >> ${TMPBLOGFILE}
mv ${TMPBLOGFILE} ${BLOGFILE}

echo "# DIY (Do It Yourself)" > ${DIYFILE}
echo "" >> ${DIYFILE}
echo "${DIYDESCRIPTION}" >> ${DIYFILE}
echo "" >> ${DIYFILE}
echo "${BLOGLISTPAGE}" | grep -e diy >> ${DIYFILE}

echo "# Events" > ${EVENTFILE}
echo "" >> ${EVENTFILE}
echo "${EVENTDESCRIPTION}" >> ${EVENTFILE}
echo "" >> ${EVENTFILE}
echo "${BLOGLISTPAGE}" | grep -e events >> ${EVENTFILE}

echo "# Gardening" > ${GARDENINGFILE}
echo "" >> ${GARDENINGFILE}
echo "${GARDENDESCRIPTION}" >> ${GARDENINGFILE}
echo "" >> ${GARDENINGFILE}
echo "${BLOGLISTPAGE}" | grep -e gardening >> ${GARDENINGFILE}

echo "# Lifestyle" > ${LIFESTYLEFILE}
echo "" >> ${LIFESTYLEFILE}
echo "${LIFESTYLEDESCRIPTION}" >> ${LIFESTYLEFILE}
echo "" >> ${LIFESTYLEFILE}
echo "${BLOGLISTPAGE}" | grep -e lifestyle >> ${LIFESTYLEFILE}

echo "# Technology" > ${TECHLISTFILE}
echo "" >> ${TECHLISTFILE}
echo "${TECHDESCRIPTION}" >> ${TECHLISTFILE}
echo "" >> ${TECHLISTFILE}
echo "${BLOGLISTPAGE}" | grep -e technology >> ${TECHLISTFILE}
