// Ejercicio 8 - ASOCIACION: Conductor ──── Vehiculo
//
//  ┌──────────┐           ┌──────────┐
//  │ Conductor│ ─────────>│ Vehiculo │
//  └──────────┘  conduce  └──────────┘
//
// Ambos existen independientemente.
// El Conductor referencia al Vehiculo que conduce.
//
#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
public:
    string placa;
};

class Conductor {
public:
    string    nombre;
    Vehiculo* vehiculo; // asociacion: referencia externa

    void conducir() {
        cout << nombre << " conduce el vehiculo "
             << vehiculo->placa << endl;
    }
};

int main() {
    Vehiculo v;
    v.placa = "ABC-123";

    Conductor c;
    c.nombre   = "Pedro";
    c.vehiculo = &v;

    c.conducir();
    return 0;
}
