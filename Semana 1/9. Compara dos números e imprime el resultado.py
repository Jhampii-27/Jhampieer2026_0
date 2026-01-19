num1 = int(input("Ingrese el primer numero: "))
num2 = int(input("Ingrese el segundo numero: "))

if num1 > num2:
    print(f"{num1} es mayor a {num2}")
elif num2 > num1:
    print (f"{num2} es mayor a {num1}")
else:
    print("Ambos numeros son iguales")