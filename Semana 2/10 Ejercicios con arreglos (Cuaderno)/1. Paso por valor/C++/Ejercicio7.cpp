#include <iostream>
using namespace std;

int main() {
    int v[4] = {5,8,1,3};
    int num = 8;
    bool encontrado = false;

    for (int i = 0; i < 4; i++) {
        if(v[i] == num) {
            encontrado = true;
        }
    }

    if(!encontrado) {
        cout << "Numero no encontrado";
    } else {
        cout << "Numero encontrado";
    }
    return 0;
}