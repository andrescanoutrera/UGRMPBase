/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/** 
 * @file:  ColorPalette.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on October 2, 2024, 1:20 PM
 */

#include "ColorPalette.h"
using namespace std;

void ColorPalette::init(int nColorsFromBlue, int nColorsFromLightBlue, 
        int nColorsFromGreen, int nColorsFromYellow) {
    int totalNumberOfColors = nColorsFromBlue + nColorsFromLightBlue
            + nColorsFromGreen + nColorsFromYellow + 1; // 1 for the red one
    if (totalNumberOfColors > MAX_NUMBER_COLORS){
        _numColors=0;
        throw std::invalid_argument(
            string("ColorPalette::ColorPalette(int nColorsFromBlue, int nColorsFromLightBlue, int nColorsFromGreen, int nColorsFromYellow): ") +
            " Invalid total number of colors = " + std::to_string(totalNumberOfColors));
    }
    if (nColorsFromBlue < 0 || nColorsFromLightBlue < 0 || nColorsFromGreen < 0
            || nColorsFromYellow < 0){
        throw std::invalid_argument(
            string("ColorPalette::ColorPalette(int nColorsFromBlue, int nColorsFromLightBlue, int nColorsFromGreen, int nColorsFromYellow): ") +
            " Number of colors per interval cannot be negative");
    }

    _numColors = totalNumberOfColors;
    int colorIndex = 0;
    for (int i = 0; i < nColorsFromBlue; i++) { // Insert colors from blue (included) to light blue
        _palette[colorIndex] = Color(0, 256 * i / nColorsFromBlue, 255);
        colorIndex++;
    }
    for (int i = 0; i < nColorsFromLightBlue; i++) { // Insert colors from light blue (included) to green
        _palette[colorIndex] = Color(0, 255, 255 - (256 * i / nColorsFromLightBlue));
        colorIndex++;
    }
    for (int i = 0; i < nColorsFromGreen; i++) { // Insert colors from green (included) to yellow
        _palette[colorIndex] = Color(256 * i / nColorsFromGreen, 255, 0);
        colorIndex++;
    }
    for (int i = 0; i < nColorsFromYellow; i++) { // Insert colors from yellow (included) to red
        _palette[colorIndex] = Color(255, 255 - (256 * i / nColorsFromYellow), 0);
        colorIndex++;
    }
    _palette[colorIndex] = Color(255, 0, 0); // Insert red color        
}

ColorPalette::ColorPalette(int da, int bl, int gr, int ye) {
    try{
        init(da, bl, gr, ye); // palette
    }
    catch(const std::invalid_argument &e) {
        init(2, 2, 2, 2);
    }
}

int ColorPalette::getNumColors() const {
    return _numColors;
}

const Color & ColorPalette::getColor(int index) const {
    if (index >= 0 && index < _numColors)
        return _palette[index];
    else
        throw std::invalid_argument(
            string("ColorPalette::getColor(int index) Index of color, not valid: ")
            + std::to_string(index));
}

std::string ColorPalette::toString() const {
    string outputString; // = 
    for (int i = 0; i < getNumColors(); i++) {
        outputString += _palette[i].toString() + "\n";
    }
    return outputString;
}

