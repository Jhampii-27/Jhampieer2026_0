/*
==================== BITÁCORA IA ====================
Herramienta IA usada: Claude (Anthropic)

Objetivo del uso: 
Comprender el código completo del sistema de biblioteca, especialmente:
- Gestión dinámica de memoria con arreglos dinámicos (new/delete)
- Uso de estructuras (Libro, Usuario, Prestamo, BibliotecaData)
- Punteros y referencias en funciones de búsqueda
- Manejo de archivos para persistencia de datos
- Redimensionamiento dinámico de arreglos

Preguntas que hice a la IA (resumen):
1) ¿Cómo funcionan los punteros en buscarLibroPorId() y buscarUsuarioPorId()?
   ¿Por qué retornan nullptr cuando no encuentran?
2) ¿Qué hace exactamente la función redimensionarLibros()? ¿Por qué se usa new y delete?
3) ¿Cómo funciona el guardado y carga de archivos con getline y el delimitador '|'?
4) ¿Por qué se usa BibliotecaData& (referencia) en todas las funciones?
5) ¿Qué significa cin.ignore() y por qué se usa después de cin >> variable?

Qué sugerencias acepté y por qué:
- Entendí que new[] reserva memoria dinámica porque no sabemos cuántos libros/usuarios 
  habrá, y delete[] la libera para evitar memory leaks
- Acepté que los punteros permiten retornar la dirección del libro/usuario encontrado
  sin copiarlo, siendo más eficiente
- Comprendí que el redimensionamiento duplica la capacidad cuando se llena el arreglo,
  copiando los datos al nuevo arreglo más grande
- Entendí que las referencias (&) permiten modificar la estructura original sin copiarla
- Agregué validaciones de entrada para evitar datos inválidos (IDs fuera de rango,
  cadenas vacías, años imposibles)
- Agregué mensajes informativos cuando no hay datos (listas vacías)
- Validé que existan datos antes de realizar operaciones
- Implementé guardado completo de libros, usuarios y préstamos en archivos separados

Qué sugerencias rechacé y por qué:
- No implementé validación extra con try-catch porque aún no domino manejo avanzado 
  de excepciones
- No agregué ordenamiento de libros porque no hemos visto algoritmos de ordenamiento
  en clase todavía
- No modifiqué el formato de salida original para mantener compatibilidad

Test manual diseñado por mí:
Entrada (pasos/comandos):
1) Opción 1: Agregar libro (ID: 101, Título: "C++ Básico", Autor: "Juan Pérez", Año: 2020)
2) Opción 1: Intentar ID duplicado (ID: 101) - debe rechazar
3) Opción 1: Intentar ID inválido (ID: -5 o 99999) - debe rechazar
4) Opción 1: Agregar libro válido (ID: 102, Título: "Algoritmos", Autor: "Ana López", Año: 2021)
5) Opción 3: Agregar usuario (ID: 1, Nombre: "Carlos Ruiz", Carrera: "Ingeniería")
6) Opción 6: Prestar libro inexistente - debe mostrar error
7) Opción 6: Prestar libro válido (Usuario: 1, Libro: 101)
8) Opción 6: Intentar prestar mismo libro - debe rechazar (ya prestado)
9) Opción 2: Listar libros (verificar que 101 aparezca como "Prestado")
10) Opción 8: Ver préstamos activos
11) Opción 7: Devolver libro (ID: 101)
12) Opción 7: Intentar devolver libro ya devuelto - debe rechazar
13) Opción 2: Listar libros vacía antes de agregar - mensaje informativo
14) Opción 9: Guardar datos (debe crear 3 archivos .txt)
15) Reiniciar programa y verificar carga automática de los 3 archivos

Salida esperada:
- Rechazar IDs duplicados, negativos o fuera de rango
- Rechazar cadenas vacías o muy largas
- Mostrar mensaje "No hay libros registrados" en listas vacías
- Libro 101 debe cambiar de "Disponible" a "Prestado" después del préstamo
- Debe aparecer: "Usuario ID: 1 -> Libro ID: 101" en préstamos activos
- Rechazar préstamo de libro ya prestado con mensaje claro
- Rechazar devolución de libro ya disponible
- Después de devolver, libro 101 debe volver a "Disponible"
- El préstamo debe desaparecer de la lista de activos
- Mensaje de confirmación "Datos guardados exitosamente"
- Al reiniciar, los datos deben cargarse desde biblioteca.txt, usuarios.txt y prestamos.txt

Nota de autoría:
Declaro que entiendo el código entregado y puedo explicarlo:
- Sé cómo funcionan los arreglos dinámicos con new/delete
- Comprendo el uso de punteros para búsqueda y modificación de datos
- Entiendo la lógica de préstamos/devoluciones y sus validaciones
- Puedo explicar el guardado/carga de archivos con delimitadores
- Comprendo las validaciones agregadas y su importancia
- Entiendo el sistema de 3 archivos para persistencia completa de datos
- Estoy preparado para defender este código en clase
====================================================
*/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <algorithm>

