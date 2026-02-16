
#include <iostream>
#include <string>
/**
El programa tiene 3 variables específicas: una cadena, s, un real, f, y un entero, d, 
con valores por defecto respectivamente "DEFAULT", 0.5, 5 .
Se pide mostrar todos los argumentos con el que se ejecuta el programa, 
y los valores que tienen las variables especiales se pueden dar valores como parámetros en orden,
la cadena, el real y el entero

**/
using namespace std;

int main(int nargs, char ** args)  {
    int i, d=5;
    float f=0.5;
    
    string s="DEFAULT";

    for (int i=1; i<nargs; i++)
        cout << "Parámetro ("<<i<<") = "<< args[i]<<endl;
   
    if (args >1)
    	s = args[1];
    if (args >2)
    	f = atof(args[2]);
    if (args>3)
    	d = atoi(args[3]);
    	
     cout << "cadena " << s << " real" << f <<" entero " << d << endl;

    return 0;
}
