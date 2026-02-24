// Actividad 4 - Constructores y sobrecarga
// Agrego tres constructores distintos segun los datos que tenga disponibles

#include <iostream>
#include <string>
using namespace std;

class Celular {
private:
    string marca;
    string modelo;
    int bateria;

public:
    // Constructor por defecto: cuando no se sabe nada del celular
    Celular() {
        marca = "Desconocida";
        modelo = "Generico";
        bateria = 100;
    }

    // Constructor con 2 parametros: se sabe marca y modelo, bateria inicia llena
    Celular(string marca, string modelo) {
        this->marca = marca;
        this->modelo = modelo;
        this->bateria = 100;
    }

    // Constructor completo: se tienen todos los datos
    Celular(string marca, string modelo, int bateria) {
        this->marca = marca;
        this->modelo = modelo;
        // igual valido la bateria aqui
        if (bateria >= 0 && bateria <= 100)
            this->bateria = bateria;
        else {
            cout << "Bateria invalida, se deja en 100 por defecto." << endl;
            this->bateria = 100;
        }
    }

    void mostrarInfo() const {
        cout << "Marca: " << marca << " | Modelo: " << modelo
             << " | Bateria: " << bateria << "%" << endl;
    }
};

int main() {
    Celular c1;                              // usa el constructor por defecto
    Celular c2("Motorola", "Moto G73");     // solo marca y modelo
    Celular c3("Nokia", "G21", 45);         // los tres datos

    c1.mostrarInfo();
    c2.mostrarInfo();
    c3.mostrarInfo();

    return 0;
}
