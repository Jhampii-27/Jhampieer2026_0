#include <iostream>
#include <iomanip>
#include <cstring>
#include <limits>

using namespace std;

struct Producto {
    int codigo, stock;
    char nombre[51];
    float precio;
};

const int MAX_P = 100;

// Utilidad para limpiar buffer y pausar
void limpiar() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
void pausar() {
    cout << "\n[ENTER]";
    limpiar();
}

// Lectura validada
template<typename T>
T leer(const char* m, T min, T max) {
    T v;
    while (true) {
        cout << m;
        if (cin >> v && v >= min && v <= max) return v;
        cout << "Invalido. ";
        limpiar();
    }
}

// Mostrar producto
void printP(Producto p) {
    cout << "ID: " << p.codigo << " | "
         << setw(20) << left << p.nombre
         << " | $"
         << setw(8) << fixed << setprecision(2) << p.precio
         << " | Cant: " << p.stock << endl;
}

// Registro
void registrar(Producto p[], int &n) {
    int minReq = (n == 0) ? 5 : 1;
    int cant = leer("\n¿Cuantos? ", minReq, MAX_P - n);

    for (int i = 0; i < cant; i++) {
        int nuevoCod;
        bool repetido;
        do {
            repetido = false;
            nuevoCod = leer("Codigo (1000-9999): ", 1000, 9999);
            for (int j = 0; j < n; j++) {
                if (p[j].codigo == nuevoCod) {
                    cout << "Ya existe. ";
                    repetido = true;
                    break;
                }
            }
        } while (repetido);

        p[n].codigo = nuevoCod;
        cout << "Nombre: ";
        limpiar();
        cin.getline(p[n].nombre, 51);

        p[n].precio = leer("Precio: ", 0.1f, 1000000.0f);
        p[n].stock  = leer("Stock: ", 0, 10000);
        n++;
    }
}

// Listar
void listar(Producto p[], int n) {
    if (!n) {
        cout << "Vacio\n";
        return;
    }
    for (int i = 0; i < n; i++) printP(p[i]);
    pausar();
}

// Buscar
void buscar(Producto p[], int n, bool porCodigo) {
    if (porCodigo) {
        int c = leer("Cod a buscar: ", 1000, 9999);
        for (int i = 0; i < n; i++)
            if (p[i].codigo == c)
                return (void)(printP(p[i]), pausar());
    } else {
        cout << "Nombre: ";
        limpiar();
        char nom[51];
        cin.getline(nom, 51);
        for (int i = 0; i < n; i++)
            if (strcmp(p[i].nombre, nom) == 0)
                return (void)(printP(p[i]), pausar());
    }
    cout << "No encontrado\n";
    pausar();
}

// Reportes
void reporteTop(Producto p[], int n, bool esPrecio) {
    if (!n) return;
    int idx = 0;
    for (int i = 1; i < n; i++)
        if (esPrecio ? p[i].precio > p[idx].precio
                     : p[i].stock  > p[idx].stock)
            idx = i;

    cout << (esPrecio ? "MAS CARO:\n" : "MAYOR STOCK:\n");
    printP(p[idx]);
    pausar();
}

// Valor total inventario
void valorTotalInventario(Producto p[], int n) {
    if (!n) {
        cout << "No hay productos registrados\n";
        pausar();
        return;
    }

    float total = 0;
    for (int i = 0; i < n; i++)
        total += p[i].precio * p[i].stock;

    cout << "VALOR TOTAL DEL INVENTARIO: $"
         << fixed << setprecision(2) << total << endl;
    pausar();
}

/* ================== RETO ================== */

// OPCIÓN 9: Ordenar por precio (mayor a menor)
void ordenarPorPrecio(Producto p[], int n) {
    Producto aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (p[i].precio < p[j].precio) {
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }
    cout << "Productos ordenados por precio (mayor a menor)\n";
    listar(p, n);
}

// OPCIÓN 10: Ordenar por nombre (A-Z)
void ordenarPorNombre(Producto p[], int n) {
    Producto aux;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (strcmp(p[i].nombre, p[j].nombre) > 0) {
                aux = p[i];
                p[i] = p[j];
                p[j] = aux;
            }
        }
    }
    cout << "Productos ordenados por nombre (A-Z)\n";
    listar(p, n);
}

int main() {
    Producto productos[MAX_P];
    int n = 0, op;

    do {
        cout << "\n1.Reg 2.Listar 3.Busq.Cod 4.Busq.Nom "
             << "5.Top Precio 6.Top Stock 7.Valor Inventario "
             << "9.Ordenar Precio 10.Ordenar Nombre 0.Salir\nSel: ";
        cin >> op;

        if (op == 1) registrar(productos, n);
        if (op == 2) listar(productos, n);
        if (op == 3) buscar(productos, n, true);
        if (op == 4) buscar(productos, n, false);
        if (op == 5) reporteTop(productos, n, true);
        if (op == 6) reporteTop(productos, n, false);
        if (op == 7) valorTotalInventario(productos, n);
        if (op == 9) ordenarPorPrecio(productos, n);
        if (op == 10) ordenarPorNombre(productos, n);

    } while (op != 0);

    return 0;
}
