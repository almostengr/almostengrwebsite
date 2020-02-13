#!/bin/bash

TMPBLOGFILE="blog.tmp"
BLOGFILE="blog.md"
TMPINDEXFILE="index.tmp"
INDEXFILE="index.md"

echo "INFO: Need to be in the docs directory for this script to work"

BLOGLISTING=$(grep -r -e "^# " * | grep -e blog | grep -v -i -e index.md -e "draft" | sed -e "s|# ||g" -e "s|blog/blog||g" -e "s|:|/|g" -e "s|.md||g")

BLOGLISTMD=$(echo "${BLOGLISTING}" | awk -F '/' '{print $3 "|* ["substr($3,0,11)" - "$4" ("$2")](/"$1"/"$2"/"$3")"}' | sort -r | awk -F "|" '{print $2}' | grep -v "(Blog)")

BLOGLISTPAGE=$(echo "${BLOGLISTING}" | awk -F '/' '{print $3 "| <li><a href=\"/"$1"/"$2"/"$3"\">"substr($3,0,11)" - "$4"</a></li>"}' | sort -r | awk -F "|" '{print $2}' | grep -v "blog/Blog")

##### update index page 

head -n +19 ${INDEXFILE} > ${TMPINDEXFILE}
echo "${BLOGLISTMD}" | head -10 >> ${TMPINDEXFILE}

mv ${TMPINDEXFILE} ${INDEXFILE}

##### Update blog page

head -n +32 ${BLOGFILE} > ${TMPBLOGFILE}
# echo "${BLOGLISTPAGE}" >> ${TMPBLOGFILE}
echo '<div class="tab-content">' >> ${TMPBLOGFILE}
echo '<div class="tab-pane" id="diy" role="tabpanel" aria-labelledby="diy-tab">' >> ${TMPBLOGFILE}
echo '<ul>' >> ${TMPBLOGFILE}
# echo '' >> ${TMPBLOGFILE}
(echo "${BLOGLISTPAGE}" | grep "diy") >> ${TMPBLOGFILE}
# echo '' >> ${TMPBLOGFILE}
echo '</ul>' >> ${TMPBLOGFILE}
echo '</div>' >> ${TMPBLOGFILE}

echo '<div class="tab-pane" id="gardening" role="tabpanel" aria-labelledby="gardening-tab">' >> ${TMPBLOGFILE}
echo '<ul>' >> ${TMPBLOGFILE}
# echo '' >> ${TMPBLOGFILE}
(echo "${BLOGLISTPAGE}" | grep "gardening") >> ${TMPBLOGFILE}
# echo '' >> ${TMPBLOGFILE}
echo '</ul>' >> ${TMPBLOGFILE}
echo '</div>' >> ${TMPBLOGFILE}

echo '<div class="tab-pane" id="lifestyle" role="tabpanel" aria-labelledby="lifestyle-tab">' >> ${TMPBLOGFILE}
echo '<ul>' >> ${TMPBLOGFILE}
# echo '' >> ${TMPBLOGFILE}
(echo "${BLOGLISTPAGE}" | grep "lifestyle") >> ${TMPBLOGFILE}
# echo '' >> ${TMPBLOGFILE}
echo '</ul>' >> ${TMPBLOGFILE}
echo '</div>' >> ${TMPBLOGFILE}

echo '<div class="tab-pane active" id="technology" role="tabpanel" aria-labelledby="technology-tab">' >> ${TMPBLOGFILE}
echo '<ul>' >> ${TMPBLOGFILE}
# echo '' >> ${TMPBLOGFILE}
(echo "${BLOGLISTPAGE}" | grep "technology") >> ${TMPBLOGFILE}
# echo '' >> ${TMPBLOGFILE}
echo '</ul>' >> ${TMPBLOGFILE}
# echo "${TECHNOLOGYPOSTS}" >> ${TMPBLOGFILE}
echo '</div>' >> ${TMPBLOGFILE}

echo '</div>' >> ${TMPBLOGFILE}
mv ${TMPBLOGFILE} ${BLOGFILE}
