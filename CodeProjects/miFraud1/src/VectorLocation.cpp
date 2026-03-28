
#include "Location.h"
#include "VectorLocation.h"
#include <string>
#include <istream>

using namespace std;

//needed for linking if not it has a hard time using them because it's static
//no idea why this is needed as mifraud0 also had static vars in the class
//but without it the tests refuse to run
const int VectorLocation::DIM_VECTOR_LOCATIONS;


    VectorLocation::VectorLocation(int size){ //Se quita lo del = 0, en el .h
        if (size >= 0 && size <= DIM_VECTOR_LOCATIONS){
            _size = size; 
        } else {
            throw std::out_of_range (string("VectorLocation(int size)") + to_string(size)); //con string ("") hemos pasado de cstring a string y con el + por q deja strings de c++ hemos pasado el tostring el num problematico
        }
    }

    int VectorLocation::getSize() const{
        return _size; 
    }

    int VectorLocation::getCapacity() const{
        return DIM_VECTOR_LOCATIONS; 
    }

    /**
     * @brief Obtains a string with information about this VectorLocation object,
     * in the following format:
     * - First line, the number of Location objects in this vector converted to
     * a string (using the to_string(int) C++ function).
     * - For each Location, a line with its x and y coordinates, converted to
     * a string (using the to_string(int) C++ function) and separated by a
     * whitespace.
     * Query method
     * @return string with information about this VectorLocation object
     */
    std::string VectorLocation::toString() const{ 
        

        
        string result = to_string(_size) + "\n";
        for (int i = 0; i < _size; i++){
            result += _locations[i].toString() + "\n";
        }
        return result;
    }

            //ask how +to put inside a string another line for each query
    

    /**
     * @brief Searches the 
        
        return result;provided Location in the array of locations in this
     * object. If found, it returns the position where it was found. If not,
     * it returns -1. We consider that position 0 is the first location in the
     * list of locations and this->getSize()-1 the last location.
     * In order to find a location consider only equality in the name field.
     * Query method
     * @param location A Location. Input parameter
     * @return If found, it returns the position where the location
     * was found. Otherwise it returns -1
     */
    int VectorLocation::findLocation(const Location &location) const{
        //we need to detect one where all the elements of locations of the introduced ones are the same to one line
        //of the array we're working with  
        int result = -1;

        for(int i = 0; i < _size; i++){
            if(_locations[i].getName() == location.getName()){ //only considered the name as asked
                //ts if is only entered if it's literally the exact same line
                //the only slight problem it that it will go through all the array and pick the last appearance when it's the same
                result = i;


            }

        } 

        return result;
    };

    /**
     * @brief Returns a VectorLocation object with those locations whose
     * positions are inside the area determined by the two given Locations.
     * Query method
     * @param bottomLeft The Location of the bottom left point. Input parameter
     * @param topRight The Location of the top right point. Input parameter
     * @return A VectorLocation with the selected Locations.
     */
    VectorLocation VectorLocation::select(const Location &bottomLeft, const Location &topRight) const{
        // Cambio variables para evitar que botton>top
        VectorLocation temp;
        Location temporal;
        //The coords to make sense bcuz if not it will spit nonsense
        if(topRight.getX()>= bottomLeft.getX() &&  topRight.getY() >= bottomLeft.getY()){
            
            for(int i = 0; i < getSize();i++){
                if(_locations[i].getX()>= bottomLeft.getX() && _locations[i].getX() <= topRight.getX() && _locations[i].getY()>= bottomLeft.getY() && _locations[i].getY() <= topRight.getY()){
                    temporal = _locations[i];
                    temp.append(temporal);
                }
            }
        } else {
            temp._size = 0;
        }

        return temp;

        
    }

    /**
     * @brief Removes all the elements in this object, leaving the container
     * with a size equal to 0. It only needs to set the number of elements
     * (_size field) to zero.
     * Modifier method
     */
    void VectorLocation::clear(){
        _size = 0;
    } ;

    /**
     * @brief Gets a const reference to the Location element at the given
     * position
     * Query method
     * @throw std::out_of_range Throws an std::out_of_range exception if the
     * given position is not valid.
     * @param pos position in the VectorLocation object. Input parameter
     * @return A const reference to the Location element at the given position
     */
    
    const Location &VectorLocation::at(int pos) const{ //what is the const doing before a location
        if(pos < 0 || pos >= _size){
            throw std::out_of_range(string("Location &at(int pos)") + to_string(pos));
        }
        return _locations[pos];
    
    }
    /**
     * @brief Gets a reference to the Location element at the given position.
     * Modifier method
     * @throw std::out_of_range Throws an std::out_of_range exception if the
     * given position is not valid
     * @param pos position in the VectorLocation object. Input parameter
     * @return A reference to the Location element at the given position.
     */
    Location &VectorLocation::at(int pos){
        if(pos < 0 || pos >= _size){
            throw std::out_of_range(string("Location &at(int pos)") + to_string(pos));
        }
        return _locations[pos];
    }

     /**
     * @brief Appends a copy of the given Location object at the first free
     * position in the array of Location in this object. The location is only
     * appended to this object if it was not already found in this object or 
     * its name is an empty string.
     * @throw std::out_of_range Throws a std::out_of_range exception if the
     * provided location is going to be appended but the array of Location 
     * was full (its capacity was full). If the provided location is not going 
     * to be appended because it was already found in this object or its name 
     * is an empty string, then no exception is thrown.
     * Modifier method
     * @param value the new Location object to be appended. Input parameter
     * @return true if the given Location could be inserted in this
     * VectorLocation object; false otherwise (the location was already found
     * in this object)
     */
    bool VectorLocation::append(const Location &location){
       

        int i = 0;
        bool repeated = false, finalCondition = false;
        //Trabajamos bajo suposicion de que nombre vacio =, Localizacion sin nada
        
                
        while(i<_size && !repeated){
            
            if (location.getName() == _locations[i].getName()&& location.getName() != ""){
                repeated = true;
            }
           
            i++;
        }
        
        if(!repeated){
            if (i >= DIM_VECTOR_LOCATIONS){ //Solo entraria si al añadir 1 se pasaria de DIM
                throw out_of_range("No cabe");
            }
            _locations[i] = location;
            finalCondition = true;
            _size++;
        }

        return finalCondition;
    }

            


    void VectorLocation::join(const VectorLocation &locations){
        /*int j = 0;
        for (int i = 0; i < getSize(); i++){
            
            Location temp = locations.at(i);
            if (_locations[i].getX() == 0 && _locations[i].getY()== 0 && _locations[i].getName() == ""){
                if ( j < locations.getSize()){
                    _locations[i] = locations.at(j);
                    j++;
                }
            }
        } */  //this is an implementation w/o append so not the most ideal one
        

        for(int i = 0; i < locations.getSize(); i++){
            append(locations.at(i));
        }
    }

    /**
     * Sorts the array of locations in this object by increasing alphabetical
     * order of the name of its location (a string).
     * Modifier method
     */
    void VectorLocation::sort(){
        for(int i = 0; i < _size - 1; i++){
            for(int j = 0; j < _size - i -1 ; j++){
                if (_locations[j].getName() > _locations[j+1].getName()){ //sorts by each letter so one will be bigger than the other if the first letter is bigger than the second and so on, it uses the second as a failsafe and then the third until the last to compare
                    Location  temp = _locations[j];
                    _locations[j] = _locations[j+1];
                    _locations[j+1] = temp;
                }
            }
        }
    }




    int VectorLocation::nearest(const Location &location) const{
        //The best approach i've thought about is going with a for across all the locations in this
        //Array and doing the abs(location.getx - arraylocation pos whatever x) and with that we sum the y 
        //and the one where we have the lowest one of the sum of both abs would be the closest locattion to
        //The one as a parameter
        //this is stupid i already have squared distance SHOULD USE THAT INSTEAD
         int pos = -1; //position with the least distance to location parameter 
        for(int i = 0; i < getSize(); i++){
            if (i == 0){
                pos = 0;
            }           

            if (location.squaredDistance(_locations[i]) < location.squaredDistance(_locations[pos])){
                pos = i;
            }

        }
        return pos;
    }


    void VectorLocation::assign(const Location &location){
        for(int i = 0; i < getSize(); i++){
            _locations[i] = location;
        }
    }



    void VectorLocation::load(std::istream &is){
        Location temp[DIM_VECTOR_LOCATIONS];
        int capacity = 0; //we initialize to 0 just so there isn't garbage
        clear(); //jic there's an exception

        ReadArrayLocation(temp, DIM_VECTOR_LOCATIONS, capacity, is);

        //if it isn't valid no worries cause an exception would've been thrown
        for(int i = 0; i < capacity; i++){
            _locations[i] = temp[i];

        }

        _size = capacity;


    }

    //Ts is added from the arrayLocation in fraud0 cause it could be useful for the vectorLocation in fraud1
    void ReadArrayLocation(Location arrayLocations[], const int &capacity, int &nLocs, istream &is)
    { // put nlocs w reference bcuz it will change

        // suppose that capacity is the max, and that nlocs is like the util the ones being used
        // first input number of elements to add
        // then we individually add each of the locations (x, y and name)


        //The array location doesn't matter the contents if it's given we can using without caring
        int toAdd;

        is >> toAdd;
        if (toAdd >= 0 && toAdd <= capacity) //no importa nlocs porque lo que vamos nlocs al final sera = toAdd 
        {
            for (int i = 0; i < toAdd; i++){
                
                double x, y;
                string name;

                is >> x >> y;


                is.ignore(); //ignores the extra enter that ight skip the getline with empty contents when filling up the x & y
                getline(is, name); // apparently the source of the input (which is the first parameter of the getline)
                // can just be put as is no >> no nothing

                arrayLocations[i].set(x, y, name);
                // pq como es 0 based va a la siguiente
                
                
            }

            nLocs = toAdd;
        } else
        {
            nLocs = 0; //For some reason we should put nlocs to 0 which makes no sense
            //Why would i put nLocs to 0 instad of leaving it as is 

            //code aftee an exception isn't run so i shouldn't put anything below

            throw std::out_of_range(" NO PUEDES PONER ELEMENTOS NEGATIVOS O NO PUEDES PONER MAS ELEMENTOS QUE LA CAPACIDAD");
        }
    }
