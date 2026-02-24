class Reporte {
public:
    void generarInforme(const Vehiculo& v) {
        std::cout << "--- INFORME DE VEHICULO ---" << std::endl;
        std::cout << "ID interno: " << v.id << std::endl;
        std::cout << "Velocidad registrada: " << v.velocidad << " km/h" << std::endl;
        std::cout << "---------------------------" << std::endl;
    }
};
