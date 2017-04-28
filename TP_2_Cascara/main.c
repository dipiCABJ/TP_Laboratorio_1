#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"

#define tam 20

int main()
{
    system("color 1e");
    persona cliente;
    persona clientes[tam];

    int i,aDni,idx,auxEdad,opcion=0;
    int cont_18;
    int cont18_35;
    int cont_36;
    char auxDni[9], auxNombre[50];
    char Men_18[tam];
    char Edad18_35[tam];
    char May_35[tam];
    char seguir = 's';

    inicializarActiveStatus(clientes,tam,-1);

    while(seguir=='s')
    {
      printf("                           >>>>>>ABM Maestros<<<<<<               ");
      opcion = obtenerEntero("\n1 - Agregar una persona\n2 - Borrar una persona\n3 - Imprimir lista ordenada por nombre\n4 - Imprimir grafico de edades\n5 - Salir\nIngrese una opcion: ");
      while(opcion < 1 || opcion > 5)
      {
         printf("Error, opcion no valida, reingrese\n");
         opcion = obtenerEntero("\n1 - Agregar una persona\n2 - Borrar una persona\n3 - Imprimir lista ordenada por nombre\n4 - Imprimir grafico de edades\5 - Salir ");
      }
       switch(opcion)
      {
        case 1:
        printf(">>Alta de Persona<<\n");
        idx = buscarIdx(clientes,tam,-1);
        if(idx == -1)
        {
            printf("No hay lugar para la carga de datos!!\n");
            break;
        }
        if(!(obtenerNumeros("Ingrese el D.N.I: ",auxDni)))
          {
             printf ("El DNI debe estar compuesto solo por numeros!\n");
             system("pause");
             system("cls");
             break;
          }
          aDni = atoi(auxDni);
          if(buscarIdxDni(clientes,tam,aDni)>-1)
          {
            printf("D.N.I existente!\n");
            system("cls");
            system("pause");
            break;
          }
          //Agregado
          if(!(obtenerCadena("Ingrese Nombre y apellido: ",auxNombre)))
          {
            printf ("El nombre debe estar compuesto solo por letras!\n");
            system("pause");
            system("cls");
            break;
          }
          auxEdad = obtenerEdad("Ingrese la edad: ");
          if(!(auxEdad))
          {
            printf ("La edad debe ser entre 18 y 100 anios!!\n");
            system("pause");
            system("cls");
            break;
          }
          //Fin agregado
          clientes[idx].dni = aDni;
          strcpy(clientes[idx].nombre,auxNombre);
          clientes[idx].edad = auxEdad;
          clientes[idx].activeStatus = 1;
          system("cls");
          break;

        case 2:
        printf(">>Baja de Persona<<\n");
        if(!(obtenerNumeros("Busque el D.N.I para dar de baja a la persona: ",auxDni)))
          {
             printf ("El DNI debe estar compuesto solo por numeros!\n");
             break;
          }
          aDni = atoi(auxDni);
          idx = buscarIdxDni(clientes,tam,aDni);
          if(idx == -1)
          {
            printf("D.N.I inexistente!!\n");
            break;
          }

        clientes[idx].activeStatus = -1;
        system("cls");
        break;

        case 3:
        printf(">>Mostrar lista ordenada por Nombre<<\n");
        //mostrarPersonas(clientes,tam);
        ordenarListaNombre(clientes,cliente,tam);
        mostrarListaOrdenada(clientes,tam);
        system("pause");
        system("cls");
        break;

        case 4:
        cont_18 = 0;
        cont18_35 = 0;
        cont_36 = 0;
        printf(">>Mostrar Grafico de edades<<\n");
        for(i=0;i<tam;i++)
         {
           if(clientes[i].activeStatus == 1)
             {
              if ((clientes[i].edad >= 18 && clientes[i].edad <= 35))
              {
               cont18_35++;
              }
             else
              {
                 if(clientes[i].edad < 18)
                  {
                    cont_18++;
                  }
                 else
                  {
                    cont_36++;
                  }
              }
             }

          }
        inicializaVectorEdades(Men_18,Edad18_35,May_35,'*',tam);
        BorrarAsteriscos(Men_18,cont_18,tam);
        BorrarAsteriscos(Edad18_35,cont18_35,tam);
        BorrarAsteriscos(May_35,cont_36,tam);
        ImprimeGrafico(Men_18,Edad18_35,May_35,tam);

        system("pause");
        system("cls");
        break;

        case 5:
        seguir = 'n';
        system("cls");
        printf(">>HASTA LA PROXIMA<<\n");
        system("pause");
        break;
      }
    }
    return 0;
}
