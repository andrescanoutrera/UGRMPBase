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
make CXXFLAGS=-D__REPORT_ALL_TESTS__ test
xdg-open doc/markdown/TestDescription.md
