#include <iostream>
using namespace std;
int main () {
    int num1, num2;
    cout << "Ingrese el primer numero: " << endl;
    cin >> num1;
    cout << "Ingrese el segundo numero: " << endl;
    cin >> num2;

    if (num1 > num2) {
        cout << "El numero mayor es: " << num1 << endl;
    } else if (num1 < num2) {
        cout << "El numero mayor es: " << num2 << endl;
    } else {
        cout << "Son iguales";
    }
    return 0;
}