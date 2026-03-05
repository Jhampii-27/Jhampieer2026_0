// Ejercicio 9 - HERENCIA (relacion is-a): Animal -> Gato
//
//       ┌────────┐
//       │ Animal │
//       └───┬────┘
//           │ «extends»
//       ┌───┴────┐
//       │  Gato  │
//       └────────┘
//
// Gato ES-UN Animal (relacion is-a).
//
#include <iostream>
#include <string>
using namespace std;

class Animal {
public:
    string nombre;
    void respirar() {
        cout << nombre << " respira" << endl;
    }
};

class Gato : public Animal {
public:
    void maullar() {
        cout << nombre << " dice: Miau!" << endl;
    }
};

int main() {
    Gato g;
    g.nombre = "Misi";
    g.respirar(); // heredado de Animal
    g.maullar();  // propio de Gato
    return 0;
}
