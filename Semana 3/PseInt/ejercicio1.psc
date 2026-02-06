Funcion mayor <- obtenerMayor(a, b)
    Si a > b Entonces
        mayor <- a
    Sino
        mayor <- b
    FinSi
FinFuncion

Algoritmo ejercicio1
    Definir num1, num2, mayor como Entero
    
    Escribir "Ingrese el primer numero: "
    Leer num1
    
    Escribir "Ingrese el segundo numero: "
    Leer num2
    
    mayor <- obtenerMayor(num1, num2)
    
    Escribir "El mayor es: ", mayor
FinAlgoritmo