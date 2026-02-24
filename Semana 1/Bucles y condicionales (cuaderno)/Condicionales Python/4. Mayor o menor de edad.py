num = int(input("Ingrese su edad: "))

if 18 <= num < 120:
    print ("Mayor de edad")
elif 0 <= num < 18:
    print ("Menor de edad")
else: 
    print("Edad no valida")