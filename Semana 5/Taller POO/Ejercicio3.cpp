// Actividad 3 - Uso de this->
// Cambio los parametros para que tengan el mismo nombre que el atributo
// y uso this-> para que el compilador sepa cual es cual

#include <iostream>
#include <string>
using namespace std;

class Celular {
private:
    string marca;
    string modelo;
    int bateria;

public:
    string getMarca() const { return marca; }
    string getModelo() const { return modelo; }
    int getBateria() const { return bateria; }

    // Setters usando this-> porque el parametro se llama igual que el atributo
    void setMarca(string marca) {
        this->marca = marca;
    }

    void setModelo(string modelo) {
        this->modelo = modelo;
    }

    void setBateria(int bateria) {
        if (bateria >= 0 && bateria <= 100) {
            this->bateria = bateria;
        } else {
            cout << "Bateria fuera de rango. No se asigno el valor." << endl;
        }
    }

    void mostrarInfo() const {
        cout << "Marca: " << marca << " | Modelo: " << modelo
             << " | Bateria: " << bateria << "%" << endl;
    }
};

int main() {
    Celular cel1;
    cel1.setMarca("Xiaomi");
    cel1.setModelo("Redmi Note 12");
    cel1.setBateria(72);
    cel1.mostrarInfo();

    return 0;
}
