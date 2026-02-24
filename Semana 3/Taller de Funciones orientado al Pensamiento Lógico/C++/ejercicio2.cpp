#include <iostream>
using namespace std;

bool esPar(int numero) {
    if (numero % 2 == 0) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int numero;
    
    cout << "Ingrese un numero: ";
    cin >> numero;
    
    if (esPar(numero)) {
        cout << "El numero es PAR" << endl;
    } else {
        cout << "El numero es IMPAR" << endl;
    }
    
    return 0;
}
