Funcion minimo <- obtenerMinimo(arr, tam)
    Definir minimo, i como Entero
    minimo <- arr[1]
    Para i <- 2 Hasta tam Hacer
        Si arr[i] < minimo Entonces
            minimo <- arr[i]
        FinSi
    FinPara
FinFuncion

Algoritmo ejercicio6
    Definir tam, i, valorMin como Entero
    
    Escribir "Ingrese el tamanio del arreglo: "
    Leer tam
    
    Dimension arreglo[tam]
    
    Escribir "Ingrese los elementos:"
    Para i <- 1 Hasta tam Hacer
        Escribir "Elemento ", i, ": "
        Leer arreglo[i]
    FinPara
    
    valorMin <- obtenerMinimo(arreglo, tam)
    
    Escribir "El valor minimo es: ", valorMin
FinAlgoritmo