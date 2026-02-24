#include <iostream>
using namespace std;

int main() {
    int v[4] = {1,11,5,7};
    bool ordenado = true;

    for(int i = 0; i < 4; i++) {
        if(v[i] > v[i+1]) {
            ordenado = false;
        }
    }
    if (ordenado) {
        cout << "El arreglo si esta ordenado ascendente";
    } else {
        cout << "El arreglo no esta ordenado ascendente";
        return 0;
    }
}