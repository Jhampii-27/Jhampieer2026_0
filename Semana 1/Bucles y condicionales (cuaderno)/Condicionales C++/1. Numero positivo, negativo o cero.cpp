#include <stdio.h>
int main () {
    int num;

    printf ("Ingrese el numero: \n");
    scanf ("%d", &num);

    if (num > 0) {
        printf ("Numero positivo");
    } else if (num < 0) {
        printf ("Numero negativo ");
    } else {
        printf ("Numero cero ");
    }
    return 0;
}