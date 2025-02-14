#!/bin/bash
# @brief 
# Uncompress Prado's zip assignments, extract student's information, extract Netbeans 
# Project, run make, run tests and keep a record of what happened in a final CSV summary
# Runs either as a interactive script, prompting for teacher's interactions or as 
# a batch script in background
# @author Luis Castillo Vidal L.Castillo@decsai.ugr.es
# @date March 2020
#
# @brief Initializes the summary variables & files
function cleanRecord {
	DO_STUDENT=NO
	DO_ZIP=NO
	DO_COMPILE=NO
	DO_BINARY=NO
	DO_TESTS=NO
	DO_TESTS_BASICS=NO
	DO_TESTS_INTERMEDIATE=NO
	DO_TESTS_ADVANCED=NO
	DO_VALGRIND_LEAKS=NO
	DO_VALGRIND_ACCESS=NO
	DO_VALGRIND_UNINIT=NO
	FAILED_TESTS=""
	TOTAL=0
	PASSED=0
	PERCENT1=0
	PERCENT2=0
	PERCENT3=0
	printf "\n${YELLOW}$(date)\n" > $SINGLEREPORT
}


# @brief Show final CSV file reporting the results
function showReport {
	more $SINGLEREPORT;
	if [ "$INTERACTIVE" == "YES" ]
	then
		if [ "$DO_TESTS" == "NO" ] 
		then
			if doConfirm "Press [Y] to execute manually ";
			then
				cd $NETBEANSPROJECT
				if doConfirm "Press [Y] to patch the code first";
				then
					echo "Patching the code"
					patchSource $ASSIGNMENT
					make 
				fi
				eval "$BIN"
				cd $ROOT
			fi
		fi
		eval "$EDITOR $NETBEANSPROJECT/src/*.cpp $NETBEANSPROJECT/include/*.h"
		doConfirm "Press [RETURN] to continue"
	fi
}



