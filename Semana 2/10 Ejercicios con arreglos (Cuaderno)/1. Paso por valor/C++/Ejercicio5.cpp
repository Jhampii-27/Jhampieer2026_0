#include <iostream>
using namespace std;

int main() {
    int v[5] = {4,7,2,9,6};
    int cont = 0;

    for (int i = 0; i < 5; i++) {
        if(v[i] % 2 == 0) {
            cont += 1;
        }
    }

    cout << "Numeros pares: " << cont << endl;
    return 0;
}
