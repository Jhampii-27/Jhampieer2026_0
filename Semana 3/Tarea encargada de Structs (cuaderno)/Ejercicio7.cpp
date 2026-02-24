#include <iostream>
using namespace std;

struct Estudiante {
    string nombre;
    float nota;
};

int main() {
    Estudiante v[3] = {{"Ana", 15}, {"Luis", 18}, {"Carlos", 14}};
    int pos = 0;

    for (int i = 0; i < 3; i++) {
        if (v[i].nota > v[pos].nota) {
            pos = i;
        }
    }
    cout << "Mayor nota: " << v[pos].nombre << " " << v[pos].nota;
    return 0;
}