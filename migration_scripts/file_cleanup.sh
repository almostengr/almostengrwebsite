#!/bin/bash

for filename in $(ls);
do

sed 's/\"\#/\#/g' $filename > ${filename}2;

sed 's|<br />|\
|g' ${filename}2 > ${filename}3;

cp ${filename}3 ${filename}

rm *2 *3

done

