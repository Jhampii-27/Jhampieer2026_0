#include <iostream>
using namespace std;

void paresMenosUno(int v[], int n) {
    for (int i = 0; i < n; i++) {
        if (v[i] % 2 == 0) {
            v[i] = -1;
        }
    }
}

int main() {
    int v[5] = {1,2,3,4,5};
    paresMenosUno(v, 5);

    for (int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }
    return 0;
}