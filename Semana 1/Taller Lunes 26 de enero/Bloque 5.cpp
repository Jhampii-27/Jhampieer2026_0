#include <stdio.h>

int main () {
    int hora;
    do {
    printf ("Ingrese la hora del dia: (0-23) \n");
    scanf ("%d", &hora);
    } while (hora < 0 || hora > 23);

    if (hora >= 6 && hora <= 11) {
        printf ("Buenos dias. \n");
    } else if (hora >= 12 && hora <= 18) {
        printf ("Buenas tardes. \n");
    } else if (hora >= 19 && hora <= 23) {
        printf ("Buenas noches. \n");
    } else {
        printf ("Estoy durmiendo jeje. \n");
    }
    
}