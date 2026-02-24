#include <stdio.h>

int main () {
    int edad;

    printf ("Ingrese su edad: \n");
    scanf ("%d", &edad);

    if (edad >= 18) {
        printf ("Acceso permitido. \n");
    } else {
        printf ("Acceso denegado. \n");
    }

    return 0;
}