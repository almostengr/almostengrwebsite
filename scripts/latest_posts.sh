#!/bin/bash

TMPBLOGFILE="blog/index.tmp"
BLOGFILE="blog/index.md"
TMPINDEXFILE="index.tmp"
INDEXFILE="index.md"

echo "INFO: Need to be in the docs directory for this script to work"

BLOGLISTING=$(grep -r -e "^# " * | grep -e blog | grep -v -i -e index.md -e "draft" | sed -e "s|# ||g" -e "s|blog/blog||g" -e "s|:|/|g" -e "s|.md||g" | awk -F '/' '{print $3 "|* ["substr($3,0,10)": "$4" ("$2")](/"$1"/"$2"/"$3")"}' | sort -r | awk -F "|" '{print $2}')

head -n +16 ${BLOGFILE} > ${TMPBLOGFILE}
echo "${BLOGLISTING}" >> ${TMPBLOGFILE}
mv ${TMPBLOGFILE} ${BLOGFILE}

head -n +20 ${INDEXFILE} > ${TMPINDEXFILE}
echo "${BLOGLISTING}" | head -10 >> ${TMPINDEXFILE}
mv ${TMPINDEXFILE} ${INDEXFILE}

