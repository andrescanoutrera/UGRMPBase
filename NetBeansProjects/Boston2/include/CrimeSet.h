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

#include "DateTime.h"
#include "Crime.h"

/**
 * @class CrimeSet
 * @brief A CrimeSet defines a set of instances of the Crime class that includes 
 * data on crimes (offenses) committed anywhere in the world and with the types 
 * of crimes specifically considered within its own jurisdiction. 
 * This class uses an array of Crimes objects with a fixed capacity
 * to store the set of crimes. 
 * This class also contains a field to store comments, 
 * free text that allows, for example, to describe in natural language the 
 * time period considered, the origin, the query applied to obtain the set, 
 * etc. 
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
    /**
     * @brief Basic constructor and initializer. It builds a CrimeSet object
     * with a set of 0 Crimes and a capacity of DIM_VECTOR_CRIMES. The field for
     * the comments is set as an empty string
     */
    CrimeSet();
    
    /**
     * @brief Returns the number of crimes stored in the set. 
     * Query method
     * @return The number of crimes. Positive integer.
     */
    int getSize();
    
    /**
     * @brief Gets the capacity of the array of CrimeSet objects 
     * Query method
     * @return The capacity of the array of CrimeSet objects
     */
    int getCapacity();
    
    /**
     * @brief Returns the field comment of this CrimeSet. This is a string that
     * may be composed of zero or several lines of free text. 
     * Query method
     * @return A string with the lines of comments
     */
    std::string getComment();
    
    /**
     * @brief Sets the string comment for this CrimeSet object using
     * the provided string @p text. The string @p text can contain zero or 
     * several lines; each one ends with '\n'.
     * If the last line in the string  @p text does not end with '\n' then
     * the character '\n' will be appended at the end of the comment string
     * of this object.
     * If @p text is an empty string, the comment string of this object will
     * be an empty string
     * Modifier method
     * @param text string with several lines of comments. Input parameter
     */
    void setComment(std::string text);

    /**
     * @brief Obtains a string with information about this CrimeSet object, 
     * in the following format:
     * - First line, the number of crimes 
     * - A line for each Crime with information about that Crime. Each line
     * is obtained using the method Crime::toString()
     * Query method
     * @return string with information about this CrimeSet object
     */
    std::string toString();
    
    /**
     * @brief Removes all the Crimes from this object, leaving the container 
     * with a size of 0 and an empty comment
     * Modifier method
     */
    void clear();
    
    /**
     * @brief Appends the given Crime at the end of the array of Crimes of
     * this CrimeSet object, but only if that Crime was not found in this 
     * CrimeSet.  
     * @throw std::out_of_range Throws a std::out_of_range exception if the
     * number of elements in the array of Crimes is equals to the capacity
     * of that array. In that case, the array is full, and no more elements
     * can be appended to the array.
     * @param crime The Crime to append to this object. Input parameter
     * @return true if the given Crime was inserted in this CrimeSet object;
     * false otherwise
     */
    bool append(Crime crime);
    
    /**
     * @brief Gets the crime at the provided position
     * Query method
     * @param pos position in the CrimeSet. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * provided position is not valid.
     * @return A reference to the Crime at the provided position
     */
    Crime at(int pos);
     
    /**
     * @brief Searches the provided Crime in the array of crimes in this
     * CrimeSet. If found, it returns the position where it was found. If not,
     * it returns -1. We consider that position 0 is the first crime in the 
     * list of crimes and this->getSize()-1 the last crime.
     * In order to find a crime, consider only equality in the ID field.
     * Query method
     * @param crime A crime. Input parameter
     * @param initialPos initial position where to do the search. 
     * Input parameter
     * @param finalPos final position where to do the search. Input parameter
     * @return If found, it returns the position where the crime 
     * was found. Otherwise it returns -1
     */
    int findCrime(Crime crime, int initialPos, int finalPos);

    /**
     * @brief Searches the provided Crime in the array of crimes in this
     * CrimeSet. If found, it returns the position where it was found. If not,
     * it returns -1. We consider that position 0 is the first crime in the 
     * list of crimes and this->getSize()-1 the last crime.
     * In order to find a crime consider only equality in the ID field.
     * Query method
     * @param crime A crime. Input parameter
     * @return If found, it returns the position where the crime 
     * was found. Otherwise it returns -1
     */
    int findCrime(Crime crime);
       
    /**
     * @brief Loads into this object the CrimeSet information stored in the 
     * given file. See files *.crm in the folder DataSets as example of files
     * with CrimeSet information. 
     * @note Note that this method should remove the Crime objects that 
     * this object previously contained.
     * @note This method throws an exception in some error cases (see below). 
     * Before throwing the corresponding exception, this method clears
     * the object (it calls to clear() method) to leave the object in a 
     * consistent state.
     * Modifier method
     * @param fileName The name of the file where the CrimeSet is stored. 
     * Input parameter
     * @throw std::ios_base::failure Throws a std::ios_base::failure exception 
     * if the given file cannot be opened or if an error occurs while reading
     * from the file. 
     * @throw throw std::invalid_argument Throws a std::invalid_argument 
     * exception if an invalid magic string is found in the given file
     * @throw std::out_of_range Throws a std::out_of_range exception if the 
     * number of crimes in the given file is negative.
     */
    void load(std::string fileName);
    
    /**
     * @brief Saves this CrimeSet object in the given file. 
     * @note This method sends each Crime to the output stream in the same 
     * format as the one described in the Crime::toString() method
     * Query method
     * @param fileName A string with the name of the file where this CrimeSet 
     * object will be saved. Input parameter
     * @throw std::ios_base::failure Throws a std::ios_base::failure exception 
     * if the given file cannot be opened or if an error occurs while writing
     * to the file
     */
    void save(std::string fileName);
    
    /**
     * @brief Appends to this CrimeSet object, the list of  
     * Crime objects contained in the provided CrimeSet @p crimeSet that are
     * not found (using CrimeSet::findCrime(Crime)) in this CrimeSet. 
     * This method could be implemented with the help of the method 
     * CrimeSet::append(Crime crime), to append to this 
     * CrimeSet, the Crimes of the provided CrimeSet @p crimeSet.
     * Modifier method
     * @param crimeSet A CrimeSet object. Input parameter
     */
    void join(CrimeSet crimeSet);
    
    /**
     * @brief Normalizes each one of the Crime objects in this CrimeSet
     * Modifier method
     */
    void normalize();

    /**
     * @brief It takes the array of Crimes of this object as input and 
     * calculates the cumulative frequency distribution of crimes (histogram) by 
     * days of the week or by hours of the day. The histogram is saved in the 
     * array @p histogram. 
     * The DateTime field of each Crime contains the information about when it 
     * took place.
     * Query method
     * @pre the array @p histogram should have enough capacity to save the 
     * calculated frequencies. Otherwise, possible runtime errors will be obtained 
     * @throw std::out_of_range if @p dataField is neither 0 nor 1
     * @param dataField Integer to select the type of calculation to be performed: 
     * - value 0 to calculate by day of the week 
     * - value 1 to calculate by hours of the day 
     * Input parameter
     * @param histogram output array where the cumulative frequencies will be saved. 
     * Input/output parameter
     */
    void computeHistogram(int dataField, int histogram[]);

    /**
     * @brief Returns a CrimeSet object with those crimes whose label of 
     * attribute is provided with the provided @p field parameter and whose 
     * value is equals to the provided @p value parameter. 
     * This function enables simple queries as: Code = "unknown" or 
     * Code = "3114" as well as Street = "WASHINGTON ST" or 
     * DateTime = dd.toString() (being dd, a DateTime object),
     * but no other relational operators as greater than, etc. 
     * The new CrimeSet will have the same comments as this object plus a line
     * with the content: "Restricted to " + field + " = " + value + "\n" 
     * Query method
     * @param field The label of the selected attribute of the Crime class. See
     * the description of method Crime::getField(string) for possible values. 
     * Input parameter
     * @param value The value of the selected attribute. Input parameter
     * @return A CrimeSet with the selected Crimes.
     */
    CrimeSet selectWhereEQ(std::string field, std::string value);

    /**
     * @brief Returns a CrimeSet object with those crimes whose latitude and 
     * longitude are both valid.
     * Example of invalid location for a crime are: 
     * - (91,100) latitude is out of range
     * - (90,181) longitude is out of range
     * - (181,181) both are not valid
     * The new CrimeSet will have the same comments as this object plus a line
     * with the content: "Restricted to valid Coordinates\n"" 
     * Query method
     * @return A CrimeSet with those crimes whose latitude and longitude are 
     * both valid
     */
    CrimeSet selectValidLocation();
    
    /**
     * Sorts the array of Crimes by increasing alphabetical order of the field 
     * with the DateTime (sorting by date and time when the Crime took place). 
     * If two Crimes objects have the same DateTime, then  increasing 
     * alphabetical order of the field ID of those two objects will  
     * be considered.
     * Modifier method
     */
    void sort();
    
