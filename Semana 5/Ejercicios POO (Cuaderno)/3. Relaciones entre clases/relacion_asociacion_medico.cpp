// Ejercicio 7 - ASOCIACION: Medico ──── Paciente
//
//  ┌────────┐           ┌──────────┐
//  │ Medico │ ─────────>│ Paciente │
//  └────────┘  atiende  └──────────┘
//
// Medico y Paciente son independientes.
// El Medico guarda una referencia al Paciente (no lo posee).
//
#include <iostream>
#include <string>
using namespace std;

class Paciente {
public:
    string nombre;
};

class Medico {
public:
    string   nombre;
    Paciente* paciente; // asociacion: referencia, no posesion

    void atender() {
        cout << "Dr. " << nombre
             << " atiende a " << paciente->nombre << endl;
    }
};

int main() {
    Paciente p;
    p.nombre = "Juan";

    Medico m;
    m.nombre   = "Rodriguez";
    m.paciente = &p;

    m.atender();
    return 0;
}
