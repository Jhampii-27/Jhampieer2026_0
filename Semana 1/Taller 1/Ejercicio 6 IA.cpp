#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double a = 9.0; // Lado a
    double b = 8.0; // Lado b
    double c = 7.0; // Lado c
    double R = 6.0; // Radio

    // Fórmula: S = (a * b * c) / (4 * R)
    double areaS = (a * b * c) / (4.0 * R);

    cout << "--- EJERCICIO 6: TRIANGULO INSCRITO ---" << endl;
    cout << fixed << setprecision(2);
    cout << "Area (S): " << areaS << endl;

    return 0;
}