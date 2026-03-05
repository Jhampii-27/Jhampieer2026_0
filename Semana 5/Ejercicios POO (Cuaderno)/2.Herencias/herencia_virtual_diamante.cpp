// Ejercicio 7 - Herencia Virtual: solucion al problema diamante
//
//        Dispositivo
//       /            \
//   Entrada        Salida
//       \            /
//       EntradaSalida
//
#include <iostream>
#include <string>
using namespace std;

class Dispositivo {
public:
    string nombre;
    void encender() {
        cout << nombre << " encendido" << endl;
    }
};

class Entrada : virtual public Dispositivo {
public:
    void leer() {
        cout << "Leyendo desde " << nombre << endl;
    }
};

class Salida : virtual public Dispositivo {
public:
    void escribir() {
        cout << "Escribiendo en " << nombre << endl;
    }
};

// Sin virtual habria dos copias de Dispositivo (ambiguedad)
class EntradaSalida : public Entrada, public Salida {};

int main() {
    EntradaSalida es;
    es.nombre = "USB";
    es.encender(); // un solo Dispositivo gracias a virtual
    es.leer();
    es.escribir();
    return 0;
}
