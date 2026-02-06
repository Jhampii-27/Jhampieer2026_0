#include <iostream>
using namespace std;

int calcularFactorial(int n) {
    int factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    return factorial;
}

int main() {
    int n;
    
    cout << "Ingrese un numero para calcular su factorial: ";
    cin >> n;
    
    int resultado = calcularFactorial(n);
    cout << "El factorial de " << n << " es: " << resultado << endl;
    
    return 0;
}
