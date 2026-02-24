#include <iostream>
using namespace std;

// Función que crea y retorna un arreglo dinámico
int* crearArreglo(int n) {
    int* arreglo = new int[n];  // reservar memoria

    // Llenar con números pares: 2, 4, 6, ...
    for (int i = 0; i < n; i++) {
        arreglo[i] = 2 * (i + 1);
    }

    return arreglo;  // retornar el puntero
}

int main() {
    int n;

    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    if (n <= 0) {
        cout << "El tamaño debe ser mayor que 0." << endl;
        return 1;
    }

    // Llamar a la función
    int* arreglo = crearArreglo(n);

    // Imprimir elementos
    cout << "\nElementos del arreglo:\n";
    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
    }

    // Liberar memoria
    delete[] arreglo;

    return 0;
}
