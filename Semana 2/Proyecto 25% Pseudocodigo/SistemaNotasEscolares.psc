Algoritmo SistemaNotasEscolares
	
    Dimension codigosEstudiantes[50]
    Dimension nombresEstudiantes[50]
    Dimension gradosEstudiantes[50]
    Dimension notas[50,5]
    Dimension cantidadNotas[50]
    Dimension promedios[50]
	
    Definir cantidadEstudiantes, opcion, i Como Entero
    cantidadEstudiantes <- 0
	
    Para i <- 1 Hasta 50 Hacer
        codigosEstudiantes[i] <- ""
        nombresEstudiantes[i] <- ""
        gradosEstudiantes[i] <- ""
        cantidadNotas[i] <- 0
        promedios[i] <- 0
    FinPara
	
    Repetir
        Limpiar Pantalla
        Escribir "================================"
        Escribir "  SISTEMA DE NOTAS ESCOLARES"
        Escribir "================================"
        Escribir "1. Registrar Estudiante"
        Escribir "2. Mostrar Estudiantes"
        Escribir "3. Ingresar Notas"
        Escribir "4. Mostrar Notas"
        Escribir "5. Calcular Promedios"
        Escribir "6. Salir"
        Escribir "================================"
        Escribir Sin Saltar "Opción: "
        Leer opcion
		
        Segun opcion Hacer
            1:
                RegistrarEstudiante(codigosEstudiantes, nombresEstudiantes, gradosEstudiantes, cantidadEstudiantes)
            2:
                MostrarEstudiantes(codigosEstudiantes, nombresEstudiantes, gradosEstudiantes, cantidadEstudiantes)
            3:
                IngresarNotas(codigosEstudiantes, notas, cantidadNotas, cantidadEstudiantes)
            4:
                MostrarNotas(codigosEstudiantes, nombresEstudiantes, notas, cantidadNotas, cantidadEstudiantes)
            5:
                CalcularPromedios(notas, cantidadNotas, promedios, cantidadEstudiantes, nombresEstudiantes)
            6:
                Escribir "Saliendo del sistema..."
            De Otro Modo:
                Escribir "Opción inválida"
        FinSegun
		
        Si opcion <> 6 Entonces
            Escribir ""
            Escribir "Presione ENTER para continuar..."
            Esperar Tecla
        FinSi
    Hasta Que opcion = 6
	
FinAlgoritmo


SubProceso RegistrarEstudiante(codigosEstudiantes Por Referencia, nombresEstudiantes Por Referencia, gradosEstudiantes Por Referencia, cantidadEstudiantes Por Referencia)
    Definir codigo, nombre, grado Como Caracter
    Definir i Como Entero
    Definir existe Como Logico
	
    Escribir "--- REGISTRAR ESTUDIANTE ---"
	
    Si cantidadEstudiantes < 50 Entonces
		
        Repetir
            Escribir Sin Saltar "Código: "
            Leer codigo
            existe <- Falso
			
            Si Longitud(codigo) = 0 Entonces
                Escribir "Error: Código vacío"
                existe <- Verdadero
            Sino
                // ?? PROTECCIÓN CLAVE
                Si cantidadEstudiantes > 0 Entonces
                    Para i <- 1 Hasta cantidadEstudiantes Hacer
                        Si codigosEstudiantes[i] = codigo Entonces
                            Escribir "Error: Código repetido"
                            existe <- Verdadero
                        FinSi
                    FinPara
                FinSi
            FinSi
			
        Hasta Que NO existe
		
        Repetir
            Escribir Sin Saltar "Nombre: "
            Leer nombre
        Hasta Que Longitud(nombre) > 0
		
        Repetir
            Escribir Sin Saltar "Grado (1-5): "
            Leer grado
        Hasta Que grado >= "1" Y grado <= "5"
		
        cantidadEstudiantes <- cantidadEstudiantes + 1
        codigosEstudiantes[cantidadEstudiantes] <- codigo
        nombresEstudiantes[cantidadEstudiantes] <- nombre
        gradosEstudiantes[cantidadEstudiantes] <- grado
		
        Escribir "? Estudiante registrado correctamente"
		
    Sino
        Escribir "Capacidad máxima alcanzada"
    FinSi
