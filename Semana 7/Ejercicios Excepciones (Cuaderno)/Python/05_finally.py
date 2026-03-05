try:
    x = 1 / 0
except ZeroDivisionError:
    print("Error capturado")
finally:
    print("Esto siempre se ejecuta (finally)")
