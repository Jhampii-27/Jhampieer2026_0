#include <iostream>
using namespace std;

void Ejercicio3(int numero) {
    if (numero % 2 == 0)
        cout << numero << " es PAR." << endl;
    else
        cout << numero << " es IMPAR." << endl;
}

int main() {
    Ejercicio3(7);
    Ejercicio3(10);
    return 0;
}
