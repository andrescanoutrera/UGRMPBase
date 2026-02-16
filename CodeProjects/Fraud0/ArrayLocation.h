/*
 * Metodología de la Programación
 * Curso 2025/2026
 */

/**
 * @file ArrayLocation.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 22 de octubre de 2025, 11:57
 */

#ifndef ARRAYLOCATION_H
#define ARRAYLOCATION_H

#include "Location.h"
#include "VectorLocation.h"

/**
 * @brief Displays on the standard output an integer (the value in nLocs,
 * number of locations in arrayLocations) and the content of the provided
 * array of locations. Each location is displayed on a new line with the help
 * of the Location::toString() method. For example, here it is displayed
 * an array with 4 locations:
4
24.8 14.9 Quadrangle
25.6 14.9 Ivy
26.4 14.9 Cottage
27.3 14.5 Cap & Gown
 * @param arrayLocations An array of Location objects. Input parameter
 * @param nLocs Number of Location objects in the array arrayLocations.
 * Input parameter
 */
void PrintArrayLocation(Location arrayLocations[], int nLocs);

/**
 * @brief Reads from the standard input an integer n and then reads
 * n Location objects that are placed into the provided array of locations.
 * @throw Throws a std::out_of_range exception if the integer n read from
 * standard input is negative. In that case, nLocs will be set to 0.
 * @throw Throws a std::out_of_range exception if the integer n read from
 * standard input exceeds the array capacity. In that case, nLocs will be set to 0.
 * @param arrayLocations An array of Location objects. Output parameter
 * @param capacity An integer with the capacity of arrayLocations.
 * Input parameter
 * @param nLocs An integer with the number of objects inserted in
 * arrayLocations. Output parameter
 */
void ReadArrayLocation(Location arrayLocations[], int capacity, int nLocs);

/**
 * @brief Places a copy of each Location of the provided VectorLocation object
 * into the provided array of Location (arrayLocations).
 * @throw Throws a std::out_of_range exception if the number of Location objects
 * in the provided VectorLocation exceeds the array capacity. In that case,
 * nLocs will be set to 0.
 * @param vector A VectorLocation object. Input parameter
 * @param arrayLocations Array of Location objects. Output parameter
 * @param capacity An integer with the capacity of arrayLocations.
 * Input parameter
 * @param nLocs An integer with the number of objects inserted in
 * arrayLocations. Output parameter
 */
void ToArrayLocation(VectorLocation vector, Location arrayLocations[],
                     int capacity, int nLocs);

/**
 * @brief Returns a VectorLocation object filled with a copy of the objects from
 * the provided array of Location objects (arrayLocation)
 * @throw Throws a std::out_of_range exception if nLocs is negative.
 * @param arrayLocations Array of Location objects. Input parameter
 * @param nLocs An integer with the number of objects in
 * arrayLocations. Input parameter
 * @return A VectorLocation object filled with the objects from the provided
 * array of Location objects (arrayLocation)
 */
VectorLocation ToVectorLocation(Location arrayLocations[], int nLocs);

#endif /* ARRAYLOCATION_H */