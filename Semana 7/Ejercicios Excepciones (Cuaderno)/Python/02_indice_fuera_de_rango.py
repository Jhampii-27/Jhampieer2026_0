try:
    lista = [1, 2, 3]
    print(lista[10])
except IndexError as e:
    print(f"Error: {e}")
