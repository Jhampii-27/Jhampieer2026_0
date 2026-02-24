#include <iostream>
using namespace std;

struct Empleado {
    string nombre;
    float sueldo;
};

int main() {
    Empleado e[2] = {{"Juan", 1200}, {"ana", 1800}};

    for (int i = 0; i < 2; i++) {
        cout << "Nombre: " << e[i].nombre  << " -Sueldo: " << e[i].sueldo << endl;
    }
    return 0;
}