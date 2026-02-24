#include <iostream>
using namespace std;

int main() {
    int v[5] = {2,4,2,5,2};
    int cont = 0, num = 4;

    for(int i = 0; i < 5; i++) {
        if(v[i] == num) {
            cont += 1;
        }
    }

    cout << "El numero de veces que aprece " << num << " en el arreglo es: " << cont << endl;
    return 0;
}