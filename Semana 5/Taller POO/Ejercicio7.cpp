// Actividad 7 - Mini reto: sistema de vehiculos
// Clase base Vehiculo con dos clases derivadas: Carro y Moto

#include <iostream>
#include <string>
using namespace std;

class Vehiculo {
private:
    string marca;
    int velocidadMax;

public:
    Vehiculo(string marca, int velocidadMax) {
        this->marca = marca;
        this->velocidadMax = velocidadMax;
    }

    string getMarca() const { return marca; }
    int getVelocidadMax() const { return velocidadMax; }

    void mostrarInfo() const {
        cout << "Marca: " << marca
             << " | Velocidad maxima: " << velocidadMax << " km/h" << endl;
    }
};

// Carro agrega el numero de puertas
class Carro : public Vehiculo {
private:
    int puertas;

public:
    Carro(string marca, int velocidadMax, int puertas)
        : Vehiculo(marca, velocidadMax) {
        this->puertas = puertas;
    }

    int getPuertas() const { return puertas; }

    void mostrarInfo() const {
        Vehiculo::mostrarInfo();
        cout << "Puertas: " << puertas << endl;
    }
};

// Moto agrega el cilindraje
class Moto : public Vehiculo {
private:
    int cilindraje;

public:
    Moto(string marca, int velocidadMax, int cilindraje)
        : Vehiculo(marca, velocidadMax) {
        this->cilindraje = cilindraje;
    }

    int getCilindraje() const { return cilindraje; }

    void mostrarInfo() const {
        Vehiculo::mostrarInfo();
        cout << "Cilindraje: " << cilindraje << " cc" << endl;
    }
};

int main() {
    Carro miCarro("Toyota", 180, 4);
    Moto miMoto("Honda", 140, 250);

    cout << "=== Carro ===" << endl;
    miCarro.mostrarInfo();

    cout << endl << "=== Moto ===" << endl;
    miMoto.mostrarInfo();

    return 0;
}
