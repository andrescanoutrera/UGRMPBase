/*
 * Metodología de la Programación: Kmer5
 * Curso 2023/2024
 */

/* 
 * @file:   KmerCounter.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 *
 * Created on 7 November 2023, 14:00
 */

#ifndef KMER_COUNTER_H
#define KMER_COUNTER_H

#include <string>

#include "Profile.h"

/**
 * @class KmerCounter
 * @brief It is a helper class used to calculate the frequency of each kmer in
 * a text file. 
 * It consists of a matrix of integers. Each element in the matrix contains
 * the frequency of the kmer that is defined by its row and column: the kmer formed 
 * taking the nucleotides defined by the row and column of that element. 
 * 
 * This class has a private data member string _validNucleotides to contain the set of
 * possible nucleotides in a kmer and a private data member
 * string _allNucleotides that contains the character that define the missing
 * nucleotide (Kmer::MISSING_NUCLEOTIDE) plus the characters in 
 * _validNucleotides. Also, it contains a private data member int _k that
 * defines the number of nucleotides in each kmer.
 * 
 * For example, if "ACGT" are the valid nucleotides, then _validNucleotides will
 * be "ACGT", _allNucleotides will be "_ACGT". 
 * If the number of nucleotides in each kmer is 5, then _k will be 5. The first 
 * 3 nucleotides of each kmer will be associated to index the rows of the 
 * frequency matrix and the last 2 nucleotides to index the columns. For 
 * example, for the kmer "ACATG", "ACA" will be used to index the row and
 * "TG" to index the column.
 * In this example, the first row corresponds to "___", the second to "__A",
 * the third to "__C" and so on. The first column corresponds to "__",
 * the second to "_A", the third to "_C" and so on.
 * 
 *  
 * When searching for kmers in a text file, if we find a character that 
 * does not belong to the set of valid nucleotides, it will be replaced by the 
 * character Kmer::MISSING_NUCLEOTIDE in the corresponding kmer
 */
class KmerCounter {
public:

    /**
     * A const c-string with the set of characters that are considered as 
     * part of a word. Any other character will be considered a separator  
     * Only lowercase characters are included in this string. This c-string
     * is used in the constructor of this class, as the default value to assign
     * to the field _validNucleotides
     */
    static const char* const DEFAULT_VALID_NUCLEOTIDES;

    /**
     * @brief Constructor of the class. This object uses a matrix of 
     * integers that contains the frequency for each kmer. Each element of the 
     * matrix will be initialized with 0. The constructor also initializes the
     * private data _k, _validNucleotides and _allNucleotides. _allNucleotides
     * is initialized with the characters 
     * Kmer::MISSING_NUCLEOTIDE + validNucleotides
     * @param k The number of nucleotides in each kmer. Input parameter
     * @param validNucleotides The set of nucleotides (characters) that are 
     * considered as part of a kmer. Input parameter
     */
    KmerCounter(int k=5, 
       std::string validNucleotides = DEFAULT_VALID_NUCLEOTIDES);

    /**
     * @brief Copy constructor
     * @param orig the KmerCounter object used as source for the copy. 
     * Input parameter
     */
    KmerCounter(KmerCounter orig);

    /**
     * @brief Destructor
     */
    ~KmerCounter();

    /**
     * @brief Returns the number of nucleotides that can be part of a
     * kmer, that is, the number of characters in the private data
     * _allNucleotides. For example, if "_ACGT" are the set of all nucleotides, 
     * then this method will return 5.
     * Query method
     * @return The number of nucleotides that can be part of a kmer
     */
    int getNumNucleotides();
    
    /**
     * @brief Returns the number of nucleotides in each kmer
     * Query method
     * @return The number of nucleotides in each kmer
     */
    int getK();
    
    /**
     * @brief Returns the number of different kmers that can be built using
     * @p _k nucleotides (including the missing nucleotide)
     * Query method
     * @return The number of different kmers that can be built using
     * @p _k nucleotides 
     */
    int getNumKmers();
    

    /**
     * @brief Gets the number of kmers with a frequency greater than 0
     * Query method
     * @return the number of kmers with a frequency greater than 0
     */
    int getNumberActiveKmers();
    
    /**
     * @brief Obtains a string with the following content:
     * - In the first line, the content of the private data _allNucleotides and
     * the value of _k (number of nucleotides in each kmer) separated by a 
     * whitespace.
     * - In the following lines, each one of the rows in the frequency matrix
     * (frequencies separated by a whitespace).
     * Query method
     * @return A string with the content of this object
     */
    std::string toString();

    /**
     * @brief Increases the current frequency of the given kmer using the value 
     * provided by @p frequency. If the argument @p frequency is not 
     * provided, then 1 is added to the current frequency of the kmer.
     * Modifier method
     * @throw std::invalid_argument This method throws an 
     * std::invalid_argument exception if the given kmer contains any
     * invalid nucleotide.
     * @param kmer The kmer in which the frequency will be modified. 
     * Input parameter
     * @param frequency The quantity that will be added to the current 
     * frequency. Input parameter
     */
    void increaseFrequency(Kmer kmer, int frequency = 1);

    /**
     * @brief Overloading of the assignment operator.
     * Modifier method
     * @param orig the KmerCounter object used as source for the assignment.
     * Input parameter
     * @return A reference to this object
     */
    KmerCounter operator=(KmerCounter orig);

