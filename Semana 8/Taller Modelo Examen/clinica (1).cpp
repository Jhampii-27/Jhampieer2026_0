/*
 * ============================================================
 *  CLINICA SALUD+ - Sistema de Gestion de Citas
 *  Taller UML + POO en C++
 * ============================================================
 *  Compilar : g++ -std=c++17 -Wall clinica.cpp -o clinica
 *  Ejecutar : ./clinica
 * ============================================================
 *
 *  Relaciones UML implementadas:
 *   - Herencia     : Persona <- Paciente, Doctor
 *   - Composicion  : Paciente <>-- HistoriaClinica <>-- EntradaHistoria
 *   - Agregacion   : Clinica o-- Doctor
 *   - Asociacion   : Cita --> Paciente*, Cita --> Doctor*
 *   - Dependencia  : Reporte ..> Clinica (recibe datos por parametro)
 * ============================================================
 */

#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include <algorithm>
#include <stdexcept>
#include <regex>
#include <map>
#include <limits>
#include <iomanip>

using namespace std;

// ============================================================
//  EXCEPCION PERSONALIZADA
// ============================================================

/*
 * EntidadNoEncontrada
 * Lanzada cuando se busca un Paciente, Doctor o Cita inexistente.
 * Hereda de runtime_error para captura generica si se necesita.
 */
class EntidadNoEncontrada : public runtime_error {
    string tipo, id;
public:
    EntidadNoEncontrada(const string& tipo, const string& id)
        : runtime_error("No se encontro " + tipo + " con ID: " + id),
          tipo(tipo), id(id) {}
    const string& getTipo() const { return tipo; }
    const string& getId()   const { return id; }
};


// ============================================================
//  VALIDACIONES
// ============================================================

void validarDNI(const string& dni) {
    if (dni.size() != 8 || !all_of(dni.begin(), dni.end(), ::isdigit))
        throw invalid_argument("DNI invalido: debe tener 8 digitos. Recibido: '" + dni + "'");
}

void validarEdad(int edad) {
    if (edad < 0 || edad > 120)
        throw invalid_argument("Edad invalida: rango [0-120]. Recibida: " + to_string(edad));
}

void validarTelefono(const string& tel) {
    if (tel.size() != 9 || !all_of(tel.begin(), tel.end(), ::isdigit))
        throw invalid_argument("Telefono invalido: debe tener 9 digitos. Recibido: '" + tel + "'");
}

void validarTarifa(double tarifa) {
    if (tarifa <= 0.0)
        throw invalid_argument("Tarifa invalida: debe ser mayor a 0. Recibida: " + to_string(tarifa));
}

void validarFecha(const string& fecha) {
    regex pat(R"(\d{4}-(0[1-9]|1[0-2])-(0[1-9]|[12]\d|3[01]))");
    if (!regex_match(fecha, pat))
        throw invalid_argument("Fecha invalida: use YYYY-MM-DD. Recibida: '" + fecha + "'");
}

void validarHora(const string& hora) {
    regex pat(R"((0[0-9]|1[0-9]|2[0-3]):[0-5][0-9])");
    if (!regex_match(hora, pat))
        throw invalid_argument("Hora invalida: use HH:MM. Recibida: '" + hora + "'");
}

void validarNoVacio(const string& val, const string& campo) {
    if (val.empty())
        throw invalid_argument("El campo '" + campo + "' no puede estar vacio.");
}


// ============================================================
//  EntradaHistoria
//  Composicion: HistoriaClinica <>-- EntradaHistoria (1..*)
// ============================================================

class EntradaHistoria {
    string fecha, nota, diagnostico;
public:
    EntradaHistoria(const string& f, const string& n, const string& d = "")
        : fecha(f), nota(n), diagnostico(d) {}

    void mostrar() const {
        cout << "  [" << fecha << "] " << nota;
        if (!diagnostico.empty()) cout << " | Dx: " << diagnostico;
        cout << "\n";
    }
};


// ============================================================
//  HistoriaClinica
//  Composicion: Paciente <>-- HistoriaClinica (1 a 1)
// ============================================================

