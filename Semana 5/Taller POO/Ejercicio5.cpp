// Actividad 5 - Herencia
// Creo un sistema de personas con clase base y dos clases derivadas

#include <iostream>
#include <string>
using namespace std;

// Clase base: contiene lo comun a cualquier persona
class Persona {
private:
    string nombre;
    int edad;

public:
    Persona(string nombre, int edad) {
        this->nombre = nombre;
        if (edad >= 0)
            this->edad = edad;
        else {
            cout << "Edad invalida, se pone en 0." << endl;
            this->edad = 0;
        }
    }

    string getNombre() const { return nombre; }
    int getEdad() const { return edad; }

    void mostrar() const {
        cout << "Nombre: " << nombre << " | Edad: " << edad << " anos" << endl;
    }
};

// Clase derivada: hereda todo de Persona y agrega carrera
class Estudiante : public Persona {
private:
    string carrera;

public:
    Estudiante(string nombre, int edad, string carrera)
        : Persona(nombre, edad) {
        this->carrera = carrera;
    }

    void estudiar() const {
        cout << getNombre() << " esta estudiando " << carrera << "." << endl;
    }

    void mostrar() const {
        Persona::mostrar();
        cout << "Carrera: " << carrera << endl;
    }
};

// Clase derivada: hereda de Persona y agrega materia
class Profesor : public Persona {
private:
    string materia;

public:
    Profesor(string nombre, int edad, string materia)
        : Persona(nombre, edad) {
        this->materia = materia;
    }

    void ensenar() const {
        cout << getNombre() << " esta ensenando " << materia << "." << endl;
    }

    void mostrar() const {
        Persona::mostrar();
        cout << "Materia: " << materia << endl;
    }
};

int main() {
    Estudiante est("Jhampieer Aron", 17, "Ingenieria de Sistemas");
    Profesor prof("Christian Garcia", 38, "Programacion Orientada a Objetos");

    cout << "=== Estudiante ===" << endl;
    est.mostrar();
    est.estudiar();

    cout << endl << "=== Profesor ===" << endl;
    prof.mostrar();
    prof.ensenar();

    return 0;
}
