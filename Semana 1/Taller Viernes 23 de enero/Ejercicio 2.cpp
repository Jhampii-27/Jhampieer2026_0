#include <stdio.h>
#include <math.h>

int main () {
    int base;
    int altura;
    int area;
    int perimetro;
    int diagonal;

    printf ("Ingrese la altura del rectangulo: \n");
    scanf ("%d" , &altura);

    printf ("Ingrese la base del rectangulo: \n ");
    scanf ("%d" , &base);

    area = base * altura;
    printf ("El area del rectangulo es: %d \n ", area);

    perimetro = 2 * (base + altura);
    printf ("El perimetro del rectangulo es: %d \n ", perimetro);

    diagonal = sqrt(pow(base,2) + pow(altura, 2));
    printf ("La diagonal del rectangulo es: %d \n ", diagonal);

    return 0;


}