class HistoriaClinica {
    vector<EntradaHistoria> entradas;
public:
    void agregarEntrada(const string& fecha, const string& nota, const string& diag = "") {
        validarFecha(fecha);
        validarNoVacio(nota, "nota medica");
        entradas.emplace_back(fecha, nota, diag);
    }
    int total() const { return (int)entradas.size(); }
    void mostrar() const {
        if (entradas.empty()) { cout << "  (Sin entradas)\n"; return; }
        for (const auto& e : entradas) e.mostrar();
    }
};


// ============================================================
//  Persona  (clase base abstracta)
//  Herencia: Persona <- Paciente, Doctor
// ============================================================

/*
 * mostrar() es virtual puro: hace a Persona abstracta.
 * Destructor virtual obligatorio para liberar memoria correctamente
 * cuando se borra un objeto derivado a traves de un puntero base.
 */
class Persona {
protected:
    string nombre;
public:
    explicit Persona(const string& n) : nombre(n) { validarNoVacio(n, "nombre"); }
    virtual ~Persona() = default;
    const string& getNombre() const { return nombre; }
    virtual void mostrar() const = 0;
};


// ============================================================
//  Paciente  (hereda de Persona)
//  Composicion con HistoriaClinica mediante unique_ptr
// ============================================================

class Paciente : public Persona {
    string dni, telefono;
    int    edad;
    // unique_ptr: si el Paciente se destruye, la historia tambien (composicion)
    unique_ptr<HistoriaClinica> historia;

public:
    Paciente(const string& nom, const string& dni, int edad, const string& tel)
        : Persona(nom), dni(dni), telefono(tel), edad(edad),
          historia(make_unique<HistoriaClinica>())
    {
        validarDNI(dni);
        validarEdad(edad);
        validarTelefono(tel);
    }

    const string&    getDNI()      const { return dni; }
    int              getEdad()     const { return edad; }
    const string&    getTelefono() const { return telefono; }
    HistoriaClinica* getHistoria() const { return historia.get(); }

    void mostrar() const override {
        cout << "  Paciente : " << nombre
             << " | DNI: "  << dni
             << " | Edad: " << edad
             << " | Tel: "  << telefono << "\n";
    }
};


// ============================================================
//  Doctor  (hereda de Persona)
//  La Clinica agrega doctores (agregacion)
// ============================================================

class Doctor : public Persona {
    string codigo, especialidad;
    double tarifa;

public:
    Doctor(const string& nom, const string& cod, const string& esp, double tar)
        : Persona(nom), codigo(cod), especialidad(esp), tarifa(tar)
    {
        validarNoVacio(cod, "codigo");
        validarNoVacio(esp, "especialidad");
        validarTarifa(tar);
    }

    const string& getCodigo()       const { return codigo; }
    const string& getEspecialidad() const { return especialidad; }
    double        getTarifa()       const { return tarifa; }

    void mostrar() const override {
        cout << "  Doctor   : " << nombre
             << " | Cod: "  << codigo
             << " | Esp: "  << especialidad
             << " | S/. "   << fixed << setprecision(2) << tarifa << "\n";
    }
};


// ============================================================
//  Cita
//  Asociacion: Cita --> Paciente* y Cita --> Doctor*
//  Los raw pointers son observadores: la Cita NO posee esos objetos.
// ============================================================

class Cita {
public:
    enum class Estado { ACTIVA, CANCELADA };

private:
    int     id;
    string  fecha, hora, motivo;
    Estado  estado;
    Paciente* paciente;  // puntero observador (asociacion UML)
    Doctor*   doctor;    // puntero observador (asociacion UML)
    static int contador;

public:
    Cita(Paciente* pac, Doctor* doc,
         const string& f, const string& h, const string& m)
        : id(++contador), fecha(f), hora(h), motivo(m),
          estado(Estado::ACTIVA), paciente(pac), doctor(doc)
    {
        if (!pac) throw invalid_argument("Paciente nulo en Cita.");
        if (!doc) throw invalid_argument("Doctor nulo en Cita.");
        validarFecha(f); validarHora(h); validarNoVacio(m, "motivo");
    }

