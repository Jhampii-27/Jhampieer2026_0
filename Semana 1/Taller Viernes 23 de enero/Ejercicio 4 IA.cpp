#include <iostream>

using namespace std;

int main() {
    // Datos de la imagen
    double B = 10.0; // Base mayor
    double b, h;

    // Para completar el ejercicio, el usuario puede ingresar los valores faltantes
    cout << "--- EJERCICIO 4: TRAPECIO ---" << endl;
    cout << "Base mayor (B) ya definida como: " << B << endl;
    cout << "Ingresa la base menor (b): ";
    cin >> b;
    cout << "Ingresa la altura (h): ";
    cin >> h;

    // Fórmula: A = ((B + b) * h) / 2
    double area = ((B + b) * h) / 2.0;

    cout << "\nEl Area (A) del trapecio es: " << area << endl;

    return 0;
}