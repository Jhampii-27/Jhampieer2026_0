#include <iostream>
using namespace std;

int sumarArreglo(int arr[], int tam) {
    int suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += arr[i];
    }
    return suma;
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
    
    int resultado = sumarArreglo(arreglo, tam);
    cout << "La suma total es: " << resultado << endl;
    
    return 0;
}
