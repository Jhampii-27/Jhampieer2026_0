int main() {
    demostrarPolimorfismo();

    double eficiencia = calcularEficiencia<double>(8.5, 255.0);
    std::cout << "Eficiencia: " << eficiencia << " km/L" << std::endl;

    Auto miAuto(10, 110.0, 2);
    Reporte rep;
    rep.generarInforme(miAuto);

    return 0;
}
