#!/bin/bash

# PWD=$(pwd)

# if [ "${PWD}" ]

OUTPUTFILE="blog/index.md"

echo "Need to be in the docs directory for this script to work"

echo "# Blog" > ${OUTPUTFILE}
echo "" >> ${OUTPUTFILE}

echo "Not sure what to read or looking for something to read? Then look no further." >> ${OUTPUTFILE}
echo "There's plenty to read here!" >> ${OUTPUTFILE}
echo "" >> ${OUTPUTFILE}

# OUTPUT=$(find ./* -name "*md" -type f -exec ls {} \; | grep -e technology -e lifestyle -e diy -e gardening | sed "s|\./|/|g" | sed "s|.md||g" | awk -F '/' '{print"* [" $4 " (" $3 ")](" $0 ")"}' | sort -r | grep -v "\[\.")

# (grep -r -e blog -e "^# " * | sed "s|# ||g" | sed "s|blog/blog||g" | sed "s|:|/|g" | awk -F '/' '{print "* [" $2 "](/"$1")"}' | grep -v index.md | sed "s|.md||g" ) >> ${OUTPUTFILE}

grep -r -e "^# " * | grep -e blog | grep -v -i -e index.md -e "draft" | sed -e "s|# ||g" -e "s|blog/blog||g" -e "s|:|/|g" -e "s|.md||g" | awk -F '/' '{print $3 "|* ["substr($3,0,10)": "$4" ("$2")](/"$1"/"$2"/"$3")"}' | sort -r | awk -F "|" '{print $2}' >> ${OUTPUTFILE}

