def dividir(a, b):
    if b == 0:
        raise ZeroDivisionError("Divisor no puede ser cero")
    return a / b

try:
    resultado = dividir(10, 2)
except ZeroDivisionError as e:
    print(f"Error: {e}")
else:
    print(f"División exitosa: {resultado}")
