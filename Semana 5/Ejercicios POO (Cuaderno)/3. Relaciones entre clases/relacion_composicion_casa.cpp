// Ejercicio 1 - COMPOSICION: Casa <>── Habitacion
//
//  ┌─────────┐ ◆──── ┌─────────────┐
//  │  Casa   │       │ Habitacion  │
//  └─────────┘       └─────────────┘
//
// La Habitacion solo existe dentro de Casa.
// Si Casa se destruye, Habitacion tambien.
//
#include <iostream>
#include <string>
using namespace std;

class Habitacion {
public:
    string tipo;
    void mostrar() {
        cout << "Habitacion: " << tipo << endl;
    }
};

class Casa {
public:
    Habitacion hab; // composicion: por valor, misma vida
    string direccion;

    void mostrar() {
        cout << "Casa en: " << direccion << endl;
        hab.mostrar();
    }
};

int main() {
    Casa c;
    c.direccion  = "Av. Lima 123";
    c.hab.tipo   = "Dormitorio";
    c.mostrar();
    return 0;
}
