import math

def ejercicio7(n):
    if n < 2:
        return False
    for i in range(2, int(math.sqrt(n)) + 1):
        if n % i == 0:
            return False
    return True

print(f"13 es primo? {'Si' if ejercicio7(13) else 'No'}")
print(f"15 es primo? {'Si' if ejercicio7(15) else 'No'}")
