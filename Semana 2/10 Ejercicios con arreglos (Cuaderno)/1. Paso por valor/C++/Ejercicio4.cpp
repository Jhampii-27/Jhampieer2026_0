#include <iostream>
using namespace std;

int main() {
    int v[5] = {4,8,1,9,3};
    int mayor = v[0];

    for(int i = 0; i<5; i++) {
        if (v[i] > mayor) {
            mayor = v[i];
        }
    }
    cout << "El mayor del arreglo es: " << mayor << endl;
    return 0;
}