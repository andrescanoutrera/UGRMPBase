#include <iostream>
#include <string>

#ifndef CNN_H
#define CNN_H
/**
 * Class CNN, par  carácter - valor numérico
 * con un mínimo de métodos de consulta y modificación.
 */

class CNN
{
private:
   char _c;
   int _nn;

public:
   /**
    *  Constructor con valores por defecto para cada componente del par
    */
   CNN(char c = 'A', int nn = 5);
   /**
    * @brief Compone en un string el contenido del objeto de referencia.
    * Método de consulta
    * @return std::string resultante con los dos componentes del par separados por espacio.
    */
   std::string to_string() const;
   /**
    * @brief Consulta el componente caracter del par
    * Método de consulta
    * @return char valor devuelto
    */
   char getC() const;
   /**
    * @brief Consulta el componente entero del par
    * Método de consulta
    * @return int valor devuelto
    */
   int getNN() const;
   /**
    * @brief Establece el nuevo valor para el componente entero del par
    * Método Modificador
    * @param valor
    */
   void setNN(int valor);
};
#endif
