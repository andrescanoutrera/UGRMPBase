/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/**
 * @file Crime.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * @note To be implemented by students 
 * Created on September 10, 2024, 6:26 PM
 */

#ifndef CRIME_H
#define CRIME_H

#include <iostream>
#include <string>

#include "Coordinates.h"
#include "DateTime.h"

/**
 * @class Crime 
 * @brief It stores data about a crime occurred in Boston city between 
 * 2017-01-20 02:00:00 and 2022-02-02 00:00:00
 * The data of each crime comes from a csv file located in 
 * https://www.kaggle.com/datasets/shivamnegi1993/boston-crime-dataset-2022/data
 * where some fields will be ignored.
 * 
 * The selected fields for a Crime are:
 * - 0  COUNTER: integer number that represents a counter that begins 
 *      from 0 for each year. 
 * - 1  IDENTIFIER_NUMBER: Identifier of the crime. It is an integer value 
 *      stored as a string, that is, like "0020". It is unique in a dataset of 
 *      crimes. The string for this field must contain at least one character
 *      different from whitespace and \t character. An ID will never contain
 *      leading or trailing blanks.
 * - 2  OFFENSE_CODE: string with an internal code whose group and description 
 *      come in the next two fields.
 * - 3  OFFENSE_CODE_GROUP: string with the group of the crime. 
 * - 4  OFFENSE_DESCRIPTION: string with the description of the crime.
 * - 5  DISTRICT: string with the district where the crime took place.
 * - 6  REPORTING_AREA: string with the area where the crime took place
 * - 7  SHOOTING: a boolean where true represents that the crime was caused by 
 *      a gunshot.
 * - 8  OCCURRED_ON_DATE: date and time when the crime took place. 
 * - 9  STREET: name of the street where it took place. 
 * - 10 LOCATION (latitude, longitude) where it took place. 

 * Example of a crime:
 * 2784,182102975,3820,Motor Vehicle Accident Response,M/V ACCIDENT INVOLVING PEDESTRIAN - INJURY,C6,175,0,2018-12-22 00:45:00,SOUTHAMPTON ST,42.331680,-71.067986 <br>
 * corresponding values to the fields: <br>
 * COUNTER 2784 <br>
 * IDENTIFIER_NUMBER 182102975 <br>
 * OFFENSE_CODE 3820 <br>
 * OFFENSE_CODE_GROUP Motor Vehicle Accident Response <br>
 * OFFENSE_DESCRIPTION M/V ACCIDENT INVOLVING PEDESTRIAN - INJURY <br>
 * DISTRICT C6 <br>
 * REPORTING_AREA 175 <br>
 * SHOOTING false <br>
 * OCCURRED_ON_DATE 2018-12-22 00:45:00 <br>
 * STREET SOUTHAMPTON ST <br>
 * LOCATION 42.331680,-71.067986 <br>
 */
class Crime {
public:
     // Retrieve all previous declarations and take into account
     // the new declarations included here... 
     // ...
    
    friend std::ostream operator<<(std::ostream os, Crime crime);
    friend std::istream operator>>(std::istream is, Crime crime);
    
private:
     // Retrieve all previous declarations 

};

// Retrieve all previous declarations of external functions: Trim, Capitalize 
// and Normalize 

/**
 * @brief Overloading of the stream insertion operator for Crime class. 
 * It inserts every field of the object separated by commas (,) in 
 * the output string.
 * @param os The output stream to be used. Input/Output parameter
 * @param crime the Crime object. Input parameter
 * @return @p os A reference to the output stream
 */
std::ostream operator<<(std::ostream os, Crime crime);

/**
 * @brief Overloading of the stream extraction operator for Crime class. It
 * reads a record  from the input string that will set the
 * list of fields of the provided crime object.
 * @param is The input stream to be used. Input/Output parameter
 * @param crime the Crime object. Input Output parameter
 * @return @p is the input stream
 */
std::istream operator>>(std::istream is, Crime crime);

/**
 * @brief Overloading of the relational operator < for Crime class
 * @param crime1 The first object to be compared. Input parameter
 * @param crime2 The second object to be compared. Input parameter
 * @return true if the DateTime of @p crime1 is smaller (before) than that of
 * @p crime2 or if both DateTimes are equals and the ID of 
 * @p crime1 is minor than the ID of @p crime2; false otherwise
 */
bool operator<(Crime crime1, Crime crime2);

/**
 * @brief Overloading of the operator > for Crime class. It uses the DateTime
 * and ID of the given crimes to compare them as in operator<
 * @param crime1 a Crime object. Input parameter
 * @param crime2 a Crime object. Input parameter
 * @return true if crime1 > crime2; false otherwise
 */
bool operator>(Crime crime1, Crime crime2);

/**
 * @brief Overloading of the operator == for Crime class. It uses the DateTime
 * and ID of the given crimes to compare them as in operator<
 * @param crime1 a Crime object. Input parameter
 * @param crime2 a Crime object. Input parameter
 * @return true if the two Crimes have the same DateTime and ID;
 * false otherwise
 */
bool operator==(Crime crime1, Crime crime2);

/**
 * @brief Overloading of the operator != for Crime class. It uses the DateTime
 * and ID of the given crimes to compare them as in operator<
 * @param crime1 a Crime object. Input parameter
 * @param crime2 a Crime object. Input parameter
 * @return true if the two Crimes are not equals (see operator==); 
 * false otherwise
 */
bool operator!=(Crime crime1, Crime crime2);

/**
 * @brief Overloading of the operator <= for Crime class. It uses the DateTime
 * and ID of the given crimes to compare them as in operator<
 * @param crime1 a Crime object. Input parameter
 * @param crime2 a Crime object. Input parameter
 * @return true if crime1 <= crime2; false otherwise
 */
bool operator<=(Crime crime1, Crime crime2);

/**
 * @brief Overloading of the operator >= for Crime class. It uses the DateTime
 * and ID of the given crimes to compare them as in operator<
 * @param crime1 a Crime object. Input parameter
 * @param crime2 a Crime object. Input parameter
 * @return true if crime1 >= crime2; false otherwise
 */
bool operator>=(Crime crime1, Crime crime2);

#endif /* CRIME_H */
