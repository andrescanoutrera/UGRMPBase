/*
 * Metodología de la Programación
 * Curso 2025/2026
 */

/**
 * @file DataSet.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 30 de julio de 2025, 10:00
 */

#ifndef DATASET_H
#define DATASET_H

#include <string>
#include <iostream>
#include <fstream>

#include "VectorInt.h"
#include "VectorLocation.h"
#include "Clustering.h"

/**
 * @class DataSet
 * @brief A DataSet is an object that contains a set of n instances. Each 
 * instance contains a vector of m integers that represents the amount of 
 * money spent by a person in each one of m locations.
 * This class uses a bidimensional matrix with n rows and m columns to store
 * the values of the set of instances.
 * This class also contains a vector of n labels (VectorInt _labels) to store the 
 * label of each instance. Each label is an integer that defines the class 
 * value of the corresponding instance.
 * Finally, this class contains a vector of m Location objects 
 * (VectorLocation _locations) to store each locations in the DataSet.
 * In the 2D matrix, each column i is associated with location i in the 
 * _locations vector.
 */
class DataSet {
public:
    /**
     * @brief It builds a DataSet object with the provided number of instances
     * and number of locations. This class uses a bidimensional matrix with 
     * nInstances rows and nLocations columns to store the values of the set 
     * of instances.
     * Note that this constructor also builds the vector (with a size equal to 
     * nInstances) of labels and the vector of locations (with a size equal to 
     * nLocations).
     * This constructor initializes with a value of 0 all the values in the 2D
     * matrix. 
     * The vector of labels is initialized with a value of 0 for each instance.
     * The Location objects in the vector of locations are built with the 
     * Location default constructor.
     * @param nInstances An integer with the number of instances.
     * Input parameter
     * @param nLocations An integer with the number of locations.
     * Input parameter
     */
    DataSet(int nInstances = 0, int nLocations = 0);
    
    /**
     * @brief Copy constructor
     * @param orig the DataSet object used as source for the copy. 
     * Input parameter
     */
    DataSet(DataSet orig);
    
    /**
     * @brief Destructor
     */
    ~DataSet();
    
    /**
     * @brief Overloading of the assignment operator for DataSet class
     * Modifier method
     * @param orig the DataSet object used as source for the assignment.
     * Input parameter
     * @return A reference to this object
     */
    DataSet operator=(DataSet orig);

    /**
     * @brief Gets the number of instances in this DataSet
     * Query method
     * @return The number of instances in this DataSet
     */
    int getNumInstances();
    
    /**
     * @brief Gets the number of localizations in this DataSet
     * Query method
     * @return The number of localizations in this DataSet
     */
    int getNumLocations(); 
    
    /**
     * @brief Gets the value for the instance instanceIndex at the localization
     * locationIndex.
     * @throw Throws a std::out_of_range exception if instanceIndex is not 
     * a valid index for an instance in this DataSet.
     * @throw Throws a std::out_of_range exception if locationIndex is not a
     * valid index for an location in this DataSet.
     * Query method
     * @param instanceIndex An integer with the index of the selected instance. 
     * Input parameter
     * @param locationIndex An integer with the index of the selected location. 
     * Input parameter
     * @return The value for the instance instanceIndex at the localization
     * locationIndex
     */   
    int getValue(int instanceIndex, int locationIndex);
    
    /**
     * @brief Gets the label (integer value) of the instance at the provided
     * position (instanceIndex)
     * @throw Throws a std::out_of_range exception if instanceIndex is not 
     * a valid index for an instance in this DataSet.
     * Query method
     * @param instanceIndex An integer with the index of the selected instance.
     * Input parameter
     * @return The label (integer value) of the instance at the provided
     * position
     */
    int getLabel(int instanceIndex);
    
    /**
     * @brief Gets a const reference to the vector of Location objects in this
     * DataSet
     * Query method
     * @return A const reference to the vector of Location objects in this
     * DataSet
     */
    VectorLocation getVectorLocation();

    /**
     * @brief Gets a const reference to the vector of labels in this DataSet
     * Query method
     * @return A const reference to the vector of labels in this DataSet
     */
    VectorInt getVectorLabels();
    
    /**
     * @brief Obtains a string with information about this DataSet object, 
     * in the following format:
     * -Information about the set of locations of this DataSet:
     *    - A line with the number of locations
     *    - For each location, a line with its information, converted to
     *      a string with the Location::toString() method.
     * - Information about the labels of each instance in this DataSet:
     *    - A line with the number of instances
     *    - A line with the labels (space separated) of the set of instances.
     * - Instances of the Dataset. This is the information contained in the 
     *   2D matrix of this DataSet.
     *     - For each instance, a line with the values (space separated) of 
     *       that instance.
     * Query method
     * @return string with information about this CrimeSet object
     */
    std::string toString() ;

    /**
     * @brief Sets a new value for the instance instanceIndex at the 
     * localization locationIndex.
     * Modifier method
     * @param instanceIndex An integer with the index of the selected instance. 
     * Input parameter
     * @param locationIndex An integer with the index of the selected location. 
     * Input parameter
     * @param value An integer with the new value for the selected instance.
     * Input parameter
     */
    void setValue(int instanceIndex, int locationIndex, int value);
    