using namespace std;

// ==================== COLORES ANSI ====================
#define RESET   "\033[0m"
#define BOLD    "\033[1m"
#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define YELLOW  "\033[33m"
#define CYAN    "\033[36m"

// ==================== ESTRUCTURAS ====================
struct Libro {
    int id;
    string titulo;
    string autor;
    int anio;
    bool disponible;
};

struct Usuario {
    int id;
    string nombre;
    string carrera;
};

struct Prestamo {
    int idUsuario;
    int idLibro;
};

struct BibliotecaData {
    Libro* libros;
    int cantLibros, capLibros;

    Usuario* usuarios;
    int cantUsuarios, capUsuarios;

    Prestamo* prestamos;
    int cantPrestamos, capPrestamos;
};

// ==================== PROTOTIPOS ====================
void inicializar(BibliotecaData& bib);
void liberar(BibliotecaData& bib);
void redimensionarLibros(BibliotecaData& bib);
void redimensionarUsuarios(BibliotecaData& bib);
void redimensionarPrestamos(BibliotecaData& bib);

Libro* buscarLibroPorId(BibliotecaData& bib, int id);
Usuario* buscarUsuarioPorId(BibliotecaData& bib, int id);

void agregarLibro(BibliotecaData& bib);
void listarLibros(const BibliotecaData& bib);
void agregarUsuario(BibliotecaData& bib);
void listarUsuarios(const BibliotecaData& bib);
void buscarPorTexto(const BibliotecaData& bib);
void prestarLibro(BibliotecaData& bib);
void devolverLibro(BibliotecaData& bib);
void mostrarPrestamos(const BibliotecaData& bib);

void guardarArchivo(const BibliotecaData& bib);
void cargarArchivo(BibliotecaData& bib);

// ==================== MAIN ====================
int main() {
    BibliotecaData bib;
    inicializar(bib);
    cargarArchivo(bib);

    int opcion;
    do {
        cout << BOLD << CYAN << "\n--- SISTEMA DE BIBLIOTECA UNIVERSITARIA ---" << RESET << endl;
        cout << "1. Agregar Libro        5. Buscar Libros (Texto)" << endl;
        cout << "2. Listar Libros         6. Registrar Préstamo" << endl;
        cout << "3. Agregar Usuario      7. Registrar Devolución" << endl;
        cout << "4. Listar Usuarios       8. Ver Préstamos Activos" << endl;
        cout << "9. Guardar Datos         0. Salir" << endl;
        cout << BOLD << "Seleccione: " << RESET;
        
        if (!(cin >> opcion)) {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }
        cin.ignore();

        switch (opcion) {
            case 1: agregarLibro(bib); break;
            case 2: listarLibros(bib); break;
            case 3: agregarUsuario(bib); break;
            case 4: listarUsuarios(bib); break;
            case 5: buscarPorTexto(bib); break;
            case 6: prestarLibro(bib); break;
            case 7: devolverLibro(bib); break;
            case 8: mostrarPrestamos(bib); break;
            case 9: guardarArchivo(bib); break;
            case 0: cout << "Saliendo y liberando memoria...\n"; break;
            default: cout << RED << "Opción inválida." << RESET << endl;
        }
    } while (opcion != 0);

    liberar(bib);
    return 0;
}

// ==================== IMPLEMENTACIONES ====================

void inicializar(BibliotecaData& bib) {
    bib.cantLibros = bib.cantUsuarios = bib.cantPrestamos = 0;
    bib.capLibros = bib.capUsuarios = bib.capPrestamos = 5;
    bib.libros = new Libro[bib.capLibros];
    bib.usuarios = new Usuario[bib.capUsuarios];
    bib.prestamos = new Prestamo[bib.capPrestamos];
}

void liberar(BibliotecaData& bib) {
    delete[] bib.libros;
    delete[] bib.usuarios;
    delete[] bib.prestamos;
}

