#include <iostream>
using namespace std;

int Ejercicio8(int n) {
    if (n <= 0) return 0;
    if (n == 1) return 1;
    return Ejercicio8(n - 1) + Ejercicio8(n - 2);
}

int main() {
    cout << "Fibonacci(7) = " << Ejercicio8(7) << endl;
    return 0;
}
