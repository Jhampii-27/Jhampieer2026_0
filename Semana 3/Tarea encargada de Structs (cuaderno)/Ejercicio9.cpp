#include <iostream>
using namespace std;

struct Empleado {
    string nombre;
    float sueldo;
};

int main() {
    Empleado e[3] = {{"Juan", 1200}, {"Ana", 1800}, {"Luis", 1600}};
    int cont = 0;

    for(int i = 0; i < 3 ; i++) {
        if(e[i].sueldo > 1500) {
            cont ++;
        }
    }
    cout << "Empleados con sueldo mayor a 1500: " << cont << endl;
    return 0;
}