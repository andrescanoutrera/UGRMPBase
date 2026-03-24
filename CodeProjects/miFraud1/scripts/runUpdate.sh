#!/bin/bash
# Author: Luis Castillo Vidal L.Castillo@decsai.ugr.es
VERSION=1.0
# Helpinfo
HELPTEXT='# Script runUpdate.sh   \n'\
'+ It updates all new scripts in the ../Scripts folder and builds the folder structure of the project, creating new folders if they dont exist\n\n'

SCRIPT_DIR="$(cd "$(dirname "${BASH_SOURCE[0]}")" && pwd)"
#echo "El script está en: $SCRIPT_DIR"
cd $SCRIPT_DIR # Move to the scripts folder of the Project

# Load configuration & moves to the project root folder
if [ -d ../../Scripts ]
then
    cp ../../Scripts/settingsIDE.sh .
    source ../../Scripts/doConfig.sh $*
    cp ../Scripts/run*.sh ./scripts
    #sh ../Scripts/getProjectName.sh $IDE
else
    printf "\n${RED}Unable to find Scripts library"
    printf "${WHITE}"
fi

