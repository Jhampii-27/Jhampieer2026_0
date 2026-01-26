#include <stdio.h>
#include <math.h>

int main () {
    int lado1;
    int lado2;
    int lado3;
    int radio;
    int area;

    printf ("Ingrese el lado 1: \n");
    scanf ("%d", &lado1);

    printf ("Ingrese el lado 2: \n");
    scanf ("%d", &lado2);

    printf ("Ingrese el lado 3: \n");
    scanf ("%d", &lado3);

    printf ("Ingrese el radio: \n");
    scanf ("%d", &radio);

    area = (lado1 * lado2 * lado3) / (radio * 4);
    printf ("El area del triangulo inscrito es: %d \n", area);
}