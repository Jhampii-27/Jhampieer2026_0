# Clinica Salud+ - Sistema de Gestion de Citas
**Taller: UML + POO en C++ con Relaciones y Excepciones**

---

## Como compilar y ejecutar

```bash
# Compilar
g++ -std=c++17 -Wall clinica.cpp -o clinica

# Ejecutar Linux/macOS/WSL
./clinica

# Ejecutar Windows (MinGW)
clinica.exe
```

---

## Diagrama de Clases UML

```
                   +---------------------+
                   |    <<abstract>>     |
                   |       Persona       |
                   +---------------------+
                   | # nombre : string   |
                   +---------------------+
                   | + getNombre()       |
                   | + mostrar() = 0     |  <- virtual puro
                   +----------+----------+
                              |  HERENCIA
              +---------------+---------------+
              |                               |
   +----------+----------+       +------------+---------+
   |       Paciente      |       |         Doctor       |
   +---------------------+       +----------------------+
   | - dni : string      |       | - codigo : string    |
   | - edad : int        |       | - especialidad: str  |
   | - telefono : string |       | - tarifa : double    |
   | - historia          |       +----------------------+
   |   (unique_ptr) <>-- |       | + getCodigo()        |
   +---------------------+       | + getEspecialidad()  |
   | + getDNI()          |       | + getTarifa()        |
   | + getEdad()         |       | + mostrar()          |
   | + mostrar()         |       +----------------------+
   +---------------------+
              |
              | COMPOSICION <>-- (1 a 1)
              v
   +---------------------+
   |   HistoriaClinica   |
   +---------------------+
   | - entradas: vector  |
   +---------------------+
   | + agregarEntrada()  |
   | + total() : int     |
   | + mostrar()         |
   +----------+----------+
              |
              | COMPOSICION <>-- (1 a 1..*)
              v
   +---------------------+
   |   EntradaHistoria   |
   +---------------------+
   | - fecha : string    |
   | - nota : string     |
   | - diagnostico: str  |
   +---------------------+
   | + mostrar()         |
   +---------------------+


+------------------------------------------------------+
|                      Clinica                         |
+------------------------------------------------------+
| - pacientes : vector<unique_ptr<Paciente>>           |
| - doctores  : vector<unique_ptr<Doctor>>   o-- AGREGA|
| - citas     : vector<unique_ptr<Cita>>               |
+------------------------------------------------------+
| + registrarPaciente()   + registrarDoctor()          |
| + agendarCita()         + cancelarCita()             |
| + citasPorPaciente()    + citasPorDoctor()           |
| + buscarPaciente()      + buscarDoctor()             |
| + reporteEspecialidad() + reporteFecha()             |
| + reporteResumen()                                   |
+------------------------+-----------------------------+
                         |  DEPENDENCIA ..>
                         v
              +---------------------+
              |       Reporte       |
              +---------------------+
              | (sin atributos)     |
              +---------------------+
              | + porEspecialidad() |
              | + porFecha()        |
              | + resumen()         |
              +---------------------+

+------------------------------------------------------+
|                        Cita                          |
+------------------------------------------------------+
| - id       : int  (static autoincremental)           |
| - fecha    : string                                  |
| - hora     : string                                  |
| - motivo   : string                                  |
| - estado   : enum { ACTIVA, CANCELADA }              |
| - paciente : Paciente*  --> ASOCIACION               |
| - doctor   : Doctor*    --> ASOCIACION               |
+------------------------------------------------------+
| + getId()  + estaActiva()  + cancelar()  + mostrar() |
+------------------------------------------------------+

+------------------------------------------------------+
|  EntidadNoEncontrada  (excepcion personalizada)      |
|  hereda de: std::runtime_error                       |
+------------------------------------------------------+
| - tipo : string                                      |
| - id   : string                                      |
+------------------------------------------------------+
| + getTipo()   + getId()                              |
+------------------------------------------------------+
```

### Leyenda
| Simbolo | Relacion             |
|---------|----------------------|
| `<>--`  | Composicion          |
| `o--`   | Agregacion           |
| `-->`   | Asociacion           |
| hereda  | Herencia             |
| `..>`   | Dependencia          |

---

## Justificacion del UML

**Herencia — Persona <- Paciente / Doctor**
Paciente y Doctor comparten nombre y el comportamiento mostrar(). Se unifica
en una clase base abstracta con mostrar() virtual puro para habilitar
polimorfismo real.

