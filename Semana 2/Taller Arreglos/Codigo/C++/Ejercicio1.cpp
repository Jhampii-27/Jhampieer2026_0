#include <iostream>
using namespace std;

int main() {
    float gastodia[7];
    float gastototal = 0;

    for (int i = 0; i < 7; i++) {
        do {
            cout << "Ingrese un numero (positivo): ";
            cin >> gastodia[i];
            
            if (gastodia[i] < 0) {
                cout << "Error: El gasto no puede ser negativo." << endl;
            }
        } while (gastodia[i] < 0); 
    }
    cout << "[";
    for (int i = 0; i < 7; i++) {
        cout << gastodia[i];
        if (i < 6) {
            cout << " , ";
        }
    }
    cout << "]" << endl;

    for (int i = 0; i < 7; i++) {
        gastototal = gastototal + gastodia[i];
    }
    cout << "Gasto Total: " << gastototal << endl;

    float promedio = gastototal / 7;
    cout << "Promedio: " << promedio << endl;

    int cantmayorprom = 0;
    for (int i = 0; i < 7; i++) {
        if (gastodia[i] > promedio) {
            cantmayorprom++;
        }
    }
    cout << "Dias con mayor gasto al promedio: " << cantmayorprom << endl;

    return 0;
}