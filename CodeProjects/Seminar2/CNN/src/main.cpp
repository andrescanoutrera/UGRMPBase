#include <iostream>
#include "cnn.h"
/**
 * @brief Programa que crea instancias CNN, lee un incremento 
 * que se acumula a los componentes numéricos de todos los objetos 
 * creados.
 *
 * @param argc
 * @param argv
 * @return int 0 siempre
 */
using namespace std;
int main(int argc, char *argv[]) {
    CNN uno;
    CNN dos('B');
    CNN tres('C', 100);
    int incremento;

    cin >> incremento;
    cout << incremento << endl;
               // se aplica el incremento al componente numérico de cada uno de los objetos
    uno.setNN(incremento);
    dos.setNN(incremento);
    tres.setNN(incremento);
    cout << uno.to_string() << endl;
    cout << dos.to_string() << endl;
    cout << tres.to_string() << endl;

    return 0;
}
