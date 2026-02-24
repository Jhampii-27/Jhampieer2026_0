Funcion res <- calcularFactorial(n)
    Definir res, i como Entero
    res <- 1
    Para i <- 1 Hasta n Con Paso 1 Hacer
        res <- res * i
    FinPara
FinFuncion

Algoritmo ejercicio8
    Definir num, resultado como Entero
    
    Escribir "Ingrese un numero para calcular su factorial: "
    Leer num
    
    resultado <- calcularFactorial(num)
    
    Escribir "El factorial de ", num, " es: ", resultado
FinAlgoritmo