/*
 * Metodología de la Programación
 * Curso 2025/2026
 */

/**
 * @file Clustering.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 22 de octubre de 2025, 11:57
 */

#ifndef CLUSTERING_H
#define CLUSTERING_H

#include "VectorInt.h"
#include "VectorLocation.h"

/**
 * @class Clustering
 * @brief This class is used to obtain a clustering of a given set of locations 
 * (Location objects). A clustering algorithm groups the input locations 
 * into K disjoint groups (clusters). The clustering algorithm used in this 
 * class is the K-Means algorithm. Each group will consist of a disjunct subset 
 * of the original location set and a representative location (centroid), which 
 * is calculated as the vector of the means of the locations in the group. The
 * run() method in this class executes the algorithm. An example of use is the
 * following:
VectorLocation locations;
// Suppose here code to fill the vector of locations
Clustering clustering;
clustering.set(locations, 5);
clustering.run();
 */
class Clustering {
public:
    /**
     * @brief Constructor that builds a Clustering object initializing
     * the field (_K) for the number of clusters with 0; the field (_isDone)
     * that tells whether the run() method has already been executed 
     * with false; the fields _sumWCV and _numIterations with 0 and the field
     * _seed with DEFAULT_RANDOM_SEED. 
     * The fields (_locations, _clusters,  _centroids) are initialized with 
     * the default constructor of their classes. 
     */
    Clustering();
    
    /**
     * @brief Gets the number of clusters
     * Query method
     * @return The number of clusters
     */
    int getK();
    
    /**
     * @brief Gets the current vector of centroids
     * Query method
     * @return A const reference to the vector of centroids (a VectorLocation
     * object).
     */
    VectorLocation getCentroids();
    
    /**
     * @brief Indicates whether the clustering algorithm (run() method) has 
     * already been executed for this Clustering object.
     * Query method
     * @return true if the run() method has already been executed for this 
     * Clustering object; false otherwise
     */
    bool isDone();
    
    /**
     * @brief Gets the number of locations in the set of locations of this 
     * Clustering object.
     * Query method
     * @return The number of locations in the set of locations of this 
     * Clustering
     */
    int getNumLocations();
    
    /**
     * @brief Gets the cluster number for the Location determined by the  
     * provided integer (@p locationIndex)
     * Query method
     * @param locationIndex An integer that determines the position of a 
     * location in the vector of Location objects. Input parameter
     * @return The cluster number for the Location determined by 
     * the provided integer (@p locationIndex). If the
     * clustering algorithm has not been run (_isDone is false), then it returns
     * -1.
     */
    int clusterOf(int locationIndex);
    
    /**
     * @brief Gets the value of the sum of the within-cluster variances of this 
     * Clustering. This value is obtained from the field _sumWCV
     * @note The returned value will likely be a garbage value if the run() 
     * method has not yet been executed (_isDone is false)
     * Query method
     * @return A double with the sum of within-cluster variances of this 
     * Clustering
     */
    double getSumWCV();

    /**
     * @brief  Gets the number of iterations used in the KMeans 
     * algorithm until no cluster assignment change occurs.
     * It obtains the number of iterations (field _numberIterations) used 
     * in the KMeans algorithm until no cluster change occurred.
     * @note The returned value will likely be a garbage value if the run() 
     * method has not yet been executed (_isDone is false)
     * Query method
     * @return The number of iterations used in the KMeans algorithm
     */
    int getNumIterations();

    /**
     * @brief  Gets a string with information about the provided cluster (index
     * of a cluster). That string contains a line for each location in the given
     * cluster. The information of each location consists of an integer with 
     * its location index (whithin the _location field), a whitespace, and 
     * the information returned by the Location::toString() method for that 
     * location. An example is the following (a cluster with three locations):
0 3.300000 9.100000 Graduate College
6 12.600000 17.500000 Admission Information Center
7 12.500000 20.000000 Rockefeller College
     * Query method
     * @param cluster An integer, that defines the index of a cluster. Input
     * parameter
     * @return Gets a string with information about the provided cluster. If the
     * clustering algorithm has not been run (_isDone is false) or an 
     * invalid value of cluster is provide, then it returns an empty string.
     */
    std::string clusterInfo(int cluster);

