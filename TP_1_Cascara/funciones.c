#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"
int sumar(int n1, int n2)
{
    int resultado = 0;
    resultado = n1 + n2;
    return resultado;
}

int restar(int n1, int n2)
{
    int resultado = 0;
    resultado = n1 - n2;
    return resultado;
}

int multiplicar(int n1, int n2)
{
    int resultado = 0;
    resultado = n1 * n2;
    return resultado;
}

float dividir(int n1, int n2)
{
    int resultado = 0;
    resultado = n1 / n2;
    return resultado;
}

long long factorial(int n1)
{
    if (n1 == 1)
    {
        return n1;
    }
    else
    {
        return (n1 * factorial(n1 - 1));
    }
}
