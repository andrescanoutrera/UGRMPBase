#!/bin/bash
# Author: Luis Castillo Vidal L.Castillo@decsai.ugr.es
VERSION=1.0
# Helpinfo
if [ -d ../Scripts ]
then
    source ../Scripts/doConfig.sh $*
else
   if [ -d ../../Scripts ]
   then
       source ../../Scripts/doConfig.sh $*
   else
    printf "\n${RED}Unable to find Scripts library${WHITE}"
    exit
   fi
fi

make clean
make test
xdg-open tests/TestReport.md



