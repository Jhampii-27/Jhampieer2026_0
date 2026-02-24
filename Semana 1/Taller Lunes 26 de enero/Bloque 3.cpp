#include <stdio.h>

int main () {
    int nota;

    printf ("Ingrese la nota del estudiante: \n");
    scanf ("%d", &nota);

    if (nota >= 90) {
        printf ("Exelente. \n");
    } else if (nota >= 70) {
        printf ("Aprobado. \n");
    } else {
        printf ("Reprobado. \n");
    }

    return 0;
    
}