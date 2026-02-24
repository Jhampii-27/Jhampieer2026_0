#include <iostream>
using namespace std;

void multiplicarArregloPorNum(int v[], int n, int m) {
    for(int i = 0; i < n; i++) {
        v[i] = v[i] * m;
    }
}

int main() {
    int v[5] = {1,2,3,4,5};

    multiplicarArregloPorNum(v, 5, 3);

    for(int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }
    return 0;
}