#include <iostream>
using namespace std;

struct Estudiante {
    string nombre;
    float nota;
};

int main() {
    Estudiante v[3] = {{"Ana", 14}, {"Luis", 16}, {"Carlos", 13}};
    string buscar = "Luis";
    bool encontrado = false;

    for (int i = 0; i < 3; i++) {
        if (v[i].nombre == buscar){
            cout << "Encontrado: " << v[i].nombre << " " << v[i].nota << endl;
            encontrado = true;
        }
    }

    if (!encontrado) {
        cout << "No encontrado";
    }
    return 0;
}
