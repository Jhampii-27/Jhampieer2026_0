try:
    datos = {"nombre": "Ana"}
    print(datos["edad"])
except KeyError as e:
    print(f"Clave no encontrada: {e}")