// Reallocación manual (Crecimiento dinámico)
void redimensionarLibros(BibliotecaData& bib) {
    int nuevaCap = bib.capLibros * 2;
    Libro* nuevoArreglo = new Libro[nuevaCap];
    for (int i = 0; i < bib.cantLibros; i++) nuevoArreglo[i] = bib.libros[i];
    delete[] bib.libros;
    bib.libros = nuevoArreglo;
    bib.capLibros = nuevaCap;
}

void redimensionarUsuarios(BibliotecaData& bib) {
    int nuevaCap = bib.capUsuarios * 2;
    Usuario* nuevoArreglo = new Usuario[nuevaCap];
    for (int i = 0; i < bib.cantUsuarios; i++) nuevoArreglo[i] = bib.usuarios[i];
    delete[] bib.usuarios;
    bib.usuarios = nuevoArreglo;
    bib.capUsuarios = nuevaCap;
}

void redimensionarPrestamos(BibliotecaData& bib) {
    int nuevaCap = bib.capPrestamos * 2;
    Prestamo* nuevoArreglo = new Prestamo[nuevaCap];
    for (int i = 0; i < bib.cantPrestamos; i++) nuevoArreglo[i] = bib.prestamos[i];
    delete[] bib.prestamos;
    bib.prestamos = nuevoArreglo;
    bib.capPrestamos = nuevaCap;
}

Libro* buscarLibroPorId(BibliotecaData& bib, int id) {
    for (int i = 0; i < bib.cantLibros; i++) {
        if (bib.libros[i].id == id) return &bib.libros[i];
    }
    return nullptr;
}

Usuario* buscarUsuarioPorId(BibliotecaData& bib, int id) {
    for (int i = 0; i < bib.cantUsuarios; i++) {
        if (bib.usuarios[i].id == id) return &bib.usuarios[i];
    }
    return nullptr;
}

void agregarLibro(BibliotecaData& bib) {
    if (bib.cantLibros >= bib.capLibros) redimensionarLibros(bib);
    Libro l;
    
    // Validación de ID
    cout << "ID Libro (1-9999): "; 
    while (!(cin >> l.id) || l.id < 1 || l.id > 9999) {
        cout << RED << "Error: ID debe ser entre 1 y 9999." << RESET << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "ID Libro (1-9999): ";
    }
    cin.ignore();
    
    if (buscarLibroPorId(bib, l.id)) {
        cout << RED << "Error: ID ya existe." << RESET << endl; 
        return;
    }
    
    // Validación de título
    cout << "Título (máx 50 caracteres): "; 
    getline(cin, l.titulo);
    if (l.titulo.length() > 50 || l.titulo.empty()) {
        cout << RED << "Error: Título inválido." << RESET << endl;
        return;
    }
    
    // Validación de autor
    cout << "Autor (máx 30 caracteres): "; 
    getline(cin, l.autor);
    if (l.autor.length() > 30 || l.autor.empty()) {
        cout << RED << "Error: Autor inválido." << RESET << endl;
        return;
    }
    
    // Validación de año
    cout << "Año (1500-2026): "; 
    while (!(cin >> l.anio) || l.anio < 1500 || l.anio > 2026) {
        cout << RED << "Error: Año debe estar entre 1500 y 2026." << RESET << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Año (1500-2026): ";
    }
    
    l.disponible = true;
    bib.libros[bib.cantLibros++] = l;
    cout << GREEN << "Libro agregado exitosamente." << RESET << endl;
}

void listarLibros(const BibliotecaData& bib) {
    if (bib.cantLibros == 0) {
        cout << YELLOW << "No hay libros registrados." << RESET << endl;
        return;
    }
    cout << left << setw(5) << "ID" << setw(20) << "TITULO" << setw(15) << "AUTOR" << "ESTADO" << endl;
    for (int i = 0; i < bib.cantLibros; i++) {
        cout << left << setw(5) << bib.libros[i].id << setw(20) << bib.libros[i].titulo << setw(15) << bib.libros[i].autor 
             << (bib.libros[i].disponible ? "Disponible" : "Prestado") << endl;
    }
}

