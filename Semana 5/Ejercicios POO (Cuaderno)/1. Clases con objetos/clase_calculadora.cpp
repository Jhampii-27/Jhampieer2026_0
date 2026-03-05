// Ejercicio 9 - Clase Calculadora
#include <iostream>
using namespace std;

class Calculadora {
public:
    double sumar(double a, double b) {
        return a + b;
    }

    double restar(double a, double b) {
        return a - b;
    }
};

int main() {
    Calculadora calc;
    cout << "Suma: "  << calc.sumar(10, 5)  << endl;
    cout << "Resta: " << calc.restar(10, 5) << endl;
    return 0;
}
