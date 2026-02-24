#include <iostream>
using namespace std;

struct Estudiante {
    string nombre;
    int edad;
};

int main() {
    Estudiante e;
    e.nombre = "Juan";
    e.edad = 20;

    cout << e.nombre << " " << e.edad;
    return 0;
}
