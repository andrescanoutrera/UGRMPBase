/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/** 
 * @file Color.cpp
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on October 2, 2024, 10:48 AM
 */

#include "Color.h"
using namespace std;

bool Color::isValid(int v) {
    return (v >= 0 && v <= Color::DEFAULT_RGB_VALUE);
}

Color::Color(int red, int green, int blue) {
    if (isValid(red) && isValid(green) && isValid(blue)) {
        _r = red;
        _g = green;
        _b = blue;
    }
    else throw std::invalid_argument(
            std::string("Color::Color(r,g,b) any of the three values ")
            + " are not a valid value for Color");
}

unsigned char Color::getRed() const {
    return _r;
}

unsigned char Color::getGreen() const {
    return _g;
}

unsigned char Color::getBlue() const {
    return _b;
}

std::string Color::toString() const {
    string outputString = std::to_string(_r) + " " +
            std::to_string(_g) + " " + std::to_string(_b);
    return outputString;
}
