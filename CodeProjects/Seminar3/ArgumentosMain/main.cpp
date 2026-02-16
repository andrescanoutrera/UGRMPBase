/** 
 * @file main.cpp
 * @author lcv, acid
 * @update 2/10/25, 11:15
 */

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;
// número de argumentos esperados:  0, 2 o 4
// {-n <entero>} {-s <cadena>}

int main(int nargs , char ** args) {
    string ss;
		       // args[0] contiene el nombre del ejecutable
    for (int i=1; i<nargs; ) { // Ojo! No hay i++ automático, se incrementa selectivamente (a)
        ss = args[i];
        i = i+1;  // (a)
        if (ss == "-n") {
            if (i<nargs)  // si quedan argumentos
                cout << "Este es un entero "<<atoi(args[i++])<<endl; // (a)
            else
                cerr << "Error en los argumentos"<<endl;
        } 
        else if (ss == "-s") {
            if (i<nargs)
                cout << "Esta es la cadena "<<args[i++]<<endl; // (a)
            else
                cerr << "Error en los argumentos"<<endl;
        }
        else
            cerr << "Error en los argumentos"<<endl;
    }
    return 0;
}

