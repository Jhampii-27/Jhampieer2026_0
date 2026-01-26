#include <stdio.h>
#include <math.h>

int main () {
    int lado;
    int area;
    int perimetro;
    float diagonal;

    printf("Ingrese el lado del cuadrado: \n");
    scanf ("%d", &lado);

    area = pow(lado, 2);
    printf ("El area es: %d \n", area);

    perimetro = lado * 4;
    printf ("El perimetro es: %d \n", perimetro);

    diagonal = lado * sqrt(2);
    printf ("La diagonal es: %f \n", diagonal);

    return 0;
    
}