/*
 * Metodología de la Programación
 * Curso 2025/2026
 */

/**
 * @file Clustering.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 22 de octubre de 2025, 11:57
 */


//TODO: Finish run & calculateSumWCV



#include "VectorInt.h"
#include "VectorLocation.h"
#include "Clustering.h"



using namespace std;

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




//literally just gets the SumWCV unless the algorithm hasn't run yet in which case a -1 is return
double Clustering::getSumWCV() const {
    double result;
    if (!_isDone) {
        result = -1.0; 
    } else {
        result = _sumWCV;
    }
    return result;
}


//literally just gets the numIterations unless the algorithm hasn't run yet in which case a -1 is return
int Clustering::getNumIterations() const {
    if (!_isDone) {
        return -1;
    }
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
    result += "Numero de clusters de cada ubicación:\n";
    result += _clusters.toString();
    result += "Centroides:\n";
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
    ...

    initialClusterAssignment();

    //REPEAT until no change is obtained in clusters assignment
    while { //Complete the run isn't done at all
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
            _centroids.at(_clusters.at(i)).setX(x);
            double y = ... 
            ....
        }
        // Step 2: normalize the sum of each cluster, dividing by the number
        // of locations in each cluster
        for (int i = 0; i < _K; i++) {
            if (counter.at(i) > 0) { 
                double x = _centroids.at(i).getX() / counter.at(i);
	            ...
            }
        }

        // Calculate a new cluster for each Location
        for (int i = 0; i < _locations.getSize(); i++) {
            best = _centroids.nearest(_locations.at(i)); 
            if (_clusters.at(i) != best) { 
 		        ...
            }
        }
    } // end REPEAT

    // Update the data members _isDone, _sumWCV and _numIterations
    ....
}



void Clustering::initialClusterAssignment(){
    srand(_seed);
    for (int i = 0; i < getNumLocations(); i++){
        _clusters.at(i) = rand() % _K;
    }
}


double Clustering::calculateSumWCV(){
    double result = 0;

    for (int i = 0; i < _K; i++){ //the getsize of the centroids is to get the number of clusters bcuz each cluster has a single centroid
        result += 
    
    
    }

    return result;
}
