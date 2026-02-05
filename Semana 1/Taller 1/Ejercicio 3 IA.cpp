#include <iostream>
#include <cmath> // Para sqrt() y pow()
#include <iomanip> // Para formatear decimales

using namespace std;

int main() {
    // Valores de entrada según la tabla de la imagen
    double D = 8.0; // Diagonal mayor
    double d = 6.0; // Diagonal menor
    
    // Variables para los resultados
    double area, lado, perimetro;

    // Fórmulas proporcionadas en la imagen
    // 1. Área: A = (D * d) / 2
    area = (D * d) / 2.0;

    // 2. Lado: l = raíz cuadrada de ((D/2)^2 + (d/2)^2)
    lado = sqrt(pow(D / 2.0, 2) + pow(d / 2.0, 2));

    // 3. Perímetro: P = 4 * l
    perimetro = 4.0 * lado;

    // Mostrar resultados
    cout << "--- Ejercicio 3: Rombo ---" << endl;
    cout << "Diagonal mayor (D): " << D << endl;
    cout << "Diagonal menor (d): " << d << endl;
    cout << fixed << setprecision(2); // Formato con 2 decimales
    cout << "Area (A):           " << area << endl;
    cout << "Lado (l):           " << lado << endl;
    cout << "Perimetro (P):      " << perimetro << endl;

    return 0;
}