/*
 * Metodología de la Programación
 * Curso 2025/2026
 */

/**
 * @file main.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on 24 de octubre de 2025, 9:27
 */

#include <iostream>

#include "Location.h"
#include "VectorLocation.h"
#include "ArrayLocation.h"

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
        selectedLocations2;          // second vector of selected locations
    Location arrayLocations[MAX_NLOCATIONS], // array used to read all the input locations
        arrayUnionLocations[MAX_NLOCATIONS]; // array to store the resulting union
    int nLocs, // number of locations in arrayLocations
        nUnionLocs; // number of locations in arrayUnionLocations

    // Read bottomLeft1 and topRight1 from standard input
    // Read bottomLeft2 and topRight2 from standard input

    // Read from standard input all the locations and insert them in arrayLocations

    // Insert the locations in arrayLocations in the locations object 

    // Take from the locations object the locations within each area and 
    // insert them in selectedLocations1 and selectedLocations2 

    // Calculate the union of selectedLocations1 and selectedLocations2 

    // Sort the resulting VectorLocation object

    // Convert the sorted VectorLocation object to an array of Location objects

    // Print the resulting array of Location objects in the standard output
}