#!/bin/bash 

# Remove lines that begin with 0
# remove lines that are blank
# convert the text to uppercase

INPUTFILE=${1}
OUTPUTFILE=${INPUTFILE}.out

sed '/^0/ d' ${INPUTFILE} | sed '/^$/ d' | tr [a-z] [A-Z] > ${OUTPUTFILE}

# rename the output file to the input file

mv ${OUTPUTFILE} ${INPUTFILE}
