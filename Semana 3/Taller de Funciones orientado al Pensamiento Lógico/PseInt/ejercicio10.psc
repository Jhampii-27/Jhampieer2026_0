Funcion ordenado <- estaOrdenadoAscendente(arr, tam)
    Definir ordenado como Logico
    Definir i como Entero
    ordenado <- Verdadero
    Para i <- 1 Hasta tam - 1 Hacer
        Si arr[i] > arr[i + 1] Entonces
            ordenado <- Falso
        FinSi
    FinPara
FinFuncion

Algoritmo ejercicio10
    Definir tam, i como Entero
    
    Escribir "Ingrese el tamanio del arreglo: "
    Leer tam
    
    Dimension arreglo[tam]
    
    Escribir "Ingrese los elementos:"
    Para i <- 1 Hasta tam Hacer
        Escribir "Elemento ", i, ": "
        Leer arreglo[i]
    FinPara
    
    Si estaOrdenadoAscendente(arreglo, tam) Entonces
        Escribir "El arreglo SI esta ordenado de forma ascendente"
    Sino
        Escribir "El arreglo NO esta ordenado de forma ascendente"
    FinSi
FinAlgoritmo