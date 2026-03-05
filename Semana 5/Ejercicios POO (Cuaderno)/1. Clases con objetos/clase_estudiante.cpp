// Ejercicio 4 - Clase Estudiante
#include <iostream>
#include <string>
using namespace std;

class Estudiante {
public:
    string nombre;
    float nota;

    void resultado() {
        if (nota >= 11)
            cout << nombre << " esta aprobado" << endl;
        else
            cout << nombre << " esta desaprobado" << endl;
    }
};

int main() {
    Estudiante e;
    e.nombre = "Jhampieer";
    e.nota = 14;
    e.resultado();
    return 0;
}
