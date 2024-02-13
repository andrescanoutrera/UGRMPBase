/*
 * Metodología de la Programación: Kmer5
 * Curso 2023/2024
 */

/* 
 * @file   KmerFreq.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 *
 * Created on 17 November 2023, 10:15
 */


#ifndef KMER_FREQ_H
#define KMER_FREQ_H

#include "Kmer.h"

/**
 * @class KmerFreq
 * @brief A pair formed by a Kmer object and a frequency (an int), 
 * that gives the frequency of a Kmer (times it appears) in a genoma.
 */
class KmerFreq {
public:
    /**
     * @brief Base constructor. 
     * It builds a KmerFreq object containing a Kmer with one nucleotide, the
     * unknown nucleotide (Kmer::MISSING_NUCLEOTIDE) and 0 as its frequency
     */
    KmerFreq();

    /**
     * @brief Gets a const reference to the Kmer of this KmerFreq object
     * Query method
     * @return A const reference to the Kmer of this KmerFreq object
     */
    Kmer getKmer();

    /**
     * @brief Gets the frequency of this KmerFreq object
     * Query method
     * @return The frequency of this KmerFreq object
     */
    int getFrequency();

    /**
     * @brief Sets the Kmer of this KmerFreq object.
     * Modifier method
     * @param kmer The new Kmer value for this object. Input parameter
     */
    void setKmer(Kmer kmer);

    /**
     * @brief Sets the frequency of this KmerFreq object
     * Modifier method
     * @throw std::out_of_range if @p frequency is negative
     * @param frequency the new frequency value for this KmerFreq object. 
     * Input parameter
     */
    void setFrequency(int frequency);
    
    /**
     * @brief Obtains a string with the string and frequency of the kmer
     * in this object (separated by a whitespace).
     * Query method.
     * @return A string with the nucleotide and frequency of the kmer
     * in this object
     */
    std::string toString();
    
    /**
     * @brief Writes this object to the given output stream. It first writes
     * the kmer of this object (using method Kmer::write(ostream&)) 
     * and them the bytes of the frequency (an int value) in binary format 
     * (using method ostream::write(const char* s, streamsize n))
     * Query method
     * @param outputStream An output stream where this object will be written
     */
    void write(std::ostream outputStream);
    
    /**
     * @brief Reads this object from the given input stream. It first reads
     * the Kmer of this object (using method Kmer::read(std::istream&) and 
     * then the bytes of the frequency (an int value) in binary format (using 
     * method istream::read(char* s, streamsize n))
     * Modifier method
     * @param inputStream An input stream from which this object will be read
     */
    void read(std::istream inputStream);
    
private:
    Kmer _kmer; ///< the Kmer object
    int _frequency; ///< the frequency
}; // end class KmerFreq

/**
 * @brief Overloading of the stream insertion operator for KmerFreq class
 * @param os The output stream to be used. Output parameter
 * @param kmerFreq the KmerFreq object. Input parameter
 * @return @p os A reference to the output stream
 */
std::ostream operator<<(std::ostream os, KmerFreq kmerFreq);

/**
 * @brief Overloading of the stream extraction operator for KmerFreq class
 * @param is The input stream to be used. Output parameter
 * @param kmerFreq the KmerFreq object. Input parameter
 * @return @p is A reference to the input stream
 */
std::istream operator>>(std::istream is, KmerFreq kmerFreq);

/**
 * @brief Overloading of the relational operator > for KmerFreq class
 * @param kmerFreq1 The first object to be compared. Input parameter
 * @param kmerFreq2 The second object to be compared. Input parameter
 * @return true if the frequency of @p kmerFreq1 is greater than that of
 * @p kmerFreq2 or if both frequencies are equals and the text of 
 * @p kmerFreq1 is minor than the text of @p kmerFreq2; false otherwise
 */
bool operator>(KmerFreq kmerFreq1, KmerFreq kmerFreq2);

/**
 * @brief Overloading of the operator < for KmerFreq class
 * @param kmerFreq1 a Kmer object. Input parameter
 * @param kmerFreq2 a Kmer object. Input parameter
 * @return true if kmerFreq1 < kmerFreq2; false otherwise
 */
bool operator<(KmerFreq kmerFreq1, KmerFreq kmerFreq2);

/**
 * @brief Overloading of the operator == for Kmer class
 * @param kmerFreq1 a KmerFreq object. Input parameter
 * @param kmerFreq2 a KmerFreq object. Input parameter
 * @return true if the two kmers contains the same pair Kmer-frequency;
 * false otherwise
 */
bool operator==(KmerFreq kmerFreq1, KmerFreq kmerFreq2);

/**
 * @brief Overloading of the operator != for KmerFreq class
 * @param kmerFreq1 a Kmer object. Input parameter
 * @param kmerFreq2 a Kmer object. Input parameter
 * @return true if the two kmerFreq1 are not equals (see operator==); 
 * false otherwise
 */
bool operator!=(KmerFreq kmerFreq1, KmerFreq kmerFreq2);

/**
 * @brief Overloading of the operator <= for KmerFreq class
 * @param kmerFreq1 a Kmer object. Input parameter
 * @param kmerFreq2 a Kmer object. Input parameter
 * @return true if kmerFreq1 <= kmerFreq2; false otherwise
 */
bool operator<=(KmerFreq kmerFreq1, KmerFreq kmerFreq2);

/**
 * @brief Overloading of the operator >= for KmerFreq class
 * @param kmerFreq1 a Kmer object. Input parameter
 * @param kmerFreq2 a Kmer object. Input parameter
 * @return true if kmerFreq1 >= kmerFreq2; false otherwise
 */
bool operator>=(KmerFreq kmerFreq1, KmerFreq kmerFreq2);

#endif /* KMER_FREQ_H */
