// Ejercicio 3 - AGREGACION: Universidad <>── Departamento
//
//  ┌──────────────┐ ◇──── ┌───────────────┐
//  │ Universidad  │       │  Departamento │
//  └──────────────┘       └───────────────┘
//
// Departamento existe de forma independiente.
// Universidad solo guarda un puntero (no lo posee).
//
#include <iostream>
#include <string>
using namespace std;

class Departamento {
public:
    string nombre;
    void mostrar() {
        cout << "Departamento: " << nombre << endl;
    }
};

class Universidad {
public:
    string nombre;
    Departamento* dep; // agregacion: puntero externo

    void mostrar() {
        cout << "Universidad: " << nombre << endl;
        dep->mostrar();
    }
};

int main() {
    Departamento d;   // existe independientemente
    d.nombre = "Sistemas";

    Universidad u;
    u.nombre = "UPC";
    u.dep    = &d;    // solo referencia

    u.mostrar();

    // d sigue existiendo aunque u desaparezca
    return 0;
}
