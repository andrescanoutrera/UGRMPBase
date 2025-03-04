/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/**
 * @file Crime.h
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
    /**
     * @brief default constructor that builds a Crime object with a default 
     * value for every field. The default values for each field are obtained
     * from the string @ref Crime::CRIME_DEFAULT
     */
    Crime();
    
    /**
     * @brief Builds a Crime object with the data contained in the provided
     * string. This string is a line of a csv file with fields separated by
     * commas. The details are described in the documentation of this class.
     * @pre The @p line parameter has the same preconditions as the method 
     * Crime::set(const std::string & line)
     * @param line a string with the data to build the object. Input parameter
     */
    Crime(const std::string & line);

    /**
     * @brief Returns the counter of this Crime
     * Query method
     * @return The counter of this Crime
     */
    int getCounter() const;
    
    /**
     * @brief Returns the offense ID, a primary key for identify any crime in 
     * a dataset. This ID is unique in a dataset of crimes. 
     * Query method
     * @return The offense ID.
     */
    std::string getId() const;

    /**
     * @brief Returns the offense code of this crime. 
     * Query method
     * @return The offense code number
     */
    std::string getCode() const;

    /**
     * @brief Returns the group offense of this crime. It is a string that may 
     * contain identifying words to group the offense
     * Query method
     * @return The group offense of this crime
     */
    std::string getGroup() const;
    
    /**
     * @brief Returns the description for this crime. It contains some keys 
     * words for the description of this crime.
     * Query method 
     * @return The description of this crime
     */
    std::string getDescription() const;

    /**
     * @brief Returns the name of the district for this crime. 
     * Query method
     * @return The district of this crime
     */
    std::string getDistrict() const;
    
    /**
     * @brief Returns the name of street where this crime took place. 
     * Query method
     * @return The street where this crime took place
     */
    std::string getStreet() const;

    /**
     * @brief Returns the coded area where this crime took place. It is a
     * a string that may contain a letter and a number 
     * Query method
     * @return The area of this crime
     */
    std::string getAreaReport() const;

    /**
     * @brief Returns if the crime was caused by a gunshot. 
     * Query method
     * @return true if this crime was caused by a gunshot; false otherwise
     */
    bool isShooting() const;
    
    /**
     * @brief Returns the date and time of this crime. 
     * Query method
     * @return The date and time
     */
    DateTime getDateTime() const;

    /**
     * @brief Returns the value of the Coordinates where this crime took place. 
     * Query method
     * @return Coordinates where this crime took place
     */
    Coordinates getLocation() const;

    /**
     * @brief Returns if the object has UNKNOWN ID. 
     * Query method
     * @return bool true if the crime ID is equals to constant UNKNOWN_VALUE; 
     * false otherwise.
     */
    bool isIDUnknown() const;

    /**
     * @brief Obtains a string with the fields of this Crime object, by using 
     * comma as separator. Fields appears in the following order: 
     * - 0  COUNTER <br>
     * - 1  IDENTIFIER_NUMBER <br>
     * - 2  OFFENSE_CODE <br>
     * - 3  OFFENSE_CODE_GROUP <br>
     * - 4  OFFENSE_DESCRIPTION <br>
     * - 5  DISTRICT <br>
     * - 6  REPORTING_AREA <br>
     * - 7  SHOOTING <br>
     * - 8  OCCURRED_ON_DATE  <br>
     * - 9  STREET <br>
     * - 10 LATITUDE <br>  
     * - 11 LONGITUDE <br>
     * 
     * Depending on the type of the field, it may be necessary to convert the 
     * value to a string as for example with: _counter, _shotting, _dateTime, 
     * _location:
     * - In the case of _counter the string will be obtained using the
     * std::to_string() function.
     * - In the case of _shotting the  string will be "0" or "1". 
     * - In the case of _dateTime and _location the string will be 
     * obtained with the toString() method of the corresponding class.
     * 
     * Query method
     * @return string that contains the fields of this Crime in csv format 
     * (by using commas as separator).
     */
    std::string toString() const;

    /**
     * @brief Sets the counter for this crime with the provide value
     * Modifier method
     * @param c the counter value to be set. Input parameter
     */
    void setCounter(int c);
    
    /**
     * @brief Sets the offense ID (primary key for identify the crime in 
     * a dataset) of this object using the provided string @p id. 
     * First of all, this method trims spaces and \t characters at the 
     * beginning and at the end of the provided string. It the resulting
     * string is empty, this method does not modify the ID of this object
     * and an std::invalid_argument exception will be thrown; otherwise 
     * it assigns the resulting string to the field for the offense ID.
     * Modifier method
     * @param id the offense ID value to be set. Input parameter
     * @throw std::invalid_argument Throws an std::invalid_argument exception 
     * if the provided string @p id is an empty string after removing its 
     * initial and final whitespaces and '\t' characters.
     */
    void setId(const std::string & id);
    
    /**
     * @brief Sets the offense code of this crime. 
     * Modifier method
     * @param code the offense code value to be set. Input parameter
     */
    void setCode(const std::string &code);

    /**
     * @brief Sets the group offense that belongs the crime. 
     * Modifier method
     * @param group the offense group value to be set. Input parameter
     */
    void setGroup(const std::string &group);
    
    /**
     * @brief Sets the description for the offense. 
     * Modifier method
     * @param description the offense description value to be set. 
     * Input parameter
     * @return A string that contains some keys words for the description
     */
    void setDescription(const std::string & description);
    
    /**
     * @brief Sets the name of the district for the crime. 
     * Modifier method
     * @param district the identifier for the district to be set. Input parameter
     */
    void setDistrict(const std::string &district);

    /**
     * @brief Sets the coded area where the offense took place. 
     * Modifier method
     * @param areaReport the area value to be set. Input parameter
     * @return A string that may contain a letter and a number
     */
    void setAreaReport(const std::string &areaReport);
    
    /**
     * @brief Sets the name of street where the offense  took place. 
     * Modifier method
     * @param street the street name that may contain the name with the type of 
     * route to be set. Input parameter
     */
    void setStreet(const std::string &street);

    /**
     * @brief It gives the aggravating evidence for the crime. 
     * Modifier method
     * @param shotting  the boolean value for shotting to be set. Input parameter
     */
    void setShooting(bool shotting);

    /**
     * @brief Sets the DataTime field (date and time) of this crime object
     * with the data in the provided string \p time. If \p time is empty or it 
     * is in invalid format, the date and time of this object will be set with 
     * @ref DateTime::DATETIME_DEFAULT.
     * 
     * @note The implementation of this method needs only call to 
     * method DateTime::set(time).
     * 
     * Modifier method
     * @param time Datetime in the format specified in @ref DateTime. 
     * Input parameter
     */
    void setDateTime(const std::string & time);

    /**
     * @brief Sets the coordinates where the crime took place. 
     * Modifier method
     * @param coordinates the coordinates value to set. Input parameter
     */
    void setLocation(const Coordinates & coordinates);

    /**
     * @brief It sets all the data members of the object by extracting their
     * values (in the order indicated in the below list) from the provided string
     * @p line that describes the crime in csv format, that is, concatenation
     * of every field by using commas as separator between fields.  
     * To set the value of each field in this class, this method will use each 
     * one of the set methods in this class
     * 
     * The values to set the object are:
     * - 0  COUNTER <br>
     * - 1  IDENTIFIER_NUMBER <br>
     * - 2  OFFENSE_CODE <br>
     * - 3  OFFENSE_CODE_GROUP <br>
     * - 4  OFFENSE_DESCRIPTION <br>
     * - 5  DISTRICT <br>
     * - 6  REPORTING_AREA <br>
     * - 7  SHOOTING <br>
     * - 8  OCCURRED_ON_DATE  <br>
     * - 9  STREET <br>
     * - 10 LATITUDE <br>  
     * - 11 LONGITUDE <br>
     * 
     * Modifier method

     * @pre The string for the COUNTER field must contain an integer number; 
     * otherwise an unpredictable behavior or runtime error will be obtained
     * @pre The string for the ID field must contain at least one character
     * different from whitespace and \t character; otherwise an unpredictable 
     * behavior or runtime error will be obtained
     * @pre The string for the SHOOTING field must contain "0" or "1"; 
     * otherwise an unpredictable behavior or runtime error will be obtained
     * @pre The string for both latitude and longitude fields must contain 
     * a real number; otherwise an unpredictable behavior or runtime error 
     * will be obtained
     * @pre The string for the OCCURRED_ON_DATE field must be in valid format 
     * "year-month-day hour:minutes:seconds"; otherwise an unpredictable 
     * behavior or runtime error will be obtained
     * @param line a string that contains a crime in csv format. Input parameter
     */
    void set(const std::string & line);
    
