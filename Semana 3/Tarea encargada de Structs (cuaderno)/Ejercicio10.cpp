#include <iostream>
using namespace std;

struct Alumno {
    string nombre;
    float nota1;
    float nota2;
};

int main() {
    Alumno a = {"Carlos", 14, 16};
    float promedio = (a.nota1 + a.nota2) / 2;

    cout << "Alumno: " << a.nombre << endl;
    cout << "promedio: " << promedio << endl;
    return 0;
}