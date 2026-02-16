/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/**
 * @file Coordinate.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on September 25, 2024, 1:03 PM
 */

#ifndef COORDINATES_H
#define COORDINATES_H

/**
 * @class Coordinates 
 * @brief GPS Coordinates (geographic coordinates) for measuring positions in
 * the Earth. It consists of a pair of float values (latitude and longitude) 
 * that express angles (degrees). See for example 
 * <a href="https://en.wikipedia.org/wiki/Geographic_coordinate_system">
 * Wikipedia Geographic coordinate system</a>  <br>
 * Values for latitude are between -90 and 90, while values for longitude
 * must be between -180 and 180. It is possible to build a Coordinates object
 * with a latitude or longitude out of that ranges, but that object will be 
 * considered as invalid (method \ref isValid() will return true).<br>
 * The value latitude == 0 is the EQUATOR, and the value longitude == 0 is the 
 * Greenwich meridian. <br>

 * - A point with a positive value for latitude is located in the northern 
 * hemisphere; a point with latitude==90 is in the North pole. <br>
 * - A point with a negative latitudeis located in the southern hemisphere. <br>
 * - A point with a positive longitude is located to the right of the Greenwich 
 * meridian.  <br>
 * - A point with a negative longitude is located to the left of the Greenwich 
 * meridian.  <br>
 * <br>
 * 
 * Examples: <br>
 * - Granada:  37.178056,-3.600833 
 * - Valencia: 39.47,-0.376389 
 * - Boston: 42.360278,-71.057778 
 * - Quito: -0.22, -78.5125 
 * - Johannesburgo: -26.204444, 28.045556 
 * <br>
 */


#include <iostream>
#include <string>

class Coordinates {
public:
     // Retrieve all previous declarations and take into account
     // the new declarations included here... 
     // 

    friend std::ostream operator<<(std::ostream os, Coordinates obj);
    friend std::ostream operator>>(std::ostream is, Coordinates obj);

private:
        
    const static float INVALID_COORDINATE; // ...
    // Retrieve all previous declarations 
};

/**
 * @brief Overloading of the stream insertion operator for Coordinates class. 
 * Sends to the output stream the latitude and longitude converted to strings, 
 * separated by a comma. It must use the std::to_string() function to 
 * convert latitude and longitude to strings.
 * @param os The output stream to be used. Input/output parameter
 * @param obj The Coordinates object. Input parameter
 * @return A reference to the output stream
 */
std::ostream operator<<(std::ostream os, Coordinates obj);

/**
 * @brief Overloading of the stream extraction operator for Coordinates class. 
 * First it reads from the input stream the latitude, then a character 
 * (the comma character) and finally the longitude. Those two values (float 
 * numbers) will be used to set the latitude and longitude of the given 
 * Coordinates object.
 * @param is The input stream to be used. Input/output parameter
 * @param obj The Coordinates object. Output parameter
 * @return A reference to the input stream
 */
std::istream operator>>(std::istream is, Coordinates obj);
