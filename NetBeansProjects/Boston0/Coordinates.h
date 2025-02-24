/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/**
 * @file Coordinate.h
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

    /**
     * @brief Constructor that builds an object with the given latitude 
     * and longitude parameters. Both parameters have the value
     * INVALID_COORDINATE as default value. 
     * @param latitude The latitude value to set. Default value
     * INVALID_COORDINATE. 
     * Input parameter
     * @param longitude The longitude value to set. Default value
     * INVALID_COORDINATE. 
     * Input parameter
     */
    Coordinates(float latitude = INVALID_COORDINATE,
            float longitude = INVALID_COORDINATE);

    /**
     * @brief Gets the latitude value
     * Query method
     * @return The latitude as a float.
     */
    float getLatitude() const;

    /**
     * @brief Gets the longitude value.
     * Query method
     * @return The longitude as a float.
     */
    float getLongitude() const;
    
    /**
     * @brief Checks if the current coordinates are valid; that is it 
     * determines if the latitude and longitude values are within
     * the aceptable ranges for geographical coordinates. <br> 
     * Latitude must be within the range [-90, 90], and longitude within the 
     * range [-180,180].<br>
     * Query method
     * @return true if the coordinates are valid, false otherwise.
     */
    bool isValid() const;

    /**
     * @brief Sets the latitude value in this object. 
     * Modifier method
     * @param latitude The latitude value to set. Input parameter
     */
    void setLatitude(float latitude);

    /**
     * @brief Sets the longitude value in this object. 
     * Modifier method
     * @param longitude The longitude value to be set. Input parameter
     */
    void setLongitude(float longitude);

    /**
     * @brief Sets both components, the latitude and longitude values. 
     * Modifier method
     * @param latitude The latitude value be to set. Input parameter
     * @param longitude The longitude value to be set. Input parameter
     */
    void set(float latitude, float longitude);

    /**
     * @brief Obtains a string with the latitude and longitude (comma separated).
     * To convert latitude and longitude to string you must use the
     * std::to_string() function.
     * Query method
     * @return A string representing the coordinates in the specified format.
     */
    std::string toString() const;

    /**
     * @brief Computes the dimension of the rectangle bounded by two
     * Coordinates objects (this object and the one provided as parameter
     * to this method).
     * The dimension of a rectangle that goes from Coordinates $A(lat_1,long_1)$ 
     * to $B(lat_2,long_2)$ is calculated as:
     * \f$ (|lat_2−lat_1|,|long_2−long_1|) \f$
     * The length is symmetric, that is, A.length(B) is equal to B.length(A).
     * This is valid whenever the area does not cross the meridian 180 
     * (Greenwich antimeridian) which is the international date change line.
     * Query method.
     * @param second A Coordinates object B. Input parameter.
     * @return A Coordinates object that will contain the dimension of the 
     * rectangle bounded by two Coordinates objects (this object and the one 
     * provided as parameter to this method).
     */
    Coordinates length(const Coordinates &second) const;

    /**
     * @brief Verifies if this object Coordinates is inside the area
     * determined by the two given Coordinates A (@p bottomLeft) and 
     * B (@p topRight). 
     *  ~~~~
     *     +-----------+(B)
     *     |           |
     *     |           |  +(O3)
     *     |           | 
     *     |    +(O2)  |
     *     |           |
     *     |           |
     *  (A)+-----------+
     *        +(O1)
     * ~~~~
     * Examples of false return:
     * - Object O3 surpasses longitude of B
     * - Object O1 has a latitude below that of A. 
     * Example of true return:
     * - Object O3 is inside the given area
     * 
     * Query method.
     * @pre both @p bottomLeft and @p topRight coordinates are valid and 
     * they define an area that does not cross the Greenwich antimeridian, 
     * that is, A <= B both in latitude and longitude; otherwise, 
     * unexpected return value could be obtained. This is not checked in this
     * method.
     * @param bottomLeft The Coordinates of the bottom left point. Input parameter
     * @param topRight The Coordinates of the top right point. Input parameter
     * @return true if the Coordinates of this object is inside the area
     * determined by the two given Coordinates
     */
    bool isInsideArea(const Coordinates &bottomLeft, const Coordinates &topRight) const;

private:
    const static float INVALID_COORDINATE;  ///< Constant that represents an invalid latitude or longitude
    float _latitude; ///< Latitude
    float _longitude; ///< Longitude
}; // end class Coordinates

#endif /* COORDINATES_H */
