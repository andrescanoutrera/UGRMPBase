/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/**
 * @file DateTime.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es> 
 * 
 * Created on September 17, 2024, 5:43 PM
 */

#ifndef DATETIME_H
#define DATETIME_H

#include <string>

/** 
 * @class DateTime 
 * @brief Used to represent dates and times in 
 * the format YYYY-MM-dd hh:mm::ss, where
 * 
 * ~~~~
 *      YYYY-MM-dd hh:mm:ss 
 *      +----+----+----+----+
 *      |    |    |    |    |
 *      0    5    10   15   20  
 * ~~~~
 * 
 *    - YYYY Year    Any value allowed
 *    - MM Month    values in [1,12]
 *    - dd day      values depending on the calendar
 *    - hh hour     values in [0,23]
 *    - mm minute   values in [0,59]
 *    - ss seconds  values in [0,59]
 * 
 *    The hour is in the UTC (Coordinated Universal Time) format.
 */
class DateTime {
private:
    int _year; ///< year
    int _month; ///< month (from 1 to 12)
    int _day; ///< day (from 1 to 31)
    int _hour; ///< hour (from 0 to 23)
    int _min; ///< (from 0 to 59)
    int _sec; ///< (from 0 to 59)
    
    /**
     *  Array with the names of days of the week in English
     */
    static const std::string DAY_NAMES []; 
    
    void initDefault();

public:
    /**
     * String with the default value for a DateTime object 
     * ("2000-01-01 00:00:00")
     */
    static const std::string DATETIME_STRING_DEFAULT; 

    /**
     * @brief Base constructor. It sets the default date and time
     */
    DateTime();
    
    /**
     * @brief Constructor that builds a DataTime from the data in the
     * provided string. If the string contains a valid date 
     * and time, it builds an object with the provided content; otherwise it 
     * builds an object with the default DateTime. See 
     * @ref DateTime::DATETIME_STRING_DEFAULT
     * @pre The provided string date must be in the correct format 
     * (YYYY-MM-dd hh:mm:ss), that is no errors of conversion is obtained when 
     * using stoi() for each field.
     * @param date The string containing date and time
     * Input parameter
     */
    DateTime(const std::string & date);
    
    /**
     * @brief It returns the year. 
     * Query method
     * @return The year of the date as an integer value
     */
    int year() const;
    
    /**
     * @brief It returns the month. 
     * Query method
     * @return The month of the date within its valid bounds
     */
    int month() const;
    
    /**
     * @brief It returns the day. 
     * Query method
     * @return The day of the date within its valid bounds
     */
    int day() const;
    
    /**
     * @brief It returns the hour. 
     * Query method
     * @return  The hour of the date within its valid bounds
     */
    int hour() const;
    
    /**
     * @brief It returns the minutes. 
     * Query method
     * @return The number of minutes of the date within its valid bounds
     */
    int minutes() const;
    
    /**
     * @brief It returns the number of seconds. 
     * Query method
     * @return The seconds of the date within its valid bounds
     */
    int seconds() const;
    
    /**
     * @brief Set this DataTime object with the data in the provided string \p line.  
     * A correct format is as follows: (YYYY-MM-dd hh:mm:ss). If \p line is
     * not in the correct format this DataTime will be set with the data
     * in @ref DataTime::DATETIME_DEFAULT
     * Modifier method
     * @param line the string given from the csv format YYYY-MM-dd hh:mm::ss. 
     * Input parameter 
     */
    void set(const std::string &line);
    
    /**
     * @brief Transforms this DataTime object to a string using the 
     * format: YYYY-MM-dd hh:mm::ss
     * Query method
     * @return string that contains the dateTime in the indicated format.
     */
    std::string toString() const;

    /**
     * @brief Computes the week day from this DateTime object. 
     * The implementation is based on the Zeller's congruence; look at 
     * wikipedia https://en.wikipedia.org/wiki/Zeller%27s_congruence
     * Query method.
     * @return values in the range 0..6, where 0 is Sunday, 1 is Monday ...
     */
    int weekDay() const;
    
