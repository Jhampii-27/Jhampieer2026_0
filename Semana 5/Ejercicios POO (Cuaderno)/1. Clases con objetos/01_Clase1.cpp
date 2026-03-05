#include <iostream>
using namespace std;

class Clase1{
    int valor;
public:
    Clase1(int v):valor(v){}
    void mostrar(){ 
        cout<<"Ejercicio 1 Valor: "<<valor; 
    }
};

int main(){
    Clase1 obj(10);
    obj.mostrar();
}