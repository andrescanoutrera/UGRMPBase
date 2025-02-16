/*
 * Metodología de la Programación: Boston2
 * Curso 2024/2025
 */

/** 
 * @file   main.cpp
 * @author estudiante1: apellidos*, nombre*
 * @author estudiante2: apellidos*, nombre* (solo si procede)  
 * @note To be implemented by students 
 * Created on September 25, 2024, 2:01 PM
 */

#include <string>
#include <iostream>
#include <fstream>

#include "CrimeSet.h"
#include "ArrayCrimeSetFunctions.h"

using namespace std;

void showHelp(std::ostream& outputStream);

/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc)
 */
void showHelp(std::ostream& outputStream) {
    outputStream << "ERROR in boston2 parameters" << endl;
    outputStream << "Run with the following arguments:" << endl;
    outputStream << "boston2 <inputFile.txt> [<outputFile.crm>]" << endl;
    outputStream << endl;
    outputStream << "Parameters:" << endl;
    outputStream << "<inputFile.txt>: name of the input text file that contains the names of the crm files" << endl;
    outputStream << "<outputFile.crm>: name of the output crm file (tests/output/output.crm by default)" << endl;
    outputStream << endl;
}

/**
 * The purpose of this program is to read a list of crm files, 
 * each one containing information about a CrimeSet, and make the fusion of 
 * all the CrimeSets, saving the result in a new file. 
 * The names of the input crm files are contained in a text file whose name
 * is provided to the program as the first argument.
 * The name of the output crm file can be provided to the program as the second 
 * argument (if not provided the output file is tests/output/output.crm). See below 
 * the Running sintax.
 * 
 * The program begins by checking if the number of arguments is valid.
 * Next, it reads and saves in a dynamic array of CrimeSet objects, each one
 * of the crm files whose names are provided with the first argument of the
 * program.
 * Then, for each one of the CrimeSet in the dynamic array, the following steps
 * are done:
 * - Normalize the CrimeSet. To do that, you can use the CrimeSet::normalize() 
 * method.
 * - Select only those Crimes with a valid location (discarding all with invalid
 * location). To do that, you can use the CrimeSet::selectValidLocation() method.
 * - Select only those Crimes where Shooting=="1". To do that, you can use the 
 * CrimeSet::selectWhereEQ() method.
 * Hereafter, you must obtain a CrimeSet with the fusion (join) of all the 
 * CrimeSet in the array. See in the running examples, which comment should 
 * have the resulting CrimeSet.
 * Finally, the resulting CrimeSet should be sorted and saved in an output
 * file.
 * 
 * Running sintax:
 * > dist/Debug/GNU-Linux/boston2 <inputFile.txt> [<outputFile.crm>] 
 * 
 * Running example:
 * > dist/Debug/GNU-Linux/boston2 data/input06.b2in /tmp/output.crm
 * 
 * > cat tests/output/output.crm
MP-CRIME-T-1.0
#Fusion of the crm files whose names are in the file: data/input06.b2in
5
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

    // Check if the number of arguments is valid.
    
    // Read and save in a dynamic array of CrimeSet objects,
    //    each one of the crm files from the input file
    
    // Loop for every CrimeSet in the dynamic array
            // Normalize the CrimeSet (normalize each Crime in the CrimeSet)
            // Select only those Crimes with a valid location (discard all with invalid location)
            // Select only those Crimes where Shotting =="1"
   
    // Make the fusion of all the CrimeSets in the array
    
    // Sort the array of the resulting CrimeSet
    // Save the CrimeSet in the output crm file 

}
