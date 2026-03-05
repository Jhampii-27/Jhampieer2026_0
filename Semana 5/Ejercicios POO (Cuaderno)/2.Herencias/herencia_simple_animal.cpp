// Ejercicio 1 - Herencia Simple: Animal -> Perro
#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    string nombre;
    void comer() {
        cout << nombre << " esta comiendo" << endl;
    }
};

class Perro : public Animal {
public:
    void ladrar() {
        cout << nombre << " dice: Guau!" << endl;
    }
};

int main() {
    Perro p;
    p.nombre = "Rex";
    p.comer();   // metodo heredado
    p.ladrar();  // metodo propio
    return 0;
}
