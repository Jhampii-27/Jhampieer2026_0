#include <iostream>
using namespace std;

bool validarOpcionMenu(int opcion, int minimo, int maximo) {
    if (opcion >= minimo && opcion <= maximo) {
        return true;
    } else {
        return false;
    }
}

int main() {
    int opcion, min, max;
    
    cout << "Ingrese el rango minimo: ";
    cin >> min;
    
    cout << "Ingrese el rango maximo: ";
    cin >> max;
    
    cout << "Ingrese la opcion a validar: ";
    cin >> opcion;
    
    if (validarOpcionMenu(opcion, min, max)) {
        cout << "La opcion es VALIDA" << endl;
    } else {
        cout << "La opcion es INVALIDA" << endl;
    }
    
    return 0;
}
