#include <iostream>
using namespace std;

double Ejercicio10(double base, int exponente = 2) {
    double resultado = 1;
    for (int i = 0; i < exponente; i++) {
        resultado *= base;
    }
    return resultado;
}

int main() {
    cout << "4 al cuadrado = " << Ejercicio10(4) << endl;
    cout << "2 al cubo = " << Ejercicio10(2, 3) << endl;
    return 0;
}
