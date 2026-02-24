v = [5,8,1,3]
num = 17;
encontrado = False

for i in range (len(v)):
    if v[i] == num:
        encontrado = True

if not encontrado:
    print("Numero no encontrado")
else:
    print("Numero encontrado")