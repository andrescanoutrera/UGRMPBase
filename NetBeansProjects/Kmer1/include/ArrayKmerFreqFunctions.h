
/*
 * Metodología de la Programación: Kmer1
 * Curso 2023/2024
 */

/** 
 * @file ArrayKmerFreqFunctions.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 * 
 * Created on 27 October 2023, 11:00
 */
#ifndef ARRAYKMERMFREQFUNCTIONS_H
#define ARRAYKMERFREQFUNCTIONS_H

#include "KmerFreq.h"

/**
 * @brief Reads the number of used elements and the elements of an array of
 * KmerFreq
 * If @p nElements is greater than @p dim, then only @p dim elements are read
 * If @p nElements is negative, then zero elements are read
 * @param array An array where the elements will be stored. Output parameter
 * @param dim The capacity of the array. Input parameter
 * @param nElements The number of elements used by the array. Note that this
 * integer could be modified in this function. Output parameter
*/
void ReadArrayKmerFreq(KmerFreq array[], int dim, int nElements);

/**
 * @brief Prints in the standard output the number of used elements and the 
 * elements of an array of KmerFreq 
 * @param array The array of KmerFreq to be printed. Input parameter
 * @param nElements The number of elements used by the array. Input parameter
*/
void PrintArrayKmerFreq(KmerFreq array[], int nElements);

/**
 * @brief Swaps the elements at positions @p first and @p second in the given
 * array of KmerFreq
 * @param array An array of KmerFreq. Input/output parameter
 * @param nElements The number of elements used by the array. Input parameter
 * @param first the position of the first element to be swaped. Input parameter
 * @param second the position of the second element to be swaped. Input parameter
 * @throw Throws a std::out_of_range exception if first or second are positions 
 * out of the range of the given array
*/
void SwapElementsArrayKmerFreq(KmerFreq array[], int nElements, int first,
                int second);

/**
 * @brief Searchs the given Kmer in the subarray of @p array that begins at 
 * position @p initialPos and ends at position @p finalPos (both included)
 * @param array An array of KmerFreq objects. Input parameter
 * @param kmer The Kmer to be found. Input parameter
 * @param initialPos The initial position of the subarray. Input parameter
 * @param finalPos The final position of the subarray. Input parameter
 * @return the position where the given Kmer is in the subarray of @p array 
 * that begins at position @p initialPos and ends at position @p finalPos 
 * (both included). If the given Kmer is not found, then -1 is returned.
 */
int FindKmerInArrayKmerFreq(KmerFreq array[], Kmer kmer,
        int initialPos, int finalPos);

/**
 * @brief Sorts the given array of KmerFreq in decreasing order of
 * frequency using a sort algorithm.
 * Note: It is not allowed to use any sorting algorithm available in any
 * C++ library.
 * @param array An array of KmerFreq. Input/output parameter
 * @param nElements The number of elements used by the array. Input parameter
*/
void SortArrayKmerFreq(KmerFreq array[], int nElements);


/**
 * @brief Normalizes the given array of KmerFreq. That is, for each Kmer in
 * the array, all its characters are converted to uppercase. Then, invalid 
 * characters are replaced by the MISSING_NUCLEOTIDE value.
 * 
 * If after the previous normalization process of every kmer, identical kmers 
 * are obtained, these will be merged into the first identical kmer by 
 * adding their frequencies. 
 * For example, suposse the following list of kmers:
4
Ct 5
hG 4
nG 1
cT 4
 * 
 * After the process of normalization of every kmer, we obtain the following 
 * list of kmers:
 * 
4
CT 5
_G 4
_G 1
CT 4
 * 
 * The final step will transform the list into:
2
CT 9
_G 5
 * 
 * @param array An array of KmerFreq. Input/output parameter
 * @param nElements The number of elements used by the array. Output parameter
 * @param validNucleotides a string with the list of characters (nucleotides) 
 * that should be considered as valid. Input parameter
*/
void NormalizeArrayKmerFreq(KmerFreq array[], int nElements, 
        std::string validNucleotides);

/**
 * @brief Deletes the KmerFreq object from the argument array that is at 
 * position @p pos.
 * @param array An array of KmerFreq.  nput/output parameter
 * @param nElements The number of elements used by the array. Note that the 
 * number of elements in the argument array will be modified. Input/output parameter
 * @param pos The index of the position to be deleted. Input parameter
 * @throw std::out_of_range Throws an std::out_of_range exception if @p pos 
 * is not in the range from 0 to nElements-1 (both included).
 */
void DeletePosArrayKmerFreq(KmerFreq array[], int nElements, int pos);

/**
 * @brief Deletes the KmerFreq objects from the argument array which verifies
 * one the following two criteria:
 *  -# The argument deleteMissing is true and the Kmer contains an unknown 
 * nucleotide 
 *  -# The frequency is less or equals to @p lowerBound. 
 * 
 * Note that the number of elements in the argument array could be modified.
 * 
 * @param array An array of KmerFreq. Input/output parameter
 * @param nElements The number of elements used by the array. Note that the 
 * number of elements in the argument array could be modified. Input/output parameter
 * @param deleteMissing A bool value that indicates whether kmers with any 
 * unknown nucleotide should be removed. This parameter is false by default. 
 * Input parameter
 * @param lowerBound An integer value that defines which KmerFreq objects 
 * should be deleted from the given argument array. KmerFreq objects with a 
 * frequency less or equals to this value, are deleted. This parameter has zero
 * as default value. Input parameter
 */
void ZipArrayKmerFreq(KmerFreq array[], int nElements, 
        bool deleteMissing=false, int lowerBound=0);

#endif /* ARRAYKMERFREQFUNCTIONS_H */