# @brief Process the zip downloaded from Prado, extracts useful information like student's names
# $1 zip filename in Prado
function extractData {
	# Extracs student's name from zip filename
	doExtractName "$1" STUDENT_FULLNAME
	printf "\n\n${YELLOW}%%%%%% Report for $STUDENT_FULLNAME %%%%%%%%%%%%%%%%%%%%%%%%%%\n" >> $SINGLEREPORT
	DO_STUDENT=YES
	
#	if [ "$JPLAG" == "YES" ]
#	then
#		unzip "$1" $FILES -d $ROOT/JPlag/"$NAME $SURNAME"/
#		return 0
#	fi
	printf "\n${GREEN}[Zip   ] " | tee  -a  $SINGLEREPORT
        if [ ! -d $NETBEANSPROJECT ]
        then
            mkdir $NETBEANSPROJECT
        fi
	clearNBProject $NETBEANSPROJECT
#	cp -rf $TEMPLATEPROJECT $NETBEANSPROJECT
#	echo "Unzipping student project from "$zip" to "$STUDENTPROJECT	
	clearNBProject $STUDENTPROJECT
	unzip -q -o "$zip" -d $STUDENTPROJECT
   # The zipped assignement must follow the required structure and unfold into a valid
	# Netbeans project. Otherwise it is rejected
        tmpdir=$STUDENTPROJECT/*
	mv $tmpdir/* $STUDENTPROJECT
	if [ ! -d $NETBEANSPROJECT ]
	then
		mkdir $NETBEANSPROJECT
	fi
	cp -r $TEMPLATEPROJECT/* $NETBEANSPROJECT

	rm -r $NETBEANSPROJECT/src/*.cpp # Introducido 15/6/2023 para que borre los cpp de Teacher

	if ! isNBProject $NETBEANSPROJECT;
	then
		DO_ZIP=NO				
		printf "\n${RED}[FAILED] Zip file" | tee  -a  $SINGLEREPORT
		res=1
	else
		printf "\n${GREEN}[    OK]"| tee  -a  $SINGLEREPORT
		DO_ZIP=YES
		res=0
	fi
	# Patch student sources
        
   	fileheader=include/Kmer.h
	if [ -f $STUDENTPROJECT/$fileheader ]
	then
		cat $STUDENTPROJECT/$fileheader | sed s/'public:'/'public: inline std::string inspectN() const { return  std::to_string(mphash((const unsigned char*) _text.c_str(), _text.size())); }  inline std::string inspectT() const {return  _text;}'/ | sed s/'class Kmer{'/'class Kmer {'/ | sed s/'class Kmer {'/'#include \"MPTools.h\"\nclass Kmer {'/ > $NETBEANSPROJECT/$fileheader
   	fi

   	fileheader=include/KmerFreq.h
	if [ -f $STUDENTPROJECT/$fileheader ]
	then
		cat $STUDENTPROJECT/$fileheader | sed s/'public:'/'public: inline std::string inspectN() const { std::string text = this->inspectT();  return std::to_string(mphash((const unsigned char*) text.c_str(), text.size())); } inline std::string inspectT() const { return std::string(this->_kmer.inspectT()) + " " + std::to_string(_frequency); }'/ | sed s/'class KmerFreq{'/'class KmerFreq {'/ | sed s/'class KmerFreq {'/'#include \"MPTools.h\"\nclass KmerFreq {'/ > $NETBEANSPROJECT/$fileheader
   	fi

	fileheader=include/Profile.h
	if [ -f $STUDENTPROJECT/$fileheader ]
	then
	    cat $STUDENTPROJECT/$fileheader | sed s/'public:'/'public: inline std::string inspectN() const { std::string text = this->inspectT();  return std::to_string(mphash((const unsigned char*) text.c_str(), text.size())); } inline std::string inspectT() const { std::string result = this->_profileId + " " + std::to_string(this->_size) + " "; for (int i = 0; i<this->_size; i++)  result += this->_vectorKmerFreq[i].inspectT() + " ";  return result; }'/ | sed s/'class Profile{'/'class Profile {'/ | sed s/'class Profile '/'#include \"MPTools.h\"\nclass Profile '/ > $NETBEANSPROJECT/$fileheader
	fi

	fileheader=include/KmerCounter.h
	if [ -f $STUDENTPROJECT/$fileheader ]
	then
	    cat $STUDENTPROJECT/$fileheader | sed s/'class KmerCounter{'/'class KmerCounter {'/ |  sed s/'class KmerCounter {'/'class KmerCounter {\n public: inline std::string inspectN() const {  std::string text = this->inspectT();  return std::to_string(mphash((const unsigned char*) text.c_str(), text.size())); } inline std::string inspectT() const { std::string result =  this->_allNucleotides + " " + std::to_string(this->_k) + " ";  for (int row = 0; row<this->getNumRows(); row++) for (int column = 0; column<this->getNumCols(); column++) result += std::to_string(_frequency[row][column]) + " "; return result; }'/ | sed s/'class KmerCounter{'/'class KmerCounter {'/ | sed s/'class KmerCounter '/'#include \"MPTools.h\"\nclass KmerCounter '/  > $NETBEANSPROJECT/$fileheader
	fi
   
   	fileheader=include/ArrayKmerFreqFunctions.h
	if [ -f $STUDENTPROJECT/$fileheader ]
	then
   	    cp $STUDENTPROJECT/$fileheader $NETBEANSPROJECT/$fileheader
   	fi

   	#cd $STUDENTPROJECT/src/
   	pushd $STUDENTPROJECT/src
   	for filesource in *.cpp
   	do
	    if [ -f $filesource ]
	    then
	    #Las llamadas a exit(1) se comentan pues cortarían Autocorrect.sh si ocurre en un test de unidad
		#cat $filesource | sed s:'exit(1);':'exit(0);': >  $NETBEANSPROJECT/src/$filesource

		#Se copia el fichero cpp del alumno sin tocar nada. Antes se comentaban las llamadas a exit(1) o se sustituían por exit(0)
		#Ahora podría ocurrir que los tests de un alumno se corten si al ejecutar algún test de unidad, el alumno ejecuta exit()
		cp $filesource  $NETBEANSPROJECT/src
	    fi
   	done
   	popd
   	
   	# This is for ParcialA and ParcialB
   	# Copy the file VectorDinamico.h provided by the student
	fileheader=include/VectorDinamico.h
	if [ -f $STUDENTPROJECT/$fileheader ]
	then
   	    cp $STUDENTPROJECT/$fileheader $NETBEANSPROJECT/$fileheader
   	fi
}

# @brief Executes clean&build manually over the faked makefile
function makeProject {
	if [ ! $1 ]
	then
		EndOfScript
	fi
	cd $1
	printf "\n${GREEN}[Build ]" | tee  -a  $SINGLEREPORT
	#rm -r dist/* build/*
	#make -s clean > $SINGLEREPORT.make
	touch src/*.cpp

	# Compile the project
	#make &> $SINGLEREPORT.make
	make CONF=LEARN &> $SINGLEREPORT.make
	#make CONF=JOIN &>> $SINGLEREPORT.make
	make CONF=CLASSIFY &>> $SINGLEREPORT.make

	if grep --quiet -i "error" $SINGLEREPORT.make;
	then
		DO_COMPILE=NO
		printf "\n${RED}[FAILED]\n" | tee  -a  $SINGLEREPORT
		echo "${GRAY}" >> $SINGLEREPORT
		grep -e "\*\*\*" -e "fail" -e "fallo" $SINGLEREPORT.make | tee  -a  $SINGLEREPORT
		res=1
	else
		DO_COMPILE=YES
		printf "\n${GREEN}[    OK]\n"| tee  -a  $SINGLEREPORT
		res=0
	fi
#	printf "${WHITE}COMPILE = $DO_COMPILE\n${BLUE}" >> $SINGLEREPORT
	#cat $SINGLEREPORT.make >> $SINGLEREPORT
	return $res
}

# @brief Checks if makefile finally ended up with a valid binary file
function findBinary {
	printf "${GREEN}[Binary]"| tee  -a  $SINGLEREPORT

	#BIN=$(grep "g++[^ ]*[ \t]*-o" $SINGLEREPORT.make | sed "s/^.*-o //;s/ build.*$//")
	BIN1=./dist/LEARN/GNU-Linux/LEARN
	BIN2=./dist/JOIN/GNU-Linux/JOIN
	BIN3=./dist/CLASSIFY/GNU-Linux/CLASSIFY

	#if [ ! $BIN ]
	#if [ ! $BIN1 ] ||  [ ! $BIN2 ] || [ ! $BIN3 ]
	if [ ! $BIN1 ] || [ ! $BIN3 ]
	then
		DO_BINARY=NO
		printf "\n${RED}[FAILED] Binary missing" | tee  -a  $SINGLEREPORT
		res=1
	else
		DO_BINARY=YES
		printf "\n${GREEN}[    OK]" | tee  -a  $SINGLEREPORT
		res=0
	fi
#	printf "${WHITE}BINARY = $DO_BINARY\n${BLUE}" >> $SINGLEREPORT
#	ls -la  $BIN >> $SINGLEREPORT
	return $res
}

# Summarizes possible error found by Valgrind
function summaryValgrind {
	# Minor mistakes
	for anomaly in "NO_INIT" 
	do
		NTIMES=$(grep -i "$anomaly" $TESTS | wc -l)
		if [ $NTIMES -gt 0 ]
		then
			printf "${RED} $anomaly:  $NTIMES occurrences\n" |tee -a $SINGLEREPORT
			DO_VALGRIND_UNINIT=YES
		else
			printf "${BLUE} $anomaly:  none \n" >> $SINGLEREPORT
		fi
	done
	# Major mistakes
	for anomaly in "BAD_READ" "BAD_WRITE"  
	do
		NTIMES=$(grep -i "$anomaly" $TESTS  | wc -l)
		if [ $NTIMES -gt 0 ]
		then
			printf "${RED} $anomaly:  $NTIMES occurrences\n" |tee -a $SINGLEREPORT
			DO_VALGRIND_ACCESS=YES
		else
			printf "${BLUE} $anomaly:  none \n" >> $SINGLEREPORT
		fi
	done
	for anomaly in "MEM_LEAK" "CORE_DUMP"
	do
		NTIMES=$(grep -i "$anomaly" $TESTS | wc -l)
		if [ $NTIMES -gt 0 ]
		then
			printf "${RED} $anomaly:  $NTIMES occurrences\n" |tee -a $SINGLEREPORT
			DO_VALGRIND_LEAKS=YES
		else
			printf "${BLUE} $anomaly:  none \n" >> $SINGLEREPORT
		fi
	done
}


# @brief Run fresh local tests instead of student's ones
function doTestsScripts {
	cd $STUDENTPROJECT
	if [ "$DO_BINARY" == "NO" ]
	then
		DO_TESTS=NO
		#printf "${RED}[FAILED] Software tests\n"
		#printf "${WHITE}Trying to change main.cpp\n"
		#cp $ROOT/data/mp_main.cpp $NETBEANSPROJECT/src/main.cpp
		#makeProject
		#./scripts/doTests.sh
		res=1
	else
		printf "\n${GREEN}[Tests ] \n" | tee  -a  $SINGLEREPORT
#		make -s test &>  $TESTS	
		#make test | tee -a  $TESTS		
                scripts/runTest.sh | tee  -a  $SINGLEREPORT
                return
		cat tests	

		if  grep -q "[==========].*test suites.*ms total" $TESTS;
		then
			TOTAL=$(grep  "\[==========\] Running"  $TESTS |awk '{ print $3}')			
			PASSED=$(grep  "\[  PASSED  \]" $TESTS |awk '{ print $4}')
			TOTAL1=$(grep  "tests from T1_.*ms.*"  $TESTS |awk '{ print $2}')
			TOTAL2=$(grep  "tests from T2_.*ms.*"  $TESTS |awk '{ print $2}')
			TOTAL3=$(grep  "tests from T3_.*ms.*"  $TESTS |awk '{ print $2}')
			FAIL1=$(grep -e FAILED -e SKIPPED $TESTS |grep  "T1_.*ms" | wc -l)
			FAIL2=$(grep -e FAILED  -e SKIPPED $TESTS |grep  "T02_.*ms" | wc -l)
			FAIL3=$(grep -e FAILED  -e SKIPPED $TESTS |grep  "T03_.*ms" | wc -l)
			PERCENT1=$(echo "scale=0 ; ($TOTAL1 - $FAIL1) * 100 / $TOTAL1" | bc -l)
			PERCENT2=$(echo "scale=0 ; ($TOTAL2 - $FAIL2) * 100 / $TOTAL2" | bc -l)
			PERCENT3=$(echo "scale=0 ; ($TOTAL3 - $FAIL3) * 100 / $TOTAL3" | bc -l)
			echo
			echo "$PASSED Total tests passed out of $TOTAL" | tee  -a  $SINGLEREPORT
			echo "Coverage Tests Basic Level $PERCENT1" | tee  -a  $SINGLEREPORT
			echo "Coverage Tests Intermediate Level $PERCENT2"| tee  -a  $SINGLEREPORT
			echo "Coverage Tests Advanced Level $PERCENT3"| tee  -a  $SINGLEREPORT
			if  [ "$TOTAL" == "$PASSED" ]
			then
				DO_TESTS=YES
				FAILED_TESTS=""
				printf "${GREEN}[    OK] \n" | tee  -a  $SINGLEREPORT
			else
				DO_TESTS=NO
				FAILED_TESTS=$(grep "FAILED" $TESTS)
				printf "\n${RED}[FAILED]" | tee  -a  $SINGLEREPORT			
				printf "\n${GRAY}" >> $SINGLEREPORT
				cat $TESTS >> $SINGLEREPORT
				summaryValgrind
			fi
			FAILED=$(grep -e "FAILED" $TESTS | sed -r 's:[*]+::g;s: \| FAILED \| : :;s:\|::g;s:^ :(:;s:  \_:) :' | tr '\n' ' ')
			SKIPPED=$(grep -e "SKIPPED" $TESTS | sed -r 's:[*]+::g;s: \| SKIPPED \| : :;s:\|::g;s:^ :(:;s:  \_:) :' | tr '\n' ' ')
			FAILED_TESTS="$FAILED $SKIPPED"
			grep -e "FAILED" -e "SKIPPED" $TESTS
			#printf "${GREEN}[  OK  ] Software tests\n"
			res=0
		fi
	fi
#	printf "${WHITE}TESTS = $DO_TESTS\n" >> $SINGLEREPORT
#	if [ "$DO_TESTS" == "NO" ]
#	then
#		summaryValgrind
#		cat  $NETBEANSPROJECT/tests/.report >> $SINGLEREPORT
#	fi
	return $res
}

function doTestsTDD {
	cd $NETBEANSPROJECT
	rm -f $NETBEANSPROJECT/tests/output/*
	rm $TESTS
	if [ "$DO_BINARY" == "NO" ]
	then
		DO_TESTS=NO
		printf "\n${RED}[FAILED]" | tee  -a  $SINGLEREPORT
		#printf "${RED}[FAILED] Software tests\n"
		#printf "${WHITE}Trying to change main.cpp\n"
		#cp $ROOT/data/mp_main.cpp $NETBEANSPROJECT/src/main.cpp
		#makeProject
		#./scripts/doTests.sh
		res=1
	else
		printf "\n${GREEN}[Tests ] \n" | tee  -a  $SINGLEREPORT
#		make -s test &>  $TESTS	
		echo "" > $TESTS
		make clean
		rm $TESTREPORT
		#make test | tee -a  $TESTS	
		timeout 200 make CONF=LEARN test | tee -a  $TESTS
		
		if [ "$HEADER_REPORT" == "NO" ]
		then
			HEADER_REPORT=YES
			
			printf "NAME\tPASS ZIP\tCOMPILE\tGOOD BINARY\tPASS TESTS\t UNINITIALIZED USE\tACCESS OUT OF BOUNDS\tMEMORY LEAKS\t TESTS BÁSICOS\t TESTS INTERMEDIOS\tTESTS AVANZADOS\t$(cat $NETBEANSPROJECT/tests/output/TestReport_head.csv | head -2 | tail -1)\n">> $CSVREPORT 
		fi

		if  grep -q "[==========].*test suites.*ms total" $TESTS;
		then
			TOTAL=$(grep  "\[==========\] Running"  $TESTS |awk '{ print $3}')			
			PASSED=$(grep  "\[  PASSED  \]" $TESTS |awk '{ print $4}')
			TOTAL1=$(grep  "tests from T01_.*ms.*"  $TESTS |awk '{ print $2}')
			TOTAL2=$(grep  "tests from T02_.*ms.*"  $TESTS |awk '{ print $2}')
			TOTAL3=$(grep  "tests from T03_.*ms.*"  $TESTS |awk '{ print $2}')
			FAIL1=$(grep -e FAILED -e SKIPPED $TESTS |grep  "T01.*ms)" | wc -l)
			FAIL2=$(grep -e FAILED  -e SKIPPED $TESTS |grep  "T02.*ms)" | wc -l)
			FAIL3=$(grep -e FAILED  -e SKIPPED $TESTS |grep  "T03.*ms)" | wc -l)
			PERCENT1=$(echo "scale=0 ; ($TOTAL1 - $FAIL1) * 100 / $TOTAL1" | bc -l)
			PERCENT2=$(echo "scale=0 ; ($TOTAL2 - $FAIL2) * 100 / $TOTAL2" | bc -l)
			PERCENT3=$(echo "scale=0 ; ($TOTAL3 - $FAIL3) * 100 / $TOTAL3" | bc -l)
			if  [ "$TOTAL" == "$PASSED" ]
			then
				DO_TESTS=YES
				FAILED_TESTS=""
				printf "${GREEN}[    OK] \n" | tee  -a  $SINGLEREPORT
			else
				DO_TESTS=NO
				FAILED_TESTS=$(grep "FAILED" $TESTS)
				printf "\n${RED}[FAILED]" | tee  -a  $SINGLEREPORT			
				printf "\n${GRAY}" >> $SINGLEREPORT
				cat $TESTS >> $SINGLEREPORT
				summaryValgrind
			fi
			echo
			echo "$PASSED Total tests passed out of $TOTAL" | tee  -a  $SINGLEREPORT

			echo "Failed Tests Basic Level $FAIL1" | tee  -a  $SINGLEREPORT
			echo "Failed Tests Intermediate Level $FAIL2"| tee  -a  $SINGLEREPORT
			echo "Failed Tests Advanced Level  $FAIL3"| tee  -a  $SINGLEREPORT

			echo "Coverage Tests Basic Level $PERCENT1" | tee  -a  $SINGLEREPORT
			echo "Coverage Tests Intermediate Level $PERCENT2"| tee  -a  $SINGLEREPORT
			echo "Coverage Tests Advanced Level $PERCENT3"| tee  -a  $SINGLEREPORT
			FAILED=$(grep -e "FAILED" $TESTS | sed -r 's:[*]+::g;s: \| FAILED \| : :;s:\|::g;s:^ :(:;s:  \_:) :' | tr '\n' ' ')
			SKIPPED=$(grep -e "SKIPPED" $TESTS | sed -r 's:[*]+::g;s: \| SKIPPED \| : :;s:\|::g;s:^ :(:;s:  \_:) :' | tr '\n' ' ')
			FAILED_TESTS="$FAILED $SKIPPED"
			grep -e "FAILED" -e "SKIPPED" $TESTS
			#printf "${GREEN}[  OK  ] Software tests\n"
			res=0
		fi
	fi
#	printf "${WHITE}TESTS = $DO_TESTS\n" >> $SINGLEREPORT
#	if [ "$DO_TESTS" == "NO" ]
#	then
#		summaryValgrind
#		cat  $NETBEANSPROJECT/tests/.report >> $SINGLEREPORT
#	fi
	return $res
}

function doTestsLab {
	cd $NETBEANSPROJECT
	if [ "$DO_BINARY" == "NO" ]
	then
		DO_TESTS=NO
		res=1
	else
		cd $NETBEANSPROJECT
		printf "\n${GREEN}[Valida] $BIN \n" | tee  -a  $SINGLEREPORT
		timeout 5 valgrind --leak-check=full $BIN &> $TESTS
		summaryValgrind
		FILESOL=$(grep "Fichero: " $TESTS |sed 's/Fichero: //')
		CLEAN=$(grep "ERROR SUMMARY: 0" $TESTS | wc -l)
		SALIDA=$(diff $NETBEANSPROJECT/data/salida.dat $NETBEANSPROJECT/data/$FILESOL.sol | wc -l)
		if  [ "$CLEAN" == "1" ] && [ "$SALIDA" == "0" ]
		then
			DO_TESTS=YES
			FAILED_TESTS=""
			printf "${GREEN}[    OK] \n" | tee  -a  $SINGLEREPORT
		else
			DO_TESTS=NO
			FAILED_TESTS=$(grep "FAILED" $TESTS)
			printf "\n${RED}[FAILED]" | tee  -a  $SINGLEREPORT			
			printf "\n${GRAY}" >> $SINGLEREPORT
			cat $TESTS >> $SINGLEREPORT
			echo "salida.dat" >> $SINGLEREPORT
			diff $NETBEANSPROJECT/data/salida.dat $NETBEANSPROJECT/data/$FILESOL.sol >> $SINGLEREPORT
		fi
		res=0
	fi
	return $res
}
  

#@brief Summarizes the Review before proceeding, if interactive, otherwise it summarizes and go
function doSummarize() {
	clear
	echo "Checking for new students ..."
	if [ ! -f $KNOWN_NSTUDENTS ] 
	then 
		echo "0" > $KNOWN_NSTUDENTS
	fi
  	if [ ! "$(cat $KNOWN_NSTUDENTS)" == "$(ls $DOWNLOAD/*/*.zip | wc -l)" ]
	then
		NUM_STUDENTS=$(ls $DOWNLOAD/*/*.zip | wc -l)
		COUNT=1
		PB_X=1
		PB_Y=2
		PB_MAX=$NUM_STUDENTS
		PB_WIDTH=$PB_MAX
		PB_BACKGROUND=$WHITE
		PB_COLOR=$BLUE
		PB_BACKGROUND=$LIGHTGRAY
		PB_LABEL="Searching..."
		for zip in $DOWNLOAD/*/*.zip
		do 
			PB_COUNT=$COUNT
			PB_Show
			COUNT=$[COUNT + 1]	
			doExtractName "$zip" STUDENT_FULLNAME
			printf "${LBLUE}$STUDENT_FULLNAME                         \n"
		done
		echo $NUM_STUDENTS > $KNOWN_NSTUDENTS
	else 
		NUM_STUDENTS=$(cat $KNOWN_NSTUDENTS) 
	fi
	printf "${WHITE}Number of assignments found in $1 : $NUM_STUDENTS\n"
        pressReturn

}

