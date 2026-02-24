def impares_por_cero(v):
    for i in range(len(v)):
        if v[i] % 2 != 0:
            v[i] = 0

v = [1,2,3,4,5]
impares_por_cero(v)
print(v)