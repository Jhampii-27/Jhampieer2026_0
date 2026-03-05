// Ejercicio 10 - HERENCIA (relacion is-a): Vehiculo -> Moto
//
//       ┌──────────┐
//       │ Vehiculo │
//       └────┬─────┘
//            │ «extends»
//       ┌────┴─────┐
//       │   Moto   │
//       └──────────┘
//
// Moto ES-UN Vehiculo (relacion is-a).
//
#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
public:
    string marca;
    void desplazar() {
        cout << marca << " se desplaza" << endl;
    }
};

class Moto : public Vehiculo {
public:
    int cilindrada;
    void mostrar() {
        cout << marca << " - " << cilindrada << "cc" << endl;
    }
};

int main() {
    Moto m;
    m.marca      = "Honda";
    m.cilindrada = 150;
    m.desplazar(); // heredado de Vehiculo
    m.mostrar();   // propio de Moto
    return 0;
}
