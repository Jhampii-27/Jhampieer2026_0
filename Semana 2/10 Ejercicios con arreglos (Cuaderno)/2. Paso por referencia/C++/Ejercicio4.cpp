#include <iostream>
using namespace std;

void ordenar(int v[], int n) {
    for(int i = 0; i < n; i++) {
        for(int j = i+1; j < n; j++) {
            if (v[i] > v[j]) {
                swap (v[i], v[j]);
            }
        }
    }
}

int main() {
    int v[5] = {5,2,4,1,3};
    ordenar(v, 5);

    for(int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }
    return 0;
}