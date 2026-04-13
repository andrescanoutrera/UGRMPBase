/*
 * Metodología de la Programación
 * Curso 2025/2026
 */

/**
 * @file ArrayClustering.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 22 de octubre de 2025, 11:57
 */

#ifndef ARRAYCLUSTERING_H
#define ARRAYCLUSTERING_H

#include "Clustering.h"

const int INITIAL_ARRAY_CLUSTERING_CAPACITY = 2;
const int ARRAY_CLUSTERING_CAPACITY_INCREMENT = 2;

/**
 * @struct ArrayClustering
 * @brief An ArrayClustering object contains a dynamic array of Clustering 
 * objects, along with its capacity and current size.
 */
struct ArrayClustering{
    Clustering *clustering; // Pointer to the dynamic array of Clustering objects
    int capacity; // Capacity of the dynamic array
    int size; // Current number of Clustering objects stored in the array
};

/**
 * @brief Initializes the provided ArrayClustering with a given capacity. It
 * allocates a dynamic array of Clustering objects with the provided capacity, 
 * sets the capacity field and initializes the size field to 0.
 * @throw std::out_of_range Throws a std::out_of_range exception if the
 * provided capacity is less than or equal to 0.
 * @param arrayClustering The ArrayClustering to initialize. Output parameter
 * @param capacity The initial capacity of the array. Input parameter
 */
void InitializeArrayClustering(ArrayClustering arrayClustering, 
    int capacity=INITIAL_ARRAY_CLUSTERING_CAPACITY);

/**
 * @brief Deallocates the dynamic array of Clustering objects in the provided
 * ArrayClustering. It also sets the clustering pointer to nullptr, and the
 * capacity and size fields to 0.
 * @param arrayClustering The ArrayClustering to deallocate. Output parameter
 */
void DeallocateArrayClustering(ArrayClustering arrayClustering);

/**
 * @brief Searches for a given Clustering object in the provided
 * ArrayClustering. The search is performed by comparing each Clustering object
 * in the array with the provided Clustering object using the
 * Clustering::isEquivalentTo() method.
 * @param arrayClustering The ArrayClustering where to search will be 
 * performed. Input parameter
 * @param clustering The Clustering object to search for. Input parameter
 * @return The position of the Clustering object in the array if found;
 * -1 otherwise.
 */
int FindArrayClustering(ArrayClustering arrayClustering,
                        Clustering clustering);

/**
 * @brief Appends the given Clustering object to the provided ArrayClustering
 * object. The Clustering object is only appended if the array does not 
 * contain another Clustering object equivalent to the one being inserted.
 * If the array is full and the Clustering object must be appended to the array,
 * this function resizes the array with a capacity equal to the current 
 * capacity plus an extra block of size equal to
 * ARRAY_CLUSTERING_CAPACITY_INCREMENT.
 * @param arrayClustering The ArrayClustering where the Clustering object will
 * be appended. Output parameter
 * @param clustering The Clustering object to append. Input parameter
 */
void AppendArrayClustering(ArrayClustering arrayClustering,
                           Clustering clustering);

/**
 * @brief Sorts the Clustering objects in the provided ArrayClustering in
 * ascending order based on their sum of within-cluster variances. If two
 * Clustering objects have the same sum of within-cluster variances, they are
 * further sorted by their number of iterations in ascending order.
 * @param arrayClustering The ArrayClustering to sort. Output parameter
 */
void SortArrayClustering(ArrayClustering arrayClustering);

#endif /* ARRAYCLUSTERING_H */