// Ejercicio 4 - Herencia Multiple: Maquina + Programable -> Robot
#include <iostream>
#include <string>
using namespace std;

class Maquina {
public:
    void encender() {
        cout << "Motor encendido" << endl;
    }
};

class Programable {
public:
    void ejecutar(string tarea) {
        cout << "Ejecutando: " << tarea << endl;
    }
};

class Robot : public Maquina, public Programable {
public:
    string nombre;
};

int main() {
    Robot r;
    r.nombre = "R2D2";
    r.encender();            // de Maquina
    r.ejecutar("Soldar");    // de Programable
    return 0;
}