    int           getId()      const { return id; }
    const string& getFecha()   const { return fecha; }
    const string& getHora()    const { return hora; }
    bool          estaActiva() const { return estado == Estado::ACTIVA; }
    Paciente*     getPaciente()const { return paciente; }
    Doctor*       getDoctor()  const { return doctor; }

    void cancelar() {
        if (!estaActiva())
            throw runtime_error("La cita #" + to_string(id) + " ya estaba cancelada.");
        estado = Estado::CANCELADA;
    }

    void mostrar() const {
        cout << "  Cita #" << id
             << " | " << fecha << " " << hora
             << " | " << paciente->getNombre()
             << " -> Dr. " << doctor->getNombre()
             << " | " << motivo
             << " [" << (estaActiva() ? "ACTIVA" : "CANCELADA") << "]\n";
    }
};

int Cita::contador = 0;


// ============================================================
//  Reporte
//  Dependencia ..> Clinica: recibe datos por parametro,
//  no almacena ni hereda nada de Clinica.
// ============================================================

class Reporte {
public:
    static void porEspecialidad(const vector<unique_ptr<Cita>>& citas) {
        cout << "\n--- Reporte: citas activas por especialidad ---\n";
        map<string, int> cont;
        for (const auto& c : citas)
            if (c->estaActiva()) cont[c->getDoctor()->getEspecialidad()]++;
        if (cont.empty()) { cout << "  Sin citas activas.\n"; return; }
        for (const auto& p : cont) cout << "  " << p.first << ": " << p.second << "\n";
    }

    static void porFecha(const vector<unique_ptr<Cita>>& citas) {
        cout << "\n--- Reporte: citas activas por fecha ---\n";
        map<string, int> cont;
        for (const auto& c : citas)
            if (c->estaActiva()) cont[c->getFecha()]++;
        if (cont.empty()) { cout << "  Sin citas activas.\n"; return; }
        for (const auto& p : cont) cout << "  " << p.first << ": " << p.second << "\n";
    }

    static void resumen(int nPac, int nDoc, const vector<unique_ptr<Cita>>& citas) {
        int act = 0;
        for (const auto& c : citas) if (c->estaActiva()) act++;
        cout << "\n--- Resumen general ---\n";
        cout << "  Pacientes : " << nPac << "\n";
        cout << "  Doctores  : " << nDoc << "\n";
        cout << "  Citas act.: " << act  << "\n";
        cout << "  Citas tot.: " << citas.size() << "\n";
    }
};


// ============================================================
//  Clinica  (contenedor principal)
//  - Posee pacientes y citas  (unique_ptr -> propiedad)
//  - Agrega doctores          (unique_ptr, modela agregacion)
// ============================================================

class Clinica {
    string nombre;
    vector<unique_ptr<Paciente>> pacientes;
    vector<unique_ptr<Doctor>>   doctores;
    vector<unique_ptr<Cita>>     citas;

public:
    explicit Clinica(const string& n) : nombre(n) {}

    int numPacientes() const { return (int)pacientes.size(); }
    int numDoctores()  const { return (int)doctores.size(); }
    const vector<unique_ptr<Cita>>& getCitas() const { return citas; }

    // -- Pacientes --

    void registrarPaciente(const string& nom, const string& dni, int edad, const string& tel) {
        for (const auto& p : pacientes)
            if (p->getDNI() == dni)
                throw runtime_error("Ya existe paciente con DNI: " + dni);
        pacientes.push_back(make_unique<Paciente>(nom, dni, edad, tel));
        cout << "  OK - Paciente '" << nom << "' registrado.\n";
    }

    Paciente* buscarPaciente(const string& dni) {
        for (const auto& p : pacientes)
            if (p->getDNI() == dni) return p.get();
        throw EntidadNoEncontrada("Paciente", dni);
    }

