#!/bin/bash

STATUSOUTPUT=$(git status)

if [[ ${STATUSOUTPUT} != *"nothing to commit, working tree clean"* ]]; then
    echo "Videos were found in todays feed"

    # git config user.name github-actions
    # git config user.email github-actions@github.com
    git add .
    git commit -m "Auto commit latest YouTube video as blog post"
    # git push

else
    echo "No videos were found for today"
    exit 0
fi