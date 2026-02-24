#include <iostream>
using namespace std;
int main () {
    int N, suma = 0;
    int i = 0;

    cout << "Ingrese un numero:" << endl;
    cin >> N;

    while (i <= N) {
        suma = suma + i;
        i++;
    }
    cout << "La suma es: " << suma << endl;
    return 0;
}