#!/bin/bash
if [ $1 ]
then
	if ! cmp -s ./tests/validation/$1.expected ./tests/output/$1.output;
	then
# wdiff -n -w $'\033[30;41m' -x $'\033[0m' -y $'\033[30;42m' -z $'\033[0m' ./tests/validation/$1.expected ./tests/output/$1.output
		wdiff -n  ./tests/output/$1.output ./tests/validation/$1.expected
	fi
elif [ $2 ]
then
	if ! cmp -s $1 $2;
	then
		wdiff -n  $1 $2
	fi
else
	echo "Call error. Please use one of the following calls:"
	echo "getDifferenceOutput.sh <testname>"
	echo "getDifferenceOutput.sh fileOutput fileValidation"
fi
	 
