/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/** 
 * @file ArrayCrimesFunctions.h
 * 
 * Created on September 19, 2024, 1:14 PM
 */

#ifndef ARRAYCRIMESFUNCTIONS_H
#define ARRAYCRIMESFUNCTIONS_H

#include "Crime.h"

/**
 * @brief Initializes to 0 the elements of the provided array @p array 
 * @param array Array of integers. Output parameter
 * @param size Size of the array @p array. Input parameter
 */
void InitializeArrayInts(int array[], int size);

/**
 * @brief Obtains the maximum value and its position (index) in the
 * provided array of integers @p array 
 * @param array Array of integers. Input parameter
 * @param size The size of @p array. Input parameter
 * @param max The maximum value found in the vector. Output parameter
 * @param posMax The position in the array of the value with the maximun. Output parameter
 */
void ComputeMaxPosArrayInts(int array[], int size, int max, int posMax);

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
 * first line for hour 0, 1 for hour 1, and so on. An example of output when 
 * using dataField==1 is the following:
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
 * @brief Displays the content of the provided array of Crimes on the standard 
 * output. Each Crime is displayed in a new line with the help of the 
 * Crime::toString() method
 * @param crimes array of Crimes. Input parameter
 * @param nCrimes number of crimes in the array. Input parameter
 */
void PrintArrayCrimes(Crime crimes[], int nCrimes);

/**
 * @brief Finds the position of the element with the minimum crime in the
 * subarray of @p array that begins at position @p initialPos and ends at position
 * @p finalPos (both included). The order
 * criterion among Crimes uses the dateTime and ID fields: crime1<crime2 if
 * crime1.dateTime < crime2.dateTime. If crime1.dateTime == crime2.dateTime
 * then the alphabetical order of the ID field is used.
 * @param array An array of Crime. Input parameter
 * @param initialPos The initial position of the subarray. Input parameter
 * @param finalPos The final position of the subarray. Input parameter
 * @return the position of the element with minimum crime in the subarray 
 * that begins at position @p initialPos and ends at position @p finalPos 
 * (both included). If no element can be retrieved, it returns -1
*/
int PosMinArrayCrimes(Crime array[], int initialPos, int finalPos);

/**
 * @brief Swaps the elements at positions @p first and @p second in the given
 * array of Crime
 * @param array An array of Crime. Input/output parameter
 * @param nElements The number of elements used by the array. Input parameter
 * @param first the position of the first element to be swaped. Input parameter
 * @param second the position of the second element to be swaped. Input parameter
 * @throw Throws a std::out_of_range exception if first or second are positions 
 * out of the range of the given array
*/
void SwapElementsArrayCrimes(Crime array[], int nElements, int first, int second);

/**
 * @brief Sorts the given array of Crime in increasing order using a sorting 
 * algorithm. The criterion order among Crimes is the same as the one
 * explained in the function PosMinArrayCrimes, that uses the dateTime and ID 
 * fields of each Crime.
 * 
 * @note It is not allowed to use any sorting algorithm available in any 
 * C++ library.
 * @param array An array of Crime. Input/output parameter
 * @param nElements The number of elements used by the array. Input parameter
*/
void SortArrayCrimes(Crime array[], int nElements);

/**
 * @brief Searchs if the Id of the provided Crime is in the subarray of @p array 
 * that begins at position @p initialPos and ends at position @p finalPos 
 * (both included)
 * @param array An array of Crime objects. Input parameter
 * @param Crime The Crime to be found. Input parameter
 * @param initialPos The initial position of the subarray. Input parameter
 * @param finalPos The final position of the subarray. Input parameter
 * @return the position where the Id of the given Crime is in the subarray of 
 * @p array that begins at position @p initialPos and ends at position @p finalPos 
 * (both included). If the given Crime is not found, then -1 is returned.
 */
int FindCrimeInArrayCrimes(Crime array[], Crime crime,
        int initialPos, int finalPos);

/**
 * It takes the array of Crimes @p crimes as input and calculates the 
 * cumulative frequency distribution of crimes (histogram) by days of the week 
 * or by hours of the day. The histogram is saved in the array @p histogram. 
 * The DateTime field of each Crime contains the information about when it 
 * took place.
 * @pre the array @p histogram should have enough capacity to save the 
 * calculated frequencies. Otherwise, possible runtime errors will be obtained 
 * @throw std::out_of_range if @p dataField is neither 0 nor 1
 * @param crimes Input array of Crime objects. Input parameter
 * @param nCrimes The size of @p crimes. Input parameter
 * @param dataField Integer to select the type of calculation to be performed: 
 * - value 0 to calculate by day of the week 
 * - value 1 to calculate by hours of the day 
 * Input parameter
 * @param histogram output array where the cumulative frequencies will be saved. 
 * Input/output parameter
 */
void ComputeHistogramArrayCrimes(Crime crimes[], int nCrimes, 
        int dataField, int histogram[]);

/**
 * @brief Saves in the array @p outputCrimes those crimes in the array 
 * @p inputCrimes whose name of attribute is provided with @p field parameter 
 * and whose value is equals to @p value parameter. 
 * This function enables simple queries as: "Code" == "unknown" or "Code"== "3114"
 * as well as "Street"== "WASHINGTON ST" or "DateTime"==dd.to_string() 
 * (being dd, a DateTime object),* but no other relational operators as 
 * greater than etc. 
 * @pre The array @p outputCrimes must have enough capacity to save all the
 * Crimes that verify the given condition.
 * @param inputCrimes Input array of crimes. Input parameter
 * @param inputCrimesSize size of the array @p inputCrimes. Input parameter
 * @param field The label of the selected attribute of the Crime class. See
 * the description of method Crime::getField(string) for possible values. 
 * Input parameter
 * @param value The value of the selected attribute. Input parameter
 * @param outputCrimes Output array where the selected Crimes will be stored.
 * Output parameter
 * @param outputCrimesSize Size of the array @p outputCrimes. Output parameter
 */
void SelectWhereEQArrayCrimes(Crime inputCrimes[], int  inputCrimesSize, 
        std::string  field, std::string value,  
        Crime outputCrimes[], int outputCrimesSize);

#endif /* ARRAYCRIMESFUNCTIONS_H */

