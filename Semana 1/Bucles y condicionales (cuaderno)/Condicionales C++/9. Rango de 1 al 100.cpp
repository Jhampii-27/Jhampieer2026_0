#include <iostream>
using namespace std;

int main () {
    int num;
     
    cout << "Ingrese un numero: " << endl;
    cin >> num;

    if (num >= 1 && num <= 100) {
        cout << "Numero dentro de rango (1-100)";
    } else {
        cout << "Numero fuera de rango (1-100)";
    }
    return 0;
}