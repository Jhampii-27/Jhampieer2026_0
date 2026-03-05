#include <iostream>
#include <stdexcept>
using namespace std;

class Cuenta {
public:
    double saldo;
    Cuenta(double s) {
        if (s < 0) throw invalid_argument("El saldo inicial no puede ser negativo");
        saldo = s;
    }
};

int main() {
    try {
        Cuenta c(-100.0);
    } catch (invalid_argument& e) {
        cout << "Error al crear cuenta: " << e.what() << endl;
    }
    return 0;
}
