#include <iostream>
using namespace std;
int main() {
    int estudiante;

    cout << "Ingrese cuantos estudiantes desea registrar: " << endl;
    cin >> estudiante;

    int asistencia[estudiante][5];

    for (int i = 0; i < estudiante; i++) {
        cout << "Estudiante: " << i+1 << endl;
        for (int j = 0; j < 5; j++ ) {
            do {
                cout << "Elemento [" << i << "] [" << j << "]: " << endl;
                cin >> asistencia [i][j];
                if (asistencia[i][j] != 1 && asistencia [i][j] != 0 ){
                    cout << "Intentelo de nuevo solo (0 y 1)" << endl;
                }
            } while (asistencia[i][j] != 1 && asistencia[i][j] != 0 );
        }
    }


    bool hayperfectos = false;
    for (int i = 0; i < estudiante ; i++){
        int total = 0;
        for (int j = 0; j < 5; j++) {
            total += asistencia[i][j];
        }
        cout << "Estudiante: " << i+1 << "(" << total << " dias de asistencia)" <<endl;
        if (total == 5) {
            cout << "Estudiante " << i+1 << " con asistencias perfectas." << endl;
            hayperfectos = true;
        }
    }
    if (!hayperfectos) {
        cout << "No hay Ningun estudiante con asistencia perfecta." << endl;
    }
    
    int totalasistencias = 0;
    for (int i = 0; i < estudiante; i++) {
        for (int j = 0; j < 5; j++ ) {
            totalasistencias += asistencia[i][j];
        }
    }
    cout << "El total de asistencias es: " << totalasistencias << endl;




    for (int i = 0; i < estudiante; i++) {
        for (int j = 0; j < 5; j++ ) {
            cout << asistencia [i][j] << " ";
            
        }
        cout << endl;
    }

}
    

    
