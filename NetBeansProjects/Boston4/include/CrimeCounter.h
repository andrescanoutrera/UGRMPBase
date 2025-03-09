/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/**
 * @file:   CrimeCounter.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * @note To be implemented by students 
 */

#ifndef CRIMECOUNTER_H
#define CRIMECOUNTER_H

#include <cstring>
#include <string>
#include "CrimeSet.h"
#include "ColorPalette.h"

/**
 * @class CrimeCounter
 * @brief It is a helper class used to calculate the number of crimes 
 * (frequency) occurring within each one of the smaller areas (cells) in which 
 * is divided a given target geographical area of the world. The target 
 * geographical area is determined by the next two fields in this 
 * class (Coordinates objects):
 * - _bottomLeftCoord: Bottom left corner of the target geographical area
 * - _topRightCoord: Top right corner of the target geographical area
 * 
 * The target geographical area is divided into smaller rectangular areas (cells)
 * using a grid of nRows x nColumns cells.  
 * This class uses a dynamic two-dimensional matrix of integers to store
 * the frequencies for each cell of the grid. Each integer in this matrix 
 * allows to save the frequency of one of the cells.
 * The field _frequency of this class is a pointer to that matrix.
 */
class CrimeCounter {
public:
    /**
     * Constant with the default Coordinates for the bottom left corner of the  
     * input geographical area. It is set to the bottom left corner of the 
     * Boston area
     */
    static const Coordinates DEFAULT_COORD_BOTTOMLEFT; 
    
    /**
     * Constant with the default Coordinates for the top right corner of the  
     * input geographical area. It is set to the top right corner of the 
     * Boston area
     */
    static const Coordinates DEFAULT_COORD_TOPRIGHT;
    
    /**
     * @brief Constructor of the class. It allocates memory for the
     * two-dimensional matrix of frequencies and sets the Coordinates
     * (bottom left corner and top right corner) that defines the target 
     * geographical area. 
     * Each element of the matrix will be initialized with 0 in this constructor.
     * If the provided number of rows or columns is less or equals to zero,
     * the matrix will be set with 0 rows and columns.
     * 
     * This constructor uses default values for the parameters 
     * @p bottomLeftCoord and @p topRightCoord that have been taken from the 
     * border coordinates of the dataset for Boston city (1). That full 
     * dataset is the source of the different datasets used in this course.
     * (1) (csv file located in
     * https://www.kaggle.com/datasets/shivamnegi1993/boston-crime-dataset-2022/data).
     * 
     * @pre bottomLeftCoord.latitude < topRightCoord.latitude
     * and bottomLeftCoord.longitude < topRightCoord.longitude in order to
     * calculate correctly the area set by the two Coordinates; otherwise
     * incorrect calculations could be obtained with this class. This constructor
     * does not check this precondition.
     * @thrown std::invalid_argument Throws an std::invalid_argument exception 
     * if any of the provided coordinates is invalid. In this case, the 
     * fields of the object are initialized as follows: 
     * - _nRows=0
     * - _rCols=0
     * - _frequency=nullptr 
     * - _bottomLeftCoord and _topRightCoord fields are left with the 
     * default value assigned by the default constructor of the 
     * class Coordinates;  
     * After the fields are initialized as described above, the exception 
     * is thrown.
     *  
     * @param nRows Number of rows for the frequency matrix. Input parameter
     * @param nColumns Number of columns for the frequency matrix. Input parameter.  
     * @param bottomLeftCoord Coordinates of the bottom left corner of the 
     * target geographical area. Input parameter
     * @param topRightCoord Coordinates of the top right corner of the 
     * target geographical area. Input parameter
     */
    CrimeCounter(int nRows = DEFAULT_ROWS, int nColumns = DEFAULT_COLUMNS,
            Coordinates  bottomLeftCoord = DEFAULT_COORD_BOTTOMLEFT, 
            Coordinates  topRightCoord = DEFAULT_COORD_TOPRIGHT);

    /**
     * @brief Copy constructor. Builds an exact copy of the provided 
     * object @p orig.
     * @param orig object used as source for the copy. Input parameter
     */
    CrimeCounter(CrimeCounter orig);

    /**
     * @brief Destructor
     */
    ~CrimeCounter();
    
    /**
     * @brief Overloads the assignment operator for CrimeCounter class.
     * Modifier method
     * @param orig the CrimeCounter object used as source for the assignment. 
     * Input parameter
     * @return A reference to this object
     */
    CrimeCounter operator=(CrimeCounter orig);

    /**
     * @brief Returns the numbers of rows of the frequency matrix in 
     * this object. 
     * Query method
     * @return The numbers of rows of the frequency matrix in this object
     */
    int getNumRows();

