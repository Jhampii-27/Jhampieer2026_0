#include <iostream>
using namespace std;

int main () {
    int N, i= 0;  
    
    cout << "Ingrese un numero natural: " << endl;
    cin >> N;
    
    if (N < 0) { 
        cout << "Numero negativo no es un numero natural." << endl;
    } else {
        while (i <= N) {
            cout << i << endl;
            i += 1;
        }
    }
    
    return 0;
}