#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>
#include <limits>

using namespace std;

// ============================================================
// EXCEPCIÓN PERSONALIZADA
// ============================================================

/**
 * CuentaNoEncontrada: Se lanza cuando se busca una cuenta
 * que no existe en el banco.
 * Hereda de runtime_error.
 */
class CuentaNoEncontrada : public runtime_error {
private:
    int numeroBuscado;

public:
    explicit CuentaNoEncontrada(int numero)
        : runtime_error("Cuenta no encontrada con numero: " + to_string(numero)),
          numeroBuscado(numero) {}

    int getNumeroBuscado() const {
        return numeroBuscado;
    }
};

// ============================================================
// CLASE CuentaBancaria
// ============================================================

class CuentaBancaria {
private:
    int    numeroCuenta;
    string titular;
    double saldo;

public:
    CuentaBancaria(int numero, const string& nombre, double saldoInicial)
        : numeroCuenta(numero), titular(nombre), saldo(0.0)
    {
        // El constructor llama a depositar() para validar el saldo inicial
        depositar(saldoInicial);
    }

    // ---- depositar ----
    void depositar(double monto) {
        if (monto <= 0) {
            throw invalid_argument(
                "El monto a depositar debe ser positivo. Recibido: " +
                to_string(monto));
        }
        saldo += monto;
    }

    // ---- retirar ----
    void retirar(double monto) {
        if (monto <= 0) {
            throw invalid_argument(
                "El monto a retirar debe ser positivo. Recibido: " +
                to_string(monto));
        }
        if (monto > saldo) {
            throw runtime_error(
                "Saldo insuficiente. Saldo actual: " + to_string(saldo) +
                " | Monto solicitado: " + to_string(monto));
        }
        saldo -= monto;
    }

    // ---- consultarSaldo ----
    double consultarSaldo() const {
        return saldo;
    }

    // ---- getNumeroCuenta ----
    int getNumeroCuenta() const {
        return numeroCuenta;
    }

    // ---- mostrar ----
    void mostrar() const {
        cout << "  Cuenta #" << numeroCuenta
             << " | Titular: " << titular
             << " | Saldo: $" << saldo << "\n";
    }
};

// ============================================================
// CLASE Banco
// ============================================================

class Banco {
private:
    vector<CuentaBancaria> cuentas;
    int siguienteNumero;

public:
    Banco() : siguienteNumero(1001) {}

    // ---- agregarCuenta ----
    void agregarCuenta() {
        string nombre;
        double saldoInicial;

        cout << "  Nombre del titular: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(cin, nombre);

        cout << "  Saldo inicial: $";
        if (!(cin >> saldoInicial)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Entrada no valida para el saldo inicial.");
        }

        // Puede lanzar invalid_argument si saldoInicial <= 0
        CuentaBancaria nueva(siguienteNumero, nombre, saldoInicial);
        cuentas.push_back(nueva);
        cout << "  Cuenta creada con numero: " << siguienteNumero << "\n";
        ++siguienteNumero;
    }

    // ---- buscarCuenta ----
    CuentaBancaria& buscarCuenta(int numero) {
        for (auto& c : cuentas) {
            if (c.getNumeroCuenta() == numero) {
                return c;
            }
        }
        throw CuentaNoEncontrada(numero);   // excepción personalizada
    }

    // ---- mostrarCuentas ----
    void mostrarCuentas() const {
        if (cuentas.empty()) {
            cout << "  No hay cuentas registradas.\n";
            return;
        }
        for (const auto& c : cuentas) {
            c.mostrar();
        }
    }

    // ---- pedirNumeroCuenta (helper) ----
    int pedirNumeroCuenta() {
        int numero;
        cout << "  Numero de cuenta: ";
        if (!(cin >> numero)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Entrada no valida: se esperaba un numero de cuenta.");
        }
        return numero;
    }

    // ---- flujo depositar desde menú ----
    void flujoDepositar() {
        int numero = pedirNumeroCuenta();
        CuentaBancaria& cuenta = buscarCuenta(numero);  // puede lanzar CuentaNoEncontrada

        double monto;
        cout << "  Monto a depositar: $";
        if (!(cin >> monto)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Entrada no valida para el monto.");
        }
        cuenta.depositar(monto);  // puede lanzar invalid_argument
        cout << " Deposito exitoso. Saldo actual: $" << cuenta.consultarSaldo() << "\n";
    }

    // ---- flujo retirar desde menú ----
    void flujoRetirar() {
        int numero = pedirNumeroCuenta();
        CuentaBancaria& cuenta = buscarCuenta(numero);

        double monto;
        cout << "  Monto a retirar: $";
        if (!(cin >> monto)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            throw invalid_argument("Entrada no valida para el monto.");
        }
        cuenta.retirar(monto);  // puede lanzar invalid_argument o runtime_error
        cout << " Retiro exitoso. Saldo actual: $" << cuenta.consultarSaldo() << "\n";
    }

    // ---- flujo consultar desde menú ----
    void flujoConsultar() {
        int numero = pedirNumeroCuenta();
        CuentaBancaria& cuenta = buscarCuenta(numero);
        cout << "  Saldo actual: $" << cuenta.consultarSaldo() << "\n";
    }
};

// ============================================================
// FUNCIÓN mostrarMenu
// ============================================================

void mostrarMenu() {
    cout << "\n========== SISTEMA BANCARIO ==========\n"
         << "  1. Crear cuenta\n"
         << "  2. Depositar dinero\n"
         << "  3. Retirar dinero\n"
         << "  4. Consultar saldo\n"
         << "  5. Mostrar todas las cuentas\n"
         << "  6. Salir\n"
         << "======================================\n"
         << "  Opcion: ";
}

// ============================================================
// MAIN
// ============================================================

int main() {
    Banco banco;
    int opcion;

    cout << "Bienvenido al Sistema Bancario POO\n";

    while (true) {
        mostrarMenu();

        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "  [ERROR] Opción inválida: ingrese un número del 1 al 6.\n";
            continue;
        }

        try {
            // Validar rango → out_of_range
            if (opcion < 1 || opcion > 6) {
                throw out_of_range(
                    "Opción fuera de rango: " + to_string(opcion) +
                    ". Ingrese entre 1 y 6.");
            }

            switch (opcion) {
                case 1: banco.agregarCuenta();   break;
                case 2: banco.flujoDepositar();  break;
                case 3: banco.flujoRetirar();    break;
                case 4: banco.flujoConsultar();  break;
                case 5: banco.mostrarCuentas();  break;
                case 6:
                    cout << "  Hasta luego.\n";
                    return 0;
            }
        }
        // ---- MÚLTIPLES CATCH EN ORDEN CORRECTO (más específico primero) ----
        catch (const CuentaNoEncontrada& e) {
            // Excepción personalizada (más específica que runtime_error)
            cout << "  [CUENTA NO ENCONTRADA] " << e.what() << "\n";
        }
        catch (const invalid_argument& e) {
            // Montos negativos o entradas no numéricas
            cout << "  [ARGUMENTO INVÁLIDO] " << e.what() << "\n";
        }
        catch (const out_of_range& e) {
            // Opción de menú fuera de rango
            cout << "  [FUERA DE RANGO] " << e.what() << "\n";
        }
        catch (const runtime_error& e) {
            // Saldo insuficiente u otros errores en tiempo de ejecución
            cout << "  [ERROR EN TIEMPO DE EJECUCIÓN] " << e.what() << "\n";
        }
        catch (const exception& e) {
            // Red de seguridad para cualquier otra excepción estándar
            cout << "  [EXCEPCIÓN] " << e.what() << "\n";
        }
    }

    return 0;
}
