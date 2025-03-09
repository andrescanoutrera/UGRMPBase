/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/** 
 * @file:  Color.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 *
 * Created on October 2, 2024, 10:48 AM
 */

#ifndef COLOR_H
#define COLOR_H

#include <iostream>

/**
 * @class Color
 * @brief A color object Color(red, green, blue) is used to encapsulate colors 
 * in the default RGB color space. An RGB color value is specified with 
 * 3 components (alpha components): red, green and blue. Each component is 
 * represented using and unsigned char value (alpha value) in the range 0 - 255.
 * Value of 255 means that the basic color is completely 
 * opaque and an alpha value of 0 means that the color is completely transparent.
 * For example: 
 *   - Color(255, 0, 0) represents red color, that is, red is set to 
 *     its highest value (255), and the other two (green and blue) are set to 0
 *   - Color(0, 255, 0) represents green color
 *   - Color(0, 0, 255) represents blue color 
 *   - Color(0, 0, 0) represents black color 
 *   - Color(255, 255, 255) represents white color 
 */
class Color {
public:
    /**
     * @brief  Creates a RGB color with the specified red, green, and 
     * blue values, each one in the range (0 - 255). 
     * Each one of the three components (red, green and blue) is 255 by default.
     * @param red  the red component. Input parameter
     * @param green  the green component. Input parameter
     * @param blue  the blue component. Input parameter
     * @throw std::invalid_argument This method throws an std::invalid_argument 
     * exception  if red, green or blue are outside of the range [0..255],  
     * both inclusive.
     */
    Color(int red = DEFAULT_RGB_VALUE, int green = DEFAULT_RGB_VALUE,
            int blue = DEFAULT_RGB_VALUE);
    /**
     * @brief Returns the red component in the range 0-255 in the default RGB space.
     * Query method
     * @return The red component of this Color
     */
    unsigned char getRed() const;
    /**
     * @brief Returns the green component in the range 0-255 in the default RGB space.
     * Query method
     * @return The green component of this Color
     */
    unsigned char getGreen() const;
    /**
     * @brief Returns the blue component in the range 0-255 in the default RGB space.
     * Query method
     * @return The blue component of this Color
     */
    unsigned char getBlue() const;
       
    /**
     * @brief Returns a string representation of this Color with the three
     * component values separated by a whitespace. 
     * Query method
     * @return  the string composed
     */
    std::string toString() const;
        
private:
    /**
     * Constant with the default value for each RGB value
     */
    static const unsigned char DEFAULT_RGB_VALUE=255;
    
    unsigned char _r; ///<  Red component
    unsigned char _g; ///<  Green component
    unsigned char _b; ///<  Blue component 
    
    /**
     * @brief function that verifies that an alpha value is in the correct 
     * domain.
     * Query method
     * @param v any of the 3 components of the Color object.
     * @return true when v in the correct range; false otherwise
     */
    bool isValid(int v);
}; // end class Color

#endif /* COLOR_H */



