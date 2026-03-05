// Ejercicio 5 - Herencia Multinivel: Vehiculo -> Motor -> Auto
#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
public:
    string marca;
    void mover() {
        cout << marca << " se mueve" << endl;
    }
};

class VehiculoMotorizado : public Vehiculo {
public:
    void encenderMotor() {
        cout << "Motor encendido" << endl;
    }
};

class Auto : public VehiculoMotorizado {
public:
    int puertas;
    void mostrar() {
        cout << marca << " con " << puertas << " puertas" << endl;
    }
};

int main() {
    Auto a;
    a.marca   = "Toyota";
    a.puertas = 4;
    a.mover();         // de Vehiculo
    a.encenderMotor(); // de VehiculoMotorizado
    a.mostrar();       // propio
    return 0;
}
