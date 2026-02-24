#include <iostream> 
using namespace std;

int main () {
    int num;

    cout << "ingrese su edad; " << endl;
    cin >> num;

    if (num >= 18 && num < 120) {
        cout << "Mayor de edad" << endl;
    } else if (num >= 0 && num < 18) {
        cout << "Menor de edad" << endl;
    } else {
        cout << "Edad no valida";
    }
    return 0;
}