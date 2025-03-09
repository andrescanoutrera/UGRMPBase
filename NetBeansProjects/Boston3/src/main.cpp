/*
 * Metodología de la Programación: Boston3
 * Curso 2024/2025
 */


/** 
 * @file   main.cpp
 * @author estudiante1: apellidos*, nombre*
 * @author estudiante2: apellidos*, nombre* (solo si procede)  
 */

#include <string>
#include <iostream>

#include "CrimeSet.h"

using namespace std;

void showHelp(std::ostream& outputStream);

/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc) 
 */
void showHelp(std::ostream& outputStream) {
    outputStream << "ERROR in boston3 parameters" << endl;
    outputStream << "Run with the following arguments:" << endl;
    outputStream << "boston3 [-o <outputFile.crm>] <inputFile1.crm> {<inputFile.crm>}" << endl;
    outputStream << endl;
    outputStream << "Parameters:" << endl;
    outputStream << "-o <outputFile.crm>: name of the output file (tests/output/output.crm by default)" << endl;
    outputStream << "<inputFile1.crm> {<inputFile.crm>}: input crm files" << endl;
    outputStream << endl;
}

/**
 * The purpose of this program is to read a list of crm files, 
 * each one containing information about a CrimeSet, and make the fusion of 
 * all the CrimeSets, saving the result in a new crm file. 
 * The names of the input crm files are passed as arguments to the program.
 * The name of the output crm file can be provided to the program as an optional
 * argument (if not provided, the output file is /tmp/output.crm). See below 
 * the Running sintax.
 * 
 * The program begins by processing the running arguments.
 * Next, it obtains the fusion of the crm files whose names are passed as 
 * arguments to the program. The resulting CrimeSet will have a comment with
 * the list of the input crm files used to do the fusion. See below, the Running
 * example.
 * Finally, the resulting CrimeSet is normalized, sorted and saved in the
 * output crm file.
 * 
 * Running sintax:
 * > dist/Debug/GNU-Linux/boston3 [-o <outputFile.crm>] <inputFile1.crm> {<inputFile.crm>}
 * 
 * Running example:
 * > dist/Debug/GNU-Linux/boston3 -o /tmp/output.crm ../DataSets/crimes_01.crm ../DataSets/crimes_05.crm
 * 
 * > cat /tmp/output.crm
MP-CRIME-T-1.0
#Fusion of the following crm files: 
#../DataSets/crimes_01.crm
#../DataSets/crimes_05.crm
6
2,222201764,724,UNKNOWN,AUTO THEFT,C6,200,0,2022-01-09 00:00:00,W BROADWAY,42.341286,-71.054680
7,222073971,611,UNKNOWN,LARCENY PICK-POCKET,A1,77,1,2022-02-01 10:07:00,NEW SUDBURY ST,42.361839,-71.059769
1,222648862,3831,UNKNOWN,M/V - LEAVING SCENE - PROPERTY DAMAGE,B2,288,1,2022-02-05 00:00:00,WASHINGTON ST,42.329750,-71.084541
0,225520077,3126,UNKNOWN,WARRANT ARREST - OUTSIDE OF BOSTON WARRANT,D14,786,1,2022-02-05 00:00:00,WASHINGTON ST,42.343082,-71.141724
3,222201559,301,UNKNOWN,ROBBERY,D4,UNKNOWN,1,2022-03-05 13:00:00,ALBANY ST,42.333183,-71.073936
5,222107076,3126,UNKNOWN,WARRANT ARREST - OUTSIDE OF BOSTON WARRANT,D4,UNKNOWN,1,2022-03-11 10:45:00,MASSACHUSETTS AVE & ALBANY ST BOSTON  MA 02118 UNI
,42.333500,-71.073509
 * @return Returns 1 in case of error in program arguments; 0 otherwise
 */
int main(int argc, char* argv[]) {
 
    string outputFileName = "tests/output/output.crm"; // Name of the output crm file
    string comments = "Fusion of the following crm files: \n"; // Comments for the result of fusion

   
    // Process program arguments
    
    // for every file from the main arguments
        // load the file
        // do the fusion 
        // compose the comment

    // set the comments, normalize, sort and save
    
    return 0;
}
