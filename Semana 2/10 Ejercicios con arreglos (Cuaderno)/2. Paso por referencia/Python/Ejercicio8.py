def multiplicar(v, n):
    for i in range(len(v)):
        v[i] = v[i] * n

v = [1,2,3,4,5]
multiplicar(v, 3)
print(v)