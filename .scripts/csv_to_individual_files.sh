#!/bin/bash

dos2unix mkconversion.csv

while read line
do
	echo "$line" | awk -F '";"' '{print $1}' >> $(echo $line | awk -F '";"' '{print $2}' | sed 's/"//g');
done < mkconversion.csv

