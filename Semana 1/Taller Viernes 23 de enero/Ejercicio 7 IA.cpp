#include <iostream>
#include <iomanip> // Para formatear la salida de decimales

using namespace std;

int main() {
    // Datos de entrada proporcionados en la tabla de la imagen
    double a = 9.0;     // lado (a)
    double b = 12.0;    // lado (b)
    double c = 15.0;    // lado (c)
    double r = 6.0;     // radio (r)

    // Fórmulas según la imagen
    // 1. Semi perímetro (p) = (a + b + c) / 2
    double p = (a + b + c) / 2.0;

    // 2. Área (S) = r * p
    double S = r * p;

    // Mostrar resultados
    cout << "--- EJERCICIO 7: TRIANGULO CIRCUNSCRITO ---" << endl;
    cout << fixed << setprecision(2); // Muestra 2 decimales
    cout << "Lado (a): " << a << endl;
    cout << "Lado (b): " << b << endl;
    cout << "Lado (c): " << c << endl;
    cout << "Radio (r): " << r << endl;
    cout << "-------------------------------------------" << endl;
    cout << "Semi perimetro (p): " << p << endl;
    cout << "Area (S):           " << S << endl;

    return 0;
}