#include <iostream>
using namespace std;

struct Estudiantes {
    string nombre;
    float nota;
};

int main() {
    Estudiantes v[2] = {{"Juan", 18}, {"Maria", 20}};

    for (int i = 0; i < 2; i++) {
        cout << v[i].nombre << " -Nota " << v[i].nota << endl; 
    }
    return 0;
}
