#include <iostream>
#include <cmath>    // Para usar la función sqrt()
#include <iomanip>  // Para configurar los decimales

using namespace std;

int main() {
    // Datos de entrada de la imagen
    double a = 3.0;
    double b = 7.0;
    double c = 5.0;

    // 1. Calcular el semiperímetro (p)
    // Fórmula: p = (a + b + c) / 2
    double p = (a + b + c) / 2.0;

    // 2. Calcular el Área (S) usando la fórmula de Herón
    // Fórmula: A = sqrt(p * (p - a) * (p - b) * (p - c))
    double area = sqrt(p * (p - a) * (p - b) * (p - c));

    // Mostrar resultados formateados
    cout << "--- EJERCICIO 8: FORMULA DE HERON ---" << endl;
    cout << fixed << setprecision(2);
    cout << "Lado (a): " << a << endl;
    cout << "Lado (b): " << b << endl;
    cout << "Lado (c): " << c << endl;
    cout << "-------------------------------------" << endl;
    cout << "Semi perimetro (p): " << p << endl;
    cout << "Area (S):           " << area << endl;

    return 0;
}