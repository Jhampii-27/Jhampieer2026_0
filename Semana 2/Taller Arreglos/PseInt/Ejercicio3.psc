Algoritmo Ejercicio3
	Definir estudiante, i, j, total, totalasistencias Como Entero
	Definir hayperfectos Como Logico
	
	Escribir "Ingrese cuantos estudiantes desea registrar: "
	Leer estudiante
	
	Dimension asistencia[estudiante, 5]

	Para i <- 1 Hasta estudiante Hacer
		Escribir "Estudiante: ", i
		Para j <- 1 Hasta 5 Hacer
			Repetir
				Escribir "Elemento [", i-1, "] [", j-1, "]: "
				Leer asistencia[i, j]
				Si asistencia[i, j] <> 1 Y asistencia[i, j] <> 0 Entonces
					Escribir "Intentelo de nuevo solo (0 y 1)"
				FinSi
			Hasta Que asistencia[i, j] = 1 O asistencia[i, j] = 0
		FinPara
	FinPara
	
	hayperfectos <- Falso
	Para i <- 1 Hasta estudiante Hacer
		total <- 0
		Para j <- 1 Hasta 5 Hacer
			total <- total + asistencia[i, j]
		FinPara
		
		Escribir "Estudiante: ", i, " (", total, " dias de asistencia)"
		
		Si total = 5 Entonces
			Escribir "Estudiante ", i, " con asistencias perfectas."
			hayperfectos <- Verdadero
		FinSi
	FinPara
	
	Si No hayperfectos Entonces
		Escribir "No hay Ningun estudiante con asistencia perfecta."
	FinSi

	totalasistencias <- 0
	Para i <- 1 Hasta estudiante Hacer
		Para j <- 1 Hasta 5 Hacer
			totalasistencias <- totalasistencias + asistencia[i, j]
		FinPara
	FinPara
	
	Escribir "El total de asistencias es: ", totalasistencias
	
	Para i <- 1 Hasta estudiante Hacer
		Para j <- 1 Hasta 5 Hacer
			Escribir Sin Saltar asistencia[i, j], " "
		FinPara
		Escribir "" 
	FinPara
	
FinAlgoritmo