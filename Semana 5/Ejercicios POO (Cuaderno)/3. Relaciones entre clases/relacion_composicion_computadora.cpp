// Ejercicio 2 - COMPOSICION: Computadora <>── CPU
//
//  ┌──────────────┐ ◆──── ┌───────┐
//  │ Computadora  │       │  CPU  │
//  └──────────────┘       └───────┘
//
// CPU no puede existir fuera de la Computadora.
//
#include <iostream>
#include <string>
using namespace std;

class CPU {
public:
    string modelo;
    void procesar() {
        cout << "CPU " << modelo << " procesando..." << endl;
    }
};

class Computadora {
public:
    CPU cpu; // composicion: CPU vive dentro de Computadora
    string marca;

    void encender() {
        cout << "Computadora " << marca << " encendida" << endl;
        cpu.procesar();
    }
};

int main() {
    Computadora pc;
    pc.marca     = "HP";
    pc.cpu.modelo = "Intel i5";
    pc.encender();
    return 0;
}
