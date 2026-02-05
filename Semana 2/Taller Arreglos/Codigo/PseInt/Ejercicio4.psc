Algoritmo Ejercicio4
	Definir dia, i, rachaactual, rachamax Como Entero
	Definir balance Como Real
	
	Repetir
		Escribir "De cuantos dias va a registrar el balance diario: "
		Leer dia
		Si dia <= 0 Entonces
			Escribir "Ingrese nuevamente."
		FinSi
	Hasta Que dia > 0
	
	Dimension balance[dia]
	
	Para i <- 1 Hasta dia Hacer
		Escribir "Ingrese el balance diario de la empresa: "
		Leer balance[i]
	FinPara
	
	rachaactual <- 0
	rachamax <- 0
	
	Para i <- 1 Hasta dia Hacer
		Si balance[i] > 0 Entonces
			rachaactual <- rachaactual + 1
			Si rachaactual > rachamax Entonces
				rachamax <- rachaactual
			FinSi
		Sino
			rachaactual <- 0
		FinSi
	FinPara
	
	Escribir "Mayor racha positiva: ", rachamax, " dias."
	
FinAlgoritmo