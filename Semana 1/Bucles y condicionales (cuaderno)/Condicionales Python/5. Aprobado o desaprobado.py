nota = int (input("Ingrese una nota: "))

if 0 <= nota <= 11:
    print("Desaprobado")
elif 11 < nota <= 20:
    print ("Aprobado")
else:
    print ("Nota fuera de rango (0-20)")