Algoritmo Ejercicio2
    Definir M, i, x Como Entero
    Definir temp, sumaDigitos, auxSuma Como Entero
    Definir cantDigitos, auxCant Como Entero
    
    Repetir
        Escribir "Ingrese M (M >= 1): " Sin Saltar
        Leer M
    Hasta Que M >= 1
    
    Para i <- 1 Hasta M Con Paso 1 Hacer
        Escribir "Ingrese x: " Sin Saltar
        Leer x
        
        temp <- x
        Si temp < 0 Entonces
            temp <- temp * (-1)
        FinSi
        
        sumaDigitos <- 0
        auxSuma <- temp
        Mientras auxSuma > 0 Hacer
            sumaDigitos <- sumaDigitos + (auxSuma MOD 10)
            auxSuma <- trunc(auxSuma / 10)
        FinMientras
        
        cantDigitos <- 0
        Si temp = 0 Entonces
            cantDigitos <- 1
        SiNo
            auxCant <- temp
            Mientras auxCant > 0 Hacer
                cantDigitos <- cantDigitos + 1
                auxCant <- trunc(auxCant / 10)
            FinMientras
        FinSi
        
        Si sumaDigitos MOD 2 = 0 Y x MOD 4 = 0 Entonces
            Escribir "A"
        SiNo
            Si sumaDigitos MOD 2 <> 0 Y x MOD 6 = 0 Entonces
                Escribir "B"
            SiNo
                Si cantDigitos = 3 Entonces
                    Escribir "C"
                SiNo
                    Escribir "D"
                FinSi
            FinSi
        FinSi
    FinPara
FinAlgoritmo
