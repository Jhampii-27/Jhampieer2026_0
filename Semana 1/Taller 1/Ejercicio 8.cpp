#include <stdio.h>
#include <math.h>

int main () {
    double lado1, lado2, lado3, semiperimetro, area;

    printf ("Ingrese el lado 1: \n");
    scanf ("%lf", &lado1);

    printf ("Ingrese el lado 2: \n");
    scanf ("%lf", &lado2);

    printf ("Ingrese el lado 3: \n");
    scanf ("%lf", &lado3);

    semiperimetro = (lado1 + lado2 + lado3) / 2;
    printf ("El semiperimetro es: %lf \n", semiperimetro);

    area = sqrt(semiperimetro * (semiperimetro - lado1) * (semiperimetro - lado2) * (semiperimetro - lado3));
    printf ("El area es: %lf \n", area);
}