Funcion prom <- calcularPromedio(arr, tam)
    Definir prom, suma como Real
    Definir i como Entero
    suma <- 0
    Para i <- 1 Hasta tam Hacer
        suma <- suma + arr[i]
    FinPara
    prom <- suma / tam
FinFuncion

Algoritmo ejercicio4
    Definir tam, i como Entero
    Definir promedio como Real
    
    Escribir "Ingrese la cantidad de notas: "
    Leer tam
    
    Dimension notas[tam]
    
    Escribir "Ingrese las notas:"
    Para i <- 1 Hasta tam Hacer
        Escribir "Nota ", i, ": "
        Leer notas[i]
    FinPara
    
    promedio <- calcularPromedio(notas, tam)
    
    Escribir "El promedio es: ", promedio
FinAlgoritmo