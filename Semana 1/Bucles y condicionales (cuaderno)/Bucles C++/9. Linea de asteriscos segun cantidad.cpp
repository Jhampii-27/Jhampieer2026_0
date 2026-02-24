#include <iostream>
using namespace std;
int main () {
    int num, i = 1;

    cout << "Ingrese el numero de asteristicos que desearia ver: " << endl;
    cin >> num;

    do {
        cout << "*";
        i += 1;
    } while (num >= i);
    return 0;
}