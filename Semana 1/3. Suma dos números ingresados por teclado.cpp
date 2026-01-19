/*Suma dos números ingresados por teclado.*/
#include <iostream>
using namespace std;

int main () {
    int num1;
    int num2;
    int suma;

    cout << "Ingrese el primer numero: " << endl;
    cin >> num1;

    cout << "Ingrese el segundo numero: " << endl;
    cin >> num2;

    suma = num1 + num2;

    cout << "La suma de "  << num1 << " mas " << num2 << " da como resultado: " << suma;
    return 0;
}