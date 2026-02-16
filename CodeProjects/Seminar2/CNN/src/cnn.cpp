#include "cnn.h"

using namespace std;

CNN::CNN(char c, int n) {}

std::string CNN::to_string() const {
    std::string s = std::string(1, _c);
    s += " " + std::to_string(_nn);
    return s;
}
char CNN::getC() const {
    return _c;
}

int CNN::getNN() const {
    return _nn;
}
void CNN::setNN(int valor){
    _nn = valor;
}
