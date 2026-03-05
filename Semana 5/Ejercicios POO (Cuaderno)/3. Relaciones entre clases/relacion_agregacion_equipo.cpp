// Ejercicio 4 - AGREGACION: Equipo <>── Jugador
//
//  ┌────────┐ ◇──── ┌─────────┐
//  │ Equipo │       │ Jugador │
//  └────────┘       └─────────┘
//
// Jugador puede existir sin Equipo (puede ser transferido).
//
#include <iostream>
#include <string>
using namespace std;

class Jugador {
public:
    string nombre;
    void mostrar() {
        cout << "Jugador: " << nombre << endl;
    }
};

class Equipo {
public:
    string nombre;
    Jugador* jugador; // agregacion: referencia externa

    void mostrar() {
        cout << "Equipo: " << nombre << endl;
        jugador->mostrar();
    }
};

int main() {
    Jugador j;   // existe independientemente
    j.nombre = "Messi";

    Equipo eq;
    eq.nombre  = "Inter Miami";
    eq.jugador = &j;

    eq.mostrar();

    // j sigue existiendo si eq se destruye
    return 0;
}
