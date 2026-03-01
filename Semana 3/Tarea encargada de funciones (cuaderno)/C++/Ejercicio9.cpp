#include <iostream>
using namespace std;

void Ejercicio9(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x = 10, y = 20;
    cout << "Antes: x=" << x << ", y=" << y << endl;
    Ejercicio9(x, y);
    cout << "Despues: x=" << x << ", y=" << y << endl;
    return 0;
}
