#include <iostream>
using namespace std;

int main () {
    int año;

    cout << "Ingrese el anio:" << endl;
    cin >> año;

    if ((año % 4 == 0 && año % 100 != 0) || (año % 400 == 0)) {
        cout << "Anio bisiesto.";
    } else {
        cout << "Anio No bisiesto";
    }
    return 0;
}