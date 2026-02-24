#include <iostream>
using namespace std;
int main () {
    int num;

    cout << "Ingrese el numero: " << endl;
    cin >> num;

    if (num % 2 == 0) {
        cout << "Par";
    } else {
        cout << "Impar";
    }
    return 0;
}