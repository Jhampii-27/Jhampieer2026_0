#include <iostream>
using namespace std;

int obtenerMaximo(int arr[], int tam) {
    int maximo = arr[0];
    for (int i = 1; i < tam; i++) {
        if (arr[i] > maximo) {
            maximo = arr[i];
        }
    }
    return maximo;
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
    
    int maximo = obtenerMaximo(arreglo, tam);
    cout << "El valor maximo es: " << maximo << endl;
    
    return 0;
}
