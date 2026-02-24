// Actividad 1 - Clase vs Objeto
// Hice esta clase para practicar lo basico de clases y objetos en C++

#include <iostream>
#include <string>
using namespace std;

class Celular {
public:
    string marca;
    string modelo;
    int bateria;

    void mostrarInfo() {
        cout << "Marca: " << marca << endl;
        cout << "Modelo: " << modelo << endl;
        cout << "Bateria: " << bateria << "%" << endl;
        cout << "-------------------" << endl;
    }
};

int main() {
    // Creo el primer celular
    Celular cel1;
    cel1.marca = "Samsung";
    cel1.modelo = "Galaxy A54";
    cel1.bateria = 85;

    // Creo el segundo con datos distintos
    Celular cel2;
    cel2.marca = "Apple";
    cel2.modelo = "iPhone 13";
    cel2.bateria = 60;

    cel1.mostrarInfo();
    cel2.mostrarInfo();

    return 0;
}
