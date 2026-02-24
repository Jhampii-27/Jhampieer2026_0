// Actividad 2 - Encapsulamiento con private + getters y setters
// Modifique la clase para proteger los atributos y agregar validacion

#include <iostream>
#include <string>
using namespace std;

class Celular {
private:
    string marca;
    string modelo;
    int bateria;

public:
    // Getters
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getBateria() const { return bateria; }

    // Setters con validacion
    void setMarca(string m) { marca = m; }
    void setModelo(string mo) { modelo = mo; }

    void setBateria(int b) {
        if (b >= 0 && b <= 100) {
            bateria = b;
        } else {
            cout << "Error: el valor de bateria no es valido (debe ser 0-100)." << endl;
        }
    }

    void mostrarInfo() const {
        cout << "Marca: " << getMarca() << endl;
        cout << "Modelo: " << getModelo() << endl;
        cout << "Bateria: " << getBateria() << "%" << endl;
        cout << "-------------------" << endl;
    }
};

int main() {
    Celular cel1;
    cel1.setMarca("Samsung");
    cel1.setModelo("Galaxy A54");
    cel1.setBateria(85);

    Celular cel2;
    cel2.setMarca("Apple");
    cel2.setModelo("iPhone 13");
    cel2.setBateria(150);  // esto deberia mostrar error

    cel1.mostrarInfo();
    cel2.mostrarInfo();

    return 0;
}
