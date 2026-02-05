#include <iostream>
#include <cmath> // Required for the sqrt() and pow() functions

using namespace std;

int main() {
    // Variable declarations
    double b, h, area, perimeter, diagonal;

    // User Input
    cout << "Enter the base (b): ";
    cin >> b;
    cout << "Enter the height (h): ";
    cin >> h;

    // Calculations based on image formulas
    area = b * h;
    perimeter = 2 * (b + h);
    diagonal = sqrt(pow(b, 2) + pow(h, 2));

    // Output results
    cout << "\n--- Results ---" << endl;
    cout << "Area (A): " << area << endl;
    cout << "Perimeter (P): " << perimeter << endl;
    cout << "Diagonal (d): " << diagonal << endl;

    return 0;
}