private:
    static int DIM_VECTOR_CRIMES = 2000; ///< The capacity of the array _crimes
    static std::string MAGIC_STRING_T; ///< A string with the magic string for text files
    
    /**
     * string that contains several lines of comments (text in natural 
     * language). Each line, except possibly the last one, ends with the 
     * character '\n'
     */
    std::string _comment; 
    
    Crime _crimes[DIM_VECTOR_CRIMES]; ///< Array of crimes
    int _nCrimes; ///< Number of used elements in _crimes
    
    /**
     * @brief Gets the crime at the provided position. 
     * Modifier method
     * @param pos position in the CrimeSet. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * given pos is not valid
     * @return A reference to the Crime at the given position.
     */
    Crime at(int pos);
    
    /**
     * @brief Reads comment lines from the provided input stream and appends
     * them to the end of the string _comment. 
     * In the provided input stream, comment lines are text lines that 
     * begin with the character '#'.
     * This method reads lines until a line is read that does not begin with 
     * the '#' character.
     * The '#' characters will not be saved in the string _comment, that is, 
     * this character will be discarded.
     * In the string _comment, each comment line will have the character '\n' at
     * the end.
     * @param inputStream input stream from which comments will be read 
     */
    void readComments(std::istream inputStream);

    /**
     * @brief Saves the line comments contained in the field _comment in the 
     * provided output stream. Each line will be saved as '#' plus the content
     * of that line. This method can be easily implemented with the help of the 
     * function FormatAsComment()
     * Query method
     * @param outputStream output stream where the comments will be saved
     */
    void saveComments(std::ostream outputStream);
}; // end class CrimeSet

