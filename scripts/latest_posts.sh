#!/bin/bash

TMPBLOGFILE="blog/index.tmp"
BLOGFILE="blog.md"
TMPINDEXFILE="index.tmp"
INDEXFILE="index.md"

echo "INFO: Need to be in the docs directory for this script to work"

BLOGLISTING=$(grep -r -e "^# " * | grep -e blog | grep -v -i -e index.md -e "draft" | sed -e "s|# ||g" -e "s|blog/blog||g" -e "s|:|/|g" -e "s|.md||g")

BLOGLISTPAGE=$(echo "${BLOGLISTING}" | awk -F '/' '{print $3 "|* ["substr($3,0,11)": "$4" ("$2")](/"$1"/"$2"/"$3")"}' | sort -r | awk -F "|" '{print $2}' | grep -v "(Blog)")

head -n +16 ${BLOGFILE} > ${TMPBLOGFILE}
echo "${BLOGLISTPAGE}" >> ${TMPBLOGFILE}
mv ${TMPBLOGFILE} ${BLOGFILE}

head -n +30 ${INDEXFILE} > ${TMPINDEXFILE}
echo "${BLOGLISTPAGE}" | head -10 >> ${TMPINDEXFILE}

mv ${TMPINDEXFILE} ${INDEXFILE}
