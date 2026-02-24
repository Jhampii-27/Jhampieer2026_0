class Auto : public Vehiculo {
private:
    int numeroPasajeros;
public:
    Auto(int id, double vel, int pasajeros)
        : Vehiculo(id, vel), numeroPasajeros(pasajeros) {}

    void moverse() override {
        std::cout << "Auto " << id << " se desplaza por la carretera a "
                  << velocidad << " km/h." << std::endl;
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        std::cout << "  Pasajeros: " << numeroPasajeros << std::endl;
    }
};

class Drone : public Vehiculo {
private:
    double alturaMaxima;
public:
    Drone(int id, double vel, double altura)
        : Vehiculo(id, vel), alturaMaxima(altura) {}

    void moverse() override {
        std::cout << "Drone " << id << " vuela a " << alturaMaxima
                  << " m de altura a " << velocidad << " km/h." << std::endl;
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        std::cout << "  Altura max: " << alturaMaxima << " m" << std::endl;
    }
};

class Camion : public Vehiculo {
private:
    double capacidadCarga;
public:
    Camion(int id, double vel, double carga)
        : Vehiculo(id, vel), capacidadCarga(carga) {}

    void moverse() override {
        std::cout << "Camion " << id << " transporta " << capacidadCarga
                  << " ton a " << velocidad << " km/h." << std::endl;
    }

    void mostrarInfo() override {
        Vehiculo::mostrarInfo();
        std::cout << "  Carga maxima: " << capacidadCarga << " ton" << std::endl;
    }
};
