#include <iostream>
#include <string>
#include <stdexcept>
using namespace std;

int main() {
    try {
        string s = "abc123";
        int n = stoi(s);
        cout << "Número: " << n << endl;
    } catch (invalid_argument& e) {
        cout << "Error al convertir: " << e.what() << endl;
    }
    return 0;
}
