#include <iostream>
using namespace std;

int main () {
    int num, i = 1;
    cout << "Ingrese un numero: " << endl;
    cin >> num;

    do {
        cout << num << " x " << i << " = " << num * i << endl;
        i += 1;
    } while (i <= 10);
    return 0;
}