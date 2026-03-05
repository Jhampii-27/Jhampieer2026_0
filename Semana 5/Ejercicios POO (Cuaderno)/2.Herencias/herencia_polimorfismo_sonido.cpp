// Ejercicio 10 - Polimorfismo: Instrumento -> Guitarra / Flauta
#include <iostream>
using namespace std;

class Instrumento {
public:
    virtual void tocar() = 0; // virtual puro
};

class Guitarra : public Instrumento {
public:
    void tocar() override {
        cout << "Guitarra: Strum strum!" << endl;
    }
};

class Flauta : public Instrumento {
public:
    void tocar() override {
        cout << "Flauta: Ti ri ri!" << endl;
    }
};

int main() {
    Guitarra g;
    Flauta   f;

    Instrumento* i1 = &g;
    Instrumento* i2 = &f;

    i1->tocar(); // llama a Guitarra::tocar
    i2->tocar(); // llama a Flauta::tocar
    return 0;
}
