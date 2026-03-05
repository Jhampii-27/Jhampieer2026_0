#include <iostream>
#include <stdexcept>
using namespace std;

int main() {
    try {
        int a = 10, b = 0;
        if (b == 0) throw runtime_error("No se puede dividir por cero");
        cout << a / b << endl;
    } catch (runtime_error& e) {
        cout << "Error: " << e.what() << endl;
    }
    return 0;
}
