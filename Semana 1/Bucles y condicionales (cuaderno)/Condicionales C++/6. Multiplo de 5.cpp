#include <iostream>
using namespace std;

int main () {
    int num;

    cout << "Ingrese un numero: " << endl;
    cin >> num;

    if (num % 5 == 0) {
        cout << "Es multiplo de 5";
    } else {
        cout << "No es multiplo de 5";
    }
    return 0;
}