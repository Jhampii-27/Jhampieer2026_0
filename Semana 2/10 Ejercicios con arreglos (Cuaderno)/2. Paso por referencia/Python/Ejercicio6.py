def cuadrado(v):
    for i in range(len(v)):
        v[i] = v[i] ** 2

v = [1,2,3,4,5]
cuadrado(v)
print(v)