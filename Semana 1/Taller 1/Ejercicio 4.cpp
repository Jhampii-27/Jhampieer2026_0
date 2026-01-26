#include <stdio.h>
#include <math.h>

int main () {
    int bmayor;
    int bmenor;
    int altura;
    int area;

    printf ("Ingrese la base mayor del trapecio: \n");
    scanf ("%d", &bmayor);

    printf ("Ingrese la base menor del trapecio: \n");
    scanf ("%d", &bmenor);

    printf ("Ingrese la altura del trapecio: \n");
    scanf ("%d", &altura);

    area = ((bmayor + bmenor) * altura) / 2;

    printf ("El area del trapecio es: %d \n", area);

}