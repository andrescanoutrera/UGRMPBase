/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/** 
 * @file  ArrayCrimeSetFunctions.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es> 
 * @note To be implemented by students
 *  
 * Created on November 26, 2024, 11:04 AM
 */

#ifndef ARRAYCRIMESETFUNCTIONS_H
#define ARRAYCRIMESETFUNCTIONS_H

#include "CrimeSet.h"

/**
 * @brief Reads the CrimeSets contained in the files whose names are provided
 * in the given input stream (one name of file in each line) and appends then 
 * at the end of the dynamic array @p arrayCrimeSet. 
 * In case that the input stream contains empty lines, they should be ignored, 
 * because an empty line corresponds with the empty string for the name of
 * the file to be read.
 * This function can be implemented with the help of the function 
 * AppendCrimeArrayCrimeSet() that automatically reallocate the dynamic array, 
 * each time a new CrimeSet is appended to the array.
 * nCrimeSets will contain the number of CrimeSet saved in the the dynamic array
 * @param inputStream Input stream. Input/output parameter 
 * @param arrayCrimeSet A pointer to a dynamic array of CrimeSet. 
 * The pointer is an input/output parameter and the content of the array can 
 * be modified
 * @param nCrimeSets Number of CrimeSets in the dynamic array arrayCrimeSet. 
 * Input/output parameter 
 */
void ReadArrayCrimeSet(std::istream inputStream, CrimeSet *arrayCrimeSet, 
        int nCrimeSets);

/**
 * @brief Shows in the standard output the CrimeSet contained in the 
 * provided array @p arrayCrimeSet. Each CrimeSet is shown with the 
 * help of the method CrimeSet::toString()
 * @param arrayCrimeSet A pointer to a dynamic array of CrimeSet. 
 * The pointer is an input parameter and the content of the array is not modified
 * @param nCrimeSets Number of CrimeSets in the dynamic array arrayCrimeSet. 
 * Input parameter 
 */
void PrintArrayCrimeSet(CrimeSet *arrayCrimeSet, int nCrimeSets);

/**
 * @brief Allocates memory for a dynamic array of CrimeSets with a capacity 
 * equals to @p nCrimeSets
 * @param nCrimeSets number of CrimeSets to allocate in the dynamic array. 
 * Input parameter
 * @return A pointer to the allocated memory for the dynamic array. If 
 * @p nCrimeSets <= 0 it returns nullptr
 */
CrimeSet * AllocateArrayCrimeSet(int nCrimeSets);

/**
 * @brief Deallocates the memory pointed by the provided dynamic array of 
 * CrimeSets @arrayCrimeSet. That pointer will also be set to nullptr
 * @param arrayCrimeSet A pointer to a dynamic array of CrimeSet. 
 * The pointer is an input/output parameter and the content of the array is 
 * modified
 */
void DeallocateArrayCrimeSet(CrimeSet * arrayCrimeSet);

/**
 * @brief Appends the provided CrimeSet @p newCrimeSet at the end of the 
 * dynamic array of CrimeSet @p arrayCrimeSet. This function starts by 
 * reallocating the array, increasing its capacity by 1 to allow saving the
 * new CrimeSet.
 * @param arrayCrimeSet A pointer to a dynamic array of CrimeSet. 
 * The pointer is an input/output parameter and the content of the array can 
 * be modified
 * @param nCrimeSets Number of CrimeSets in the dynamic array arrayCrimeSet. 
 * Input/output parameter 
 * @param newCrimeSet The new CrimeSet to be inserted at the end of the
 * dynamic array. Input parameter
 */
void AppendCrimeArrayCrimeSet(CrimeSet * arrayCrimeSet, int nCrimeSets, 
        CrimeSet newCrimeSet);

#endif /* ARRAYCRIMESETFUNCTIONS_H */
