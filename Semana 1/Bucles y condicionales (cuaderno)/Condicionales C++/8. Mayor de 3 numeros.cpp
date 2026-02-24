#include <iostream>
using namespace std;

int main () {
    int num1, num2, num3; 
    cout << "Ingrese el primer numero: " << endl;
    cin >> num1;

    cout << "Ingrese el segundo numero: " << endl;
    cin >> num2;

    cout << "Ingrese el tercer numero: " << endl;
    cin >> num3;

    if (num1 > num2 && num1 > num3) {
        cout << "El mayor es: " << num1 << endl;
    } else if (num1 < num2 && num2 > num3) {
        cout << "El mayor es: " << num2 << endl;
    } else {
        cout << "El mayor es: " << num3 << endl;
    }
    return 0;
}