FinSubProceso


SubProceso MostrarEstudiantes(codigosEstudiantes Por Referencia, nombresEstudiantes Por Referencia, gradosEstudiantes Por Referencia, cantidadEstudiantes)
    Definir i Como Entero
    Si cantidadEstudiantes = 0 Entonces
        Escribir "No hay estudiantes"
    Sino
        Para i <- 1 Hasta cantidadEstudiantes Hacer
            Escribir codigosEstudiantes[i], " | ", nombresEstudiantes[i], " | Grado ", gradosEstudiantes[i]
        FinPara
    FinSi
FinSubProceso


SubProceso IngresarNotas(codigosEstudiantes Por Referencia, notas Por Referencia, cantidadNotas Por Referencia, cantidadEstudiantes)
    Definir codigo Como Caracter
    Definir indice, cant, i Como Entero
    Definir nota Como Real
    Definir encontrado Como Logico
	
    Escribir Sin Saltar "Código del estudiante: "
    Leer codigo
    encontrado <- Falso
	
    Para i <- 1 Hasta cantidadEstudiantes Hacer
        Si codigosEstudiantes[i] = codigo Entonces
            indice <- i
            encontrado <- Verdadero
        FinSi
    FinPara
	
    Si encontrado Entonces
        Repetir
            Escribir Sin Saltar "Cantidad de notas (1-5): "
            Leer cant
        Hasta Que cant >= 1 Y cant <= 5
		
        Para i <- 1 Hasta cant Hacer
            Repetir
                Escribir Sin Saltar "Nota ", i, " (0-20): "
                Leer nota
            Hasta Que nota >= 0 Y nota <= 20
            notas[indice,i] <- nota
        FinPara
		
        cantidadNotas[indice] <- cant
        Escribir "? Notas registradas"
    Sino
        Escribir "Estudiante no encontrado"
    FinSi
FinSubProceso


SubProceso MostrarNotas(codigosEstudiantes Por Referencia, nombresEstudiantes Por Referencia, notas Por Referencia, cantidadNotas Por Referencia, cantidadEstudiantes)
    Definir codigo Como Caracter
    Definir indice, i Como Entero
    Definir encontrado Como Logico
	
    Escribir Sin Saltar "Código del estudiante: "
    Leer codigo
    encontrado <- Falso
	
    Para i <- 1 Hasta cantidadEstudiantes Hacer
        Si codigosEstudiantes[i] = codigo Entonces
            indice <- i
            encontrado <- Verdadero
        FinSi
    FinPara
	
    Si encontrado Entonces
        Escribir "Estudiante: ", nombresEstudiantes[indice]
        Para i <- 1 Hasta cantidadNotas[indice] Hacer
            Escribir "Nota ", i, ": ", notas[indice,i]
        FinPara
    Sino
        Escribir "No encontrado"
    FinSi
FinSubProceso


SubProceso CalcularPromedios(notas Por Referencia, cantidadNotas Por Referencia, promedios Por Referencia, cantidadEstudiantes, nombresEstudiantes Por Referencia)
    Definir i, j Como Entero
    Definir suma Como Real
	
    Para i <- 1 Hasta cantidadEstudiantes Hacer
        Si cantidadNotas[i] > 0 Entonces
            suma <- 0
            Para j <- 1 Hasta cantidadNotas[i] Hacer
                suma <- suma + notas[i,j]
            FinPara
            promedios[i] <- suma / cantidadNotas[i]
            Escribir nombresEstudiantes[i], " - Promedio: ", promedios[i]
        Sino
            Escribir nombresEstudiantes[i], " - Sin notas"
        FinSi
    FinPara
FinSubProceso
