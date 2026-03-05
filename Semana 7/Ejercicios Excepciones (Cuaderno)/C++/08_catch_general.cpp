#include <iostream>
using namespace std;

int main() {
    try {
        throw 99.9f;
    } catch (...) {
        cout << "Se capturó una excepción desconocida" << endl;
    }
    return 0;
}
