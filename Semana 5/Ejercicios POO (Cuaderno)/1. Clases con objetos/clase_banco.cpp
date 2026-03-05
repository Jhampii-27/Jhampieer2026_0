// Ejercicio 5 - Clase CuentaBancaria
#include <iostream>
using namespace std;

class CuentaBancaria {
public:
    double saldo;

    void depositar(double monto) {
        saldo += monto;
        cout << "Saldo actual: " << saldo << endl;
    }
};

int main() {
    CuentaBancaria c;
    c.saldo = 0;
    c.depositar(500);
    return 0;
}
