void demostrarPolimorfismo() {
    std::vector<std::shared_ptr<Vehiculo>> flota;

    flota.push_back(std::make_shared<Auto>(1, 120.0, 4));
    flota.push_back(std::make_shared<Drone>(2, 80.0, 200.0));
    flota.push_back(std::make_shared<Camion>(3, 90.0, 15.0));

    std::cout << "\n=== Recorrido de flota ===" << std::endl;
    for (const auto& v : flota) {
        v->moverse();
        v->mostrarInfo();
        std::cout << std::endl;
    }
}
