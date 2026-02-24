factorial = 1
i = 1

num = int(input("Ingrese un numero: "))

while True:
    factorial = factorial * i
    i += 1
    
    if i > num:
        break
    
print (factorial)