/*Calcula el promedio de 3 números.*/

#include <iostream>
using namespace std;
int main () {
    int num1 = 2;
    int num2 = 8;
    int num3 = 4;
    double promedio;
    double suma;

    suma = num1 + num2 + num3;

    promedio = suma / 3;

    cout << "El promedio es: " << promedio << endl;
    return 0;

}