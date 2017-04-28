#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


void inicializarActiveStatus(persona cli[],int cant_elem,int valor)
{
  int i;
  for(i=0;i<cant_elem;i++)
  {
     cli[i].activeStatus = valor;
  }
}


int buscarIdx(persona cli[],int cant_elem,int valor)
{
    int i;
    for(i=0;i<cant_elem;i++)
    {
       if (cli[i].activeStatus == valor)
          {
            return i;
            break;
          }
    }
    return -1;
}



int buscarIdxDni(persona cli[],int cant_elem,int valor)
{
    int i;
    for(i=0;i<cant_elem;i++)
    {
       if ((cli[i].dni == valor)&&(cli[i].activeStatus == 1))
          {
            return i;
            break;
          }
    }
    return -1;
}

int obtenerEntero(char msj[])
{
  int aux;
  printf("%s",msj);
  scanf("%d",&aux);
  return aux;

}

int isString(char str[])
{
  int cont = 0;
  while(str[cont] != '\0')
  {
     if((str[cont] != ' ')&&(str[cont]<'a'||str[cont]>'z')&&(str[cont]<'A'||str[cont]>'Z'))
      {
        return 0;
      }
      cont++;
  }
  return 1;
}

int isNumeric(char str[])
{
  int cont = 0;
  while(str[cont] != '\0')
  {
     if((str[cont]<'0'||str[cont]>'9'))
      {
        return 0;
      }
      cont++;
  }
  return 1;
}

int obtenerCadena(char msj[],char aux[])
{
    char cad[100];
    printf("%s",msj);
    fflush(stdin);
    gets(cad);
    if(isString(cad))
    {
      strcpy(aux,cad);
      return 1;
    }
    return 0;
}

int obtenerNumeros(char msj[],char aux[])
{
    char cad[20];
    printf("%s",msj);
    fflush(stdin);
    gets(cad);
    if(isNumeric(cad))
    {
      strcpy(aux,cad);
      return 1;
    }
    return 0;
}

void mostrarListaOrdenada(persona cli[],int cant)
{
   int i;
   printf("D.N.I\t\t\tNombre\t\t\tEdad\t\t\tEstado\n");
   for(i=0;i<cant;i++)
    {
      if(cli[i].activeStatus == 1)
      {
        printf("%d\t\t%s\t\t\t%d\t\t\t%d\n",cli[i].dni,cli[i].nombre,cli[i].edad,cli[i].activeStatus);
      }
    }
}

int obtenerEdad(char msj[])
{
  int anios;
  printf("%s",msj);
  scanf("%d",&anios);
  if(anios < 1 || anios > 100)
  {
    return 0;
  }
  return anios;
}

void ordenarListaNombre(persona cli[],persona auxCli,int valor)
{
    int i,j;
    for(i=0;i<valor-1;i++)
    {
       for(j=i+1;j<valor;j++)
        {
          if(strcmp(cli[i].nombre,cli[j].nombre)==1)
          {
            auxCli = cli[i];
            cli[i] = cli[j];
            cli[j] = auxCli;
          }
        }
    }

}

void inicializaVectorEdades(char vec1[],char vec2[],char vec3[],char caracter,int x)
{
    int i;
    for(i=0;i<x;i++)
    {
        vec1[i] = caracter;
        vec2[i] = caracter;
        vec3[i] = caracter;
    }
}
void BorrarAsteriscos(char vec[], int x, int y)
{
    int i;
    int aux = y - x;
    for(i=0;i<aux;i++)
    {
       //printf("%s\n",vec[i]);
       vec[i] = ' ';
    }
}

void ImprimeGrafico(char men18[],char e19_35[],char may35[],int x)
{
    int i;
    for(i=0;i<x;i++)
    {
        printf("%c\t%c\t%c\n",men18[i],e19_35[i],may35[i]);
    }
    printf("<18\t18-35\t>35\n\n");
}
