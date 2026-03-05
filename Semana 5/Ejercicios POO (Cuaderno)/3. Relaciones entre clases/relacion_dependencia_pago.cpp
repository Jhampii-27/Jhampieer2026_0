// Ejercicio 6 - DEPENDENCIA: ProcesadorPago - - -> Carrito
//
//  ┌──────────────────┐  «uses»  ┌─────────┐
//  │  ProcesadorPago  │- - - - ->│ Carrito │
//  └──────────────────┘          └─────────┘
//
// ProcesadorPago usa Carrito solo durante el cobro.
// No mantiene relacion permanente con el.
//
#include <iostream>
using namespace std;

class Carrito {
public:
    double total;
};

class ProcesadorPago {
public:
    // Dependencia: Carrito llega como parametro
    void cobrar(Carrito carrito) {
        cout << "Cobrado: S/." << carrito.total << endl;
    }
};

int main() {
    ProcesadorPago pp;
    Carrito c;
    c.total = 350.0;

    pp.cobrar(c); // uso temporal
    return 0;
}
