def mayores_10(v):
    for i in range(len(v)):
        if v[i] > 10:
            v[i] = 10

v = [11,22,13,4,5]
mayores_10(v)
print(v)