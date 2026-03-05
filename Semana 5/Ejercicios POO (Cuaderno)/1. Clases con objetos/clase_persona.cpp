// Ejercicio 1 - Clase Persona
#include <iostream>
#include <string>
using namespace std;

class Persona {
public:
    string nombre;
    int edad;

    void mostrar() {
        cout << "Nombre: " << nombre << ", Edad: " << edad << endl;
    }
};

int main() {
    Persona p;
    p.nombre = "Ana";
    p.edad = 25;
    p.mostrar();
    return 0;
}
