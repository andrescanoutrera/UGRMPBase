/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/** 
 * @file:  CrimeCounter.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * Created on September 24, 2024, 3:19 PM
 */

#include <iostream>
#include <fstream>
#include <cmath>

#include "CrimeCounter.h"
using namespace std;


/**
 * DEFAULT_COORD_BOTTOMLEFT is set to the bottom left corner of the Boston area
 */
const Coordinates CrimeCounter::DEFAULT_COORD_BOTTOMLEFT(42.207760,-71.178673);  

/**
 * DEFAULT_COORD_TOPRIGHT is set to the top right corner of the Boston area
 */
const Coordinates CrimeCounter::DEFAULT_COORD_TOPRIGHT(42.395042,-70.953728);  


/* CrimeCounter::CrimeCounter(
...//
 */

void saveAsPPMTextImage(std::string fileName, 
        ColorPalette palette, std::string comment = ""){  // declaration must be revised
    // Compute maxFrequency as the maximum frequency in the frequency matrix
    // Save heading and comments into the ppm file
    // For every cell in the frequency matrix
            // colorIndex = GetIndexPalette(palette, 
                  //log(this->_frequency[row][column]+1), log(maxFrequency+1));
            // Save into the ppm file the RGB components of the color at 
                  //the position colorIndex of the palette
}

void CrimeCounter::getRowColumn(const Coordinates &coordinates, int& row, 
        int& column) const {
    if (!coordinates.isValid() || 
            !coordinates.isInsideArea(_bottomLeftCoord, _topRightCoord)) {
        throw std::invalid_argument(
            string("void CrimeCounter::getRowColumn((const Coordinates &loc, int& row, int& column) const: ") +
            coordinates.toString() + " is not a valid location or is outside the target area");
    }
    Coordinates targetArea = this->_bottomLeftCoord.length(this->_topRightCoord);
    float cellHeight = targetArea.getLatitude()/_nRows;
    float cellWidth = targetArea.getLongitude()/_nCols;
    Coordinates delta = _bottomLeftCoord.length(coordinates);
    
    row = _nRows - (delta.getLatitude() / cellHeight);
    column = (delta.getLongitude() / cellWidth);
    if (row == _nRows) row = _nRows-1;
    if (column == _nCols) column = _nCols-1;
}

// External functions
int GetIndexPalette(const ColorPalette &palette, float frequency, float maxFrequency) {
    return frequency == maxFrequency ? palette.getNumColors() - 1 : 
        frequency * palette.getNumColors() / maxFrequency;
}