#@brief Perform the review of one student
function PerformReview {
	# If make succeeds
	if makeProject $NETBEANSPROJECT;
	then
		# And there is a valid binary
		if findBinary;
		then
			# And pass the fresh tests
			doTestsTDD;
			echo
		fi
	fi
	pressReturn
}

#@brief Decompress the zip project and Perform the review of one student
function ExtractDataAndPerformReview {
	# If zip is a good one
	if extractData "$1";
	then
		PerformReview
	fi
}

function PerformReviewLab {
	# If zip is a good one
	if extractData "$1";
	then
		if [ "$REVIEWCODE" == "YES" ] 
		then 
			gedit $NETBEANSPROJECT/src/*.cpp 
			doConfirm "Press [Y] to continue"
			return
		fi
		# And make succeeds
		if makeProject "$1";
		then 
			# And there is a valid binary
			if findBinary;
			then
				# And pass the fresh tests
				doTestsLab;									
				echo
			fi
		fi
	fi
	if [ "$INTERACTIVE" == "YES" ]
	then
	   doConfirm "Press [Y] to continue"
	fi

}

# @brief Main function, specific for each assignment
# $1 Practicax
function review {
	if [ -d $1 ]
	then
		doSummarize $1
		if [ "$INTERACTIVE" == "YES" ]
		then
			preessRETURN
		else
			rm $CURRENT
		fi
		echo "" > $CSVREPORT
		HEADER_REPORT=NO
#		echo -e "NAME\tPASS ZIP\tCOMPILE\tGOOD BINARY\tPASS TESTS\t UNINITIALIZED USE\tACCESS OUT OF BOUNDS\tMEMORY LEAKS\t %TESTS LEVEL 1\t %TESTS LEVEL 2\t%TESTS LEVEL 3\t" > $CSVREPORT
#		T1\tT2\tT3\tT4\tT5\tT6\tT7\tT8\tT9\tT10\tT11\tT12\tT13\tT14\tT15\tT16\tT17\tT18\tT19\t "
		printf "\n${YELLOW}$(date)\n"  > $FULLREPORT
		# Uncompress every student's assignment and proceed to review
		if [ -e $CURRENT ]
		then
			NEXT=$(cat $CURRENT)
		else
			NEXT=0
		fi
		PB_MAX=$NUM_STUDENTS
		PB_WIDTH=$PB_MAX
		PB_BACKGROUND=$WHITE
		PB_COLOR=$BLUE
		PB_LABEL="Reviewing "
		COUNT=0
		ZIPS=($DOWNLOAD/*/*.zip)

		while ( true )
		do
			#pressReturn
			clear
			zip=${ZIPS[${COUNT}]}
			cleanRecord
			doExtractName "$zip" STUDENT_FULLNAME NAME SURNAME
			PB_LABEL="Reviewing $STUDENT_FULLNAME"
			PB_COUNT=$[COUNT + 1]
			PB_Show
			printf "\n"
			if [ "$CONTINUE" == "YES" ] && [ $COUNT -lt $NEXT ]
			then						
				COUNT=$[COUNT + 1]
			else
				if [ "$INTERACTIVE" == "YES" ]
				then
					doMenu e Exit n Next p Previous c Check r Review_code C Check_RebuildProject l Load_in_Rebuild
					CHOICE=$?
					if [ $CHOICE -eq 0 ]
					then
						break;
					elif  [ $CHOICE -eq 1 ]
					then
						COUNT=$[COUNT + 1] 
						Min $COUNT $[NUM_STUDENTS - 1] COUNT
					elif  [ $CHOICE -eq 2 ]
					then
						COUNT=$[COUNT - 1] 
						Max 0 $COUNT COUNT
					elif [ $CHOICE -eq 4 ]
					then 
						# If zip is a good one
						if extractData "$zip";
						then
							# And make succeeds
							if makeProject $STUDENTPROJECT;
							then 
								gedit $STUDENTPROJECT/src/*.cpp 
                                                                
								continue
							fi
						fi
					fi
				fi
				if [ "$INTERACTIVE" == "YES" ] && [ $CHOICE -eq 3 ] || [ "$INTERACTIVE" == "NO" ]
				then
					ExtractDataAndPerformReview "$zip"
					if [ "$DO_BINARY" == "YES" ]
					then
						TDD="$(head $NETBEANSPROJECT/tests/output/TestReport_body.csv | tail -1)"
					else
						TDD=""
					fi
					printf "$STUDENT_FULLNAME\t$DO_ZIP\t$DO_COMPILE\t$DO_BINARY\t$DO_TESTS\t$DO_VALGRIND_UNINIT\t$DO_VALGRIND_ACCESS\t$DO_VALGRIND_LEAKS\t$PERCENT1\t$PERCENT2\t$PERCENT3\t$TDD\n">> $CSVREPORT
					if [ "$DO_BINARY" == "YES" ]
					then
						cp $TESTREPORT ${TEST_REPORTS_FOLDER}/TestReport_"${SURNAME} ${NAME}".md
					fi

#head $NETBEANSPROJECT/tests/output/TestReport_body.csv >> $CSVREPORT
#printf "\n"
					if [ "$INTERACTIVE" == NO ]
					then
						# Save record in the CSV file
						COUNT=$[COUNT + 1] 
						if [ $COUNT -ge $NUM_STUDENTS ]
						then
							break;
						fi
					fi
				fi	
				if [ "$INTERACTIVE" == "YES" ] && [ $CHOICE -eq 5 ] #[C] Check Rebuild Project
				then
				   echo  $STUDENT_FULLNAME
				   echo $NETBEANSPROJECT
				   PerformReview
					if [ "$DO_BINARY" == "YES" ]
					then
						TDD="$(head $NETBEANSPROJECT/tests/output/TestReport_body.csv | tail -1)"
					else
						TDD=""
					fi
					printf "$STUDENT_FULLNAME\t$DO_ZIP\t$DO_COMPILE\t$DO_BINARY\t$DO_TESTS\t$DO_VALGRIND_UNINIT\t$DO_VALGRIND_ACCESS\t$DO_VALGRIND_LEAKS\t$PERCENT1\t$PERCENT2\t$PERCENT3\t$TDD\n">> $CSVREPORT
					if [ "$DO_BINARY" == "YES" ]
					then
						cp $TESTREPORT ${TEST_REPORTS_FOLDER}/TestReport_"${SURNAME} ${NAME}".md
					fi
				fi
				if [ "$INTERACTIVE" == "YES" ] && [ $CHOICE -eq 6 ] #[l] load in Rebuild
				then
					extractData "$zip";
					pressReturn
				fi
			fi
			cd $ROOT
			cat $SINGLEREPORT >> $FULLREPORT
#			if [ ! "$JPLAG" == "YES" ]
#			then
#			
#				if [ "$DO_STUDENT" == "YES" ]  
#				then
#					if [ "$INTERACTIVE" == "YES" ]   
#					then
#						doMenu
#					fi
#				fi
#			#COUNT=$[COUNT + 1]
#			fi
   		echo $COUNT > $CURRENT			
		done
	else
		printf "${RED}ERROR: Folder $1 does not exist\n"
	fi
}

# Laboratory
function exlab {
	if [ -d $1 ]
	then
		doSummarize $1
		if [ "$INTERACTIVE" == "YES" ]
		then
			if  ! doConfirm "Please select [Y] to proceed to review process";
			then
				return 0
			fi
		else
			rm $CURRENT
		fi
		echo "NAME;PASS ZIP;COMPILE;GOOD BINARY;PASS TESTS;%TESTS LEVEL 1; %TESTS LEVEL 2;%TESTS LEVEL 3; FAILED TESTS; UNINITIALIZED USE;ACCESS OUT OF BOUNDS;MEMORY LEAKS" > $CSVREPORT
		printf "\n${YELLOW}$(date)\n"  > $FULLREPORT
		# Uncompress every student's assignment and proceed to review
		if [ -e $CURRENT ]
		then
			NEXT=$(cat $CURRENT)
		else
			NEXT=0
		fi
		PB_MAX=$NUM_STUDENTS
		PB_WIDTH=$PB_MAX
		PB_BACKGROUND=$WHITE
		PB_COLOR=$BLUE
		PB_LABEL="Reviewing "
		COUNT=0
		ZIPS=($DOWNLOAD/*/*.zip)
		while ( true )
		do
			clear
			zip=${ZIPS[${COUNT}]}
			cleanRecord
			doExtractName "$zip" STUDENT_FULLNAME
			PB_LABEL="Reviewing $STUDENT_FULLNAME"
			PB_COUNT=$[COUNT + 1]
			PB_Show
			printf "\n"
			if [ "$CONTINUE" == "YES" ] && [ $COUNT -lt $NEXT ]
			then						
				COUNT=$[COUNT + 1]
			else
				if [ "$INTERACTIVE" == "YES" ]
				then
					doMenu e Exit n Next p Previous c Check
					CHOICE=$?
					if [ $CHOICE -eq 0 ]
					then
						break;
					elif  [ $CHOICE -eq 1 ]
					then
						COUNT=$[COUNT + 1] 
						Min $COUNT $[NUM_STUDENTS - 1] COUNT
					elif  [ $CHOICE -eq 2 ]
					then
						COUNT=$[COUNT - 1] 
						Max 0 $COUNT COUNT
					fi
				fi
				if [ "$INTERACTIVE" == "YES" ] && [ $CHOICE -eq 3 ] || [ "$INTERACTIVE" == "NO" ]
				then
					PerformReviewLab "$zip"
					if [ "$INTERACTIVE" == NO ]
					then
						# Save record in the CSV file
						echo "$STUDENT_FULLNAME;$DO_ZIP;$DO_COMPILE;$DO_BINARY;$DO_TESTS;$PERCENT1;$PERCENT2;$PERCENT3;$FAILED_TESTS;$DO_VALGRIND_UNINIT;$DO_VALGRIND_ACCESS;$DO_VALGRIND_LEAKS" >> $CSVREPORT
						COUNT=$[COUNT + 1] 
						if [ $COUNT -ge $NUM_STUDENTS ]
						then
							break;
						fi
					fi
				fi	
			fi
			cd $ROOT
			cat $SINGLEREPORT >> $FULLREPORT
