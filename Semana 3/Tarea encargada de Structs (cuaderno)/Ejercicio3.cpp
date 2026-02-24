#include <iostream>
using namespace std;

struct Persona {
    string nombre;
    int dni;
};

int main() {
    Persona p;
    p.nombre = "Jhampieer";
    p.dni = 60584488;

    cout << p.nombre << " -DNI: " << p.dni <<endl;
    return 0;
}
