#include <iostream>
using namespace std;

void mayoresQueDiezADiez(int v[], int n) {
    for(int i = 0; i < n; i++) {
        if (v[i] > 10) {
            v[i] = 10;
        }
    }
}

int main() {
    int v[5] = {11, 22, 13, 4, 5};

    mayoresQueDiezADiez(v, 5);

    for(int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }
    return 0;
}