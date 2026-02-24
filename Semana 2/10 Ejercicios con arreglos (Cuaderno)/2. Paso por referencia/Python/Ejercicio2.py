def negativos_a_cero(v):
    for i in range (len(v)):
        if v[i] < 0:
            v[i] = 0

v = [-2, 4, -1, 6, 3]

negativos_a_cero(v)

print(v)