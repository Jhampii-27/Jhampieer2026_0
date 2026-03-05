// Ejercicio 9 - Polimorfismo: Figura -> Circulo / Rectangulo
#include <iostream>
using namespace std;

class Figura {
public:
    virtual float area() = 0; // metodo virtual puro
};

class Circulo : public Figura {
public:
    float radio;
    float area() override {
        return 3.1416 * radio * radio;
    }
};

class Rectangulo : public Figura {
public:
    float base, altura;
    float area() override {
        return base * altura;
    }
};

int main() {
    Circulo c;
    c.radio = 5;

    Rectangulo r;
    r.base   = 4;
    r.altura = 6;

    Figura* f1 = &c;
    Figura* f2 = &r;

    cout << "Area circulo   : " << f1->area() << endl;
    cout << "Area rectangulo: " << f2->area() << endl;
    return 0;
}
