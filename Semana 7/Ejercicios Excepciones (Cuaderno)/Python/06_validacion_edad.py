try:
    edad = -3
    if edad < 0:
        raise ValueError("La edad no puede ser negativa")
    print(f"Edad: {edad}")
except ValueError as e:
    print(f"Error: {e}")
