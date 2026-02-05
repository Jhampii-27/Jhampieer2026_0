#include <iostream>

using namespace std;

int main() {
    double a = 9.0; // Lado 1
    double c = 6.0; // Lado 2
    double b = 8.0; // Base
    double h = 6.0; // Altura

    double A = (b * h) / 2.0;
    double P = a + b + c;

    cout << "--- EJERCICIO 5: TRIANGULO ---" << endl;
    cout << "Area (A): " << A << endl;
    cout << "Perimetro (P): " << P << endl;

    return 0;
}