#include <iostream>
using namespace std;

int obtenerMinimo(int arr[], int tam) {
    int minimo = arr[0];
    for (int i = 1; i < tam; i++) {
        if (arr[i] < minimo) {
            minimo = arr[i];
        }
    }
    return minimo;
}

int main() {
    int tam;
    
    cout << "Ingrese el tamanio del arreglo: ";
    cin >> tam;
    
    int arreglo[tam];
    
    cout << "Ingrese los elementos:" << endl;
    for (int i = 0; i < tam; i++) {
        cout << "Elemento " << (i + 1) << ": ";
        cin >> arreglo[i];
    }
    
    int minimo = obtenerMinimo(arreglo, tam);
    cout << "El valor minimo es: " << minimo << endl;
    
    return 0;
}
