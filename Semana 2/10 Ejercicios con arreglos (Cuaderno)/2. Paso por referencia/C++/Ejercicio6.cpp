#include <iostream>
using namespace std;

void cuadrado(int v[], int n) {
    for(int i = 0; i < n; i++) {
        v[i] = v[i] * v[i];
    }
}

int main() {
    int v[5] = {1,2,3,4,5};
    cuadrado(v, 5);

    for(int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }
    return 0;
}