/*
 * Metodología de la Programación: Kmer2
 * Curso 2023/2024
 */

/** 
 * @file Kmer.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 * 
 * Created on 31 October 2023, 14:15
 */

#ifndef KMER_H
#define KMER_H

#include <iostream>
#include <string>

/**
 * @class Kmer
 * @brief It represents a list of k consecutive nucleotides of a DNA or RNA
 * sequence. Each nucleotide is represented with a character like 
 * 'A', 'C', 'G', 'T', 'U'.
 */
class Kmer {
public:
    /**
     * A static const character representing an unknown nucleotide. It is used
     * when we do not known which nucleotide we have in a given position of
     * a Kmer
     */
    static const char MISSING_NUCLEOTIDE = '_';
    
    /**
     * @brief It builds a Kmer object using a string with @p k characters 
     * (nucleotides). Each character will be set to the value 
     * @p MISSING_NUCLEOTIDE.
     * @throw std::invalid_argument Throws an std::invalid_argument exception
     * if @p k is less or equal than zero
     * @param k the number of nucleotides in this Kmer. It should be an integer
     * greater than zero. Input parameter
     */
    Kmer(int k=1);
    
    /**
     * @brief It builds a Kmer object with the characters in the string @p text 
     * representing the list of nucleotides of the new Kmer. 
     * @throw std::invalid_argument Throws an std::invalid_argument exception 
     * if the given text is empty
     * @param text a string with the characters representing the nucleotides for
     * the kmer. It should be a string with at least one character. Input parameter
     */
    Kmer(const std::string& text);

    /**
     * @brief Returns the number of nucleotides in this Kmer.
     * Query method
     * @return the number of nucleotides in this Kmer
     */
    int getK() const;
    
    /**
     * @brief Returns the number of nucleotides in this Kmer.
     * Query method
     * @return the number of nucleotides in this Kmer
     */
    int size() const;
    
    /**
     * @brief Returns a string with a list of characters, each one representing 
     * a nucleotide of this Kmer.
     * Query method
     * @return The text of this Kmer as a string object
     */
    std::string toString() const;

    /**
     * @brief Gets a const reference to the character (nucleotide) at the given 
     * position.
     * Query method
     * @param index the position to consider. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * index is not in the range from 0 to k-1 (both included).
     * @return A const reference to the character at the given position
     */
    const char& at(int index) const;

    /**
     * @brief Gets a reference to the character (nucleotide) at the given 
     * position.
     * Modifier method
     * @param index the position to consider. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * index is not in the range from 0 to k-1 (both included).
     * @return A reference to the character at the given position
     */
    char& at(int index);
    
    /**
     * @brief Converts uppercase letters in this Kmer to lowercase
     * Modifier method
     */
    void toLower();
    
    /**
     * @brief Converts lowercase letters in this Kmer to uppercase
     * Modifier method
     */
    void toUpper();
 
    /**
     * @brief Normalizes this Kmer. That is, it converts all the characters to
     * uppercase. Then, invalid characters are replaced by the 
     * MISSING_NUCLEOTIDE value.
     * Modifier method
     * @param validNucleotides a string with the list of characters
     * (nucleotides) that should be considered as valid. Input parameter
     */
    void normalize(const std::string& validNucleotides);
    
    /**
     * @brief Returns the complementary of this Kmer. For example, given the Kmer
     * "TAGAC", the complementary is "ATCTG" (assuming that we use.
     * @p nucleotides="ATGC" and @p complementaryNucleotides="TACG").
     * If a nucleotide in this object is not in @p nucleotides, then that 
     * nucleotide remains the same in the returned kmer.
     * Query method
     * @param nucleotides A string with the list of possible nucleotides. Input parameter
     * @param complementaryNucleotides A string with the list of complementary
     * nucleotides. Input parameter
     * @throw std::invalid_argument Throws an std::invalid_argument exception if 
     * the sizes of @p nucleotides and @p complementaryNucleotides are not 
     * the same
     * @return The complementary of this Kmer
     */
    Kmer complementary(const std::string& nucleotides, 
         const std::string& complementaryNucleotides) const;
    
private:
    /**
     * A string with a list of characters representing the nucleotides in 
     * this Kmer. 
     */
    std::string _text;
}; // end class Kmer

/**
 * @brief Checks if the given nucleotide is contained in @p validNucleotides. 
 * That is, if the given character can be considered as part of a genetic 
 * sequence.
 * @param nucleotide The nucleotide (a character) to check. Input parameter
 * @param validNucleotides The set of characters that we consider as possible 
 * characters in a genetic sequence. Input parameter
 * @return true if the given character is contained in @p validNucleotides; 
 * false otherwise
 */
bool IsValidNucleotide(char nucleotide, const std::string& validNucleotides);

/**
 * @brief Converts to lowercase the characters (nucleotides) of the given Kmer
 * @deprecated This function could go away in future versions
 * @param kmer A Kmer object. Output parameter
 */
void ToLower(Kmer& kmer);

/**
 * @brief Converts to uppercase the characters (nucleotides) of the given Kmer
 * @deprecated This function could go away in future versions
 * @param kmer A Kmer object. Output parameter
 */
void ToUpper(Kmer& kmer);

#endif /* KMER_H */