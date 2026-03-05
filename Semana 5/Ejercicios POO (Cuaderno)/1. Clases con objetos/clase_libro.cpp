// Ejercicio 7 - Clase Libro
#include <iostream>
#include <string>
using namespace std;

class Libro {
public:
    string titulo;
    string autor;

    void mostrar() {
        cout << "Libro: " << titulo << " - Autor: " << autor << endl;
    }
};

int main() {
    Libro lb;
    lb.titulo = "El Principito";
    lb.autor  = "Saint-Exupery";
    lb.mostrar();
    return 0;
}
