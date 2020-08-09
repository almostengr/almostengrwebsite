#!/bin/bash

MISSPELLING=""
LINE=0
COUNTER=0

for filename in $(ls -1 *md)
do
# echo ${LINE}

MISSPELLING=$(cat ${filename} | aspell list -a | grep -e ,)

echo MS: ${MISSPELLING}

ERRORCOUNT=$(echo $MISSPELLING | wc -l)
echo Count $COUNT

LINE=$((${LINE} + ${ERRORCOUNT}))

# echo Errors: ${LINE}

COUNTER=$(($COUNTER + 1))

done

echo "Lines counted $COUNTER"
echo "Total errors: ${LINE}"


echo "LINES - ERRORS "$(($COUNTER - $LINE))

