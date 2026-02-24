#include <iostream>
using namespace std;

struct Compra {
    string producto;
    int cantidad;
    float precio;
};

int main() {
    Compra c = {"Cuaderno", 3, 5.5};
    float total = c.cantidad * c.precio;
    cout << "Total a pagar por " << c.producto <<  " es: " << total << endl;

    return 0;
}
