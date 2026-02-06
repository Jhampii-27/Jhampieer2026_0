#include <iostream>
using namespace std;

bool estaOrdenadoAscendente(int arr[], int tam) {
    for (int i = 0; i < tam - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            return false;
        }
    }
    return true;
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
    
    if (estaOrdenadoAscendente(arreglo, tam)) {
        cout << "El arreglo SI esta ordenado de forma ascendente" << endl;
    } else {
        cout << "El arreglo NO esta ordenado de forma ascendente" << endl;
    }
    
    return 0;
}
