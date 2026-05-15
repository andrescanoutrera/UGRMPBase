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
    /*
    if(size <0 || size > DIM_VECTOR_VALUES){
        throw out_of_range("values below 0 or over the max cap");
    } //as mentioned countless times no need to worry about _size being assigned size bcuz the check of this if throws an exception that exits the program

    _size = size;

    for(int i = 0; i < _size; i++){
        _values[i] = 0;
    }

    */


    if(size < 0){
        throw out_of_range("size cannot be lower than 0");
    }


    _values = new int[size];
    _size = _capacity = size;

    for(int i = 0; i < _size; i++){
        _values[i] = 0;
    }


}

VectorInt::VectorInt(const VectorInt& orig){
    //very likely edge case if you initialize it with itself but that is impossible
    //maybe for an assign later but here it's a bit crazy
    
    _size = orig._size;
    _capacity = orig._capacity;
    //deleting is dangerous cause no heap memory is being used yet
    _values = new int[_capacity];
    for(int i = 0; i < _size; i++){
        _values[i] = orig._values[i];
    }
}


VectorInt::~VectorInt(){
    delete[] _values;
    //no need to delete the rest as they are just stack variables
}

VectorInt& VectorInt::operator=(const VectorInt& orig){
 // we wanna replace the contents of our current class with the ones in the parameter one
 //deep copy
    //This could perfectly be a void assignment, but y reterning a reference to this class we can do multiple assignments in the same line

    //EDGE CASE assignment to itself


    if( !(this == &orig) ){ //This checks if this which is the mem adress to this instance is the same to the orig one, if that's the case it doesn't do anything 
        int* temp = new int[orig._capacity];
        for(int i=0; i < orig._size; i++){
            temp[i] = orig._values[i];
        }
        delete[] _values;
        _size = orig._size;
        _capacity= orig._capacity;
        _values = temp;
        //With this we have done a deep copy of orig to our current instance
        //As we can now have them identical to each other with the main diff that they are both in different places in the heap
    }   

    return *(this);

}

int VectorInt::getSize() const{
    return _size;
}

int VectorInt::getCapacity() const{
    return _capacity;
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
//the one uptop is fine need to fix at tho




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
//fine as well no change needed i think


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
//the one uptop is fine need to fix at tho


void VectorInt::assign(int value){
    for(int i = 0; i < getSize(); i++){
        _values[i] = value;
    }
}


void VectorInt::append(int value){
    if(getSize() >= getCapacity()){ //if it's full we need a resize
        grow(); //This makes it grow so that it can fit the new int
    }

    _values[getSize()] = value;
    _size++;
}

void VectorInt::clear(){
    //BS header description what does it want only set _size to 0 or to set each value to 0 ALONGSIDE having size as 0 ...
    for(int i = 0; i < getSize(); i++){
        _values[i] = 0;
    } //Remove this if i start doubting, leave jic but any doubt i should delete the for
    _size = 0;
}

const int &VectorInt::at(int pos) const {
    if(pos < 0 ||pos >= getSize()){
        throw out_of_range("pos ain't a valid range on the array");
    }

    return _values[pos];
}

int &VectorInt::at(int pos){
    if(pos < 0 ||pos >= getSize()){
        throw out_of_range("pos ain't a valid range on the array");
    }

    return _values[pos];
}


VectorInt& VectorInt::grow(int capMod){
    //The sizemod is how much to grow by
    if(capMod <0){
        throw out_of_range("this is a grow not a decrease");
    }
    
    
    
    int* temp = new int[_capacity + capMod];
    _capacity += capMod;
    for(int i = 0; i < getSize();i++){
        temp[i] = _values[i];
    }

    delete[] _values;
    _values=temp;
    //Doesn't crew with the size that's appends job
    return *(this); //works as a void but we do this to allow multiple functions calls in a single line
}

VectorInt& VectorInt::resize(int toRes){


    if(_capacity + toRes < 1){ //the problem is with negative toRes because we make it smalle
        throw out_of_range("you cannot remove positions to make the size 0 or lower");
    }
    //after that check we can modify the capacity as we please

    int* temp = new int[_capacity + toRes]; //This could throw an exception that's why we modify the capacity afterwards
    _capacity += toRes;
    
    //Size doesn't change
    //OFC IT CHANGES if it shrinks

    if(_size >= _capacity){
        for(int i = 0; i < _capacity;i++){ 
            temp[i] = _values[i];
        }
        _size = _capacity;
    } else {
        for(int i = 0; i < getSize();i++){
            temp[i] = _values[i];
        }
    }
    delete[] _values;
    _values = temp;
 

    return *(this);
}