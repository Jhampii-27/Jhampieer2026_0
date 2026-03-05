#include <iostream>
using namespace std;

class MiExcepcion : public exception {
public:
    const char* what() const noexcept override {
        return "¡Excepción personalizada lanzada!";
    }
};

int main() {
    try {
        throw MiExcepcion();
    } catch (MiExcepcion& e) {
        cout << "Capturada: " << e.what() << endl;
    }
    return 0;
}
