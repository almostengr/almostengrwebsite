#!/bin/bash

for filename in $(ls);
do
	sed 's/\"\#/\#/g' $filename > ${filename}2;

	# sed 's|<br />|\n|g' ${filename}2 > ${filename}3;

	cp ${filename}2 ${filename}

	rm *2
done

