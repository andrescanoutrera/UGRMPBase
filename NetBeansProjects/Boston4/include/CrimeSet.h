/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/** 
 * @file  CrimeSet.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * @note To be implemented by students 
 */

#ifndef CRIMESET_H
#define CRIMESET_H

#include <string>
#include <iostream>
#include <fstream>
#include <cmath>       /* ceil */

#include "DateTime.h"
#include "Crime.h"

/**
 * @class CrimeSet
 * @brief A CrimeSet defines a set of instances of the Crime class that includes 
 * data on crimes (offenses) committed anywhere in the world and with the types 
 * of crimes specifically considered within its own jurisdiction. 
 * This class uses a dynamic array of objects of the Crime class to store 
 * the set of crimes. 
 * This class also contains a field to store comments, free text that allows, 
 * for example, to describe in natural language the time period considered, 
 * the origin, the query applied to obtain the set, etc. 
 * In general, the records in the set are not sorted by date and time 
 * when each crime was committed. 
 * Usually the records appear in the order in which they were recorded when 
 * the crimes were collected by the police department.
 * The public methods of this class do not allow a CrimeSet to contain two 
 * Crime objects with identical IDs.
 * 
 * @see See the content of the files *.crm in the DataSets folder as examples
 * of files that contain information about CrimeSets
 */

class CrimeSet {
public:
     // Retrieve all previous declarations and take into account
     // the new declarations included here... 
     // ...

    
    /**
     * @brief Overloading of the [] operator for CrimeSet class
     * Query method
     * @param index index of the element 
     * @return Aant reference to the Crime object at position @p index
     */
    Crime operator[](int index);   

    /**
     * @brief Overloads the operator += for the CrimeSet class. It appends to 
     * this CrimeSet object, the list of Crime objects contained in the 
     * provided CrimeSet @p crimeSet that are not found in this CrimeSet.  
     * Modifier method
     * @param other The right CrimeSet operand. Input parameter
     * @return A reference to this object
     */
    CrimeSet operator+=(CrimeSet other);
    
    friend std::ostream operator<<(std::ostream os, CrimeSet crimeSet);
    friend std::istream operator>>(std::istream is, CrimeSet crimeSet);
    
private:

   /**
     * @brief Overloading of the [] operator for CrimeSet class
     * Modifier method
     * @param index index of the element 
     * @return A  reference to the Crime object at position @p index
     */
    Crime operator[](int index);
    
    // Retrieve all previous declarations 

};
/**
 * @brief Overloading of the stream insertion operator for CrimeSet class.
 * @note This operator sends each Crime to the output stream in the same 
 * format as the one described in the Crime::toString() method
 * @param os The output stream to be used. Input/output parameter
 * @param crimeSet the CrimeSet object. Input parameter
 * @return @p os A reference to the output stream
 */
std::ostream operator<<(std::ostream os, const CrimeSet crimeSet);

/**
 * @brief Overloading of the stream extraction operator for CrimeSet class.
 * @note This operator should remove any crime previously contained in the
 * provided CrimeSet @p crimeSet.
 * @note This operator throws an exception in some error cases (see below). 
 * Before throwing the corresponding exception, this operator clears
 * the provided object (it calls to clear() method) to leave it in a 
 * consistent state.
 * @note This operator does not read the lines of comments, only the information
 * about crimes (an integer n with the number of crimes and n lines with Crime 
 * information).
 * @throw std::out_of_range Throws a std::out_of_range if the number of Crimes
 * read from the file is negative.
 * @param is The input stream to be used. Input/output parameter
 * @param crimeSet The CrimeSet object to be filled. Input/output parameter
 * @return @p is A reference to the input stream
 */
std::istream  operator>>(std::istream is, CrimeSet crimeSet);