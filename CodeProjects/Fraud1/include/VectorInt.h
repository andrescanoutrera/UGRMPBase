/*
 * Metodología de la Programación
 * Curso 2025/2026
 */

/**
 * @file VectorInt.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * 
 * Created on 30 de julio de 2025, 9:54
 */

#ifndef VECTORINT_H
#define VECTORINT_H

#include <iostream>
#include <string>

/**
 * @class VectorInt
 * @brief A VectorInt object contains a vector of integer elements. It has
 * a capacity (maximun number of elements that can be stored in the vector)
 * and a size (number of elements the vector currently contains).
 */
class VectorInt {
public:
    
    /**
     * @brief It builds a VectorInt object (vector of integers) with a 
     * size and capacity equal to the provided value (@p size). Each element
     * will be filled with a value equal to 0.
     * @throw std::out_of_range Throws a std::out_of_range exception if
     * @p size < 0 or size>DIM_VECTOR_VALUES
     * @param size The size for the vector of integers in this object. Input
     * parameter
     */
    VectorInt(int size=0);
    
    /**
     * @brief Gets the number of elements in the vector of this object
     * Query method
     * @return The number of elements
     */
    int getSize();
    
    /**
     * @brief Gets the capacity of the vector in this object
     * Query method
     * @return The capacity of the vector in this object
     */
    int getCapacity();
    
    /**
     * @brief Compares the integer vectors of this object and the provided 
     * object, and returns the number of identical elements in both of them. The 
     * comparison is performed in order, element by element, in both vectors.
     * For example, given the following two vectors:
     * 2 1 2 3 5
     * 1 1 2 4 5
     * this method will return 3 (there is a match ​in positions 1, 2 and 4)
     * @throw std::invalid_argument Throws an std::invalid_argument exception 
     * if the sizes of this and the provided object are different
     * Query method
     * @param other A VectorInt object. Input parameter
     * @return The number of identical elements in the vectors of this
     * and the provided object.
     */
    int countIdenticalElements(VectorInt other);
    
    /**
     * @brief Obtains a string with information about this VectorInt object, 
     * in the following format:
     * - First line, the number of elements in this vector. 
     * - Second line, the elements in this vector, separated by a whitespace. 
     * Take into account that a '\n' should appear after the last element 
     * instead of a whitespace.
     * Query method
     * @return string with information about this VectorInt object
     */
    std::string toString();

    /**
     * @brief Gets the Euclidean distance between this and the provided object.
     * The Euclidean distance between two points \f$ P=(p_1, p_2, ... , p_n) \f$ 
     * and \f$ Q=(q_1, q_2, ... , q_n) \f$ in an n-dimensional space \f$ R^n \f$ 
     * is the length of the line segment connecting them, calculated as the 
     * square root of the sum of the squared differences of their components: 
     * \f$ d(P,Q)=\sqrt{ \sum_{i=1}^{n} (p_i-q_i)^{2} } \f$
     * @throw std::invalid_argument Throws an std::invalid_argument exception 
     * if the size of this object and the provided one are not equal
     * @throw std::invalid_argument Throws an std::invalid_argument exception 
     * if the size of the provided object is zero
     * Query method
     * @param other A VectorInt. Input parameter
     * @return The Euclidean distance between this and the provided objects
     */
    double distance(VectorInt other);
    
    /**
     * @brief Assigns the provided value to all the elements in this vector
     * Modifier method
     * @param value An integer value. Input parameter
     */
    void assign(int value=0);
    
    /**
     * @brief Appends the given integer value at the end (first free position) 
     * of the array of integers in this object. 
     * @throw std::out_of_range Throws a std::out_of_range exception if the 
     * array of Location was full (its capacity was full).
     * Modifier method
     * @param value the new integer value to be appended. Input parameter
     */
    void append(int value);
    
    /**
     * @brief Removes all the elements in this object, leaving the container 
     * with a size equal to 0. It only need to set the number of elements 
     * (_size field) to zero.
     * Modifier method
     */
    void clear();

    /**
     * @brief Gets a const reference to the integer element at the given 
     * position
     * Query method
     * @param pos position in the VectorInt object. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * given position is not valid.
     * @return A const reference to the integer element at the given position
     */
    int at(int pos);
    
    /**
     * @brief Gets a reference to the integer element at the given position. 
     * Modifier method
     * @param pos position in the VectorInt object. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * given position is not valid
     * @return A reference to the integer element at the given position.
     */
    int at(int pos);

private:
    /**
     * Constant with the capacity of the array _values
     */
    static const int DIM_VECTOR_VALUES = 100; 

    /**
     * Array of integers with the integer elements in this object
     */
    int _values[DIM_VECTOR_VALUES];
    
    /**
     * Number of elements contained in the array _values
     */
    int _size;

}; // end of class VectorInt

#endif /* VECTORINT_H */

