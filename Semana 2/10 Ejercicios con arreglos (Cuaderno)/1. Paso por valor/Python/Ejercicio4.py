v = [4,8,1,9,33]
mayor = v[0]

for i in range (len(v)):
    if v[i] > mayor:
        mayor = v[i]

print("El mayor elemento es: ",mayor)