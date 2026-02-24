// Actividad 6 - Polimorfismo basico (parte opcional)
// Agrego el metodo virtual rol() y lo sobreescribo en cada clase derivada

#include <iostream>
#include <string>
using namespace std;

class Persona {
private:
    string nombre;
    int edad;

public:
    Persona(string nombre, int edad) : nombre(nombre), edad(edad) {}

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }

    void mostrar() const {
        cout << "Nombre: " << nombre << " | Edad: " << edad << endl;
    }

    // Metodo virtual para polimorfismo
    virtual void rol() const {
        cout << "Soy una persona." << endl;
    }
};

class Estudiante : public Persona {
private:
    string carrera;
public:
    Estudiante(string nombre, int edad, string carrera)
        : Persona(nombre, edad), carrera(carrera) {}

    void rol() const override {
        cout << "Soy estudiante de " << carrera << "." << endl;
    }
};

class Profesor : public Persona {
private:
    string materia;
public:
    Profesor(string nombre, int edad, string materia)
        : Persona(nombre, edad), materia(materia) {}

    void rol() const override {
        cout << "Soy profesor de " << materia << "." << endl;
    }
};

int main() {
    // Arreglo de punteros a Persona
    Persona* personas[2];
    personas[0] = new Estudiante("Jhampieer Aron", 21, "Soporte de TI");
    personas[1] = new Profesor("Christian Garcia", 38, "Programacion");

    // Recorro el arreglo y llamo rol() - cada objeto responde distinto
    for (int i = 0; i < 2; i++) {
        personas[i]->mostrar();
        personas[i]->rol();
        cout << "---" << endl;
    }

    // Libero la memoria
    delete personas[0];
    delete personas[1];

    return 0;
}
