#!/bin/bash

# PWD=$(pwd)

# if [ "${PWD}" ]

echo "Need to be in the docs directory for this script to work"

echo "# Blog" > blog.md
echo "" >> blog.md

OUTPUT=$(find ./* -name "*md" -type f -exec ls {} \; | grep -e technology -e lifestyle -e diy -e gardening | sed "s|\./|/|g" | awk -F '/' '{print"* [" $3 " (" $2 ")](" $0 ")"}' | sort -r | grep -v "\[\.")

echo "${OUTPUT}" >> blog.md
