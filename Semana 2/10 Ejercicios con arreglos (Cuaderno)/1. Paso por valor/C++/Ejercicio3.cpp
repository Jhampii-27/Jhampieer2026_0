#include <iostream>
using namespace std;

int main() {
    int v[5] = {10,20,30,40,50};
    float suma = 0;

    for(int i = 0; i<5; i++) {
        suma += v[i];
    }
    cout << "Promedio: " << suma/5;
    return 0;
}