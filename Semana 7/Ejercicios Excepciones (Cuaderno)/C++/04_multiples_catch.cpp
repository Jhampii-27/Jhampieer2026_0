#include <iostream>
#include <string>
using namespace std;

int main() {
    try {
        int tipo = 2;
        if (tipo == 1) throw 42;
        if (tipo == 2) throw string("Error de texto");
        if (tipo == 3) throw 3.14;
    } catch (int e) {
        cout << "Entero: " << e << endl;
    } catch (string& e) {
        cout << "String: " << e << endl;
    } catch (double e) {
        cout << "Double: " << e << endl;
    }
    return 0;
}
