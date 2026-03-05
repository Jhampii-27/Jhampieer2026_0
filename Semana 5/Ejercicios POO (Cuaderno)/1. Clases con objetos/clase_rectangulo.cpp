// Ejercicio 2 - Clase Rectangulo
#include <iostream>
using namespace std;

class Rectangulo {
public:
    float base;
    float altura;

    float area() {
        return base * altura;
    }
};

int main() {
    Rectangulo r;
    r.base = 5;
    r.altura = 3;
    cout << "Area: " << r.area() << endl;
    return 0;
}
