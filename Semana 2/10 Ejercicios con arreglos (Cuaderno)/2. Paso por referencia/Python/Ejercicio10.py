def ceros_por_uno(v):
    for i in range(len(v)):
        if v[i] == 0:
            v[i] = 1

v = [0,11,0,2,0] 
ceros_por_uno(v)
print(v)   