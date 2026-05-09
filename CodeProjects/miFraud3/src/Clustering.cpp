/*
 * Metodología de la Programación
 * Curso 2025/2026
 */

/**
 * @file idk
 * @author estudiante1: Romero Lopez, Ulises
 * @author estudiante2: Ruiz Cano, Juan
 */




#include "VectorInt.h"
#include "VectorLocation.h"
#include "Location.h"
#include "Clustering.h"

#include <cmath>



using namespace std;

//needed for linking if not it has a hard time using them because it's static
//no idea why this is needed as mifraud0 also had static vars in the class
//but without it the tests refuse to run
const unsigned int Clustering::DEFAULT_RANDOM_SEED;

Clustering::Clustering() {
    _K = 0;
    _isDone = false;
    _sumWCV = 0.0;
    _numIterations = 0;
    _seed = DEFAULT_RANDOM_SEED;

}

//all of the gets and isDone are pretty self explanatory 
int Clustering::getK() const {
    return _K;
}

VectorLocation Clustering::getCentroids() const {
    return _centroids;
}

bool Clustering::isDone() const {
    return _isDone;
}

int Clustering::getNumLocations() const {
    return _locations.getSize();
}




//in the parameter a pos is given for a location in the locations array
//and with that it gives you the  the cluster from the cluster array that
//corresponds w the location 
int Clustering::clusterOf(const int& locationIndex) const {
    int result;
    if (!_isDone || locationIndex < 0 || locationIndex >= _locations.getSize()) {
        result = -1; //if algorithm has been run or the location
    } else {
        result = _clusters.at(locationIndex);
    }
    return result;
}



//Self explanatory
double Clustering::getSumWCV() const {
    
    return _sumWCV;
}

//Self explanatory
int Clustering::getNumIterations() const {
    
    return _numIterations;
}


//returns a string with the locations of the clusters that match with pos given
//the string must have a diff line for each element, consisting of firstly the pos in the array
//And then the coords and the name each separated by a whitespace
string Clustering::clusterInfo(const int& cluster) const {
    string result = "";
    if (_isDone && cluster >= 0 && cluster < _K) {
    
        for (int i = 0; i < _locations.getSize(); i++) {
            if (_clusters.at(i) == cluster) {
                result += to_string(i) + " " + _locations.at(i).toString() + "\n";
            }
        }
    }
    return result;
}

//just returns a string with the variables shown in the to string being transformed
std::string Clustering::getStatistics() const {
    string result = "";
    //READDED the titles as shown in toString just in case the tests are too picky with the exact wording
    result += "K=" + to_string(_K) + "\n"; 
    result += "Sum of within-cluster variances: " + to_string(_sumWCV) + "\n";
    result += "Number of iterations: " + to_string(_numIterations) + "\n";
    return result;
}

//compares equivalency of the object we're in rn with the one in the parameter
//Equivalency is basically that the condiitons included in the if are true, important even tho it's in the if
//to keep in mind that they both have to have run the algorithm
bool Clustering::isEquivalentTo(const Clustering& other) const { 
    bool EsVerdad = false; 
    if (_K == other._K && _sumWCV == other._sumWCV && _numIterations == other._numIterations && isDone() && other.isDone()) {
        EsVerdad = true; 
    }
    return EsVerdad;
}


//another string returner that has lots of info, in this instance we 
//return a string w everything from getstatistics, and then all the clusters nums, and then
//all the centroinds locations, 
//finally with for and the clusterinfo we're able to also add to the string each cluster with
//the positions that form that cluster
string Clustering::toString() const{
    string result = getStatistics();
    result += "Cluster number for each location:\n";
    result += _clusters.toString();
    result += "Centroids:\n";
    result += _centroids.toString();
    for(int i=0; i<_K; i++){
        result += "Cluster " + to_string(i) + " information:\n";
        result += clusterInfo(i);
    }

    return result;
}


//Sets the privates variables seen inside the set to the given parameters
void Clustering::set(const VectorLocation &locations,const int &K,const unsigned int &seed){
    
    if (K <= 0 ) { //REMOVED: || K > _locations.getSize()
        throw invalid_argument("Mal valor para K"); //Even tho the prev comments extra condition makes perfect sense i ain't risking it
    }else {
        _K = K;
    }
    //Decided to put this exception check plus the assignment in the case of it not being an exception at the top
    //cause nothing was clarified and it's prob better to not have anything changed right b4 a possible exception
    
    _locations = locations;
    _seed = seed;
    _isDone = false;
    _clusters = VectorInt(locations.getSize());
    _centroids = VectorLocation(K);
    _sumWCV = 0.0;
    _numIterations = 0;
}


//RUN ISN'T DONE YET


//IDK WHAT JUAN DID HERE

