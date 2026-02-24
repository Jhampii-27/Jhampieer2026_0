Funcion esValida <- validarOpcionMenu(opcion, minimo, maximo)
    Si opcion >= minimo Y opcion <= maximo Entonces
        esValida <- Verdadero
    Sino
        esValida <- Falso
    FinSi
FinFuncion

Algoritmo ejercicio8
    Definir opcion, min, max como Entero
    
    Escribir "Ingrese el rango minimo: "
    Leer min
    
    Escribir "Ingrese el rango maximo: "
    Leer max
    
    Escribir "Ingrese la opcion a validar: "
    Leer opcion
    
    Si validarOpcionMenu(opcion, min, max) Entonces
        Escribir "La opcion es VALIDA"
    Sino
        Escribir "La opcion es INVALIDA"
    FinSi
FinAlgoritmo