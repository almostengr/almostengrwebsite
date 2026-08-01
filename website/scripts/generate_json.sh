#!/bin/bash

for filename in ../website/docs/*.md
do
    title=$(grep "title: " "${filename}" | awk -F ':' '{print $2}')
    author=$(grep "author: " "${filename}" | awk -F ':' '{print $2}')
    posted=$(grep "posted: " "${filename}" | awk -F ':' '{print $2}')
    keywords=$(grep "keywords: " "${filename}" | awk -F ':' '{print $2}')
    content=$(sed '1,/^---$/d' "${filename}")
    json_filename=$(sed 's/md/json/g' "${filename}")
done