#include <iostream>
using namespace std;
int main () {
    int lado;
    int perimetro;


    cout <<  "Ingrese el lado del cuadrado: " << endl;
    cin >> lado;

    perimetro = lado * 4;

    cout << "El perimetro del cuadrado es: " << perimetro << endl;
    return 0;
}