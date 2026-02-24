#include <iostream>
using namespace std;

struct Producto {
    string nombre;
    float precio;
};

int main() {
    Producto p;
    p.nombre = "Mouse";
    p.precio = 35.5;

    cout << p.nombre << " cuesta " << p.precio << " soles.";
    return 0;

}
