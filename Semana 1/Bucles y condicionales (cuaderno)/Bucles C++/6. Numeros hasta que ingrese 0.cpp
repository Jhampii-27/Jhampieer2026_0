#include <iostream>
using namespace std;
int main () {
    int num, i = 0;

    cout << "Ingrese un numero: " << endl;
    cin >> num;

    while (num != 0) {
        cout << "Ingrese un numero: " << endl;
        cin >> num;
        i += 1;
    }
    cout << "Se ingresaron: " << i+1 << " numeros.";
    return 0;
}