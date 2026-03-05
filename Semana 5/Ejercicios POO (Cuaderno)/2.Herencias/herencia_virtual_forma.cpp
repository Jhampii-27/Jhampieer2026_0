// Ejercicio 8 - Herencia Virtual: Forma -> Coloreable / ConBorde -> FormaDecorada
//
//          Forma
//         /      \
//  Coloreable  ConBorde
//         \      /
//       FormaDecorada
//
#include <iostream>
#include <string>
using namespace std;

class Forma {
public:
    string nombre;
};

class Coloreable : virtual public Forma {
public:
    string color;
    void pintar() {
        cout << nombre << " pintado de " << color << endl;
    }
};

class ConBorde : virtual public Forma {
public:
    int grosor;
    void borde() {
        cout << nombre << " con borde de " << grosor << "px" << endl;
    }
};

class FormaDecorada : public Coloreable, public ConBorde {};

int main() {
    FormaDecorada fd;
    fd.nombre = "Cuadrado";
    fd.color  = "Rojo";
    fd.grosor = 3;
    fd.pintar(); // de Coloreable
    fd.borde();  // de ConBorde
    return 0;
}
