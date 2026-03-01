def ejercicio9(a, b):
    return b, a  # En Python se intercambian con múltiple asignación

x, y = 10, 20
print(f"Antes: x={x}, y={y}")
x, y = ejercicio9(x, y)
print(f"Despues: x={x}, y={y}")
