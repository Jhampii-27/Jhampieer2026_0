Funcion resultado <- esPar(numero)
    Si numero MOD 2 = 0 Entonces
        resultado <- Verdadero
    Sino
        resultado <- Falso
    FinSi
FinFuncion

Algoritmo ejercicio2
    Definir num como Entero
    
    Escribir "Ingrese un numero: "
    Leer num
    
    Si esPar(num) Entonces
        Escribir "El numero es PAR"
    Sino
        Escribir "El numero es IMPAR"
    FinSi
FinAlgoritmo