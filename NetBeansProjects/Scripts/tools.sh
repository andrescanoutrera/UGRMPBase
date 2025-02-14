#!/bin/bash
# @brief 

source ansiterminal.sh

echo "Loading tools ..."

# Check if folder exists, otherwise creates it or set it to default
# param $1 The folder to check
# param $2 The variable used to store $1 (reference)
function CheckFolder() {
    if [ ! $1 ] || [ ! $2 ]
    then
       alert "ERROR: Missing parameters to CheckFolder() "
       exit 1
    fi
	label "Checking folder $1\n"
	    FOLDER=/dev/null
    if [ ! -d $1 ]
    then
      label "Creating folder $1\n"
      mkdir $1
      FOLDER=$1
    else    	  
        FOLDER=$1
    fi
    eval "$2=$FOLDER"
}

# Check if folder exists, otherwise creates it or set it to default
# param $1 A description
# param $2 The folder to check
# param $3 The variable used to store $1 (reference)
function CheckFolderEcho() {
    regular "Checking folder "$2" ... $1\n"	
    FOLDER=/dev/null
    if [ ! -d $2 ]
    then
      label "Creating folder $2 ... $1\n"
      mkdir $2
      FOLDER=$2
    else    	  
        FOLDER=$2
    fi
    eval "$3=$FOLDER"
}

function existFolder {
    if [ ! $1 ] 
    then
	    alert "Missing parameters to existFolder"
       EndOfScript
    fi
    if [ ! -d $1 ]
    then
       alert "Folder $1 does not exist..."
       EndOfScript
    fi
}


# Some maths
# $3 = max($1, $2)
function Max {
	if [ 1 -eq "$(echo "$1 > $2" | bc -l)" ]
	then  
		 eval "$3=$1"
	else
		 eval "$3=$2"
	fi
}

# $3 = min($1, $2)
function Min {
	if [ 1 -eq "$(echo "$1 < $2" | bc -l)" ]
	then  
		 eval "$3=$1"
	else
		 eval "$3=$2"
	fi
}

# @brief Checks if a given folder is eligible to hold a NetBeans project
# $1 Folder to check
function isNBProject {
	if [ -d $1/nbproject ]
	then
		return 0
	else
		if [ -d $1/*/nbproject ]
		then
			cp -r $(ls -d $1/*)/* $1/
			return 0
		else
			return 1
		fi
	fi
}


# @brief Clean the restored project and its BASE folder
# $1 a NB Project folder
function clearNBProject {
	TARGET=$1
	# Remove previously restored project from other students
	if [ -d $TARGET ] && [ ${#TARGET} -gt 3 ] && [ -d $TARGET/nbproject ]
	then
		#echo "Clearing "$TARGET
#		read f
		rm -rf $TARGET
	fi
}

# @brief Extracts the student's name from Prado's zip file
# $1 The name of Prado's zip file
# $2 The variable to return student's fullname
# $3 The variable to return student's name (Optional parameter)
# $4 The variable to return student's surname (Optional parameter)
function doExtractName {
#	STUDENT_NAME="$(echo $1 | sed "s/^.*, //;s/_.*$//") $(echo $1 | sed "s/$DOWNLOAD\///;s/,.*$//")"
	zipFileName=$(basename "$1") # Añadido por Andrés Cano el 7/2/2024 porque no se extraía bien nombre y apellidos alumno
	zipDirectoryName=$(basename "$(dirname "$1")") # Añadido por Andrés Cano el 7/2/2024 porque no se extraía bien nombre y apellidos alumno
	zipName="$zipDirectoryName""/""$zipFileName" # Añadido por Andrés Cano el 7/2/2024 porque no se extraía bien nombre y apellidos alumno

	#N="$(echo $1 | sed "s/^.*, //;s/_.*$//;s/├С/Ñ/")" # Comentado por Andrés Cano el 7/2/2024 porque no se extraía bien nombre y apellidos alumno
	#SN="$(echo $1 |  sed "s/^[^\_]*\///;s/,.*$//;s/?/Ñ/;s/├С/Ñ/")" # Comentado por Andrés Cano el 7/2/2024 porque no se extraía bien nombre y apellidos alumno
	N="$(echo $zipName | sed "s/^.*, //;s/_.*$//;s/├С/Ñ/")" # Añadido por Andrés Cano el 7/2/2024 porque no se extraía bien nombre y apellidos alumno
	SN="$(echo $zipName |  sed "s/^[^\_]*\///;s/,.*$//;s/?/Ñ/;s/├С/Ñ/")" # Añadido por Andrés Cano el 7/2/2024 porque no se extraía bien nombre y apellidos alumno

	NAME=${N^^}
	SURNAME=${SN^^}
	eval "$2='$NAME $SURNAME'"
	if [ $4 ]
	then
		eval "$3='$NAME'"
		eval "$4='$SURNAME'"
	fi
}

# @brief Fakes student's makefiles. Replaces "their local references" with references to "../local" both
# for .h and .a
# $1 A Netbeans Project
function preprocessMakeProject {
	if isNBProject $1;
	then
		# Generic transformation of *local into ../locañ
		cp nbproject/Makefile-Debug.mk nbproject/mkd.mk
		cat nbproject/mkd.mk | sed "s/[\.\/][^ ]*[Ll]ocal/..\/local/g" > nbproject/Makefile-Debug.mk
		# Generic definition of library folder
		cp nbproject/Makefile-Debug.mk nbproject/mkd.mk
		cat nbproject/mkd.mk | sed "s/LDLIBSOPTIONS=/LDLIBSOPTIONS=-L..\/local\/lib /" > nbproject/Makefile-Debug.mk
		# Specific rule 1
		cp nbproject/Makefile-Debug.mk nbproject/mkd.mk
		cat nbproject/mkd.mk | sed "s/local\/h/local\/include/g" > nbproject/Makefile-Debug.mk
		# Specific rule 2
		cp nbproject/Makefile-Debug.mk nbproject/mkd.mk
		cat nbproject/mkd.mk | sed "s/local\/[^ ]*\/include/local\/include/g" > nbproject/Makefile-Debug.mk
		cp nbproject/Makefile-Debug.mk nbproject/mkd.mk
		cat nbproject/mkd.mk | sed "s/local\/[^li ]*\/lib\//local\/lib\//g" > nbproject/Makefile-Debug.mk
		# Specific rule 3
		cp nbproject/Makefile-Debug.mk nbproject/mkd.mk
		cat nbproject/mkd.mk | sed "s/\".*lib\//\"..\/local\/lib\//" | sed "s/: .*lib\//: ..\/local\/lib\//" > nbproject/Makefile-Debug.mk
	else
		printf "\n${RED}Netbeans project missing${WHITE}"
		exit 1
	fi
}

function Abort {
	if [ ! $1 ]
	then 
	   MSG="Aborting "
	else
		MSG=$1
	fi
	echo "${RED}$MSG${GRAY}"
	exit
}

