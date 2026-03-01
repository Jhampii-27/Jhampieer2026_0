#include <iostream>
#include <cmath>
using namespace std;

bool Ejercicio7(int n) {
    if (n < 2) return false;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0)
            return false;
    }
    return true;
}

int main() {
    cout << "13 es primo? " << (Ejercicio7(13) ? "Si" : "No") << endl;
    cout << "15 es primo? " << (Ejercicio7(15) ? "Si" : "No") << endl;
    return 0;
}
