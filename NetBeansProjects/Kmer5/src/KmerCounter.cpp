/*
 * Metodología de la Programación: Kmer5
 * Curso 2023/2024
 */

/** 
 * @file KmerCounter.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @author Javier Martínez Baena <jbaena@ugr.es>
 * 
 * Created on 22 December 2023, 10:00
 */

#include "KmerCounter.h"

using namespace std;

/**
 * DEFAULT_VALID_NUCLEOTIDES is a c-string that contains the set of characters
 * that will be considered as valid nucleotides. 

 * The constructor of the class KmerCounter uses this c-string as a 
 * default parameter. It is possible to use a different c-string if that
 * constructor is used with a different c-string
 */
const char* const KmerCounter::DEFAULT_VALID_NUCLEOTIDES="ACGT";

std::string KmerCounter::toString() const{
    string outputString = _allNucleotides + " " + to_string(_k) + "\n";
    
    for(int row=0; row<this->getNumRows(); row++){
        for(int col=0; col<this->getNumCols(); col++){
            outputString += to_string((*this)(row,col)) + " ";
        }
        outputString += "\n";
    }
    
    return outputString;
}

int KmerCounter::getIndex(const std::string& kmer) const{
    int index = 0;
    int base = 1;

    for (size_t i = 0; i < kmer.size(); i++) {
        size_t pos = _allNucleotides.find(kmer[kmer.size()-i-1]);
        if (pos == string::npos)
            return -1;
        index += pos * base;
        base *= _allNucleotides.size();
    }
    return index;
}

string KmerCounter::getInvertedIndex(int index, int nCharacters) const {
    string result(nCharacters, Kmer::MISSING_NUCLEOTIDE);

    for (int i = result.size(); i > 0; i--) {
        result[i - 1] = _allNucleotides[index % _allNucleotides.size()];
        index = index / _allNucleotides.size();
    }
    return result;
}

