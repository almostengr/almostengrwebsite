#!/bin/bash 

# Remove lines that begin with 0
# Also remove lines that are blank
# ALso convert the text to uppercase

sed '/^0/ d' ${1} | sed '/^$/ d' | tr [a-z] [A-Z] > ${1}.out
