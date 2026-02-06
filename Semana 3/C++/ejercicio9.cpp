#include <iostream>
using namespace std;

bool buscarValor(int arr[], int tam, int valor) {
    for (int i = 0; i < tam; i++) {
        if (arr[i] == valor) {
            return true;
        }
    }
    return false;
}

int main() {
    int tam, valorBuscar;
    
    cout << "Ingrese el tamanio del arreglo: ";
    cin >> tam;
    
    int arreglo[tam];
    
    cout << "Ingrese los elementos:" << endl;
    for (int i = 0; i < tam; i++) {
        cout << "Elemento " << (i + 1) << ": ";
        cin >> arreglo[i];
    }
    
    cout << "Ingrese el valor a buscar: ";
    cin >> valorBuscar;
    
    if (buscarValor(arreglo, tam, valorBuscar)) {
        cout << "El valor SI existe en el arreglo" << endl;
    } else {
        cout << "El valor NO existe en el arreglo" << endl;
    }
    
    return 0;
}
