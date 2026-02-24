#include <iostream>
using namespace std;

int main() {

    int dia;

    do {
        cout << "De cuantos dias va a registrar el balance diario: " << endl;
        cin >> dia;
        if (dia <= 0) {
            cout << "Ingrese nuevamente." << endl;
        }
    } while (dia <= 0);



    float balance[dia];
    int rachaactual = 0;
    int rachamax = 0;



    for (int i = 0; i < dia; i++) {
        cout << "Ingrese el balance diario de la empresa: " << endl;
        cin >> balance[i];
    }

    cout << endl << endl;



    for (int i = 0; i < dia; i++) {
        if (balance[i] > 0) {
            rachaactual++;
        
            if (rachaactual > rachamax) {
                rachamax = rachaactual;
            }

        } else {
            rachaactual= 0;
        }
        
    }
    cout << "Mayor racha positiva: " << rachamax <<" dias. " << endl;
    return 0;
}

