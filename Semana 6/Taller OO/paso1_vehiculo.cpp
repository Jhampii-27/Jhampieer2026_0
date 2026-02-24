#include <iostream>
#include <vector>
#include <string>
#include <memory>

class Vehiculo {
protected:
    int id;
    double velocidad;

public:
    Vehiculo(int id, double velocidad)
        : id(id), velocidad(velocidad) {}

    virtual void moverse() = 0;

    virtual void mostrarInfo() {
        std::cout << "ID: " << id
                  << " | Velocidad: " << velocidad << " km/h" << std::endl;
    }

    virtual ~Vehiculo() {}

    friend class Reporte;
};
