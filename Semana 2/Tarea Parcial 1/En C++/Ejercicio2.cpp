#include <iostream>
using namespace std;

int main() {
    int M;
    
    do {
        cout << "Ingrese M (M >= 1): ";
        cin >> M;
    } while (M < 1);
    
    for (int i = 1; i <= M; i++) {
        int x;
        cout << "Ingrese x: ";
        cin >> x;
        
        int temp = x;
        if (temp < 0) temp = -temp;
        
        int sumaDigitos = 0;
        int auxSuma = temp;
        while (auxSuma > 0) {
            sumaDigitos += auxSuma % 10;
            auxSuma /= 10;
        }
        
        int cantDigitos = 0;
        if (temp == 0) {
            cantDigitos = 1;
        } else {
            int auxCant = temp;
            while (auxCant > 0) {
                cantDigitos++;
                auxCant /= 10;
            }
        }
        
        if (sumaDigitos % 2 == 0 && x % 4 == 0) {
            cout << "A" << endl;
        } else if (sumaDigitos % 2 != 0 && x % 6 == 0) {
            cout << "B" << endl;
        } else if (cantDigitos == 3) {
            cout << "C" << endl;
        } else {
            cout << "D" << endl;
        }
    }
    
    return 0;
}