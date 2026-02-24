#include <stdio.h>

int main () {
    int opcion;
    float num1, num2, suma, resta, multi, division;

    printf ("Menú de Opciones: \n");
    printf ("1. Suma: \n");
    printf ("2. Resta: \n");
    printf ("3. Multiplicacion: \n");
    printf ("4. Division: \n");

    printf ("Ingrese la opcion a escoger: \n");
    scanf ("%d", &opcion);

    printf ("Ingrese el primer numero: \n");
    scanf ("%f", &num1);
    printf ("Ingrese el segundo numero: \n");
    scanf ("%f", &num2);


    switch (opcion){
        case 1:
        suma = num1 + num2;
        printf ("La suma como resultado: %f \n", suma);
        break;

        case 2:
        resta = num1 - num2;
        printf ("La resta da como diferencia: %f \n", resta);
        break;

        case 3:
        multi = num1 * num2;
        printf ("La multiplicacion da como producto: %f \n", multi);
        break;

        case 4:
        division = num1 / num2;
        printf ("La division da como cociente: %f \n", division);
        break;

        default:
        printf ("Error: Numero no valido. \n");
        break;
    }
    return 0;
}