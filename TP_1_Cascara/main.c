#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{
    char seguir='s';
    int opcion=0;
    int num1;
    int num2;
    int suma;
    int resta;
    int producto;
    float division;
    int flag1 = 0;
    int flag2 = 0;

    while(seguir=='s')
    {
        if(flag1)
          {
              printf("1- Ingresar 1er operando (A=%d)\n",num1);
          }
        else
          {
          printf("1- Ingresar 1er operando (A=x)\n");
          }
        if(flag2)
          {
              printf("2- Ingresar 2do operando (B=%d)\n",num2);
          }
        else
          {
            printf("2- Ingresar 2do operando (B=y)\n");
          }
        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n\n");

        printf("Ingrese una opcion: ");
        scanf("%d",&opcion);

        while((!((flag1)&&(flag2))) && opcion!=1 && opcion!=2 && opcion!=9)
        {
           printf("Atencion!!, debe cargar los 2 operandos antes de realizar una operacion\n");
           printf("Ingrese una opcion: ");
           scanf("%d",&opcion);
        }
        switch(opcion)
        {
            case 1:
                printf("Ingrese 1er operando: ");
                scanf("%d",&num1);
                flag1 = 1;
                system("cls");
                break;
            case 2:
                printf("Ingrese 2do operando: ");
                scanf("%d",&num2);
                flag2 = 1;
                system("cls");
                break;
            case 3:
                suma = sumar(num1,num2);
                printf("La suma es: %d\n\n",suma);
                flag1 = 0;
                flag2 = 0;
                system("pause");
                system("cls");
                break;
            case 4:
                resta = restar(num1,num2);
                printf("La resta es: %d\n\n",resta);
                flag1 = 0;
                flag2 = 0;
                system("pause");
                system("cls");
                break;
            case 5:
                while(num2 == 0)
                {
                  flag2 = 0;
                  printf("Atencion!!, el divisor es 0, no se puede realizar la operacion, ingrese nuevamente el operando 2: ");
                  scanf("%d",&num2);
                }
                division = dividir(num1,num2);
                printf("La division es: %.2f\n\n",division);
                flag1 = 0;
                flag2 = 0;
                system("pause");
                system("cls");
                break;
            case 6:
                producto = multiplicar(num1,num2);
                printf("El Producto es: %d\n\n",producto);
                flag1 = 0;
                flag2 = 0;
                system("pause");
                system("cls");
                break;
            case 7:
                printf("El factorial de %d es: %lld\n\n",num1,factorial(num1));
                flag1 = 0;
                flag2 = 0;
                system("pause");
                system("cls");
                break;
            case 8:
                suma = sumar(num1,num2);
                resta = restar(num1,num2);
                division = dividir(num1,num2);
                producto = multiplicar(num1,num2);
                printf("La suma es: %d\n",suma);
                printf("La resta es: %d\n",resta);
                printf("La division es: %.2f\n",division);
                printf("El Producto es: %d\n",producto);
                printf("El factorial de %d es: %lld\n\n",num1,factorial(num1));
                flag1 = 0;
                flag2 = 0;
                system("pause");
                system("cls");
                break;
            case 9:
                seguir = 'n';
                printf("Usted ha salido...\n");
                break;
        }
    }
    return 0;
}
