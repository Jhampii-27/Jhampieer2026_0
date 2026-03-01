def ejercicio8(n):
    if n <= 0:
        return 0
    if n == 1:
        return 1
    return ejercicio8(n - 1) + ejercicio8(n - 2)

print(f"Fibonacci(7) = {ejercicio8(7)}")