    void listarPacientes() const {
        cout << "\n--- Pacientes (" << pacientes.size() << ") ---\n";
        if (pacientes.empty()) { cout << "  (ninguno)\n"; return; }
        for (const auto& p : pacientes) p->mostrar();
    }

    // -- Doctores --

    void registrarDoctor(const string& nom, const string& cod,
                         const string& esp, double tar) {
        for (const auto& d : doctores)
            if (d->getCodigo() == cod)
                throw runtime_error("Ya existe doctor con codigo: " + cod);
        doctores.push_back(make_unique<Doctor>(nom, cod, esp, tar));
        cout << "  OK - Doctor '" << nom << "' registrado.\n";
    }

    Doctor* buscarDoctor(const string& cod) {
        for (const auto& d : doctores)
            if (d->getCodigo() == cod) return d.get();
        throw EntidadNoEncontrada("Doctor", cod);
    }

    void listarDoctores() const {
        cout << "\n--- Doctores (" << doctores.size() << ") ---\n";
        if (doctores.empty()) { cout << "  (ninguno)\n"; return; }
        for (const auto& d : doctores) d->mostrar();
    }

    // -- Citas --

    void agendarCita(const string& dni, const string& cod,
                     const string& fecha, const string& hora, const string& motivo) {
        Paciente* pac = buscarPaciente(dni);
        Doctor*   doc = buscarDoctor(cod);
        for (const auto& c : citas)
            if (c->estaActiva() &&
                c->getDoctor()->getCodigo() == cod &&
                c->getFecha() == fecha && c->getHora() == hora)
                throw runtime_error("El doctor ya tiene cita el " + fecha + " a las " + hora);
        citas.push_back(make_unique<Cita>(pac, doc, fecha, hora, motivo));
        cout << "  OK - Cita: " << pac->getNombre()
             << " con Dr. " << doc->getNombre()
             << " el " << fecha << " " << hora << "\n";
    }

    void cancelarCita(int id) {
        for (const auto& c : citas)
            if (c->getId() == id) {
                c->cancelar();
                cout << "  OK - Cita #" << id << " cancelada.\n";
                return;
            }
        throw EntidadNoEncontrada("Cita", to_string(id));
    }

    void citasPorPaciente(const string& dni) {
        Paciente* pac = buscarPaciente(dni);
        cout << "\n--- Citas de " << pac->getNombre() << " ---\n";
        bool hay = false;
        for (const auto& c : citas)
            if (c->getPaciente()->getDNI() == dni) { c->mostrar(); hay = true; }
        if (!hay) cout << "  (ninguna)\n";
    }

    void citasPorDoctor(const string& cod) {
        Doctor* doc = buscarDoctor(cod);
        cout << "\n--- Citas del Dr. " << doc->getNombre() << " ---\n";
        bool hay = false;
        for (const auto& c : citas)
            if (c->getDoctor()->getCodigo() == cod) { c->mostrar(); hay = true; }
        if (!hay) cout << "  (ninguna)\n";
    }

    // -- Reportes --
    void reporteEspecialidad() const { Reporte::porEspecialidad(citas); }
    void reporteFecha()        const { Reporte::porFecha(citas); }
    void reporteResumen()      const { Reporte::resumen(numPacientes(), numDoctores(), citas); }
};


// ============================================================
//  UTILIDADES DE ENTRADA
// ============================================================

int leerInt() {
    int v;
    if (!(cin >> v)) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    return v;
}

string leerLinea() {
    string s; getline(cin, s);
    size_t a = s.find_first_not_of(" \t");
    if (a == string::npos) return "";
    return s.substr(a, s.find_last_not_of(" \t") - a + 1);
}

void mostrarMenu() {
    cout << "\n+---------------------------------------+\n";
    cout << "|   CLINICA SALUD+ - Gestion de Citas   |\n";
    cout << "+---------------------------------------+\n";
    cout << "| 1) Registrar paciente                 |\n";
    cout << "| 2) Registrar doctor                   |\n";
    cout << "| 3) Agendar cita                       |\n";
    cout << "| 4) Cancelar cita                      |\n";
    cout << "| 5) Citas por paciente                 |\n";
    cout << "| 6) Citas por doctor                   |\n";
    cout << "| 7) Reporte por especialidad           |\n";
    cout << "| 8) Reporte por fecha                  |\n";
    cout << "| 9) Resumen general                    |\n";
    cout << "| 0) Salir                              |\n";
    cout << "+---------------------------------------+\n";
    cout << "Opcion: ";
}


