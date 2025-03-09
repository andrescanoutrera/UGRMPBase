/*
 * Metodología de la Programación: Boston4
 * Curso 2024/2025
 */

/** 
 * @file   main.cpp
 * @author estudiante1: apellidos*, nombre*
 * @author estudiante2: apellidos*, nombre* (solo si procede)  
 */

#include <string>
#include <iostream>

#include "Coordinates.h"
#include "CrimeSet.h"
#include "CrimeCounter.h"
#include "ColorPalette.h"

using namespace std;

void showHelp(ostream& outputStream);

/**
 * Shows help about the use of this program in the given output stream
 * @param outputStream The output stream where the help will be shown (for example,
 * cout, cerr, etc) 
 */
void showHelp(ostream& outputStream) {
    outputStream << "ERROR in boston4 parameters" << endl;
    outputStream << "Run with the following arguments:" << endl;
    outputStream << "boston4 [-o outputFilename] [-c text] " ;
    outputStream << "[-h int] [-w int] [-d int] [-b int] [-g int] [-y int] ";
    outputStream << "<inputFile1.crm> {<inputFile.crm>}" << endl;
    outputStream << endl;
    outputStream << "Parameters:" << endl;
    outputStream << "-o outputFilename: name of the output PPM file (tests/output/output.ppm by default)" << endl;
    outputStream << "-c text: extra comment to be included in the output PPM file (list of program parameters, by default)" << endl;
    outputStream << "-h high: number of rows (19  by default)" << endl;
    outputStream << "-w width: number of columns (23  by default)" << endl;
    outputStream << "-d number: number of dark blue tones in the color palette (2 by default)" << endl;
    outputStream << "-b number: number of blue tones in the color palette (2 by default)" << endl;
    outputStream << "-g number: number of green tones in the color palette (2 by default)" << endl;
    outputStream << "-y number: number of yellow tones in the color palette (2 by default)" << endl;
    outputStream << "<inputFile1.crm> {<inputFile.crm>}: input crm files" << endl;
    outputStream << endl;
}

/**
 * The purpose of this program is to obtain a heat map for the set of crimes 
 * contained in the fusion of a list of input crm files, saving the result 
 * in a PPM color image file.
 * The names of the input crm files are passed as arguments to the program.
 * The name of the output PPM file can be provided to the program as an optional
 * argument (if not provided, the output file is tests/output/output.ppm). See below 
 * the Running sintax. 
 * A PPM file can have comment lines. Each comment line begins with the 
 * '#' character. This program will save in the output PPM file a comment line
 * with the content of the running parameters, but additional lines could be 
 * appended with the -c parameter (see the running example). 
 * 
 * The program begins by processing the running arguments. 
 * Next, the program obtains the fusion of the crm files whose names are passed 
 * as arguments to the program. 
 * Hereafter, the program calculates the frequency for each cell in which 
 * is divided the target geographical area. To do that, an object of the class 
 * CrimeCounter is used. This object is created using a given number of rows
 * and columns, and with a given coordinates to fix the target geographical 
 * area.
 * Finally, a PPM image with the heat map is saved in the output file. This 
 * PPM image is build and saved with the method 
 * CrimeCounter::saveAsPPMTextImage() that obtain an image from the frequency 
 * matrix of the previous CrimeCounter object. Remember to fill in the content 
 * of the comment string (third parameter of the previous method) as 
 * indicated above. You can insert the character '#' at the beginning of each
 * line in the comment string, using the function FormatAsComment().
 * 
 * Running sintax:
 * > dist/Debug/GNU-Linux/boston4 boston4 [-o outputFilename] [-c text]  
 *      [-h int] [-w int] [-d int] [-b int] [-g int] [-y int]
 *      <inputFile1.crm> {<inputFile.crm>}
 * 
 * Running example:
 * > dist/Debug/GNU-Linux/boston4 -c "Heat map for crimes_20.crm" -h 3 -w 3 -o /tmp/output.ppm ../DataSets/crimes_20.crm
 * 
 * > cat /tmp/output.ppm
P3
#Running parameters: -c Heat map for crimes_20.crm -h 3 -w 3 -o /tmp/output.ppm ../DataSets/crimes_20.crm
#Heat map for crimes_20.crm
3 3
255
128 255 0 255 0 0 0 0 255 255 255 0 255 0 0 0 0 255 0 0 255 0 0 255 0 0 255
 * 
 * > display -resize 500 -filter point /tmp/output.ppm
 * 
 * @return Returns 1 in case of error in program arguments; 0 otherwise
 */ 
int main(int argc, char* argv[]) {   
    string ofilename="tests/output/output.ppm"; // output PPM file name
 
    Coordinates topRightCoor=CrimeCounter::DEFAULT_COORD_TOPRIGHT, // (42.395042,-70.953728)
        bottonLeftCoor=CrimeCounter::DEFAULT_COORD_BOTTOMLEFT; // (42.207760,-71.178673)
    
    int firstInputFile=-1; // index in argv[] with the name of the first input file
    bool hasBeenReadInitialParameters = false; // true if all the parameters starting with - has been read
    CrimeSet crimeSet, // CrimeSet to obtain the fusion of the input crm files
        currentCrimeSet; // CrimeSet to load each one of the input crm files
  
    // Loop to process program arguments 
       // (finish when the optional arguments have been read)
    
    // Obtain the fusion of the input crm files with operator+= of CrimeSet class
    // Load the first input crm file into the crimeSet object
    // Loop to load the rest of the crm files
        // Load the next crm file into the currentCrimeSet object
        // join crimeSet with currentCrimeSet using operator+= of CrimeSet 

    // Calculate the frequencies of crimeSet using a CrimeCounter object
 
    // Compose a string with the comments for the output PPM file
    //    and append the '#' character at the beginning of each line

    // Build a ColorPalette object
    // Use saveAsPPMTextImage to save the heat map in the output file, using
    //   the selected palette and the comment

    return 0;
}


