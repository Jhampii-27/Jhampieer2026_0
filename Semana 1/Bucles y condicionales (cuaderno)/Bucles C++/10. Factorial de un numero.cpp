#include <iostream>
using namespace std;
int main () {
    int num, i = 1, factorial = 1;

    cout << "Ingrese un numero: " << endl;
    cin >> num;

    do{
        factorial = factorial * i;
        i += 1;
    } while (i <= num);
    cout << factorial;
}