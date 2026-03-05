// Ejercicio 2 - Herencia Simple: Empleado -> Gerente
#include <iostream>
#include <string>
using namespace std;

class Empleado {
public:
    string nombre;
    double sueldo;

    void mostrar() {
        cout << "Empleado: " << nombre << " - S/." << sueldo << endl;
    }
};

class Gerente : public Empleado {
public:
    double bono;

    void mostrarTotal() {
        cout << "Gerente: " << nombre
             << " - Total: S/." << (sueldo + bono) << endl;
    }
};

int main() {
    Gerente g;
    g.nombre = "Jhampieer";
    g.sueldo = 5000;
    g.bono   = 1500;
    g.mostrar();      // heredado
    g.mostrarTotal(); // propio
    return 0;
}