    /**
     * @brief Sets a new the label for the provided instance.
     * Modifier method
     * @param instanceIndex An integer with the index of the selected instance. 
     * Input parameter
     * @param label An integer with the new value for the label of the selected
     * instance.
     * Input parameter
     */
    void setLabel(int instanceIndex, int label);
    
    /**
     * Assigns the provided value to each instance and location. That is, all 
     * instances of this DataSet are initialized with the provided value.
     * Modifier method
     * @param value An integer with the value to assign to every instance and
     * location
     * Input parameter
     */
    void initInstances(int value = 0);
    
    /**
     * @brief Removes all the information in this DataSet object:
     * - The vector of Location objects (_locations) is left empty. That is,
     * it should represent a vector with 0 locations.
     * - The vector of labels (_labels) is left empty. That is, it should 
     * represent a vector with 0 labels.
     * - The matrix (_values) with the values for each instance is left empty. 
     * That is, it should represent a matrix with 0 instances and 0 locations.
     * - The remaining fields of this object are updated accordingly.
     * Modifier method
     */
    void clear();
    
    /**
     * @brief Saves this DataSet object in the given file. See files *.dts in 
     * the folder DataSets as example of files with DataSet information. 
     * Note that the format of the output file is the same as the string that
     * returns the toString() method, except that the save() method should 
     * insert the magic string at the beginning of the output file.
     * @throw std::ios_base::failure Throws a std::ios_base::failure exception 
     * if the given file cannot be opened or if an error occurs while writing
     * to the file.
     * Query method
     * @param fileName The name of the file where the DataSet will be saved. 
     * Input parameter
     */
    void save(std::string fileName);

    /**
     * @brief Loads into this object the DataSet information stored in the 
     * given file. See files *.dts in the folder DataSets as example of files
     * with DataSet information. 
     * @note Note that this method should remove any previous information that
     * this object previously contained.
     * @note This method throws an exception in some error cases (see below). 
     * Before throwing the corresponding exception, this method clears
     * the object (it calls to clear() method) to leave the object in a 
     * consistent state.
     * @throw throw std::invalid_argument Throws a std::invalid_argument 
     * exception if an invalid magic string is found in the given file
     * @throw std::out_of_range Throws a std::out_of_range exception if the 
     * number of locations or the number of instances in the given file is 
     * negative.
     * Modifier method
     * @param fileName The name of the file where the DataSet is stored. 
     * Input parameter
     * @throw std::ios_base::failure Throws a std::ios_base::failure exception 
     * if the given file cannot be opened or if an error occurs while reading
     * from the file. 
     */
    void load(std::string fileName);
    
    /**
     * @brief Gets a new DataSet from this DataSet. The DataSet will contain 
     * the same number of instances as this DataSet, but the number of locations
     * is given by the number of clusters in the provided Clustering object.
     * Therefore, the returned DataSet will have a reduced number of columns 
     * and an equal number of rows compared to this DataSet. 
     * The provided Clustering object defines how to reduce the set of columns.
     * Column 0 will contain the sum of the columns of this DataSet belonging 
     * to cluster 0, column 1 the sum of the columns belonging to cluster 1, 
     * and so on.
     * The vector of locations will be a copy of the vector of centroids of the
     * provided Clustering object.
     * The vector of labels will be a copy of the vector of labels in this 
     * DataSet.
     * @throw throw std::invalid_argument Throws a std::invalid_argument 
     * exception if the method Clustering::isDone() return false with the 
     * provided Clustering object.
     * @throw throw std::invalid_argument Throws a std::invalid_argument 
     * exception if the number of locations in the provided Clustering object
     * is not equal to the number of locations in this DataSet.
     * Query method
     * @param clustering A Clustering object.
     * Input parameter
     * @return A reduced DataSet
     */
    DataSet getReducedDataSet(Clustering clustering);

private:
    /**
     * A const string with the magic string for text files
     */
    static const std::string MAGIC_STRING_T;

    /**
     * Bidimensional matrix with the values of the instances of this DataSet.
     * It is a 2D matrix of integer values, with n rows and m columns. n is 
     * the number of instances in the DataSet and m is the number of locations.
     */
    int** _values;

    /**
     * Number of rows in the 2D matrix. It is the number of instances of the 
     * DataSet
     */
    int _nInstances;

    /**
     * Number of columns of the 2D matrix. It is the number of
     * locations of the DataSet
     */
    int _nLocations;

    /**
     * A VectorInt (vector of integers) with the labels of each one of the 
     * n instances in this DataSet. The order of the integers in this vector
     * is assumed to correspond to the order of the rows in the 2D matrix of 
     * this DataSet.
     */
    VectorInt _labels;
    
    /**
     * A VectorLocation object containing the m locations used in this DataSet. 
     * The order of the locations in this vector is assumed to correspond to 
     * the order of the columns in the 2D matrix of this DataSet.
     */
    VectorLocation _locations;
}; // end of class DataSet

#endif /* DATASET_H */

