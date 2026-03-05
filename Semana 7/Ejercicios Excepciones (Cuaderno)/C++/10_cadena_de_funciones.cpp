#include <iostream>
#include <stdexcept>
using namespace std;

void nivel3() { throw runtime_error("Error en nivel 3"); }
void nivel2() { nivel3(); }
void nivel1() { nivel2(); }

int main() {
    try {
        nivel1();
    } catch (runtime_error& e) {
        cout << "Capturada desde nivel 1: " << e.what() << endl;
    }
    return 0;
}
