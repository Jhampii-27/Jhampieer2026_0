#include <iostream>
using namespace std;
int main () {
    double metros;
    double centimetros;

    cout << "Ingrese la distancia en metros: " << endl;
    cin >> metros;

    centimetros = metros * 1000;

    cout << "la distancia en centimetros es: " << centimetros << endl;
}