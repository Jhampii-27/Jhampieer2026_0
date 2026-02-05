#include <iostream> 
using namespace std;
int main() {
    int num;
    do {
        cout << "Ingrese un numero entero positivo: " << endl;
        cin >> num;
        if (num <= 0) {
            cout << "Intente nuevamente. " << endl;
        }
    } while (num <= 0);

    float temperatura[num];
    int conttempmax = 0;
    int conttempmin = 0;
    float tempmax;
    float tempmin;

    for (int i = 0; i < num; i++) {
            cout << "Ingrese la " << i+1 << " temperatura. " << endl;
            cin >> temperatura[i];
    }

    cout << "[";
    for (int i = 0; i < num; i++) {
        cout << temperatura[i];
        if (i < num-1){
            cout << ", ";
        }
    }
    cout << "]" << endl;

    tempmax = temperatura[0];
    tempmin = temperatura[0];
    conttempmax = 0;
    conttempmin = 0;

    for (int i = 0; i < num; i++) {
        
        if (temperatura[i] > tempmax) {
            tempmax = temperatura[i];
            conttempmax = i;
        }

        if (temperatura[i] < tempmin) {
            tempmin = temperatura[i];
            conttempmin = i;
        }
    }

    cout << "Maxima: " << tempmax << " (dia " << conttempmax+1 << ")" << endl;
    cout << "Minima " << tempmin << " (dia "  << conttempmin+1 << ")" << endl;

    int mayor30 = 0;
    for (int i = 0; i < num; i++) {
        if (temperatura[i] > 30) {
            mayor30++;
        }
    }
    if (mayor30 == 0) {
        cout << "No esiste temperatura mayor a 30." << endl;
    } else {
        cout << "Dias mayores a 30: " << mayor30 << endl;
    }
    return 0;
}