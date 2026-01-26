#include <stdio.h>
#include <math.h>

int main (){
    int lado1, lado2, lado3, radio, semiperimetro, area;

    printf ("Ingrese el lado 1: \n");
    scanf ("%d", &lado1);
    printf ("Ingrese el lado 2: \n");
    scanf ("%d", &lado2);
    printf ("Ingrese el lado 3: \n");
    scanf ("%d", &lado3);
    printf ("Ingrese el radio: \n");
    scanf ("%d", &radio);

    semiperimetro = (lado1 + lado2 + lado3) / 2;
    printf ("El semiperimetro es: %d \n", semiperimetro);

    area = radio * semiperimetro;
    printf ("El area es: %d \n", area);
    
}