/*
void run(){
    _centroids = VectorLocation();
    _clusters = VectorInt(_locations.getSize());
    _isDone = true; 
    _sumWCV = calculateSumWithinClusterVariances(); 
}


*/
// Note that in the following code, _clusters.at(i) provides the cluster 
// number of location number i
// This method uses a local variable (VectorInt counter) with _K integer 
// elements. It is used to count the number of locations in each cluster
void Clustering::run() {
    VectorInt counter(_K);
    int best;
    bool change = true;
    Location zeroLocation; //Constructor assigns 0 to it's x & y automatically
    int whilecounter = 0;

    initialClusterAssignment();

    //REPEAT until no change is obtained in clusters assignment
    while (change) { //Complete the run isn't done at all
        
        change = false;
        
        // Initialize the counter
        counter.assign(0);

        // Initialize the coordinates of the centroids with (0.0, 0.0)
        _centroids.assign(zeroLocation);

        //Calculate centroids. Two main steps are necessary (Step 1 and Step 2): 
        // Step 1: Sum the coordinates of the locations within each cluster
        for (int i = 0; i < _locations.getSize(); i++) {
            // Sum 1 to the cluster at location i
            counter.at(_clusters.at(i))++;

            //Obtain separately the sum of the x and y coordinates
            double x = _centroids.at(_clusters.at(i)).getX() + _locations.at(i).getX();
            //se debe sumar al centroide del cluster al que esta de la posicion esa la localizacion
            _centroids.at(_clusters.at(i)).setX(x); //y tras calcular eso ese es el nuevo centroide 
            double y = _centroids.at(_clusters.at(i)).getY() + _locations.at(i).getY();
            _centroids.at(_clusters.at(i)).setY(y);
            
            

            //SUMMARY OF THIS AND THE BELOW CLASS WE HAVE WHATEVER ASSIGNED TO THE CENTROIDS RIGHT
            //OR THAT 0,0 of the zeroLocation it doesn't matter 
            //WITH THAT WE GO THROUGH EACH LOCATION AND WE RECALCULATE THE CENTROID OF THE CLUSTER 
            //OF WHICH THAT LOCATION "BELONGS" TO
            //WE CALCULATE THE NEW CENTROID BY GETTING THE CENTROID WE HAD FOR THAT CLUSTER AND ADDING
            //THE COORDS OF THIS LOCATION
            //AS WE CAN SEE HERE WE'VE DONE IT FIRST FOR X AND THEN Y

            //BUT THAT AIN'T ALL WE ALSO NEED TO DO AN EXTRA STEP GIVEN BU THE EQUATION
            //WHICH IS LITERALLY TO THE CENTROIDS WE OBTAINED FROM THIS FOR LOOP WE HAVE TO
            //DIVIDE THAT BY THE ELEMENTS THAT "ARE" IN THAT CLUSTER, HENCE WHY WE HAD IN THIS FOR LOOP
            //THAT COUNTER
        }
        // Step 2: normalize the sum of each cluster, dividing by the number
        // of locations in each cluster
        for (int i = 0; i < _K; i++) { //here we don't do it for each location, just for each cluster so we divide by the counter for each var, FOR EACH cluster
            if (counter.at(i) > 0) { //FAILSAFE SO WE DONT / BY 0
                double x = _centroids.at(i).getX() / counter.at(i);
	            double y = _centroids.at(i).getY() / counter.at(i);
                //We finalize ts by giving centroid the new x and y values
                _centroids.at(i).setX(x);
                _centroids.at(i).setY(y);
            } 
        }

        // Calculate a new cluster for each Location
        for (int i = 0; i < _locations.getSize(); i++) {


            //With this literally i need to go through each location and
            //see with of the centroids is the closest
            //and the closest of the options must be assigned ot it in the _clusters
            //array WE CAN DO THIS for each location seeing which of the centroids is 
            //the closest
            best = _centroids.nearest(_locations.at(i)); //This returns a pos
            if (_clusters.at(i) != best) { 
 		        _clusters.at(i) = best;
                change = true;
            }
        }


        whilecounter++;
    } // end REPEAT

    // Update the data members _isDone, _sumWCV and _numIterations
    _isDone = true;
    _sumWCV = calculateSumWCV(); //need to do ts cause the sumWCV is a query method
    _numIterations= whilecounter;
}



void Clustering::initialClusterAssignment(){
    srand(_seed);
    for (int i = 0; i < getNumLocations(); i++){
        _clusters.at(i) = rand() % _K;
    }
}

//really darn weird function but what it must do is
//[LOOK EQUATIONS IN FRAUD1 PDF]
//do the square distance for all the points that correspond to a cluster
//and obv have them all summed up, and then sum up all the different cluster
//sums
double Clustering::calculateSumWCV() const{
    double result = 0;

    //TS was a more logical attempt by doing the sum of sums
    /*for (int i = 0; i < _K; i++){ 
        
        for (int j = 0; j < _clusters.getSize();j++){
            if(i == _clusters.at(j)){
                result += _locations.at(j).squaredDistance(_centroids.at(i))
                
                //the thing below should be done with squaredDistance as there is a function for it already
                //result += pow( _locations.at(j).getX() - _centroids.at(i).getX(), 2 ) + pow( _locations.at(j).getY() - _centroids.at(i).getY(), 2 );
                //important to remember that centroids size = num of Ks, so we must access it with i
            }
        }
    
    
    }*/

    //TS is more efficient cause it doesn't do 2 sums (fors) therefore it just does a sum of squareDistances
    //of each location with it's corresponding centroid
    for(int i = 0; i < _locations.getSize();i++){
        
        result += _locations.at(i).squaredDistance(_centroids.at(_clusters.at(i))); //The centroids at clusters at mess basically 
        //just gives me the centroid for the cluster of the location
    }

    return result;
}
