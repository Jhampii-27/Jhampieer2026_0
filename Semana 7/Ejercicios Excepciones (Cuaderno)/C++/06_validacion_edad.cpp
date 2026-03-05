#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        int edad = -5;
        if (edad < 0) throw invalid_argument("La edad no puede ser negativa");
        cout << "Edad válida: " << edad << endl;
    } catch (invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
