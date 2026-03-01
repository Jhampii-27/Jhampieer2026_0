def ejercicio10(base, exponente=2):
    resultado = 1.0
    for _ in range(exponente):
        resultado *= base
    return resultado

print(f"4 al cuadrado = {ejercicio10(4)}")
print(f"2 al cubo = {ejercicio10(2, 3)}")
