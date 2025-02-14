#!/bin/bash
MPREPO=
AUTOCORRECT_FOLDER=
clear
echo "AutoCorrect preconfigure"
echo "Loading modules ... "
PDIR=$(pwd)
DIR=$(dirname $0)
source $DIR/tools.sh
source $DIR/ansiterminal.sh

if [ ! -f $DIR/settings.sh ]
then
	highlight "First time preconfiguring...\n"
	cd $DIR
	cd ../..
	MPREPO=$(pwd)
	if ! doConfirm "Is this your MP REPO root folder $MPREPO? (y/n) ";
	then 
		inputLine "Please type your curent MP Repo: " MPREPO							
		if [ ! -d $MPREPO ]
		then
			alert "Folder $MPREPO does not exist"
			EndOfScript
		fi
	fi
	AUTOCORRECT_FOLDER=$PDIR
	if ! doConfirm "Is this your AutoCorrect workspace folder $PDIR? (y/n) ";
	then 
		inputLine "Please type your AutoCorrect workspace folder: " AUTOCORRECT_FOLDER							
		label "Checking $AUTOCORRECT_FOLDER\n"
		if [ ! -d $AUTOCORRECT_FOLDER ]
		then
			alert "Folder $AUTOCORRECT_FOLDER does not exist"
			EndOfScript
		fi
	fi
	label "Updating workspace in "$AUTOCORRECT_FOLDER"\n"
	label "Copying Scripts to "$AUTOCORRECT_FOLDER"\n"
	cp -rf $MPREPO/NetBeans/Scripts $AUTOCORRECT_FOLDER
	label "Copying MPTools to "$AUTOCORRECT_FOLDER"\n"
	cp -rf $MPREPO/NetBeans/MPTools $AUTOCORRECT_FOLDER
	label "Copying Genomes folder to "$AUTOCORRECT_FOLDER"\n"
	cp -rf $MPREPO/NetBeans/Genomes $AUTOCORRECT_FOLDER
	chmod ugo-w $AUTOCORRECT_FOLDER/Genomes
	chmod ugo-w $AUTOCORRECT_FOLDER/Genomes/*
	echo "MPREPO=$MPREPO" > $AUTOCORRECT_FOLDER/Scripts/settings.sh
	echo "AUTOCORRECT_FOLDER=$AUTOCORRECT_FOLDER" >> $AUTOCORRECT_FOLDER/Scripts/settings.sh
else
	source $DIR/settings.sh
	highlight "Preconfigure done\n"
fi

	


