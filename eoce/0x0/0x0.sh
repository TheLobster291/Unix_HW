#!/bin/bash
#setting up variables
	base=10

	upperBound=9

	lowerBound=1

#taking arguments
		if [ $# -eq 1 ]; then
		base=$1
		upperBound=${base-1}
		fi
	
		if [ $# -eq 2 ]; then
		base=$1
		upperBound=$2
		fi
		
		if [ $# -eq 3 ]; then
		base=$1
		upperBound=$2
		lowerBound=$3
		fi
#checking arguments for faults	
	if [ "$1" -gt 16 || "$1" -lt 2 ]; then
	echo "ERROR: invalid base" >&2
	exit
	fi
	
	if [ "$2" -gt 99 || "$2" -lt 0 ]; then
	echo "ERROR: invalid upper bound" >&2
	exit
	fi
	
	if [ "$3" -gt 99 || "$3" -lt 0 ]; then
	echo "ERROR: invalid lower bound" >&2
	exit
	fi

#printing top
	printf "%4s" " "
	
	if [  [ "$3" -lt "$2" ]; then
		while [ "$3" -le "$2" ]; then
			printf "%d"
