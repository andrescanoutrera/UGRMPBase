/*
 * Metodología de la Programación: Kmer4
 * Curso 2023/2024
 */

/** 
 * @file Profile.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 * 
 * Created on 17 November 2023, 10:15
 */

#ifndef PROFILE_H
#define PROFILE_H


#include <iostream>
#include "KmerFreq.h"

/**
 * @class Profile
 * @brief It defines a model (profile) for a given biological species. It 
 * contains a vector of pairs Kmer-frequency (objects of the class KmerFreq) 
 * and an identifier (string) of the profile.
 */
class Profile {
public:

    /**
     * @brief Base constructor. It builds a Profile object with "unknown" as
     * identifier, and an empty vector of pairs Kmer-frequency. The vector will
     * have Kmer::INITIAL_CAPACITY as initial capacity.
     */
    Profile();

   
    /**
     * @brief It builds a Profile object with "unknown" as
     * identifier, and a vector with a size of @p size pairs 
     * Kmer-frequency. The vector will also have @p size as initial capacity.
     * Each pair will be initialized as Kmer::MISSING_NUCLEOTIDE for the Kmer 
     * and 0 for the frequency.
     * @throw std::out_of_range Throws a std::out_of_range exception if
     * @p size <0
     * @param size The size for the vector of kmers in this Profile.
     * Input parameter
     */
    Profile(int size);

    /**
     * @brief Copy constructor
     * @param orig the Profile object used as source for the copy. Input 
     * parameter
     */
    Profile(Profile orig);

    /**
     * @brief Destructor
     */
    ~Profile();

    /**
     * @brief Overloading of the assignment operator for Profile class.
     * Modifier method
     * @param orig the Profile object used as source for the assignment. Input
     * parameter
     * @return A reference to this object
     */
    Profile operator=(Profile orig);

    /**
     * @brief Returns the identifier of this profile object.
     * Query method
     * @return A const reference to the identifier of this profile object
     */
    std::string getProfileId();

    /**
     * @brief Sets a new identifier for this profile object.
     * Modifier method
     * @param id The new identifier. Input parameter
     */
    void setProfileId(std::string id);


    /**
     * @brief Gets a const reference to the KmerFreq at the given position 
     * of the vector in this object.
     * Query method
     * @param index the position to consider. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * given index is not valid
     * @return A const reference to the KmerFreq at the given position
     */
    KmerFreq at(int index); 

    /**
     * @brief Gets a reference to the KmerFreq at the given position of the 
     * vector in this object
     * Query and modifier method
     * @param index the position to consider. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * given index is not valid
     * @return A reference to the KmerFreq at the given position
     */
    KmerFreq at(int index); 

    /**
     * @brief Gets the number of KmerFreq objects.
     * Query method
     * @return The number of KmerFreq objects 
     */
    int getSize();
    
    /**
     * @brief Gets the capacity of the vector of KmerFreq objects.
     * Query method
     * @return The capacity of the vector of KmerFreq objects
     */
    int getCapacity();
    
    /**
     * @brief Gets the distance between this Profile object (\f$P_1\f$) and 
     * the given argument object @p otherProfile (\f$P_2\f$).
     * The distance between two Profiles \f$P_1\f$ and \f$P_2\f$ is 
     * calculated in the following way:
     * 
     * \f$d = \frac{ \sum_{kmer_i(P_1)} | rank_{kmer_i(P_1)}^{P_1} - 
     * rank_{kmer_i(P_1)}^{P_2} | }{size(P_1) * size(P_2) }\f$, 
     * 
     * where \f$kmer_i(p_j)\f$ is the kmer \f$i\f$ of the Profile \f$p_j, 
     * j \in \{1, 2\}\f$ and \f$rank_{kmer_i(p_j)}^{p_k}\f$ is the ranking
     * of the kmer \f$i\f$ of the Profile \f$p_j, j \in \{1, 2\}\f$ in the
     * Profile \f$p_k\f$. 
     * 
     * The rank of a kmer is the position in which it
     * appears in the list of KmerFreq. We consider 0 as the 
     * first position (rank equals to 0). When calculating 
     * \f$rank_{kmer_i(P_1)}^{P_2}\f$, if the kmer \f$kmer_i(P_1)\f$ 
     * does not appears in the Profile \f$P_2\f$ we consider that the rank
     * is equals to the size of Profile \f$P_2\f$. 
     * Query method
     * @param otherProfile A Profile object. Input parameter
     * @pre The list of kmers of this and otherProfile should be ordered in 
     * decreasing order of frequency. This is not checked in this method.
     * @throw Throws a std::invalid_argument exception if the implicit object
     * (*this) or the argument Profile object are empty, that is, they do not 
     * have any kmer.
     * @return The distance between this Profile object and the given 
     * argument @p otherProfile.
     */
    double getDistance(Profile otherProfile);
    
    /**
     * @brief Searchs the given kmer in the list of kmers in this
     * Profile, but only in positions from initialPos to finalPos 
     * (both included). If found, it returns the position where it was found. 
     * If not, it returns -1. We consider that position 0 is the first kmer in 
     * the list of kmers and this->getSize()-1 the last kmer.
     * Query method
     * @param kmer A kmer. Input parameter
     * @param initialPos initial position where to do the search. Input parameter
     * @param finalPos final position where to do the search. Input parameter
     * @return If found, it returns the position where the kmer 
     * was found. If not, it returns -1
     */
    int findKmer(Kmer kmer, int initialPos, int finalPos);

