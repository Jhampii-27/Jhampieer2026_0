#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double lado;
    
    // Solicitar el lado del cuadrado
    cout << "=== EJERCICIO 1: CUADRADO ===" << endl;
    cout << "\nIngrese el lado del cuadrado (l): ";
    cin >> lado;
    
    // Calcular propiedades
    double area = lado * lado;                    // A = l²
    double perimetro = 4 * lado;                  // P = 4·l
    double diagonal = lado * sqrt(2);             // d = l√2
    
    // Mostrar resultados
    cout << "\n--- RESULTADOS ---" << endl;
    cout << fixed << setprecision(2);
    cout << "Lado (l):      " << lado << endl;
    cout << "Área (A):      " << area << endl;
    cout << "Perímetro (P): " << perimetro << endl;
    cout << "Diagonal (d):  " << diagonal << endl;
    
    return 0;
}