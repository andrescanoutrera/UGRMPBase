/*
 * Metodología de la Programación
 * Curso 2025/2026
 */

/**
 * @file idk
 * @author estudiante1: Romero Lopez, Ulises
 * @author estudiante2: Ruiz Cano, Juan
 */


//TODO:

//NICE TO HAVE: could be interesting to change all the _values to modifiers at but im unsure of the efficiency implications
//Research efficiency implications of small sized parameters such as def data types(like int ot string) if it's more efficient to pass them by reference, because obv big objects or arrays... will be more efficient


#include "VectorInt.h"


#include <iostream>
#include <string>
#include <cmath>

using namespace std;

VectorInt::VectorInt(int size){ //apparently only the default values that it resorts to for the parameter HAS TO BE ONLY in the header file
    if(size <0 || size > DIM_VECTOR_VALUES){
        throw out_of_range("values below 0 or over the max cap");
    } //as mentioned countless times no need to worry about _size being assigned size bcuz the check of this if throws an exception that exits the program

    _size = size;

    for(int i = 0; i < _size; i++){
        _values[i] = 0;
    }
}


int VectorInt::getSize() const{
    return _size;
}

int VectorInt::getCapacity() const{
    return DIM_VECTOR_VALUES;
}

int VectorInt::countIdenticalElements(const VectorInt &other) const{
    unsigned int counter = 0;
    
    if(getSize() != other.getSize()){
        throw invalid_argument("differently sized arrays");
    }


    for(int i = 0; i < getSize(); i++){
        if(_values[i] == other.at(i)){ //The compiler automatically chooses the query (const) at cause we promised to the compiler that at couldn't be modified so it's left with no choice
            counter++;
        }
    }

    return counter;

}

string VectorInt::toString() const{
    string output = to_string(getSize()) + "\n";
    if (getSize() > 0){
        for(int i = 0; i < getSize()-1;i++){
            output += to_string(_values[i]) + " ";

        
        }
        //NOOOO what am i doing HORRIBLE IF THE SIZE IS 0 WILL ACCESS NEG POS
        //output += to_string(_values[getSize()-1]) + "\n"; //ts is so BS but i would much rather have this than and if and an else inside the for 
        //all of this bs just for the slight efficiency improvement of not having those constant if/else inside the for loop

        //Scratch the if just for the last pos do it for the loop and this final output
        output += to_string(_values[getSize()-1]) + "\n";
    }
    return output;
}


double VectorInt::distance(const VectorInt &other) const{

    double result = 0;
    if(getSize() != other.getSize()){
        throw invalid_argument("differently sized arrays");
    }

    if(other.getSize() == 0){
        throw invalid_argument("empty parameter array");

    }

    
    for(int i = 0; i < getSize(); i++){
        result += pow(_values[i] - other.at(i), 2);
    } //so bcuz their size is the same, result just keeps being added the diff of each slot ^2


    return sqrt(result);
}


void VectorInt::assign(const int &value){
    for(int i = 0; i < getSize(); i++){
        _values[i] = value;
    }
}


void VectorInt::append(const int &value){
    if(getSize() >= getCapacity()){
        throw out_of_range("array full, cannot accept more values");
    }

    _values[getSize()] = value;
    _size++;
}

void VectorInt::clear(){
    //BS header description what does it want only set _size to 0 or to set each value to 0 ALONGSIDE having size as 0 ...
    for(int i = 0; i < getSize(); i++){
        _values[i] = 0;
    }
    _size = 0;
}

const int &VectorInt::at(const int &pos) const {
    if(pos < 0 ||pos >= getSize()){
        throw out_of_range("pos ain't a valid range on the array");
    }

    return _values[pos];
}

int &VectorInt::at(const int &pos){
    if(pos < 0 ||pos >= getSize()){
        throw out_of_range("pos ain't a valid range on the array");
    }

    return _values[pos];
}