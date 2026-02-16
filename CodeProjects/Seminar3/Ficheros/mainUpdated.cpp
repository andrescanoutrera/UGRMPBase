
#include <iostream>  // Input/output streams
#include <string>
#include <fstream>   // Filestreams
using namespace std;

int main() {
    int i; double d; string s;
    ifstream entrada;  // Input filestream
    ofstream salida;   // Output filestream
    entrada.open("datos.txt");
    if (entrada) {
        entrada >> i;
        entrada >> d;
        entrada >> s;
        if (entrada){
            cout << "Has leído esto: "<<i<<" "<<d<<" "<<s<< endl;
            salida.open("salida.txt");
            if (salida) {
                salida << i*d << endl;
                salida << s+" Fernándo"<<endl;
                salida.close();
            } else
                cerr << "Error abriendo fichero salida.txt"<<endl;
        }
        else
            cerr << "Error leyendo datos desde datos.txt"<<endl;
        entrada.close();
    }
    else
        cerr<<"Error abriendo fichero datos.txt" << endl;
    return 0;
}

