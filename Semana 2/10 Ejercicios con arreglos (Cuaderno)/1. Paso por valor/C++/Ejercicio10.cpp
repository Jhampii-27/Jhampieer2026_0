#include <iostream>
using namespace std;

int main() {
    int v[5] = {-2,5,7,-1,3};
    int cont = 0;

    for (int i = 0; i < 5; i++) {
        if(v[i] > 0) {
            cont +=1;
        }
    }
    cout << "Cantidad de positivos: " << cont << endl;
    return 0;
}