#			if [ ! "$JPLAG" == "YES" ]
#			then
#			
#				if [ "$DO_STUDENT" == "YES" ]  
#				then
#					if [ "$INTERACTIVE" == "YES" ]   
#					then
#						doMenu
#					fi
#				fi
#			#COUNT=$[COUNT + 1]
#			fi
   		echo $COUNT > $CURRENT			
		done
	else
		printf "${RED}ERROR: Folder $1 does not exist\n"
	fi

}


# Process command line arguments
function processArgument {
	if [ ! $1 ]
	then
		return 0
	elif [ "$1" == "--UPDATE" ]
	then 
		Update
		exit
	elif [ "$1" == "--EXLAB" ]
	then 
		EXLAB=YES
	elif [ "$1" == "--TEMPLATE" ]
	then 
		TEMPLATE=YES
	elif [ "$1" == "--INTERACTIVE" ]
	then 
		INTERACTIVE=YES
	elif [ "$1" == "--RESTART" ]
	then 
		CONTINUE=NO
		#rm -f $CURRENT
              
	elif [ "$1" == "--CODE" ]
	then 
		REVIEWCODE=YES
	elif [ "$1" == "--JPLAG" ]
	then 
		JPLAG=YES
		INTERACTIVE=NO
		CONTINUE=NO
		VALGRIND=NO
	elif [ "$JPLAG" == "YES" ]
	then
		FILES="$1"
	else		 
		printf "${RED}ERROR: missing argument\nPlease try AuutCorrect PracticaX [--BATCH --RESTART --TEMPLATE --VALGRIND --JPLAG <files>]\n"
	fi
}