/**
 * @brief Initializes to 0 the elements of the provided array @p array 
 * @param array Array of integers. Output parameter
 * @param size Size of the array @p array. Input parameter
 */
void InitializeArrayInts(int array[], int size);

/**
 * @brief Displays the provided histogram (cumulative frequencies of crimes 
 * by day of the week or hour of the day) on the standard output
 * @param dataField  Integer to select the type of histogram to display (0 or 1): 
 * - value 0 when the histogram contains frequencies by days of the week. In this
 * case, 7 lines will be displayed, one for each day of the week; first line 
 * for Sunday, second for Monday, and so on. Use method 
 * DateTime::dayName(int day) to recover a string with the name of each 
 * day of the week given an integer (0 for Sunday, 1 for Monday, ...). An 
 * example of output when using dataField==0 is the following:
SUNDAY 25
MONDAY 11
TUESDAY 12
WEDNESDAY 5 
THURSDAY 13
FRIDAY 17
SATURDAY 32
 * - value 1 when the histogram contains frequencies by hours of the day. In 
 * this case, 24 lines will be displayed, one for each hour of the day; 
 * first line for hour 0, second line for hour 1, and so on. An example of 
 * output when using dataField==1 is the following:
0 23
1 21
2 15
3 12
4 7
5 3
6 2
7 0
8 5
...
 * - Other values for dataField produce empty output
 * Input parameter
 * @param histogram histogram with cumulative frequencies by day of the week 
 * or hour of the day. Input parameter
 */
void PrintHistogramArrayCrimes(int dataField, int histogram[]);

/**
 * Returns a string with the same content as the provided string @p comment,
 * but with the character @p commentCharacter inserted at the begining
 * of each line, thus obtaining a formatted comment. The character 
 * @p commentCharacter is '#' by default.
 * In case that the last line in @p comment does not have '\n' at the end, 
 * this function add it to the end of the returned string.
 * @param comment The input string to be used to format the comment.
 * @param commentCharacter The character to use at the begining of the formatted
 * string
 * @return A string with the same content as the provided string @p comment,
 * but with the character @p commentCharacter inserted at the begining
 * of each line
 */
std::string FormatAsComment(std::string comment, char commentCharacter='#');

#endif /* CRIMESET_H */

