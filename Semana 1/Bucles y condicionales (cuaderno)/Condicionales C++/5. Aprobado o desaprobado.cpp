#include <iostream>
using namespace std;

int main () {
    int nota;

    cout << "Ingrese una nota (0-20)" << endl;
    cin >> nota;

    if (nota >= 0 && nota <= 11) {
        cout << "Desaprobado";
    } else if (nota > 11 && nota <= 20) {
        cout << "Aprobado";
    } else {
        cout << "Nota fuera de rango (0-20)";
    }
    return 0;
}