**Composicion — Paciente <>-- HistoriaClinica <>-- EntradaHistoria**
La HistoriaClinica no existe sin su Paciente. Se crea con unique_ptr dentro
del constructor del Paciente y se destruye automaticamente con el. Las
EntradaHistoria se guardan como objetos directos en un vector dentro de la
historia (composicion doble).

**Agregacion — Clinica o-- Doctor**
La clinica administra doctores pero estos pueden existir conceptualmente fuera
del sistema. La relacion no es de propiedad absoluta.

**Asociacion — Cita --> Paciente* / Doctor***
Una Cita referencia a un Paciente y a un Doctor mediante punteros crudos
observadores (raw*). No los posee; la propiedad sigue siendo de la Clinica.

**Dependencia — Reporte ..> Clinica**
Reporte no almacena datos ni hereda de Clinica. Solo recibe las citas como
parametro en sus metodos estaticos.

---

## Pruebas documentadas

### Prueba 1 — DNI invalido
- **Entrada:** DNI "1234" (4 digitos)
- **Excepcion:** std::invalid_argument
- **Esperado:** "DNI invalido: debe tener 8 digitos."
- **Resultado:** OK - El registro se rechaza, el menu continua.

### Prueba 2 — Cita duplicada
- **Entrada:** Agendar dos veces con el mismo doctor, fecha y hora.
- **Excepcion:** std::runtime_error
- **Esperado:** "El doctor ya tiene cita el 2026-03-15 a las 10:00"
- **Resultado:** OK - Solo se registra la primera cita.

### Prueba 3 — Cancelar cita ya cancelada
- **Entrada:** Cancelar la cita #1 dos veces.
- **Excepcion:** std::runtime_error
- **Esperado:** "La cita #1 ya estaba cancelada."
- **Resultado:** OK - El estado se preserva, no se rompe el programa.

### Prueba 4 — Paciente inexistente (excepcion personalizada)
- **Entrada:** Listar citas del DNI "99999999" sin registrarlo.
- **Excepcion:** EntidadNoEncontrada (personalizada)
- **Esperado:** "No se encontro Paciente con ID: 99999999"
- **Resultado:** OK - Se lanza y captura la excepcion personalizada.

### Prueba 5 — Opcion de menu fuera de rango
- **Entrada:** Ingresar 99 como opcion.
- **Excepcion:** std::out_of_range
- **Esperado:** "Opcion invalida. Ingresa un numero del 0 al 9."
- **Resultado:** OK - El menu vuelve a mostrarse sin cerrar el programa.

### Prueba 6 — Tarifa negativa
- **Entrada:** Tarifa -50.0 al registrar doctor.
- **Excepcion:** std::invalid_argument
- **Esperado:** "Tarifa invalida: debe ser mayor a 0."
- **Resultado:** OK - El doctor no se registra.

### Prueba 7 — Formato de fecha incorrecto
- **Entrada:** Fecha "15-03-2026" al agendar cita.
- **Excepcion:** std::invalid_argument
- **Esperado:** "Fecha invalida: use YYYY-MM-DD."
- **Resultado:** OK - La cita no se agenda.

### Prueba 8 — Flujo completo (ciclo de vida de una cita)
- **Pasos:** Registrar paciente y doctor -> agendar cita -> verificar en lista
  -> cancelar -> verificar en reporte (debe aparecer como 0 citas activas).
- **Excepcion:** Ninguna (flujo feliz)
- **Resultado:** OK - Todas las operaciones funcionan en secuencia.

---

## Checklist de entrega

- [x] UML con herencia, composicion, agregacion, asociacion y dependencia
- [x] try/catch completo; el programa nunca se cae ante errores
- [x] Validacion: DNI (8 dig), edad (0-120), telefono (9 dig), tarifa (>0), fecha, hora
- [x] No se permiten citas duplicadas (mismo doctor + fecha + hora)
- [x] Excepcion personalizada EntidadNoEncontrada
- [x] Excepciones estandar: invalid_argument, out_of_range, runtime_error
- [x] unique_ptr para propiedad; raw pointers observadores en Cita
- [x] Mas de 10 metodos definidos entre todas las clases
- [x] 8 pruebas documentadas
- [x] Compila sin errores: g++ -std=c++17 -Wall clinica.cpp -o clinica
