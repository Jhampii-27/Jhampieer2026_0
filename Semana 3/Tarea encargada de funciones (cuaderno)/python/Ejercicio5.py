def ejercicio5(n):
    resultado = 1
    for i in range(1, n + 1):
        resultado *= i
    return resultado

print(f"Factorial de 5 = {ejercicio5(5)}")
