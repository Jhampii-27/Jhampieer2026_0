#include <iostream>
using namespace std;

double Ejercicio6(double celsius) {
    return (celsius * 9.0 / 5.0) + 32.0;
}

int main() {
    cout << "100 C = " << Ejercicio6(100) << " F" << endl;
    return 0;
}
