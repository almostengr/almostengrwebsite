#!/bin/bash

####################################################################################
# DESCRIPTION: Check to see if there are any files that need to be commmitted. If 
# there are not any files, then the script will exit.
# AUTHOR: Kenny Robinson, @almostengr
# CREATED: 2021-06-06
####################################################################################

STATUSOUTPUT=$(git status)

if [[ ${STATUSOUTPUT} != *"nothing to commit, working tree clean"* ]]; then
    echo "Updates were found"

    git config user.name github-actions
    git config user.email github-actions@github.com
    git add .
    git commit -m "Auto commit latest content"
    git push
    exit 0
else
    echo "No updates were found"
    exit 1
fi