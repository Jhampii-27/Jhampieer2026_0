class MiExcepcion(Exception):
    def __init__(self, mensaje="¡Excepción personalizada!"):
        super().__init__(mensaje)

try:
    raise MiExcepcion("Algo salió mal en mi app")
except MiExcepcion as e:
    print(f"Capturada: {e}")
