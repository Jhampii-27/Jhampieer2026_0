#include <iostream>
using namespace std;

int main()
{
    int N;

    do
    {
        cout << "Ingrese N (N >= 1): ";
        cin >> N;
    } while (N < 1);

    int maximo, minimo;
    int cantidadPrimos = 0;
    int sumaPositivosPares = 0;
    int cantPositivosPares = 0;
    int mayorMasImpares;
    bool existeMayorMasImpares = false;

    for (int i = 1; i <= N; i++)
    {
        int num;
        cout << "Ingrese numero " << i << ": ";
        cin >> num;

        if (i == 1)
        {
            maximo = num;
            minimo = num;
        }
        else
        {
            if (num > maximo)
                maximo = num;
            if (num < minimo)
                minimo = num;
        }

        bool esPrimo = true;
        if (num < 2)
        {
            esPrimo = false;
        }
        else if (num == 2)
        {
            esPrimo = true;
        }
        else if (num % 2 == 0)
        {
            esPrimo = false;
        }
        else
        {
            for (int j = 3; j * j <= num; j += 2)
            {
                if (num % j == 0)
                {
                    esPrimo = false;
                    break;
                }
            }
        }

        if (esPrimo)
        {
            cantidadPrimos++;
        }

        if (num > 0 && num % 2 == 0)
        {
            sumaPositivosPares += num;
            cantPositivosPares++;
        }

        int temp = num;
        if (temp < 0)
            temp = -temp;

        int digitosImpares = 0;
        int digitosPares = 0;
        int auxTemp = temp;

        while (auxTemp > 0)
        {
            int digito = auxTemp % 10;
            if (digito % 2 == 0)
            {
                digitosPares++;
            }
            else
            {
                digitosImpares++;
            }
            auxTemp /= 10;
        }

        if (digitosImpares > digitosPares)
        {
            if (!existeMayorMasImpares || num > mayorMasImpares)
            {
                mayorMasImpares = num;
                existeMayorMasImpares = true;
            }
        }
    }

    cout << "\nRESULTADOS:" << endl;
    cout << "Maximo: " << maximo << endl;
    cout << "Minimo: " << minimo << endl;

    if (cantidadPrimos == 0)
    {
        cout << "Cantidad de primos: NO EXISTE" << endl;
    }
    else
    {
        cout << "Cantidad de primos: " << cantidadPrimos << endl;
    }

    if (cantPositivosPares == 0)
    {
        cout << "Promedio de positivos pares: NO EXISTE" << endl;
    }
    else
    {
        double promedio = (double)sumaPositivosPares / cantPositivosPares;
        cout << "Promedio de positivos pares: " << promedio << endl;
    }

    if (!existeMayorMasImpares)
    {
        cout << "Mayor con mas digitos impares que pares: NO EXISTE" << endl;
    }
    else
    {
        cout << "Mayor con mas digitos impares que pares: " << mayorMasImpares << endl;
    }

    return 0;
}