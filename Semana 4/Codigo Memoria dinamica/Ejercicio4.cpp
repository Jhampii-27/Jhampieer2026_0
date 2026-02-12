#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Ingrese el tamaño del arreglo: ";
    cin >> n;

    if (n <= 0) {
        cout << "El tamaño debe ser mayor que 0." << endl;
        return 1;
    }

    // Crear vector
    vector<int> arreglo(n);

    // Llenar vector
    for (int i = 0; i < n; i++) {
        cout << "Ingrese el valor " << i + 1 << ": ";
        cin >> arreglo[i];
    }

    // Mostrar elementos
    cout << "\nElementos del arreglo:\n";
    int suma = 0;

    for (int i = 0; i < n; i++) {
        cout << arreglo[i] << " ";
        suma += arreglo[i];
    }

    double promedio = (double)suma / n;
    cout << "\nPromedio: " << promedio << endl;

    return 0;
}
