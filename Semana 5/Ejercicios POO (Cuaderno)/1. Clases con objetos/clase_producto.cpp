// Ejercicio 10 - Clase Producto
#include <iostream>
#include <string>
using namespace std;

class Producto {
public:
    string nombre;
    double precio;
    int    stock;

    void mostrar() {
        cout << nombre << " - S/." << precio
             << " - Stock: " << stock << endl;
    }
};

int main() {
    Producto p;
    p.nombre = "Laptop";
    p.precio = 2500;
    p.stock  = 10;
    p.mostrar();
    return 0;
}