void agregarUsuario(BibliotecaData& bib) {
    if (bib.cantUsuarios >= bib.capUsuarios) redimensionarUsuarios(bib);
    Usuario u;
    
    // Validación de ID
    cout << "ID Usuario (1-9999): "; 
    while (!(cin >> u.id) || u.id < 1 || u.id > 9999) {
        cout << RED << "Error: ID debe ser entre 1 y 9999." << RESET << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "ID Usuario (1-9999): ";
    }
    cin.ignore();
    
    if (buscarUsuarioPorId(bib, u.id)) {
        cout << RED << "Error: ID de usuario ya existe." << RESET << endl;
        return;
    }
    
    // Validación de nombre
    cout << "Nombre (máx 40 caracteres): "; 
    getline(cin, u.nombre);
    if (u.nombre.length() > 40 || u.nombre.empty()) {
        cout << RED << "Error: Nombre inválido." << RESET << endl;
        return;
    }
    
    // Validación de carrera
    cout << "Carrera (máx 35 caracteres): "; 
    getline(cin, u.carrera);
    if (u.carrera.length() > 35 || u.carrera.empty()) {
        cout << RED << "Error: Carrera inválida." << RESET << endl;
        return;
    }
    
    bib.usuarios[bib.cantUsuarios++] = u;
    cout << GREEN << "Usuario agregado exitosamente." << RESET << endl;
}

void listarUsuarios(const BibliotecaData& bib) {
    if (bib.cantUsuarios == 0) {
        cout << YELLOW << "No hay usuarios registrados." << RESET << endl;
        return;
    }
    for (int i = 0; i < bib.cantUsuarios; i++) {
        cout << "ID: " << bib.usuarios[i].id << " | Nombre: " << bib.usuarios[i].nombre << " | Carrera: " << bib.usuarios[i].carrera << endl;
    }
}

void buscarPorTexto(const BibliotecaData& bib) {
    if (bib.cantLibros == 0) {
        cout << YELLOW << "No hay libros registrados." << RESET << endl;
        return;
    }
    string busqueda;
    cout << "Texto a buscar: "; 
    getline(cin, busqueda);
    
    if (busqueda.empty()) {
        cout << RED << "Búsqueda vacía." << RESET << endl;
        return;
    }
    
    bool encontrado = false;
    for (int i = 0; i < bib.cantLibros; i++) {
        if (bib.libros[i].titulo.find(busqueda) != string::npos || bib.libros[i].autor.find(busqueda) != string::npos) {
            cout << "- " << bib.libros[i].titulo << " (" << bib.libros[i].autor << ")" << endl;
            encontrado = true;
        }
    }
    
    if (!encontrado) {
        cout << YELLOW << "No se encontraron resultados." << RESET << endl;
    }
}

void prestarLibro(BibliotecaData& bib) {
    if (bib.cantLibros == 0 || bib.cantUsuarios == 0) {
        cout << RED << "Debe haber libros y usuarios registrados." << RESET << endl;
        return;
    }
    
    int idU, idL;
    cout << "ID Usuario: "; 
    while (!(cin >> idU) || idU < 1) {
        cout << RED << "ID inválido." << RESET << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "ID Usuario: ";
    }
    
    cout << "ID Libro: "; 
    while (!(cin >> idL) || idL < 1) {
        cout << RED << "ID inválido." << RESET << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "ID Libro: ";
    }
    
    Libro* l = buscarLibroPorId(bib, idL);
    Usuario* u = buscarUsuarioPorId(bib, idU);
    
    if (!u) {
        cout << RED << "Usuario no encontrado." << RESET << endl;
        return;
    }
    if (!l) {
        cout << RED << "Libro no encontrado." << RESET << endl;
        return;
    }
    if (!l->disponible) {
        cout << RED << "Libro no disponible (ya prestado)." << RESET << endl;
        return;
    }
    
    if (bib.cantPrestamos >= bib.capPrestamos) redimensionarPrestamos(bib);
    l->disponible = false;
    bib.prestamos[bib.cantPrestamos++] = {idU, idL};
    cout << GREEN << "Préstamo registrado exitosamente." << RESET << endl;
}

void devolverLibro(BibliotecaData& bib) {
    if (bib.cantPrestamos == 0) {
        cout << YELLOW << "No hay préstamos activos." << RESET << endl;
        return;
    }
    
    int idL;
    cout << "ID Libro a devolver: "; 
    while (!(cin >> idL) || idL < 1) {
        cout << RED << "ID inválido." << RESET << endl;
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "ID Libro a devolver: ";
    }
    
    Libro* l = buscarLibroPorId(bib, idL);
    
    if (!l) {
        cout << RED << "Libro no encontrado." << RESET << endl;
        return;
    }
    
    if (l->disponible) {
        cout << RED << "Este libro no está prestado." << RESET << endl;
        return;
    }
    
    l->disponible = true;
    for (int i = 0; i < bib.cantPrestamos; i++) {
        if (bib.prestamos[i].idLibro == idL) {
            bib.prestamos[i] = bib.prestamos[bib.cantPrestamos - 1];
            bib.cantPrestamos--;
            break;
        }
    }
    cout << GREEN << "Libro devuelto exitosamente." << RESET << endl;
}