    /**
     * @brief Searchs the given kmer in the list of kmers in this
     * Profile. If found, it returns the position where it was found. If not,
     * it returns -1. We consider that position 0 is the first kmer in the 
     * list of kmers and this->getSize()-1 the last kmer.
     * Query method
     * @param kmer A kmer. Input parameter
     * @return If found, it returns the position where the kmer 
     * was found. If not, it returns -1
     */
    int findKmer(Kmer kmer);

    /**
     * @brief Obtains a string with the following content:
     * - In the first line, the profile identifier of this Profile
     * - In the second line, the number of kmers in this Profile  
     * - In the following lines, each one of the pairs kmer-frequency 
     * (separated by a whitespace).
     * Query method
     * @return A string with the number of kmers and the list of pairs of
     * kmer-frequency in the object
     */
    std::string toString();

    /**
     * @brief Sorts the vector of KmerFreq in decreasing order of frequency.
     * If two KmerFreq objects have the same frequency, then the alphabetical 
     * order of the kmers of those objects will be considered (the object 
     * with a kmer that comes first alphabetically will appear first).
     * Modifier method
     */
    void sort();

    /**
     * @brief Saves this Profile object in the given file. 
     * Query method
     * @param fileName A c-string with the name of the file where this Profile 
     * object will be saved. Input parameter
     * @throw std::ios_base::failure Throws a std::ios_base::failure exception 
     * if the given file cannot be opened or if an error occurs while writing
     * to the file
     */
    void save(char fileName[]);

    /**
     * @brief Loads into this object the Profile object stored in the given 
     * file. Note that this method should remove any Kmer-frequency pairs that 
     * this object previously contained.
     * Modifier method
     * @param fileName A c-string with the name of the file where the Profile 
     * will be stored. Input parameter
     * @throw std::out_of_range Throws a std::out_of_range exception if the 
     * number of kmers in the given file, cannot be allocated in this Profile
     * because it exceeds the maximum capacity or if the number of kmers read 
     * from the given file is negative.
     * @throw std::ios_base::failure Throws a std::ios_base::failure exception 
     * if the given file cannot be opened or if an error occurs while reading
     * from the file
     * @throw throw std::invalid_argument Throws a std::invalid_argument if
     * an invalid magic string is found in the given file
     */
    void load(char fileName[]);
     
    /**
     * @brief Appends a copy of the given KmerFreq to this Profile object.
     * If the kmer is found in this object, then its frequency is increased
     * with the one of the given KmerFreq object. If not, a copy of the 
     * given KmerFreq object is appended to the end of the list of
     * KmerFreq objects in this Profile.
     * Modifier method
     * @thow std::out_of_range Throws a std::out_of_range exception in case
     * that a new element must be appended to the end of the array and the
     * number of elements in the array of KmerFreq is equals to the capacity
     * of that array. In that case, the array is full, and no more elements
     * can be appended to the array.
     * @param kmerFreq The KmerFreq to append to this object. Input paramether
     */
    void append(KmerFreq kmerFreq);
    
    /**
     * @brief Normalizes the Kmers of the vector of KmerFreq in this object. 
     * That is, for each Kmer in the vector, all its characters are converted 
     * to uppercase. Then, invalid characters are replaced by the 
     * MISSING_NUCLEOTIDE value.
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
     * Modifier method
     * @param validNucleotides a string with the list of characters (nucleotides) 
     * that should be considered as valid. Input parameter
     */
    void normalize(std::string validNucleotides);

    /**
     * @brief Deletes the KmerFreq object from the vector of KmerFreq in this
     * object at the position @p pos. We consider that the first element has
     * position 0, and the last element position size()-1.
     * Modifier method
     * @param pos The index of the position to be deleted. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if @p pos 
     * is not in the range from 0 to size()-1 (both included).
     */
    void deletePos(int pos);

    /**
     * @brief Deletes the KmerFreq objects from the vector of KmerFreq in this
     * object which verifies one the following two criteria:
     *  -# The argument deleteMissing is true and the Kmer contains an unknown 
     * nucleotide 
     *  -# The frequency is less or equals to @p lowerBound. 
     * 
     * Note that the number of elements in the argument array could be modified.
     * Modifier method
     * @param deleteMissing A bool value that indicates whether kmers with any 
     * unknown nucleotide should be removed. This parameter is false by default.
     * Input parameter
     * @param lowerBound An integer value that defines which KmerFreq objects 
     * should be deleted from the vector of KmerFreq in this object. 
     * KmerFreq objects with a frequency less or equals to this value, are 
     * deleted. This parameter has zero as default value.
     * Input parameter
     */
    void zip(bool deleteMissing=false, int lowerBound = 0);
    
    /**
     * @brief Appends to this Profile object, the list of pairs  
     * kmer-frequency objects contained in the Profile @p profile. This
     * method uses the method append(const KmerFreq& kmerFreq) to
     * append the pairs kmer-frequency contained in the argument 
     * Profile @p profile
     * Modifier method
     * @param profile A Profile object. Input parameter
     */
    void join(Profile profile);
    
private:
    std::string _profileId; ///< Profile identifier
    KmerFreq* _vectorKmerFreq; ///< Dynamic array of KmerFreq
    int _size; ///< Number of used elements in the dynamic array _vectorKmerFreq
    int _capacity; ///< Number of reserved elements in the dynamic array _vectorKmerFreq

    static const int INITIAL_CAPACITY=10; ///< Default initial capacity for the dynamic array _vectorKmerFreq. Should be a number >= 0
    static const int BLOCK_SIZE=20; ///< Size of new blocks in the dynamic array _vectorKmerFreq 

    static const std::string MAGIC_STRING_T; ///< A const string with the magic string for text files
};

#endif /* PROFILE_H */