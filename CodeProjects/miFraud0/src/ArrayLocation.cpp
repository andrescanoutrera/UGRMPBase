/*
 * Metodología de la Programación
 * Curso 2025/2026
 */

/**
 * @file ArrayLocation.cpp
 * @author estudiante1: Romero Lopez, Ulises
 * @author estudiante2: Ruiz Cano, Juan
 *
 * Created on 22 de octubre de 2025, 11:57
 */

// Apparently arraylocation isn't any class it's just random global functions
// no need to worry about that

#include <Location.h>
#include <ArrayLocation.h>
#include <stdexcept>

using namespace std;

void PrintArrayLocation(const Location arrayLocations[],const int &nLocs)
{ // We get literally as a parameter an array full of locations

    // nlocs is the elements to print from the array so we only print the first nlocs of that array

    cout << nLocs << endl;

    for (int i = 0; i < nLocs; i++)
    {
        cout << arrayLocations[i].toString() << endl;
    }
}

void ReadArrayLocation(Location arrayLocations[], const int &capacity, int &nLocs)
{ // put nlocs w reference bcuz it will change

    // suppose that capacity is the max, and that nlocs is like the util the ones being used
    // first input number of elements to add
    // then we individually add each of the locations (x, y and name)


    //The array location doesn't matter the contents if it's given we can using without caring
    int toAdd;

    cin >> toAdd;
    if (toAdd >= 0 && toAdd <= capacity) //no importa nlocs porque lo que vamos nlocs al final sera = toAdd 
    {
        for (int i = 0; i < toAdd; i++){
            
            double x, y;
            string name;

            cin >> x >> y;


            cin.ignore(); //ignores the extra enter that ight skip the getline with empty contents when filling up the x & y
            getline(cin, name); // apparently the source of the input (which is the first parameter of the getline)
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

/**
 * @brief Places a copy of each Location of the provided VectorLocation object
 * into the provided array of Location (arrayLocations).
 * @throw Throws a std::out_of_range exception if the number of Location objects
 * in the provided VectorLocation exceeds the array capacity. In that case,
 * nLocs will be set to 0.
 * @param vector A VectorLocation object. Input parameter
 * @param arrayLocations Array of Location objects. Output parameter
 * @param capacity An integer with the capacity of arrayLocations.
 * Input parameter
 * @param nLocs An integer with the number of objects inserted in
 * arrayLocations. Output parameter
 */

 //no se porque pero por mi modificaria y vector de VectorLocation lo dejaria como const al final solo es read
void ToArrayLocation(const VectorLocation &vector, Location arrayLocations[],const int &capacity, int &nLocs)
{ ///to many things to guess i mean i will guess that arrayLocations is empty so i can really just start nLocks back to 0 
    nLocs = 0;
    if (vector.getSize() <= capacity){
        for (int i = 0; i< vector.getSize() ;i++){
            Location temp;
            temp = vector.at(i);

            arrayLocations[i].set(temp.getX(), temp.getY(), temp.getName());
            nLocs++; //we just added a new Location to ArrayLocation so we have to up it's nLocs by 1 
        }



    } else {
        nLocs = 0;
        
        throw std::out_of_range("ns que mensaje poner"); //Se que sobra std cuando tenemos ya el using pero bueno
    }


}

/**
 * @brief Returns a VectorLocation object filled with a copy of the objects from
 * the provided array of Location objects (arrayLocation)
 * @throw Throws a std::out_of_range exception if nLocs is negative.
 * @param arrayLocations Array of Location objects. Input parameter
 * @param nLocs An integer with the number of objects in
 * arrayLocations. Input parameter
 * @return A VectorLocation object filled with the objects from the provided
 * array of Location objects (arrayLocation)
 */
VectorLocation ToVectorLocation(const Location arrayLocations[],const  int &nLocs){
    
    VectorLocation temp; //no need to give it a starting value cause then the append cound affect it
    if(nLocs >= 0 && nLocs<= temp.getCapacity()){
        for(int i = 0; i < nLocs; i++){
            //bcuz the array is in private i need to create a set method which just adds the contents of each location in the array in the parameters
            temp.append(arrayLocations[i]);        }
    } else {
        throw out_of_range("nlocs is a negative, which isn't allowed, or it exceeds capacity");
    }

    return temp;

    //i am surprised that i am not obliged to check with an exception or anything at all that the nLocs of the arraylocation when we use the constructor
    //for the vector, that we don't check if we exceed the capacity, but it's not asked so
    //I did it anyways
}

//TO DO: 
//fIX USING CIN SOMEWHERE IN LOCATION INSTEAD OF INPUT
