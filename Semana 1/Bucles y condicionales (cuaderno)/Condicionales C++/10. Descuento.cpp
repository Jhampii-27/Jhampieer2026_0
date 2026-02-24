#include <iostream>
using namespace std;

int main () {
    int pre, des;

    cout << "Ingrese el precio del producto:" << endl;
    cin >> pre;

    if (pre >= 100) {
        des = pre - pre * 0.1;
        cout << "El precio despues del 10 por ciento de descuento es: " << des << endl;
    } else if (pre > 0 && pre < 100) {
        cout << "No se aplica el descuento." << endl;
    } else {
        cout << "El precio no puede ser menor o igual que cero.";
    }
    return 0;
}