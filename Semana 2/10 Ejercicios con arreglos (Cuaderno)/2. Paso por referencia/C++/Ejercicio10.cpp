#include <iostream>
using namespace std;

void cerosPorUnos(int v[], int n) {
    for (int i = 0; i < n; i++) {
        if(v[i] == 0) {
            v[i] = 1;
        }
    }
}

int main() {
    int v[5] = {0, 11, 0, 2, 0};

    cerosPorUnos(v, 5);

    for( int i = 0; i < 5; i++) {
        cout << v[i] << " ";
    }
    return 0;
}