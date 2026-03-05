// Ejercicio 8 - Clase Empleado
#include <iostream>
#include <string>
using namespace std;

class Empleado {
public:
    string nombre;
    double sueldo;

    void mostrarSueldo() {
        cout << nombre << " gana: S/." << sueldo << endl;
    }
};

int main() {
    Empleado emp;
    emp.nombre = "Maria";
    emp.sueldo = 2500;
    emp.mostrarSueldo();
    return 0;
}
