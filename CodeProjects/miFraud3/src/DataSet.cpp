/*
 * Metodología de la Programación
 * Curso 2025/2026
 */

/**
 * @file DataSet.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 30 de julio de 2025, 10:00
 */

#include <string>
#include <iostream>
#include "DataSet.h"
#include "VectorLocation.h";
#include "VectorInt.h";

using namespace std;

const string DataSet::MAGIC_STRING_T="MP-FRAUD_DATASET-T-1.0";

std::string DataSet::toString() const {
    string result;
    
    result += _locations.toString();
    result += _labels.toString();
    for(int instance=0; instance<getNumInstances(); instance++){
        for(int location=0; location<getNumLocations(); location++){
            //result += to_string((*this)(instance,location));
            result += to_string(this->getValue(instance,location));
            if(location<getNumLocations()-1){
                result += " ";
            }
        }
        result += "\n";
    }    
    return result;
}


DataSet::DataSet(int nInstances, int nLocations){
    //for ** do the nInstances
    //and * for the nLocations


    _values = new int*[nInstances];
    for(int i = 0; i < nInstances; i++){
        _values[i] = new int[nLocations];
        
        for(int j = 0; j < nLocations; j++){
            _values[i][j] = 0;
        }
    }

    /*
    //They are already started so i cannot use any of the constructors
    //Can use resize tho which i already have, so it's 0 sized by default bcuz of the default constructor
    _labels.resize(nInstances);
    _locations.resize(nLocations);
    //they are initialized with a capacity of 0 so nInstances is how much it should grow directly it cannot go lower than that
    //even tho .getCapacity - nWhatever it is a catastrophic idea to do it in this stuation 
    */

    _labels = VectorInt(nInstances);//use assignment which is better as we create the one we want and change all of it's values correctly
    _locations = VectorLocation(nLocations);

    
    _nInstances= nInstances;
    _nLocations = nLocations;
}


DataSet::DataSet(const DataSet &orig){
    
    int** temp = new int*[orig._nInstances];
    for(int i = 0; i < orig._nInstances; i++){
        temp[i] = new int[orig._nLocations];
        for(int j = 0; j < orig._nLocations; j++){
            temp[i][j] = orig._values[i][j];
        }
    }

    _nInstances=orig._nInstances;
    _nLocations=orig._nLocations;

    //we need to copy the labels and locations we have the = operator at our disposal
    _labels = orig._labels;
    _locations = orig._locations;
}

DataSet::~DataSet(){
    //need to delete the dyn memory of the columns before the rows
    
    for(int i = 0; i < _nInstances; i++){
        delete[] _values[i];
        //Don't get this line try to get it explained
    }
    delete[] _values;
}


DataSet& DataSet::operator=(const DataSet &orig){

}

int DataSet::getNumInstances() const{
    return _nInstances;
}

int DataSet::getNumLocations() const{
    return _nLocations;
}

int DataSet::getValue(int instanceIndex, int locationIndex) const{
    if(instanceIndex < 0 || instanceIndex >= _nInstances || locationIndex < 0 || locationIndex >= _nLocations){
        throw out_of_range(" not valid positions");
    }
    return _values[instanceIndex][locationIndex];
}

int DataSet::getLabel(int instanceIndex) const{
    if(instanceIndex < 0 || instanceIndex >= _nInstances){
        throw out_of_range(" not valid pos");
    }
    return _labels.at(instanceIndex);
}

const VectorLocation& DataSet::getVectorLocation() const{
    return _locations; //no *() because they're not pointers like with this theyre objects by themselves unless i wanna do *(&)
}


const VectorInt& DataSet::getVectorLabels() const{
    return _labels;
}


void DataSet::setValue(int instanceIndex, int locationIndex, int value){
    if(instanceIndex < 0 || instanceIndex >= _nInstances || locationIndex < 0 || locationIndex >= _nLocations){
        throw out_of_range(" not valid positions");
    }

    _values[instanceIndex][locationIndex] = value;
}


void DataSet::setLabel(int instanceIndex, int label){
    //not mentiones byt it must want an exception for an out of range instanceINDEX
    //IF NOT REMOVE ASAP
    //no checking cause at does it by itself and i was trying to do check < 0 which makes sense but at does that already 
    //And >= _nInstances which ain't it

    _labels.at(instanceIndex) = label;
}

void DataSet::initInstances(int value){
    for(int i = 0; i < _nInstances; i++){
        for(int j = 0; j < _nLocations; j++){
            _values[i][j] = value;
        }
    }
}

void DataSet::clear(){
    for(int i = 0; i < _nInstances; i++){
        delete[] _values[i];
    }
    delete[] _values;
    _values = nullptr; 
    //i have to clear it bcuz if i don't i simply have no way of knowing the rows and columns it had 
    //and because to remove the columns for each row i have to do a  delete[] _values[i];
    //if i lost the number of rows that is nInstances i have no way of knowing

    //use the included clears for easiness 
    _locations.clear();
    _labels.clear();
    _nInstances = _nLocations = 0;
}

void save(std::string fileName){ //do ts one next

}