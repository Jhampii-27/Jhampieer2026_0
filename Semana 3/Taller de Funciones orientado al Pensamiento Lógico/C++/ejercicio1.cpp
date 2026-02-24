#include <iostream>
using namespace std;

int obtenerMayor(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int main() {
    int num1, num2;
    
    cout << "Ingrese el primer numero: ";
    cin >> num1;
    
    cout << "Ingrese el segundo numero: ";
    cin >> num2;
    
    int mayor = obtenerMayor(num1, num2);
    cout << "El mayor es: " << mayor << endl;
    
    return 0;
}
