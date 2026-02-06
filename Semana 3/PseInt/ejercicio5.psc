Funcion maximo <- obtenerMaximo(arr, tam)
    Definir maximo, i como Entero
    maximo <- arr[1]
    Para i <- 2 Hasta tam Hacer
        Si arr[i] > maximo Entonces
            maximo <- arr[i]
        FinSi
    FinPara
FinFuncion

Algoritmo ejercicio5
    Definir tam, i, valorMax como Entero
    
    Escribir "Ingrese el tamanio del arreglo: "
    Leer tam
    
    Dimension arreglo[tam]
    
    Escribir "Ingrese los elementos:"
    Para i <- 1 Hasta tam Hacer
        Escribir "Elemento ", i, ": "
        Leer arreglo[i]
    FinPara
    
    valorMax <- obtenerMaximo(arreglo, tam)
    
    Escribir "El valor maximo es: ", valorMax
FinAlgoritmo