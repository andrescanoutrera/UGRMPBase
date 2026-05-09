/*
 * Metodología de la Programación
 * Curso 2025/2026
 * @author estudiante1: Romero Lopez, Ulises
 * @author estudiante2: Ruiz Cano, Juan
 */


#include <cmath>
#include <cstring>


#include "Location.h"

using namespace std;


Location::Location(){
    _x=0;
    _y=0;
    //nos podemos ahorrar poner _nombre = ""; pq se hace solo
}

double Location::getX() const{
    return _x; 
}

double Location::getY() const{
    return _y; 
}


string Location::getName() const{
    return _name;
}

bool Location::isInsideArea(const Location &bottomLeft, const Location &topRight) const {
    bool EsVerdad = false; 
    if (_x >= bottomLeft._x && _x <= topRight._x && _y >= bottomLeft._y && _y <= topRight._y){
        EsVerdad = true;  
    }
    return EsVerdad; 
}

double Location::squaredDistance(const Location& location) const{
    
    return pow((_x - location._x),2) + pow((_y - location._y),2);
}

double Location::distance(const Location& location) const{
    return sqrt(squaredDistance(location)); //solo se pone location no todo lo de const porque no es ni prototipo ni la definicion
}


string Location::toString() const {
    string output;
    output += std::to_string(_x) + " " + std::to_string(_y);
    if(!_name.empty()) 
        output += " " + getName();
    return output;
}


void Location::setX(double x){
    _x = x; //used to differentiate the x on the class vs the one inputted
}

void Location::setY(double y){
    _y = y;
}

void Location::set(double x, double y, const std::string &name){
    _x = x; 
    _y = y; 
    _name = name; 
}

void Location::setName(const string& name){
    _name = name;
}


//En el main tendremos que poner de parametro cin
void Location::load(istream& is){
    //istream is replaces the tipical cin used to pass an element from the console to a data type
    //Cin normally only let's you get data from the console, w istream u have the option to also 
    //get the data from console, strings or files.

    //It asks to get the 2 coord values from a single call to the is, and then the name from another call

    double coordx , coordy;
    string name1;
    //the 2 coords are both introduced in the same line with a space separating each
    is >> coordx >> coordy; 
    //from the same is call it will save coordx and coordy if there's a space between the 2

    //we use getline w/ std inside cause it works like ts getline(where input comes from, where we save the input)
    getline(is, name1); //So we get from is the entire line and thanks to getline it saves the entire line w spaces to name1

    _x = coordx;
    _y = coordy;
    Trim(name1); //Trim isn't on the string library so we have to implement it ourselves
    _name = name1;
}

//no location:: on the funcion below cause it's a global funcion not a class function
void Trim(string & myString){

    /*
    //approach: work with an array of chars detect the first character and last position and pass all the elements from the first character to the beginning and remove the last spaces at the end
    int firstCharPos = -1, lastCharPos = -1; 
    int k = 0;
    int j = 0;
    bool firstCharAppeared = false;
    while(k < myString.length())
    {
        if(!firstCharAppeared && myString[k] != ' '){
            firstCharPos = k;
            firstCharAppeared = true;
        } else {
            if(myString[k] != ' '){
                lastCharPos = k;
            }
        }
        k++;
    }

    if(firstCharPos == -1 && lastCharPos == -1){ //no char was found therefore we return by reference an empty string 
        myString = "";
    } else {

        if (firstCharPos != -1 && lastCharPos == -1){ //This would only happen if there is a single character in the entire string.
        lastCharPos = firstCharPos;
        }

        //now we organize and move things so that we don't have the spaces at the beginning or at the end 

        for(int i = firstCharAppeared; i <= lastCharPos; i++){
            myString[j] = myString[i];

            j++;
        }
    }


    */
    //THE FIND FIRST AND LAST CHAR OF A STRING COME BY DEFAULT IN THE STRING LIBRARY I DID ALL OF TS FOR NOTHING
    
    

    string badChars = " \t\n"; //This are elements that represent things we don't want, we have the space as the first thing
    //as a string is a char array the find_first_not_of just checks all the elements from the array to find the first char
    size_t firstCharPos = myString.find_first_not_of(badChars);
    size_t lastCharPos = myString.find_last_not_of(badChars);
    //https://cplusplus.com/reference/string/string/find_last_not_of/
    //it has to be size_T, int isn't allowed cause size_t is unsigned so num Natural and 
    //if it doesn't find anything it returns

    if(firstCharPos == string::npos && lastCharPos == string::npos){ //string::npos is the "value" returned when no valid position is found
        myString = "";
    } else {
        //thanks to substr we can create a substring from a string by specifying the start and the length of the substring 
        myString = myString.substr(firstCharPos, lastCharPos - firstCharPos + 1);
        //So the substring will save in myString the part of myString that starts at firstCharPos and ends at the lenght specified
        //lastcharpos - firstcharpos +1 bcuz we remove the part of firstchar and add 1 because length doesn't respect 0 based starts
    }

}

    

