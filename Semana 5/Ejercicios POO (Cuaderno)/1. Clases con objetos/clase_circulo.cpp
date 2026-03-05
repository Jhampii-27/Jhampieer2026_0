// Ejercicio 6 - Clase Circulo
#include <iostream>
using namespace std;

class Circulo {
public:
    float radio;

    float area() {
        return 3.1416 * radio * radio;
    }
};

int main() {
    Circulo ci;
    ci.radio = 4;
    cout << "Area del circulo: " << ci.area() << endl;
    return 0;
}
