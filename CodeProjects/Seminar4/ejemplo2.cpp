#include<iostream>
using namespace std;

int main(){
   int *array=new int[5];
   cout << array[10] << endl; // Lectura de memoria fuera
}                             // de limites validos

