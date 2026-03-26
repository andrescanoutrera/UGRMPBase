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

#include "VectorInt.h"
#include "VectorLocation.h"

 std::string Clustering::toString() const {
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

// Note that in the following code, _clusters.at(i) provides the cluster 
// number of location number i
// This method uses a local variable (VectorInt counter) with _K integer 
// elements. It is used to count the number of locations in each cluster
void Clustering::run() {
    VectorInt counter(_K);
    int best;
    ...

    initialClusterAssignment();

    REPEAT until no change is obtained in clusters assignment{
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

Clustering::Clustering() {
    _K = 0;
    _isDone = false;
    _sumWCV = 0.0;
    _numInterations = 0;
    _seed = DEFAULT_RANDOM_SEED;
}

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

int Clustering::clusterOf(int locationIndex) const {
    if (!_isDone || locationIndex < 0 || locationIndex >= _locations.getSize()) {
        return -1;
    }
    return _clusters.at(locationIndex);
}

double Clustering::getSumWCV() const {
    if (!_isDone) {
        return -1.0; +
    }
    return _sumWCV;
}

int Clustering::getNumIterations() const {
    if (!_isDone) {
        return -1;
    }
    return _numIterations;
}

std::string Clustering::clusterInfo(int cluster) const {
    string result = "";
    if (!_isDone || cluster < 0 || cluster >= _K) {
    } else {
        for (int i = 0; i < _locations.getSize(); i++) {
            if (_clusters.at(i) == cluster) {
                result += to_string(i) + " " + _locations.at(i).toString() + "\n";
            }
        }
    }
    return result;
}

std::string Clustering::getStatistics() const {
    string result = "";
    result += "K: " + to_string(_K) + "\n";
    result += "Suma de varianzas: " + to_string(_sumWCV) + "\n";
    result += "Iteraciones: " + to_string(_numIterations) + "\n";
    return result;
}

bool Clustering::isEquivalent(const Clustering& other) const { // Se cambia tamb esto no?
    bool EsVerdad = false; 
    if (!(_K != other._K || _sumWCV != other._sumWCV || _numIterations != other._numIterations)) {
        EsVerdad = true; 
    }
    return EsVerdad;
}

Clustering::std::string toString() const{
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

void Clustering::set(VectorLocation locations, int K, unsigned int seed=DEFAULT_RANDOM_SEED) {
    _locations = locations;
    if (K < 1 || K > _locations.getSize()) {
        throw std::out_of_range("Mal valor para K");
    }else {
        _K = K;
    }
    _seed = seed;
    _isDone = false;
    _clusters = VectorInt(locations.getSize());
    _centroids = VectorLocation(K);
    _sumWCV = 0.0;
    _numInterations = 0;
}

void run(){
    _centroids = VectorLocation();
    _clusters = VectorInt(_locations.getSize());
    _isDone = true; 
    _sumWCV = calculateSumWithinClusterVariances(); 
}