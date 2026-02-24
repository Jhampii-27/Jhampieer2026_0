#include <iostream>
using namespace std;

int Ejercicio4(int a, int b) {
    if (a > b)
        return a;
    else
        return b;
}

int main() {
    cout << "El mayor entre 12 y 8 es: " << Ejercicio4(12, 8) << endl;
    return 0;
}
