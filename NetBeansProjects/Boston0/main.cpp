/*
 * Metodología de la Programación: Boston0
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
#include "DateTime.h"
#include "Crime.h"

using namespace std;

/**
 * The purpose of this program is to read a set of data on crimes committed 
 * in the city of Boston, showing those that have occurred within certain 
 * geographic coordinates and within the date range provided to the program.
 * This program first reads from the standard input two Coordinates objects, one 
 * Coordinates to define the minimun coordinates and another Coordinates to 
 * define the maximum coordinates.
 * Then it reads two DateTime objects, one DateTime to define the minimun 
 * DateTime and another DateTime to define the maximum DateTime.
 * Next it reads an integer number n to define the number of Crime objects to
 * read.
 * Thereafter, it reads n Crime objects, saving in an array of Crimes only the 
 * Crimes whose DateTime is between the minimum and maximun DateTimes and whose 
 * coordinates are valid (@see Coordinates::isValid() method description).
 * Each Crime object is normalized when inserted into the array.
 * Be careful that the number of crimes inserted in the array does not exceed 
 * its capacity.
 * Finally, the program shows in the standard output all the Crimes in the array
 * and then all the Crimes which Coordinates are inside the area defined by
 * the minimum and maximum Coordinates provided to the program. 
 * Be careful to show the output as in the below example.
 *  
 * Running example:
 * > dist/Debug/GNU-Linux/boston0 < data/input00.b0in 
Total number of crimes inserted in the array: 4
0,225520077,3126,UNKNOWN,WARRANT ARREST - OUTSIDE OF BOSTON WARRANT,,,0,2022-02-02 00:00:00,WASHINGTON ST,42.343082,-71.141724
1,222648862,3831,UNKNOWN,M/V - LEAVING SCENE - PROPERTY DAMAGE,B2,288,0,2022-02-05 18:25:00,WASHINGTON ST,42.329750,-71.084541
4,222111641,619,UNKNOWN,LARCENY ALL OTHERS,D14,778,0,2022-02-14 12:30:00,WASHINGTON ST,42.349056,-71.150497
5,222107076,3126,UNKNOWN,WARRANT ARREST - OUTSIDE OF BOSTON WARRANT,D4,UNKNOWN,0,2022-03-11 10:45:00,MASSACHUSETTS AVE & ALBANY ST BOSTON  MA 02118 UNI,42.333500,-71.073509

Crimes within the given geographic area:
0,225520077,3126,UNKNOWN,WARRANT ARREST - OUTSIDE OF BOSTON WARRANT,,,0,2022-02-02 00:00:00,WASHINGTON ST,42.343082,-71.141724
4,222111641,619,UNKNOWN,LARCENY ALL OTHERS,D14,778,0,2022-02-14 12:30:00,WASHINGTON ST,42.349056,-71.150497
5,222107076,3126,UNKNOWN,WARRANT ARREST - OUTSIDE OF BOSTON WARRANT,D4,UNKNOWN,0,2022-03-11 10:45:00,MASSACHUSETTS AVE & ALBANY ST BOSTON  MA 02118 UNI,42.333500,-71.073509
 */
int main(int argc, char* argv[]) {
    const int DIM_ARRAY = 10; // dimension of the array arrayCrimes
    Crime arrayCrimes[DIM_ARRAY]; // array of Crimes
 
    // Read latitude and longitude for 2 Coordinates objects
    
    // Remember to take off the \n character after longitude of max Coordinates
    // Read 2 DateTime objects

    // Read the number of crimes
    // Remember to take off the \n character after number of crimes 
    
    // Read the Crimes and put them in the array arrayCrimes
    //    whenever they follow the required restrictions and 
    //    once normalized

    cout << "Total number of crimes inserted in the array: ";
    // display the number and the current content for the arrayCrimes
  
    cout << "\nCrimes within the given geographic area:" << endl;
    // display all the Crimes in the array which Coordinates are inside the given area
}