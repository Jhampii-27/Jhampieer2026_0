num = int(input("Ingrese un numero: "))
i = 1

while True:
    print (f"{num} x {i} = {num*i}")
    i += 1
    
    if i > 10:
        break