// ============================================================
//  MAIN
// ============================================================

int main() {
    cout << "+---------------------------------------+\n";
    cout << "|   Bienvenido a Clinica Salud+         |\n";
    cout << "+---------------------------------------+\n";

    Clinica clinica("Clinica Salud+");
    bool activo = true;

    while (activo) {
        mostrarMenu();
        int op = leerInt();

        try {
            if (op < 0 || op > 9)
                throw out_of_range("Opcion invalida. Ingresa un numero del 0 al 9.");

            switch (op) {
                case 1: {
                    cout << "\n-- Registrar paciente --\n";
                    cout << "Nombre          : "; string nom = leerLinea();
                    cout << "DNI (8 digitos) : "; string dni = leerLinea();
                    cout << "Edad            : "; int    edad = leerInt();
                    cout << "Telefono (9 dig): "; string tel = leerLinea();
                    clinica.registrarPaciente(nom, dni, edad, tel);
                    break;
                }
                case 2: {
                    cout << "\n-- Registrar doctor --\n";
                    cout << "Nombre       : "; string nom = leerLinea();
                    cout << "Codigo       : "; string cod = leerLinea();
                    cout << "Especialidad : "; string esp = leerLinea();
                    cout << "Tarifa (S/.) : "; double tar; cin >> tar; cin.ignore();
                    clinica.registrarDoctor(nom, cod, esp, tar);
                    break;
                }
                case 3: {
                    cout << "\n-- Agendar cita --\n";
                    cout << "DNI paciente      : "; string dni   = leerLinea();
                    cout << "Codigo doctor     : "; string cod   = leerLinea();
                    cout << "Fecha (YYYY-MM-DD): "; string fecha = leerLinea();
                    cout << "Hora  (HH:MM)     : "; string hora  = leerLinea();
                    cout << "Motivo            : "; string mot   = leerLinea();
                    clinica.agendarCita(dni, cod, fecha, hora, mot);
                    break;
                }
                case 4: {
                    cout << "\n-- Cancelar cita --\n";
                    cout << "ID de la cita: "; int id = leerInt();
                    if (id <= 0) throw invalid_argument("El ID debe ser un numero positivo.");
                    clinica.cancelarCita(id);
                    break;
                }
                case 5: {
                    cout << "DNI del paciente : "; string dni = leerLinea();
                    clinica.citasPorPaciente(dni);
                    break;
                }
                case 6: {
                    cout << "Codigo del doctor: "; string cod = leerLinea();
                    clinica.citasPorDoctor(cod);
                    break;
                }
                case 7:  clinica.reporteEspecialidad(); break;
                case 8:  clinica.reporteFecha();        break;
                case 9:  clinica.reporteResumen();      break;
                case 0:
                    cout << "Sistema cerrado. Hasta luego.\n";
                    activo = false;
                    break;
            }

        // El programa NUNCA se cierra por un error; captura todo y continua
        } catch (const EntidadNoEncontrada& e) {
            cerr << "\n[ERROR - NO ENCONTRADO] " << e.what()
                 << " (Tipo: " << e.getTipo() << ")\n";
        } catch (const invalid_argument& e) {
            cerr << "\n[ERROR - DATO INVALIDO] "   << e.what() << "\n";
        } catch (const out_of_range& e) {
            cerr << "\n[ERROR - FUERA DE RANGO] "  << e.what() << "\n";
        } catch (const runtime_error& e) {
            cerr << "\n[ERROR - OPERACION] "        << e.what() << "\n";
        } catch (const exception& e) {
            cerr << "\n[ERROR] "                    << e.what() << "\n";
        }
    }

    return 0;
}
