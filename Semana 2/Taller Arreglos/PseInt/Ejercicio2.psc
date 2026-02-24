Algoritmo Ejercicio2
    Definir num, i, conttempmax, conttempmin, mayor30 Como Entero
    Definir tempmax, tempmin Como Real
    
    Repetir
        Escribir "Ingrese un numero entero positivo: "
        Leer num
        Si num <= 0 Entonces
            Escribir "Intente nuevamente."
        FinSi
    Hasta Que num > 0
    
    Dimension temperatura[num]
    
    Para i <- 1 Hasta num Hacer
        Escribir "Ingrese la ", i, " temperatura: "
        Leer temperatura[i]
    FinPara
    
    Escribir Sin Saltar "["
    Para i <- 1 Hasta num Hacer
        Escribir Sin Saltar temperatura[i]
        Si i < num Entonces
            Escribir Sin Saltar ", "
        FinSi
    FinPara
    Escribir "]"
    
    tempmax <- temperatura[1]
    tempmin <- temperatura[1]
    conttempmax <- 1
    conttempmin <- 1
    
    Para i <- 1 Hasta num Hacer
        Si temperatura[i] > tempmax Entonces
            tempmax <- temperatura[i]
            conttempmax <- i
        FinSi
        Si temperatura[i] < tempmin Entonces
            tempmin <- temperatura[i]
            conttempmin <- i
        FinSi
    FinPara
    
    Escribir "Maxima: ", tempmax, " (dia ", conttempmax, ")"
    Escribir "Minima: ", tempmin, " (dia ", conttempmin, ")"
    
    mayor30 <- 0
    Para i <- 1 Hasta num Hacer
        Si temperatura[i] > 30 Entonces
            mayor30 <- mayor30 + 1
        FinSi
    FinPara
    
    Si mayor30 = 0 Entonces
        Escribir "No existe temperatura mayor a 30."
    Sino
        Escribir "Dias mayores a 30: ", mayor30
    FinSi
    
FinAlgoritmo