    /**
     * @brief Returns the numbers of columns of the frequency matrix in 
     * this object. 
     * Query method
     * @return The numbers of columns of the frequency matrix in this object
     */
    int getNumCols();

    /**
     * @brief Returns the bottom left corner (Coordinates) of the target
     * geographical area of this object. 
     * Query method
     * @return Returns the bottom left corner (Coordinates) of the target
     * geographical area of this object. 
     */
    Coordinates getLeftLocation();

    /**
     * @brief Returns the top right corner (Coordinates) of the target
     * geographical area of this object. 
     * Query method
     * @return The top right corner (Coordinates)  of the target
     * geographical area of this object. 
     */
    Coordinates getRightLocation();
    
    /**
     * @brief Returns a string with the content of this object. 
     * This string is as follows:
     * - First line, the content of the private data _nRows and _nCols separated 
     * by a white space
     * - Second line, the _bottomLeftCoord coordinates (using comma between 
     * latitude and longitude)
     * - Third line, the _topRightCoord coordinates (using comma between 
     * latitude and longitude)
     * - Next, a line for each row of the frequency matrix with the content
     * of that row (white space between values).
     * Query method
     * @return A string with the content of this object
     */
    std::string toString();
    
    /**
     * @brief Returns the maximum number of crimes (frequency) located in the
     * frequency matrix of this object. 
     * Query method
     * @return the maximum frequency found in the 2D matrix. Returns 0 if the 
     * matrix has 0 rows and columns.
     */
    int getMaxFrequency();

    /**
     * @brief Returns the number of counted crimes, that is the sum of 
     * the frequencies in the frequency matrix. 
     * @note That number includes only those crimes with valid coordinates
     * located inside the target geographical area.
     * Query method
     * @return the number of total crimes
     */
    int getTotalLocated();

    /**
     * @brief Sets all values in the frequency matrix to 0. 
     * Modifier method
     */
    void clear();

    /**
     * @brief Increases with the value @p frequency the current frequency of 
     * the cell of the frequency matrix that corresponds to the location of 
     * the given Crime.
     * If the coordinates of the given Crime are not valid or the Crime
     * is not inside the area of the target geographical area of this object, 
     * this method performs no action (does not increase any frequency).
     * If @p frequency is 0 or frequency is not provided, then 1 is added
     * to the current frequency of the selected grid cell.
     * Modifier method
     * @throw std::invalid_argument The method throws an
     * std::invalid_argument exception when the given crime Coordinates are
     * valid but outside the target area.
     * @param crime The crime to consider. Input parameter
     * @param frequency The quantity to add at the current frequency
     * of the corresponding grid cell. Input parameter
     */
    void increaseFrequency(Crime crime, int frequency = 0);

    /**
     * @brief Calculates the frequencies of the crimes that can be  
     * obtained from the provided CrimeSet.
     * Only the crimes of the provided CrimeSet, with a location inside the 
     * target area of this object will be considered; others will be ignored.
     * This method sets to zero the frequency of each cell before starting to 
     * calculate frequencies. In this way, if this method is called twice 
     * consecutively, then this CrimeCounter will contain only the frecuencies
     * calculated in the last call.
     * Modifier method
     * @param crimes A CrimeSet object. Input parameter
     */
    void calculateFrequencies(CrimeSet crimes);
    
    /**
     * @brief Saves the matrix of frequencies of this object as a 
     * PPM color image. In a PPM (portable pixmap format) color image, 
     * each pixel (Color) of the image is saved as three integer 
     * numbers: the red, green and blue components (each one in the range 0-255).
     * This method follows the following steps to build the PPM file:
     * - It saves the string "P3" in a line.
     * - Then it saves the provided comments (if they are not empty). It is neccesary
     * to insert the character '#' at the beginning of the line.
     * - Next it saves the number of columns and rows (separated by white space).
     * - Next it saves the integer 255
     * - Finally it saves the pixels of the image (three integers for each pixel)
     * separated by white space. Pixels should be traversed by rows, and then
     * by column.
     * 
     * In this method, each frequency value in the matrix, is translated to 
     * a color of the output image with the help of the functions 
     * int GetIndexPalette() and ColorPalette::getColor() 
     * in the following way:
     * 
     * int pixelIndex = GetIndexPalette(palette, log((*this)(row,column)+1), 
     *     log(maxFrequency+1));
     * Color color = palette.getColor(pixelIndex);
     * 
     * where maxFrequency is the maximum frequency value found in the frequency
     * matrix.
     * 
     * Example of a PPM file:
     * P3
     * # "P3" means this is a PPM  color image in ASCII
     * # "3 2" is the width and height of the image in pixels
     * # "255" is the maximum value for each color
     * # This, up through the "255" line below are the header.
     * # Everything after that is the image data: RGB triplets.
     * # In order the pixel of this image are: red, green, blue, 
     * # yellow, white and black colors.
     * 3 2
     * 255
     * 255   0   0
     *   0 255   0
     *   0   0 255
     * 255 255   0
     * 255 255 255
     *   0   0   0
     * 
     * Query method
     * @param fileName String with the name of the file for the output image. 
     * Input parameter
     * @param palette The palette used to translate frequencies to colors
     * of the output image. Input parameter 
     * @param comment The comment may include 0 or several lines separated by \n. Input parameter
     * any of them is prefixed with the '#' character, ending by "\n"
     * @throw std::ios_base::failure Throws a std::ios_base::failure exception 
     * if the given file cannot be opened or if an error occurs while writing 
     * to the file.
     */
    void saveAsPPMTextImage(std::string fileName, 
        ColorPalette palette, std::string comment = "");
    
private:
    
