#include <stdio.h>
#include <math.h>

int main () {
    int dmayor;
    int dmenor;
    int area;
    int lado;
    int perimetro;

    printf ("Ingrese el diagonal mayor del rombo: \n ");
    scanf ("%d", &dmayor);
    
    printf ("Ingrese la diagonal menor del rombo: \n ");
    scanf ("%d", &dmenor);

    area = (dmayor * dmenor) / 2;
    printf ("El area de rombo es: %d \n", area);

    lado = sqrt(pow(dmayor/2,2) + pow(dmenor/2, 2));
    printf ("El lado de rombo es: %d \n", lado);

    perimetro = 4 * lado;
    printf ("El perimetro del rombo es %d \n", perimetro);

    return 0;



}