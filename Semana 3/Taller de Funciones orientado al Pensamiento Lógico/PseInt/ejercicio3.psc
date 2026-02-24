Funcion total <- sumarArreglo(arr, tam)
    Definir total, i como Entero
    total <- 0
    Para i <- 1 Hasta tam Hacer
        total <- total + arr[i]
    FinPara
FinFuncion

Algoritmo ejercicio3
    Definir tam, i, resultado como Entero
    
    Escribir "Ingrese el tamanio del arreglo: "
    Leer tam
    
    Dimension arreglo[tam]
    
    Escribir "Ingrese los elementos:"
    Para i <- 1 Hasta tam Hacer
        Escribir "Elemento ", i, ": "
        Leer arreglo[i]
    FinPara
    
    resultado <- sumarArreglo(arreglo, tam)
    
    Escribir "La suma total es: ", resultado
FinAlgoritmo