void mostrarPrestamos(const BibliotecaData& bib) {
    if (bib.cantPrestamos == 0) {
        cout << YELLOW << "No hay préstamos activos." << RESET << endl;
        return;
    }
    cout << BOLD << "Préstamos activos:" << RESET << endl;
    for (int i = 0; i < bib.cantPrestamos; i++) {
        cout << "Usuario ID: " << bib.prestamos[i].idUsuario << " -> Libro ID: " << bib.prestamos[i].idLibro << endl;
    }
}

void guardarArchivo(const BibliotecaData& bib) {
    // Guardar libros en biblioteca.txt
    ofstream fLibros("biblioteca.txt");
    if (!fLibros) {
        cout << RED << "Error al abrir archivo de libros." << RESET << endl;
        return;
    }
    fLibros << bib.cantLibros << endl;
    for (int i = 0; i < bib.cantLibros; i++) {
        fLibros << bib.libros[i].id << "|" 
                << bib.libros[i].titulo << "|" 
                << bib.libros[i].autor << "|" 
                << bib.libros[i].anio << "|" 
                << bib.libros[i].disponible << endl;
    }
    fLibros.close();
    
    // Guardar usuarios en usuarios.txt
    ofstream fUsuarios("usuarios.txt");
    if (!fUsuarios) {
        cout << RED << "Error al abrir archivo de usuarios." << RESET << endl;
        return;
    }
    fUsuarios << bib.cantUsuarios << endl;
    for (int i = 0; i < bib.cantUsuarios; i++) {
        fUsuarios << bib.usuarios[i].id << "|" 
                  << bib.usuarios[i].nombre << "|" 
                  << bib.usuarios[i].carrera << endl;
    }
    fUsuarios.close();
    
    // Guardar préstamos en prestamos.txt
    ofstream fPrestamos("prestamos.txt");
    if (!fPrestamos) {
        cout << RED << "Error al abrir archivo de préstamos." << RESET << endl;
        return;
    }
    fPrestamos << bib.cantPrestamos << endl;
    for (int i = 0; i < bib.cantPrestamos; i++) {
        fPrestamos << bib.prestamos[i].idUsuario << "|" 
                   << bib.prestamos[i].idLibro << endl;
    }
    fPrestamos.close();
    
    cout << GREEN << "Datos guardados exitosamente." << RESET << endl;
}

void cargarArchivo(BibliotecaData& bib) {
    // Cargar libros desde biblioteca.txt
    ifstream fLibros("biblioteca.txt");
    if (fLibros) {
        int cant; 
        fLibros >> cant;
        if (cant >= 0 && cant <= 10000) {
            for (int i = 0; i < cant; i++) {
                if (bib.cantLibros >= bib.capLibros) redimensionarLibros(bib);
                Libro l;
                fLibros >> l.id; fLibros.ignore();
                getline(fLibros, l.titulo, '|');
                getline(fLibros, l.autor, '|');
                fLibros >> l.anio; fLibros.ignore();
                fLibros >> l.disponible;
                bib.libros[bib.cantLibros++] = l;
            }
        }
        fLibros.close();
    }
    
    // Cargar usuarios desde usuarios.txt
    ifstream fUsuarios("usuarios.txt");
    if (fUsuarios) {
        int cant;
        fUsuarios >> cant;
        if (cant >= 0 && cant <= 10000) {
            for (int i = 0; i < cant; i++) {
                if (bib.cantUsuarios >= bib.capUsuarios) redimensionarUsuarios(bib);
                Usuario u;
                fUsuarios >> u.id; fUsuarios.ignore();
                getline(fUsuarios, u.nombre, '|');
                getline(fUsuarios, u.carrera);
                bib.usuarios[bib.cantUsuarios++] = u;
            }
        }
        fUsuarios.close();
    }
    
    // Cargar préstamos desde prestamos.txt
    ifstream fPrestamos("prestamos.txt");
    if (fPrestamos) {
        int cant;
        fPrestamos >> cant;
        if (cant >= 0 && cant <= 10000) {
            for (int i = 0; i < cant; i++) {
                if (bib.cantPrestamos >= bib.capPrestamos) redimensionarPrestamos(bib);
                Prestamo p;
                fPrestamos >> p.idUsuario; fPrestamos.ignore();
                fPrestamos >> p.idLibro;
                bib.prestamos[bib.cantPrestamos++] = p;
            }
        }
        fPrestamos.close();
    }
}
