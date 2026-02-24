Funcion encontrado <- buscarValor(arr, tam, valor)
    Definir encontrado como Logico
    Definir i como Entero
    encontrado <- Falso
    Para i <- 1 Hasta tam Hacer
        Si arr[i] = valor Entonces
            encontrado <- Verdadero
        FinSi
    FinPara
FinFuncion

Algoritmo ejercicio9
    Definir tam, valorBuscar, i como Entero
    
    Escribir "Ingrese el tamanio del arreglo: "
    Leer tam
    
    Dimension arreglo[tam]
    
    Escribir "Ingrese los elementos:"
    Para i <- 1 Hasta tam Hacer
        Escribir "Elemento ", i, ": "
        Leer arreglo[i]
    FinPara
    
    Escribir "Ingrese el valor a buscar: "
    Leer valorBuscar
    
    Si buscarValor(arreglo, tam, valorBuscar) Entonces
        Escribir "El valor SI existe en el arreglo"
    Sino
        Escribir "El valor NO existe en el arreglo"
    FinSi
FinAlgoritmo