    /**
     * @brief Overloading of the operator +=. It increases the current 
     * frequencies of the kmers of this object with the frequencies of the 
     * kmers of the given object.
     * Modifier method
     * @param kc a KmerCounter object. Input parameter 
     * @throw std::invalid_argument This method throws an 
     * std::invalid_argument exception if the given argument @p kc has a different
     * set of nucleotides or a different K (number of nucleotides in
     * kmers).
     * @return A reference to this object
     */
    KmerCounter operator+=(KmerCounter kc);

    /**
     * @brief Reads the given text file and calculates the frequencies of each 
     * kmer in that file. This method normalizes each found Kmer and then
     * sum 1 at the corresponding element of the frequency matrix.
     * This method sets to zero the frequency of each kmer before starting to 
     * calculate frequencies. In this way, if this method is called twice 
     * consecutively, then this KmerCounter will contain only the frecuencies
     * calculated in the last call.
     * Modifier method
     * @param fileName The name of the file to process. Input parameter
     * @throw std::ios_base::failure Throws a std::ios_base::failure if the
     * given file cannot be opened
     */
    void calculateFrequencies(char* fileName);

    /**
     * @brief Builds a Profile object from this KmerCounter object. The 
     * Profile will contain the kmers and frequencies for those one with 
     * a frequency greater than 0. 
     * Note that the resulting Profile could contain kmers with the 
     * missing nucleotide. If you want to eliminate them, you must zip 
     * (using Profile::zip(true) method) the returned Profile after calling 
     * to this method.
     * Also note that this method does not obtain a Profile with an ordered 
     * vector of kmers. If you need an ordered vector of kmers, you must sort
     * (using Profile::sort() method) the returned Profile after calling to 
     * this method.
     * Query method
     * 
     * @return A Profile object from this KmerCounter object
     */
    Profile toProfile();

private:
    int** _frequency; ///< 2D matrix with the frequency of each kmer
    
    int _k; ///< Value of K (number of nucleotides in each kmer)

    /**
     * Set of characters that define the possible nucleotides of a kmer. Any other 
     * character will be considered an invalid nucleotide. Only uppercase 
     * characters are included in this string 
     */
    std::string _validNucleotides;
    
    /**
     * Set with the character representing a missing (unknown) nucleotide
     * (Kmer::MISSING_NUCLEOTIDE) and the set of valid nucleotides.
     */
    std::string _allNucleotides;
    
    /**
     * @brief Returns the numbers of rows of the matrix in this object.
     * Query method
     * @return The numbers of rows of the matrix in this object
     */
    int getNumRows();
    
    /**
     * @brief Returns the numbers of columns of the matrix in this object.
     * Query method
     * @return The numbers of columns of the matrix in this object
     */
    int getNumCols();
    
    /**
     * Returns the index (a row or a column in the frequency matrix) 
     * corresponding to the given argument string. Note that this method
     * will be used calling it with a string that will contain a half of a Kmer.
     * Query method
     * @param kmer A string with a set of nucleotides. Input parameter
     * @return Returns the index (a row or a column in the frequency matrix) 
     * corresponding to the given argument string.
     * It returns -1 if some of the nucleotides in @p kmer does not belong to 
     * the set _allNucleotides
     */
    int getIndex(const std::string& kmer) const;
    
    /**
     * Returns a string with the nucleotides that define the given index (a 
     * row or a column of the frequency matrix). 
     * Query method
     * 
     * @param index An integer, row or column of the frequency matrix. 
     * Input parameter
     * @param nCharacters Number of characters that will be in the returned 
     * string. If defines the number of nucleotides associated with a row or 
     * column. Input parameter
     * @return a string with the nucleotides that define the given index  
     * (row or a column of the frequency matrix). 
     */
    std::string getInvertedIndex(int index, int nCharacters) const;
    
    /**
     * @brief Obtains the row and column for the frequency of the given 
     * argument Kmer. -1 will be assigned to row or column if some of the
     * nucleotides in @p kmer does not belong to the set _allNucleotides
     * Query method
     * @param kmer A Kmer. Input parameter
     * @param row The row in the frequency matrix corresponding to Kmer @p kmer.
     * Output parameter
     * @param column The column in the frequency matrix corresponding to 
     * Kmer @p kmer. Output parameter
     */
    void getRowColumn(Kmer kmer, int row, int column);

    /**
     * @brief Returns the Kmer that is defined by the provided row and column 
     * Query method
     * @param row A row in the frequency matrix (int value from 0 to nRows-1).
     * Input parameter
     * @param column A column in the frequency matrix (int value from 0 to 
     * nColumns-1). Input parameter
     * @throw std::invalid_argument This method throws an 
     * std::invalid_argument exception if the given row or column are out
     * of the correct bounds
     * @return the Kmer that is defined by the provided row and column 
     */
    Kmer getKmer(int row, int column);
    
    /**
     * @brief Sets the frequency of each kmer to 0, that is, it fills with 0 the 
     * matrix of frequencies
     * Modifier method
     */
    void initFrequencies();

    /**
     * @brief Overloading of the () operator to access to the element at a 
     * given position.
     * Query method
     * @param row Row of the element. Input parameter
     * @param column Column of the element. Input parameter
     * @return A const reference to the element at the given position
     */
    int operator()(int row, int column);

    /**
     * @brief Overloading of the () operator to access to the element at a 
     * given position.
     * Query and modifier method
     * @param row Row of the element. Input parameter
     * @param column Column of the element. Input parameter
     * @return A reference to the element at the given position
     */
    int operator()(int row, int column);
};

#endif /* KMER_COUNTER_H */
