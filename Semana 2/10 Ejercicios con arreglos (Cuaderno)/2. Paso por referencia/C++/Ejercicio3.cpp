#include <iostream>
using namespace std;

void invertir(int v[], int n) {
    for(int i = 0; i < n/2; i++) {
        swap(v[i], v[n-1-i]);
    }
}

int main() {
    int v[5] = {1,2,3,4,5};

    invertir(v, 5);

    for(int i = 0; i < 5; i++) {
        cout << v[i] << " "; 
    }
    return 0;
}