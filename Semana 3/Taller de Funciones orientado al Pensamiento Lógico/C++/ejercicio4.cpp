#include <iostream>
using namespace std;

float calcularPromedio(float arr[], int tam) {
    float suma = 0;
    for (int i = 0; i < tam; i++) {
        suma += arr[i];
    }
    return suma / tam;
}

int main() {
    int tam;
    
    cout << "Ingrese la cantidad de notas: ";
    cin >> tam;
    
    float notas[tam];
    
    cout << "Ingrese las notas:" << endl;
    for (int i = 0; i < tam; i++) {
        cout << "Nota " << (i + 1) << ": ";
        cin >> notas[i];
    }
    
    float promedio = calcularPromedio(notas, tam);
    cout << "El promedio es: " << promedio << endl;
    
    return 0;
}
