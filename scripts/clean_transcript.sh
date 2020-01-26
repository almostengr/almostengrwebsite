#!/bin/bash 

# Remove lines that begin with 0
# Also remove lines that are blank

sed '/^0/ d' ${1} | sed '/^$/ d'

