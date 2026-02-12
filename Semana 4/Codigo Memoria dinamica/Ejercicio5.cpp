#include <iostream>
#include <vector>
using namespace std;

int main() {
    int f, c;

    // 1) Pedir filas y columnas
    cout << "Ingrese numero de filas: ";
    cin >> f;

    cout << "Ingrese numero de columnas: ";
    cin >> c;

    if (f <= 0 || c <= 0) {
        cout << "Filas y columnas deben ser mayores que 0." << endl;
        return 1;
    }

    // 2) Crear matriz dinámica f x c
    vector<vector<int>> matriz(f, vector<int>(c));

    // 3) Llenar matriz
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            cout << "Ingrese valor [" << i << "][" << j << "]: ";
            cin >> matriz[i][j];
        }
    }

    // 4) Imprimir matriz en forma de tabla
    cout << "\nMatriz:\n";
    for (int i = 0; i < f; i++) {
        for (int j = 0; j < c; j++) {
            cout << matriz[i][j] << "\t";
        }
        cout << endl;
    }

    // Reto extra: suma de cada fila
    cout << "\nSuma de cada fila:\n";
    for (int i = 0; i < f; i++) {
        int sumaFila = 0;
        for (int j = 0; j < c; j++) {
            sumaFila += matriz[i][j];
        }
        cout << "Fila " << i << ": " << sumaFila << endl;
    }

    return 0;
}