    /**
     * Integer constant with the default number of rows in the matrix of 
     * frequencies
     */
    static const int DEFAULT_ROWS = 15; 
    
    /**
     * Integer constant with the default number of columns in the matrix of 
     * frequencies
     */
    static const int DEFAULT_COLUMNS = 10; 
    
    int** _frequency; ///< 2D matrix with the crime frequency for each grid cell
    int _nRows; ///< number of rows of the 2D matrix of frequencies
    int _nCols; ///< number of columns of the 2D matrix of frequencies


    /**
     * Coordinates that defines the bottom left corner of the input geographical 
     * area
     */
    Coordinates _bottomLeftCoord;

    /**
     * Coordinates that defines the top right corner of the input geographical 
     * area
     */
    Coordinates _topRightCoord;
    
    /**
     * @brief Obtains the row and column in the frequency matrix that 
     * corresponds to the provided Coordinates @p coordinates. 
     * 
     * This method performs the following steps to obtain row and column:
     * - Compute the height (height) and width (width) of the cells in which 
     * is divided the target geographical area. For the height the latitude 
     * is used and for the width the longitude is used.
     * - Compute the vertical (vd) and horizontal (hd) distances 
     * of the provided Coordinates @p coordinates to the bottom left corner 
     * of the target geographical area.
     * - Compute row = _nRows - vd/height and column=hd/width
     * - The previous row or column values must be decremented by one when 
     * they are equals respectively to the number of rows or columns of 
     * the matrix, to avoid that the obtained value is an index outside the 
     * valid range of indices of rows or columns of the frequency matrix.
     * Query method
     * @pre the location @p coordinates is valid and is inside the area set by
     * the Coordinates _bottomLeftCoord, _topRightCoord; otherwise an exception
     * will be thrown
     * @throw std::invalid_argument This method throws an 
     * std::invalid_argument exception when the given Coordinates are
     * not valid or they are outside the target geographical area. 
     * @param coordinates The Coordinate to look for its location into the
     * matrix. Input parameter
     * @param row The corresponding row into the frequency matrix. 
     * Output parameter
     * @param column The corresponding column into the frequency matrix. 
     * Output parameter
     */
     void CrimeCounter::getRowColumn(const Coordinates &coordinates, int& row, 
        int& column) const;

    /**
     * @brief Overloading of the () operator to access to the element at a
     * given position in the matrix of frequencies
     * @param row Row of the element
     * @param column Column of the element
     * @return A reference to the element at the given position
     */
    int operator()(int row, int column);

    /**
     * @brief Overloading of the () operator to access to the element at a
     * given position in the matrix of frequencies
     * @param row Row of the element
     * @param column Column of the element
     * @return A reference to the element at the given position
     */
    int operator()(int row, int column);
    
}; // end class CrimeCounter

/**
 * @brief Computes the index into the given palette that corresponds to the 
 * provided frequency. This index is calculated as follow:
 * - If frequency == maxFrequency then index=palette.getNumColors()-1;
 * - Else index=frequency * palette.getNumColors() / maxFrequency
 * @param palette The given palette. Input parameter
 * @param frequency The input value for which we want to obtain its 
 * corresponding index in the palette. 
 * Input parameter
 * @param maxFrequency Maximum value of frequency to consider. It should be
 * previously obtained as the maximum value in the frequency matrix. 
 * Input parameter
 * @return index into the Color palette that corresponds to the provided 
 * frequency
 */
int GetIndexPalette(const ColorPalette &palette, float frequency, float maxFrequency);

#endif /* CRIMECOUNTER_H */
