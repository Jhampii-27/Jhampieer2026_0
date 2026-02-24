v = [1,3,5,2]
ordenado = True

for i in range (len(v)-1):
    if v[i] > v[i+1]:
        ordenado = False

print("Ordenado: ", ordenado)