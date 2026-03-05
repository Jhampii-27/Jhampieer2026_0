// Ejercicio 5 - DEPENDENCIA: Impresora - - -> Documento
//
//  ┌──────────┐  «uses»  ┌───────────┐
//  │ Impresora│- - - - ->│ Documento │
//  └──────────┘          └───────────┘
//
// Impresora usa Documento solo como parametro del metodo.
// No guarda ninguna referencia permanente.
//
#include <iostream>
#include <string>
using namespace std;

class Documento {
public:
    string titulo;
};

class Impresora {
public:
    // Dependencia: Documento llega como parametro, no se almacena
    void imprimir(Documento doc) {
        cout << "Imprimiendo: " << doc.titulo << endl;
    }
};

int main() {
    Impresora imp;
    Documento doc;
    doc.titulo = "Informe 2026";

    imp.imprimir(doc); // uso temporal, sin guardar
    return 0;
}
