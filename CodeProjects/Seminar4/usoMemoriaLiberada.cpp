#include <cstdio>
#include <cstdlib> 
#include <iostream>

using namespace std;

int main(void){
    // Se reserva espacio para p
    char *p = new char;
    
    // Se da valor
    *p = 'a'; 

    // Se copia el caracter en c
    char c = *p; 

    // Se muestra
    cout << "Caracter c: " << c; 

    // Se libera el espacio
    delete p;
    
    // Se copia el contenido de p (YA LIBERADO) en c
    c = *p;
    return 0;
}
