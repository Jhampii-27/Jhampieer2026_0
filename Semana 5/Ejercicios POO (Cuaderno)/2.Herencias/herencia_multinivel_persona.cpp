// Ejercicio 6 - Herencia Multinivel: Ser -> Persona -> Estudiante
#include <iostream>
#include <string>
using namespace std;

class Ser {
public:
    string nombre;
    void existir() {
        cout << nombre << " existe" << endl;
    }
};

class Persona : public Ser {
public:
    int edad;
    void presentarse() {
        cout << nombre << " tiene " << edad << " anios" << endl;
    }
};

class Estudiante : public Persona {
public:
    string carrera;
    void estudiar() {
        cout << nombre << " estudia " << carrera << endl;
    }
};

int main() {
    Estudiante est;
    est.nombre  = "Jhampieer";
    est.edad    = 17;
    est.carrera = "Ing. Sistemas";
    est.existir();     // de Ser
    est.presentarse(); // de Persona
    est.estudiar();    // propio
    return 0;
}
