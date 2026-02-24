#include <iostream>
using namespace std;

int Ejercicio5(int n) {
    int resultado = 1;
    for (int i = 1; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

int main() {
    cout << "Factorial de 5 = " << Ejercicio5(5) << endl;
    return 0;
}