# @brief Main body
if [ $1 ] 
then
    INTERACTIVE=NO
	CONTINUE=YES

    # Warm up
    processArgument $2
    processArgument $3
    processArgument $4
    processArgument $5
    processArgument $6
    # NO  Batch run wihtout prompting
    PDIR=$(pwd)
    DIR=$(dirname $0)
    clear
    if [ ! -f $DIR/settings.sh ]
    then 
            $DIR/preconfigure.sh
    fi
    source $DIR/settings.sh
    echo "Loading AutoCorrect [$AUTOCORRECT_FOLDER]"
    echo "Loading modules ... "
    source $DIR/tools.sh
    source $DIR/ansiterminal.sh

    # Configuration variables
    # Folder with MP2223 Repo
    #MPREPO=

    #AutoCorrect Workspace
    CheckFolderEcho "Workspace folder" $AUTOCORRECT_FOLDER ROOT

    CheckFolderEcho "Assignment folder" $ROOT/$1  ASSIGNMENT

    #Folder to save TestReport.md of all the students
    CheckFolderEcho "TestReports folder" $ASSIGNMENT/TestReportsFolder  TEST_REPORTS_FOLDER

    # Folder with downloaded assignments from Prado
    CheckFolderEcho "Download from Prado folder" $ASSIGNMENT/Prado DOWNLOAD
    ls -la $DOWNLOAD > $DOWNLOAD/.nfiles
    if ! grep -q "assignsubmission" $DOWNLOAD/.nfiles;
    then 
        alert "Prácticas de alumnos no encontradas. Por favor baja las prácticas de Prado en un único zip e introduce el nombre del fichero ZIP descargado\n"
        inputLine "Introduce el nombre y ruta de acceso del fichero ZIP que has bajado de Prado: " PRADOZIP
        if [ ! -f $PRADOZIP ]
        then 
            alert "No se encuentra el fichero "$PRADOZIP"\n"
            EndOfScript
        fi
        highlight "Descomprimiendo ficheros de prácticas de alumnos ... "
        cd "$DOWNLOAD"
        unzip -q $PRADOZIP
        highlight "Encontrados "$(ls -la $DOWNLOAD  | grep "assignsubmission" | wc -l)" ficheros de práctica de alumnos\n"    
        cd $ROOT
        label "\n\n Vuelve a ejecutar la script, por favor"
        EndOfScript
    else
        label "Found files"
    fi

    # Folder to Unzip students projetcs
    CheckFolderEcho "Folder to contain unzipped students projects" $ASSIGNMENT/Unzip STUDENTPROJECT
    # If empty, it is populated by Students's projects
    TEMPLATE=YES
    # Folder which contains the template
    CheckFolderEcho "Folder to teacher's template" $ASSIGNMENT/Template TEMPLATEPROJECT
    #echo "Copy from "$MPREPO/NetBeans/$1_TEMPLATE/" into "$TEMPLATEPROJECT
    regular "Updating template from repo "$MPREPO/NetBeans/$1_TEMPLATE/
    cp -rf $MPREPO/NetBeans/$1_TEMPLATE/* $TEMPLATEPROJECT
    # Temporary folder used to restore students' assignments and try their project by rewriting the template
    CheckFolderEcho "Folder to contain students projects merged with the template " $ROOT/Rebuild NETBEANSPROJECT
    # Folder Tmp that contains a project template built by teachers. It is used to populate NBPROJECT
    # Folder with fresh local files: .h .a .sh .tests These are to replace those of students
    #CheckFolderEcho "Folder to teacher's template" $ASSIGNMENT/Local LOCAL
    # Folder to place reports
    REPORT=$ASSIGNMENT
    # SINGLEREPORT file for the summary of a single student
    SINGLEREPORT=$REPORT/"out.txt"
    # SINGLEREPORT of the summaries of all students
    FULLREPORT=$REPORT/"fullreport.txt"
    # Final CSV file with the partial evaluation. Ready to be imported into a spreadsheet
    CSVREPORT=$REPORT/"report.csv"
    # Editor used to examinate source code
    EDITOR=gedit
    # File that contains the sequential number of the last student
    CURRENT=$REPORT/".current"
    if [ "$CONTINUE" == "NO" ]
    then
        rm $CURRENT
    fi
    # File that contains the total number of students
    KNOWN_NSTUDENTS=$REPORT/".nstudents"

    # Continue with the last reviewed student
    CONTINUE=YES
    # Only select desired files and apply JPlag
    JPLAG=NO
    # It setups everything for the first time
    SETUP=NO
    # Files to be extracted from Prado's zip and passed to JPLAG
    FILES=
    # File that contains test report
    TESTREPORT=$NETBEANSPROJECT/tests/TestReport.md
    # File that contains test output
    TESTS=$ASSIGNMENT/tests.out
    pressReturn    
	setCursorOff
	
	if [ "$1" == "Exlab" ]
	then
		exlab $1
	else
		review $1 
	fi
        EndOfScript "End of report"
else
	printf "${RED}Error in call\n${WHITE}Please try \n   `basename $0` <folder> [--RESTART --INTERACTIVE --TEMPLATE]\n"
	printf "   --INTERACTIVE Process all student interacting wiht with the teacher. If missing, it becomes a BACTCH process without interaction with the teacher\n"
	printf "   --RESTART Process all students from the beginning. If missing, the script continues from last reviewed student\n"
	printf "   --CODE Just review code\n"
	printf "   --TEMPLATE Overwrite all students files and folders with the content of the folder Template, let us say, to include specific tests. If missing, the project of every student is checked as it is\n"
	echo 
	echo "It is recommended to run it without options. Thus, it will produce two reports"
	echo "   .fullreport.txt      A report with all the validation point and tests"
	echo "   .report.csv          A simplified report to be imported into a spreadsheet, for instance"
	echo "Then proceed with the --INTERACTIVE mode to review one by one. This review can be interrupted at any time, and continued from that point on unless the option --RESTART is given, which will start again from the first student."
	echo "In --INTERACTIVE mode, once the student revision is done, it may be opened as a NetBeans project in the Rebuild folder"
	echo
fi
printf "${GRAY}"
