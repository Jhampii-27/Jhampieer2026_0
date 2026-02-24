Algoritmo Ejercicio1
    Definir N, num, i, j Como Entero
    Definir maximo, minimo Como Entero
    Definir cantidadPrimos Como Entero
    Definir sumaPositivosPares, cantPositivosPares Como Entero
    Definir mayorMasImpares Como Entero
    Definir existeMayorMasImpares, esPrimo Como Logico
    Definir digitosImpares, digitosPares, temp, auxTemp, digito Como Entero
    Definir promedio Como Real
    
    Repetir
        Escribir "Ingrese N (N >= 1): " Sin Saltar
        Leer N
    Hasta Que N >= 1
    
    cantidadPrimos <- 0
    sumaPositivosPares <- 0
    cantPositivosPares <- 0
    existeMayorMasImpares <- Falso
    
    Para i <- 1 Hasta N Con Paso 1 Hacer
        Escribir "Ingrese numero ", i, ": " Sin Saltar
        Leer num
        
        Si i = 1 Entonces
            maximo <- num
            minimo <- num
        SiNo
            Si num > maximo Entonces
                maximo <- num
            FinSi
            Si num < minimo Entonces
                minimo <- num
            FinSi
        FinSi
        
        esPrimo <- Verdadero
        Si num < 2 Entonces
            esPrimo <- Falso
        SiNo
            Si num = 2 Entonces
                esPrimo <- Verdadero
            SiNo
                Si num MOD 2 = 0 Entonces
                    esPrimo <- Falso
                SiNo
                    Para j <- 3 Hasta trunc(rc(num)) Con Paso 2 Hacer
                        Si num MOD j = 0 Entonces
                            esPrimo <- Falso
                        FinSi
                    FinPara
                FinSi
            FinSi
        FinSi
        
        Si esPrimo Entonces
            cantidadPrimos <- cantidadPrimos + 1
        FinSi
        
        Si num > 0 Y num MOD 2 = 0 Entonces
            sumaPositivosPares <- sumaPositivosPares + num
            cantPositivosPares <- cantPositivosPares + 1
        FinSi
        
        temp <- num
        Si temp < 0 Entonces
            temp <- temp * (-1)
        FinSi
        
        digitosImpares <- 0
        digitosPares <- 0
        auxTemp <- temp
        
        Mientras auxTemp > 0 Hacer
            digito <- auxTemp MOD 10
            Si digito MOD 2 = 0 Entonces
                digitosPares <- digitosPares + 1
            SiNo
                digitosImpares <- digitosImpares + 1
            FinSi
            auxTemp <- trunc(auxTemp / 10)
        FinMientras
        
        Si digitosImpares > digitosPares Entonces
            Si NO existeMayorMasImpares O num > mayorMasImpares Entonces
                mayorMasImpares <- num
                existeMayorMasImpares <- Verdadero
            FinSi
        FinSi
    FinPara
    
    Escribir ""
    Escribir "RESULTADOS:"
    Escribir "Maximo: ", maximo
    Escribir "Minimo: ", minimo
    
    Si cantidadPrimos = 0 Entonces
        Escribir "Cantidad de primos: NO EXISTE"
    SiNo
        Escribir "Cantidad de primos: ", cantidadPrimos
    FinSi
    
    Si cantPositivosPares = 0 Entonces
        Escribir "Promedio de positivos pares: NO EXISTE"
    SiNo
        promedio <- sumaPositivosPares / cantPositivosPares
        Escribir "Promedio de positivos pares: ", promedio
    FinSi
    
    Si NO existeMayorMasImpares Entonces
        Escribir "Mayor con mas digitos impares que pares: NO EXISTE"
    SiNo
        Escribir "Mayor con mas digitos impares que pares: ", mayorMasImpares
    FinSi
FinAlgoritmo

