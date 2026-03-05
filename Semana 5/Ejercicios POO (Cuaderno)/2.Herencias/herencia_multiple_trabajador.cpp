// Ejercicio 3 - Herencia Multiple: Persona + Trabajador -> EmpleadoActivo
#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string nombre;
    void presentarse() {
        cout << "Soy: " << nombre << endl;
    }
};

class Trabajador {
public:
    string empresa;
    void trabajar() {
        cout << "Trabajo en: " << empresa << endl;
    }
};

class EmpleadoActivo : public Persona, public Trabajador {};

int main() {
    EmpleadoActivo e;
    e.nombre  = "Sofia";
    e.empresa = "TechCorp";
    e.presentarse(); // de Persona
    e.trabajar();    // de Trabajador
    return 0;
}
