#include <iostream>
using namespace std;

void duplicar (int v[], int n) {
    for(int i = 0; i < n; i++) {
        v[i] *= 2;
    }
}

int main() {
    int v[5] = {1,2,3,4,5};
    duplicar(v, 5);

    for(int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }
    return 0;
}