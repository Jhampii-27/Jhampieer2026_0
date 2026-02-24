#include <iostream>
using namespace std;

int main() {
    int v[5] = {1,2,3,4,5};
    int suma = 0;

    for (int i = 0; i<5; i++) {
        suma += v[i];
    }
    cout << "Suma = " << suma;
    return 0;
}