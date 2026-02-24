#include <iostream>
using namespace std;
int main () {
    double metros;
    double centimetros;

    cout << "Ingrese la distancia en metros: " << endl;
    cin >> metros;

    centimetros = metros * 100;

    cout << "La distancia en centimetros de " << metros << " metros es " << centimetros << " centimetros: " << endl;
    
    return 0;
}