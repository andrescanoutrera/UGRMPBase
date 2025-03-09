/*
 * Metodología de la Programación
 * Curso 2024/2025
 */

/** 
 * @file:  ColorPalette.h
 * @author Silvia Acid Carrillo <acid@decsai.ugr.es>
 * @author Andrés Cano Utrera <acu@decsai.ugr.es>
 * @author Luis Castillo Vidal <L.Castillo@decsai.ugr.es>
 * @
 *
 * Created on October 2, 2024, 1:20 PM
 */

#ifndef COLORPALETTE_H
#define COLORPALETTE_H

#include "Color.h"

/**
 * @class ColorPalette
 * @brief A palette contains a list of Colors.
 * The maximum number of colors in the list is MAX_NUMBER_COLORS. 
 */
class ColorPalette {
public:
    /**
     * @brief Builds a ColorPalette with a list of 4 intervals of "primary" 
     * colors and the red color (Color(255, 0, 0)). 
     * This constructor has 4 integer parameters to control the
     * number of colors in each interval:
     * -# \p da: number of colors from dark blue Color(0, 0, 255) (included)
     * to light blue Color(0, 255, 255) (not included).
     * -# \p bl: number of colors from light blue Color(0, 255, 255) (included) 
     * to green Color(0, 255, 0) (not included).
     * -# \p gr: number of colors from green Color(0, 255, 0) (included) 
     * to yellow Color(255, 255, 0) (not included).
     * -# \p bl: number of colors from yellow Color(255, 255, 0) (included) 
     * to red Color(255, 0, 0) (not included).
     * 
     * The total number of colors in the palette is the addition of all the 
     * tones in each interval plus 1 (red color). 
     * 
     * Examples:
     * - ColorPalette(0,0,0,0) has only one color, the red one Color(255, 0, 0)
     * - ColorPalette(1,1,1,1) has got 5 colors: 
     * Color(0, 0, 255), Color(0, 255, 255), Color(0, 255, 0),  
     * Color(255, 255, 0) and Color(255, 0, 0).
     * - ColorPalette(3,0,0,0) has 4 colors:  Color(0, 0, 255), 
     * Color(0, 85, 255), Color(0, 170, 255) and Color(255, 0, 0).
     * 
     * @note If the total number of colors in the new palette is greater than 
     * ColorPalette::MAX_NUMBER_COLORS or any of the provided parameters is 
     * negative this constructor builds a palette using the values
     * da=2, bl=2, gr=2, ye=2
     * 
     * @param da number of tones from dark blue (included) to light blue
     * (not included) 
     * @param bl number of tones from light blue (included) to green
     * (not included) 
     * @param gr number of tones from green (included) to yellow (not included)
     * @param ye number of tones from yellow(included) to red (not included) 
     */
    ColorPalette(int da=2, int bl=2, int gr=2, int ye=2);
    
    /**
     * @brief Returns the number of colors into the palette 
     * (a value among 1 and MAX_NUMBER_COLORS).
     * Query method
     * @return number of colors into the palette.      
     */
    int getNumColors() const;
    
    /**
     * @brief Gets a const reference to the Color at the given position 
     * A value between [0.. numColors[ .
     * Query method
     * @param index the position to consider. Input parameter
     * @throw std::out_of_range Throws an std::out_of_range exception if the 
     * given index is not valid 
     * @return A const reference to the Color at the given position.
     */
    const Color & getColor(int index) const;
   
    /**
     * @brief Returns a string composed one by one by the Colors stored into
     * the palette separated by "\n". 
     * Query method
     * @return A string with the list of Colors into the palette separated by 
     * "\n". 
     */
    std::string toString() const;
private:
    static const int MAX_NUMBER_COLORS =100; ///< The capacity of the array _palette
    
    Color _palette[MAX_NUMBER_COLORS]; ///< array with the list of colors
    int _numColors; ///< Number of used elements in _palette
    
    /**
     * Private method to fill colors in the palette. See 
     * @ref ColorPalette(int, int, int, int) for more details.
     * @throw std::invalid_argument Throws an std::invalid_argument exception 
     * if the total number of colors in the palette would be greater than 
     * ColorPalette::MAX_NUMBER_COLORS. In that case, the total number of
     * colors in the palette will be set to 0.
     * @throw std::invalid_argument Throws an std::invalid_argument exception 
     * if the any of the provided parameters is negative. In that case, the 
     * total number of colors in the palette will be set to 0.
     * 
     */
    void init(int nColorsFromBlue,int nColorsFromLightBlue, 
        int nColorsFromGreen, int nColorsFromYellow);
}; // end class ColorPalette

#endif /* COLORPALETTE_H */

