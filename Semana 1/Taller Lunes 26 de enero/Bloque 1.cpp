#include <stdio.h>
int main () {
    int temperatura;

    printf ("Ingrese la temperatura: \n");
    scanf ("%d", &temperatura);

    if (temperatura > 30) {
        printf ("Encender la ventiladora. \n");
    } else {
        printf ("Apagar la ventiladora. \n");
    }
    return 0;
}