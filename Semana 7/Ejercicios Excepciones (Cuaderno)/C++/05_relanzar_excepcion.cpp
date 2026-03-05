#include <iostream>
#include <stdexcept>
using namespace std;

void funcionInterna() {
    throw runtime_error("Error desde función interna");
}

int main() {
    try {
        try {
            funcionInterna();
        } catch (runtime_error& e) {
            cout << "Capturada internamente, relanzando..." << endl;
            throw;
        }
    } catch (runtime_error& e) {
        cout << "Capturada externamente: " << e.what() << endl;
    }
    return 0;
}
