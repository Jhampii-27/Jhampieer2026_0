#include <stdio.h>
#include <math.h>

int main () {
    int lado1;
    int lado2;
    int base;
    int altura;
    int area;
    int perimetro;

    printf ("Ingrese el lado 1: \n");
    scanf ("%d", &lado1);

    printf ("Ingrese el lado 2: \n");
    scanf ("%d", &lado2);

    printf ("Ingrese la base triangulo: \n");
    scanf ("%d", &base);

    printf ("Ingrese la altura del triangulo: \n");
    scanf ("%d", &altura);

    area = (base * altura) / 2;
    printf ("El area del triangulo es: %d \n", area);

    perimetro = lado1 + base + lado2;
    printf ("El perimetro del triangulo es: %d \n", perimetro);
}

