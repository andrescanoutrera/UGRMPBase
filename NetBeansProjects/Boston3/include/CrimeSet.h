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
 * Created on September 17, 2024, 5:43 PM
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
     // 

    /**
     * @brief Basicructor and initializer. It builds a CrimeSet object
     * with a set of of 0 Crimes and a capacity calculated as follows: 
     * - If size>=0 and size<INITIAL_CAPACITY, then the capacity of the
     * dynamic array will be set to INITIAL_CAPACITY. 
     * - If size>=INITIAL_CAPACITY, then the capacity of the dynamic array 
     * will be equals to size.
     * The field for the comments is set as an empty string
     * @throw std::out_of_range Throws a std::out_of_range exception if
     * @p size<0. In this case, the fields of the object are initialized 
     * as follows: 
     * - _comment = ""
     * - _capacity = 0
     * - _nCrimes = 0
     * - _crimes = nullptr 
     * After the fields are initialized as described above, the exception 
     * is thrown.
     * @param size The number of Crimes that will have the set
     */
    CrimeSet(int size=0);
    
    /**
     * @brief Copyructor. Builds a deep copy of the provided CrimeSet 
     * @p orig.   
     * @param orig CrimeSet original. Input parameter
     */
    CrimeSet(CrimeSet orig);
    
    /**
     * @brief Destructor
     */
    ~CrimeSet();

    /**
     * @brief Overloads the assignment operator for CrimeSet class.
     * Modifier method
     * @param orig the CrimeSet object used as source for the assignment. 
     * Input parameter
     * @return A reference to this object
     */
    CrimeSet operator=(CrimeSet orig);
    
private:
    static const int INITIAL_CAPACITY = 8; ///< Default initial capacity for the dynamic array _crimes. Should be a number >= 0

    /**
     * Ratio to be used to compute the next capacity to allocate in the
     * dynamic array of Crimes. When the dynamic array is full and a new
     * Crime must be appended, it is reallocated with a 
     * capacity calculated as ceil(_capacity * GROWING_RATIO) 
     */
    static const float GROWING_RATIO; 
    
    static const std::string MAGIC_STRING_T; ///< A string with the magic string for text files

    /**
     * string that contains several lines of comments (text in natural 
     * language). Each line, except possibly the last one, ends with the 
     * character '\n'
     */
    std::string _comment; 

    Crime *_crimes; ///< Pointer to a dynamic array of crimes
    int _nCrimes; ///< Number of used elements in the dynamic array _crimes
    int _capacity; ///< Number of reserved elements in the dynamic array _crimes
    

    // fill free to define as much method to manage the dynamic memory
    // ...

}; // end class CrimeSet
// retrieve previous functions ...

#endif /* CRIMESET_H */

