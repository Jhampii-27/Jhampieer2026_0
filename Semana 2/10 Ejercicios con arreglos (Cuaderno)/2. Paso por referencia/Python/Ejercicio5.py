def pares_por_uno(v):
    for i in range(len(v)):
        if v[i] % 2 == 0:
            v[i] = -1

v = [1,2,3,4,5]
pares_por_uno(v)
print(v)