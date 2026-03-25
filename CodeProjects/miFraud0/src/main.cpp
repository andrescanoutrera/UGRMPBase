/*
 * Metodología de la Programación
 * Curso 2025/2026
 */

/**
 * @file main.cpp
 * @author estudiante1: Romero Lopez, Ulises
 * @author estudiante2: Ruiz Cano, Juan
 *
 * Created on 24 de octubre de 2025, 9:27
 */





#include <iostream>

#include "Location.h"
#include "VectorLocation.h"
#include "ArrayLocation.h"


/*
#include <sstream>
#include <regex>
#include <cmath>
#include <string>




#define ENDL "\n"
#define LOCATION_DEFAULT "0.000000 0.000000"
#define LOCATION_OTHER "37.200000 -3.600000 Granada"
*/


using namespace std;





/**
 * The purpose of this program is to obtain the union of two subsets of Location
 * objects. Each one of the two subsets is obtained by reading from the
 * standard input a set of Location objects and the coordinates of the corners 
 * of two rectangular subareas of interest (x and y coordinates
 * of the bottom left and top right corners of the subarea). Each subset of 
 * locations is obtained by selecting those locations that are whithin the 
 * given subarea.
 *
 * This program first reads all the necessary data from the standard input;
 * then it calculates the union of the two subsets of Location objects; 
 * it sorts the resulting set of locations and finally it displays
 * the sorted set in the standard output.
 *
 * Be careful to show the output as in the below example.
 *
 * An example of data read from standard input is the following (see file
 * Datasets/dataP0/princeton_5locations.p0in):
21.0 10.0
26.0 16.0
24.0 10.0
27.0 16.0
5
20.9 15.4 Frist Campus Center
23.7 14.8 Cannon Dial Elm
24.8 14.9 Quadrangle
25.6 14.9 Ivy
26.4 14.9 Cottage
 *
 * Running sintax:
 * > build/Fraud0 < <inputFile.p0in>
 *
 * Running example:
 * > build/Fraud0 < ../Datasets/dataP0/princeton_5locations.p0in
4
23.700000 14.800000 Cannon Dial Elm
26.400000 14.900000 Cottage
25.600000 14.900000 Ivy
24.800000 14.900000 Quadrangle
 */





int main(int argc, char *argv[]) {

    
    const int MAX_NLOCATIONS = 20;   // capacity of the location arrays
    Location bottomLeft1, topRight1, // coordinates that define the first input area
        bottomLeft2, topRight2;      // coordinates that define the second input area
    VectorLocation locations,        // VectorLocation with all the locations
        selectedLocations1,          // first vector of selected locations
        selectedLocations2,          // second vector of selected locations
        tempUnion;
    Location arrayLocations[MAX_NLOCATIONS], // array used to read all the input locations
        arrayUnionLocations[MAX_NLOCATIONS]; // array to store the resulting union
    int nLocs, // number of locations in arrayLocations
        nUnionLocs; // number of locations in arrayUnionLocations
        

    // Read bottomLeft1 and topRight1 from standard inputF
    // Read bottomLeft2 and topRight2 from standard input
    bottomLeft1.load(cin);
    topRight1.load(cin);
    bottomLeft2.load(cin);
    topRight2.load(cin);
    // Read from standard input all the locations and insert them in arrayLocations
    
    //Read array location usarlo 

    ReadArrayLocation(arrayLocations,MAX_NLOCATIONS,nLocs);

    



    // Insert the locations in arrayLocations in the locations object 
    
   
    locations = ToVectorLocation(arrayLocations, nLocs);



    // Take from the locations object the locations within each area and 
    // insert them in selectedLocations1 and selectedLocations2 

    selectedLocations1 = locations.select(bottomLeft1, topRight1);
    selectedLocations2 = locations.select(bottomLeft2, topRight2);

    //supongo que es de bottomleft1 y topright1 coger las x y las y que hay en locations que estan entre ese bottom y top dentro de locations y guardarlo en selectedlocations
  
    // Calculate the union of selectedLocations1 and selectedLocations2 

    tempUnion.join(selectedLocations1);
    tempUnion.join(selectedLocations2);
    
    //poner en arrayunionlocations y hay que pasar y hacer transformaciones de selected para q funcione


    // Sort the resulting VectorLocation object

    tempUnion.sort();

    // Convert the sorted VectorLocation object to an array of Location objects

    ToArrayLocation(tempUnion, arrayUnionLocations, MAX_NLOCATIONS, nLocs);

    // Print the resulting array of Location objects in the standard output
    PrintArrayLocation(arrayUnionLocations, nLocs);
    


    
   


    
}