    /**
     * Returns a string with the name of the provided day of the week (0 to 6).
     * - 0: SUNDAY
     * - 1: MONDAY
     * - ...
     * - 6: SATURDAY
     * 
     * @param day selected day to return (0 to 6)
     * @throw std::invalid_argument Throws an std::invalid_argument exception 
     * if day is not in the interval [0, 6]
     * @return a string with the name of the provided day of the week (0 to 6).
     */
    static const std::string& dayName(int day);
}; // end class DateTime

/**
 * @brief Auxiliar function to check if the provided date and time are in 
 * correct format, taking into account, leap year, day in a month, etc.
 * @param year input
 * @param month input
 * @param day input
 * @param hour input
 * @param min input
 * @param sec input
 * @return true if is correct, else return false
 */
bool isCorrect(int year, int month, int day, int hour, int min, int sec);

/**
 * @brief Auxiliar function to obtain from the provided string @p line
 * the 6 components of a DateTime object.
 * Please consider using string::substr(int, int)[https://en.cppreference.com/w/cpp/string/basic_string/substr] to cut the line
 * into the appropriate substrings and then convert it into integer values with 
 * the function stoi(string) [https://en.cppreference.com/w/cpp/string/basic_string/stol]
 * ~~~~
 *      YYYY-MM-dd hh:mm:ss 
 *      +----+----+----+----+
 *      |    |    |    |    |
 *      0    5    10   15   20  
 * ~~~~
 * 
 * @param line input string
 * @param y output int
 * @param m output int
 * @param d output int
 * @param h output int
 * @param mn output int
 * @param s output int
 */
void split(const std::string& line, int &y, int & m, int & d, int & h, int &mn, int &s);

/**
 * @brief Overloading of the relational operator < for DateTime class
 * @param dateTime1 The first object to be compared. Input parameter
 * @param dateTime2 The second object to be compared. Input parameter
 * @return true if the DateTime of @p dateTime1 is smaller (before)  than that of
 * @p dateTime2; false otherwise
 */
bool operator<(const DateTime& dateTime1, const DateTime& dateTime2);

/**
 * @brief Overloading of the operator > for DateTime class
 * @param dateTime1 a DateTime object. Input parameter
 * @param dateTime2 a DateTime object. Input parameter
 * @return true if dateTime1 > dateTime2; false otherwise
 */
bool operator>(const DateTime& dateTime1, const DateTime& dateTime2);

/**
 * @brief Overloading of the operator == for DateTime class
 * @param dateTime1 a DateTime object. Input parameter
 * @param dateTime2 a DateTime object. Input parameter
 * @return true if the two DateTimes are the same, that is same date and hour;
 * false otherwise
 */
bool operator==(const DateTime& dateTime1, const DateTime& dateTime2);

/**
 * @brief Overloading of the operator != for DateTime class
 * @param dateTime1 a DateTime object. Input parameter
 * @param dateTime2 a DateTime object. Input parameter
 * @return true if the two DateTimes are not equals (see operator==); 
 * false otherwise
 */
bool operator!=(const DateTime& dateTime1, const DateTime& dateTime2);

/**
 * @brief Overloading of the operator <= for DateTime class
 * @param dateTime1 a DateTime object. Input parameter
 * @param dateTime2 a DateTime object. Input parameter
 * @return true if dateTime1 <= dateTime2; false otherwise
 */
bool operator<=(const DateTime& dateTime1, const DateTime& dateTime2);

/**
 * @brief Overloading of the operator >= for DateTime class
 * @param dateTime1 a DateTime object. Input parameter
 * @param dateTime2 a DateTime object. Input parameter
 * @return true if dateTime1 >= dateTime2; false otherwise
 */
bool operator>=(const DateTime& dateTime1, const DateTime& dateTime2);

#endif /* DATETIME_H */
