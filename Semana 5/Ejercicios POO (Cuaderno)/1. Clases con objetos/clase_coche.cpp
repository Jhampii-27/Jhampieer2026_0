// Ejercicio 3 - Clase Coche
#include <iostream>
#include <string>
using namespace std;

class Coche {
public:
    string marca;
    int anio;

    void mostrar() {
        cout << "Coche: " << marca << " (" << anio << ")" << endl;
    }
};

int main() {
    Coche c;
    c.marca = "Toyota";
    c.anio = 2022;
    c.mostrar();
    return 0;
}