private:
    int _counter; ///< COUNTER: A counter (integer)
    
    /**
     * IDENTIFIER_NUMBER: Identifier of the crime. The string for this field 
     * must contain at least one character different from whitespace and \t 
     * character
     */
    std::string _id;
    
    std::string _code; ///< OFFENSE_CODE: A string with am internal code for the kind of crime
    std::string _group; ///< OFFENSE_CODE_GROUP: A string with a code for the group to which the crime belong
    std::string _description; ///< OFFENSE_DESCRIPTION: A string with a brief description of the crime
    std::string _district; ///< DISTRICT: the district where the crime took place
    std::string _areaReport; ///< REPORTING_AREA: the area where the crime took place
    bool _shooting; ///< SHOOTING: true if the crime was committed with a gunshot
    DateTime _dateTime; ///< OCCURRED_ON_DATE: date and time when the crime took place
    std::string _street; ///< STREET: name of the street where the crime took place
    Coordinates _location; ///< LOCATION: GPS coordinates where the crime took place
    
    /**
     * A const string that contains the value "UNKNOWN" that will be assigned 
     * by default to string fields in a Crime object
     */
    static const std::string UNKNOWN_VALUE;
    
    /**
     * A const string with the default value for the DateTime of a Crime object 
     * ("2017-01-20 02:00:00")
     */
    static const std::string DATETIME_DEFAULT;

    /**
     * A string that contains the default value for every field in a Crime object
     * The content is: "0," + UNKNOWN_VALUE + "," + UNKNOWN_VALUE + "," + 
     * UNKNOWN_VALUE + "," + UNKNOWN_VALUE + "," + UNKNOWN_VALUE + "," + UNKNOWN_VALUE +
     *  "," + ((std::string)"0") + "," + DATETIME_DEFAULT + "," +
     * UNKNOWN_VALUE + ",181,181"
     */
    static const std::string CRIME_DEFAULT;
}; // end class Crime

/**
 * Removes spaces and \t characters at the beginning and at the end of the 
 * provided string @p myString. If the provided string @p myString is empty
 * or contains only spaces or \t characters then @p myString will contain an
 * empty string after calling to this function.
 * @note This function can be easily implemented using the methods 
 * find_first_not_of(string) and find_last_not_of(string) of class string.
 * @param myString a string. Input/Output parameter
 */
void Trim(std::string & myString);

/**
 * Converts to uppercase all the characters in the provided string @p myString
 * @param myString a string. Input/Output parameter
 */
void Capitalize(std::string & myString);

/**
 * Normalizes every string field in the provided Crime object. That is: 
 * -# It removes spaces and \t characters at the beginning and at the end 
 * of every string field 
 * -# It converts to uppercase every string field
 * For the ID field only the conversion to uppercase is necessary because an 
 * ID cannot contains leading or trailing blanks
 */
void Normalize(Crime & crime);

#endif /* CRIME_H */


