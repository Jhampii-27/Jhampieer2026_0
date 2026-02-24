#include <iostream>
using namespace std;

int main() {
    int num1;
    int num2;

    cout << "Ingrese el primer numero: ";
    cin >> num1;

    cout << "Ingrese el segundo numero: ";
    cin >> num2;

    if (num1 > num2) {
        cout << "El numero " << num1 << " es mayor que " << num2;
    } else if (num1 < num2) {
        cout << "El numero " << num1 << " es menor que " << num2;
    } else {
        cout << "Ambos numeros son iguales";
    }

    return 0;
}
