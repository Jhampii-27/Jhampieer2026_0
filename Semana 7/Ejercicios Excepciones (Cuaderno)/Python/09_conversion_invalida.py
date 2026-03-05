try:
    numero = int("texto_invalido")
except ValueError as e:
    print(f"No se pudo convertir: {e}")