    /**
     * @brief Obtains a string with the some statistics data about this 
     * Clustering object. 
     * The first line contains the value of K; the second line contains the
     * value of the sum of within-cluster variances; the third line contains
     * the number of iterations used in the KMeans algorithm.
     * Query method
     * @return A string with the content described above
     */
    std::string getStatistics();

    /**
     * @brief Indicates whether this Clustering object is equivalent to the 
     * provided Clustering object (@p other). Two Clustering objects are 
     * considered equivalent if they have the same K value, 
     * the same sum of within-cluster variances and the same number of 
     * iterations in the KMeans algorithm.
     * If either this Clustering object or the provided Clustering object 
     * (@p other) has not yet run the clustering algorithm (the run() method), 
     * then they are not considered equivalent.
     * Query method
     * @param other A Clustering object. Input parameter
     * @return true if this Clustering object is equivalent to the provided 
     * Clustering object (@p other); false otherwise
     */
    bool isEquivalentTo(Clustering other);

    /**
     * @brief Obtains a string with the fields of this Clustering object. 
     * The first line contains the value of K; the second line contains the
     * value of the sum of within-cluster variances; the third line contains
     * the number of iterations used in the KMeans algorithm.
     * In the next three lines, information about the cluster number for each
     * location.
     * If follows information about each centroid
     * Next, for each cluster, information about its locations
     * Here, an example is shown:
K=5
Sum of within-cluster variances: 161.136889
Number of iterations: 5
Cluster number for each location:
21
0 2 2 2 2 2 1 1 1 1 1 4 4 4 4 4 4 4 4 4 3
Centroids:
5
3.300000 9.100000 
14.880000 21.280000 
12.600000 9.460000 
18.500000 6.700000 
26.088889 15.366667 
Cluster 0 information:
0 3.300000 9.100000 Graduate College
Cluster 1 information:
6 12.600000 17.500000 Admission Information Center
7 12.500000 20.000000 Rockefeller College
8 13.700000 22.800000 Art Museum Store
9 17.000000 23.300000 Princeton University Store
10 18.600000 22.800000 Labyrinth Books
Cluster 2 information:
1 11.800000 6.900000 Wawa Public Restrooms
2 12.600000 7.300000 Princeton Station
3 10.100000 9.700000 Forbes College
4 13.300000 12.200000 Dinky Bar & Kitchen
5 15.200000 11.200000 Whitman College
Cluster 3 information:
20 18.500000 6.700000 Yeh College
Cluster 4 information:
11 20.900000 15.400000 Frist Campus Center
12 23.700000 14.800000 Cannon Dial Elm
13 24.800000 14.900000 Quadrangle
14 25.600000 14.900000 Ivy
15 26.400000 14.900000 Cottage
16 27.300000 14.500000 Cap & Gown
17 28.200000 15.000000 Cloister
18 29.100000 15.200000 Charter
19 28.800000 18.700000 Engineering Quadrangle
     * Query method
     * @return A string with the content described above
     */
    std::string toString(); 
    
    /**
     * @brief Sets the vector of locations (_locations), the value of K (_K)  
     * and the seed (_seed) with the provided values.
     * The fields _isDone, _clusters and _centroids_ are also initialized 
     * appropriately: _isDone is set to false; _clusters is initialized with
     * a VectorInt object with size equal to the number of locations;
     * _centroids is initialized with a VectorLocation object with size K;
     * the fields _sumWCV and _numIterations are set to 0.
     * Modifier method
     * @throw std::invalid_argument Throws an std::invalid_argument exception
     * if K<=0
     * @param locations The vector of locations to used in the clustering 
     * algorithm. Input parameter
     * @param K The parameter K for the K-Means algorithm. Input parameter
     * @param seed The seed used to initialize the random number generator
     * (with srand(seed)) in the initialClusterAssignment() method. 
     * Input parameter
     */
    void set(VectorLocation locations, int K, 
        unsigned int seed=DEFAULT_RANDOM_SEED);
    
