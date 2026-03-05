try:
    try:
        raise RuntimeError("Error original")
    except RuntimeError as e:
        print("Capturado internamente, relanzando...")
        raise
except RuntimeError as e:
    print(f"Capturado externamente: {e}")