    /**
     * @brief Run the clustering algorithm. The clustering algorithm implemented  
     * in this method is the KMeans algorithm. 
     * After running this method the following postcondition should be verified: 
     * @post The _centroids field should contain the vector of the means of 
     * locations in each group
     * @post _clusters (a VectorInt object) should contain the cluster number  
     * for each location in the vector of locations (_locations)
     * @post The _isDone field should be set to true 
     * @post The _sumWCV field should be set to the sum of the within-cluster 
     * variances using the claculateSumWithinClusterVariances() method.
     * @post The _numberIterations field should be set to the number of  
     * iterations used by the KMeans algorithm.
     * 
     * A brief description of the KMeans algorithm is the following:
     * 
     * -# Perform an initial assignment of a cluster to each of the Location
     * objects. This must be done by initializing the random number 
     * generator using srand(seed); 
     * Then, for each location i, assign cluster number rand() % _K 
     * to that location. Note that this step is done by modifying the _clusters 
     * field.
     * -# Repeat while any location changes its cluster number:
     *     - For each cluster, recalculate its centroid (update _centroids 
     *       field).
     *     - Assign each location to a cluster (update _clusters field). 
     *       Each location is assigned to the cluster that provides 
     *       the shortest distance to its centroid.
     * 
     * Query method
     */
    void run();

private:
    /**
     * Default random seed used to initialize the random number 
     * generator used in the initialClusterAssignment() method.
     */
    static const unsigned int DEFAULT_RANDOM_SEED=1761560597U;
    
    /**
     * Vector of Location objects. This will be the input for the 
     * clustering algorithm
     */
    VectorLocation _locations;
    
    /**
     * Number of clusters
     */
    int _K;
    
    /**
     * Vector of n integers (number of elements in _locations). This will
     * be the output of the clustering algorithm. 
     * The integers in this vector define the cluster number (values in the 
     * interval [0 - _K-1]) for each one of the Location object in  _locations
     */
    VectorInt _clusters;
    
    /**
     * A vector of @p _K Location objects with the centroids of each cluster. 
     */
    VectorLocation _centroids;
    
    /**
     * It indicates whether the run() method has already been executed to 
     * obtain a clustering of the set of Location objects. The run() method
     * should set this field to true when it ends its execution.
     */
    bool _isDone;

    /**
     * Seed used to initialize the random number generator (with srand(seed)) in 
     * the initialClusterAssignment() method.
     */
    unsigned int _seed;
    
    /**
     * This is the sum of the whithin-cluster variances of the clusters in
     * this Clustering object.
     * The value for this field should be set at the end of run() method
     * with the method calculateSumWCV(). Before running the
     * run() method, this field will likely contain a garbage value.
     * @note The value of the sum of the within-cluster variances can also be 
     * retrieved using the method calculateSumWCV(). 
     * This field is introduced in this class to calculate its value once, 
     * and thus avoiding having to recalculate it every time it 
     * is needed
     */
    double _sumWCV;
    
    /**
     * This field represents the number of iterations used in the KMeans 
     * algorithm until no cluster change occurred. Before running the
     * run() method, this field will likely contain a garbage value.
     * The value for this field should be set at the end of run() method.
     */
    int _numIterations;
    
    /**
     * @brief Performs an initial assignment of a cluster to each one of the 
     * Location objects. This method begins by initializing the random number 
     * generator using: 
     * srand(seed); 
     * Then, for each location i, assign cluster number rand() % _K to that 
     * location.
     * Modifier method
     */
    void initialClusterAssignment();
    
    /**
     * @brief Calculates the sum of the within-cluster variances of this 
     * Clustering object.
     * The within-cluster variance of a cluster C_j is calcultated with:
     * $\sum_{p_i \in C_j} squaredDistance(p_i, centroid_{C_j})$
     * @return A double with the sum of within-cluster variances of this 
     * Clustering
     * Modifier method
     */
    double calculateSumWCV();
}; // end of class Clustering

#endif /* CLUSTERING_H */

