#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "funciones.h"


void inicializarActiveStatus(EMovie* movie,int cant_elem,int valor)
{
  int i;
  for(i=0;i<cant_elem;i++)
  {
     (movie + i)->activeStatus = valor;
  }
}


EMovie* newMovies()
{
  EMovie* espacio;
  espacio = (EMovie*)malloc(sizeof(EMovie));
  if(espacio == NULL)
  {
    printf("No se pudo asignar memoria correctamente!!");
    exit(1);
  }
  return espacio;
}

EMovie* newVectorMovies(EMovie* peli,int cant)
{
  EMovie* espace;
  espace = (EMovie*)realloc(peli,sizeof(EMovie)*(cant));
  if(espace == NULL)
  {
    printf("No se pudo asignar memoria correctamente!!");
    exit(1);
  }
  return espace;
}

int agregarPelicula(EMovie* movie,int* cantidad)
{
     char auxCad[800];
     int auxInt,cont=*cantidad;
     system("cls");
     printf("                                 >>>Alta de pelicula<<<\n");
     printf("                                 ----------------------\n\n");
     if(!(obtenerCadena("Ingrese titulo de la pelicula: ",auxCad)))
       {
         return 0;
       }
     if(strlen(auxCad)>49)
       {
         printf("Cadena demasiado larga para el Titulo!");
         return 0;
       }
     strcpy((movie + cont)->titulo,auxCad);
     if(!(obtenerCadena("Ingrese genero de la pelicula: ",auxCad)))
       {
         return 0;
       }
     if(strlen(auxCad)>19)
       {
         printf("Cadena demasiado larga para el Genero!");
         return 0;
       }
     strcpy((movie + cont)->genero,auxCad);
     auxInt = getInt("Ingrese la duracion en minutos: ");
     if(auxInt < 60 || auxInt > 300)
        return 0;
     (movie + cont)->duracion = auxInt;
     if(!(obtenerCadena("Ingrese descripcion de la pelicula: ",auxCad)))
       {
         return 0;
       }
     if(strlen(auxCad)>499)
       {
         printf("Cadena demasiado larga para el Genero!");
         return 0;
       }
     strcpy((movie + cont)->descripcion,auxCad);
     auxInt = getInt("Ingrese el puntaje de la pelicula: ");
     if(auxInt < 1 || auxInt > 100)
         return 0;
     (movie + cont)->puntaje = auxInt;
     if(!(obtenerCadena("Ingrese Link de la imagen: ",auxCad)))
       {
         return 0;
       }
     if(strlen(auxCad)>199)
       {
         printf("Cadena demasiado larga para el link!");
         return 0;
       }
     strcpy((movie + cont)->linkImagen,auxCad);
    (movie + cont)->activeStatus = 1;
     cont++;
      *cantidad = cont;
   return 1;
}

int borrarPelicula(EMovie* movie,int cant)
{
    char auxTittle[50];
    int i,encontro=0;
    system("cls");
    printf("                                 >>>Borrar pelicula<<<\n");
    printf("                                 ----------------------\n\n");
    if(!(obtenerCadena("Ingrese titulo de la pelicula a eliminar: ",auxTittle)))
      {
        return 0;
      }
    for(i=0;;i++)
    {
      if((movie + i)->activeStatus != 1)
        continue;
      if(strcmp((movie + i)->titulo,auxTittle)== 0)
      {
        (movie + i)->activeStatus = -1;
        encontro=1;
        break;
      }
    }
  return encontro;
}

int modificarPelicula(EMovie* movie, int cant)
{
    char auxTittle[50],auxCad[800];
    int auxInt,i,idx,encontro=0;
    //system("cls");
    printf("                                 >>>Modificar pelicula<<<\n");
    printf("                                 ----------------------\n\n");
    if(!(obtenerCadena("Ingrese titulo de la pelicula modificar: ",auxTittle)))
      {
        return 0;
      }
    for(i=0;;i++)
    {
      if((movie + i)->activeStatus != 1)
        continue;
      if(strcmp((movie + i)->titulo,auxTittle)== 0)
      {
         idx = i;
         encontro=1;
        break;
      }
    }
    if(!(obtenerCadena("Ingrese titulo de la pelicula: ",auxCad)))
         {
           return 0;
         }
    if(strlen(auxCad)>49)
         {
           printf("Cadena demasiado larga para el Titulo!");
           return 0;
         }
    strcpy((movie + idx)->titulo,auxCad);
    if(!(obtenerCadena("Ingrese genero de la pelicula: ",auxCad)))
         {
           return 0;
         }
    if(strlen(auxCad)>19)
         {
           printf("Cadena demasiado larga para el Genero!");
           return 0;
         }
    strcpy((movie + idx)->genero,auxCad);
    auxInt = getInt("Ingrese la duracion en minutos: ");
    if(auxInt < 60 || auxInt > 300)
          return 0;
    (movie + idx)->duracion = auxInt;
    if(!(obtenerCadena("Ingrese descripcion de la pelicula: ",auxCad)))
         {
           return 0;
         }
    if(strlen(auxCad)>499)
         {
          printf("Cadena demasiado larga para el Genero!");
          return 0;
         }
    strcpy((movie + idx)->descripcion,auxCad);
    auxInt = getInt("Ingrese el puntaje de la pelicula: ");
    if(auxInt < 60 || auxInt > 300)
          return 0;
    (movie + idx)->puntaje = auxInt;
    if(!(obtenerCadena("Ingrese Link de la imagen: ",auxCad)))
         {
           return 0;
         }
    if(strlen(auxCad)>199)
         {
            printf("Cadena demasiado larga para el link!");
            return 0;
         }
    strcpy((movie + idx)->linkImagen,auxCad);
  return encontro;
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
    char cad[500];
    printf("%s",msj);
    fflush(stdin);
    gets(cad);
    if(esAlfaNumerico(cad))
    {
      strcpy(aux,cad);
      return 1;
    }
    return 0;
}

/*int isString(char str[])
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
}*/

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}

int esAlfaNumerico(char str[])
{
   int i=0;
   while(str[i] != '\0')
   {
       if((str[i] != '_')&&(str[i] != '.')&&(str[i] != ':')&&(str[i] != ')')&&(str[i] != '(')&&(str[i] != ',')&&(str[i] != ',')&&(str[i] != '-') && (str[i] != '/') && (str[i] != ' ') && (str[i] < 'a' || str[i] > 'z') && (str[i] < 'A' || str[i] > 'Z') && (str[i] < '0' || str[i] > '9'))
           return 0;
       i++;
   }
   return 1;
}

void generarPagina(EMovie lista[], char nombre[],int cant_elem)
{
  FILE* fd;
  int i,cantChar = 0;
  char* auxChar;
  fd = fopen(nombre,"w");
  if(fd == NULL)
  {
    printf("No se pudo abrir el archivo!!");
    exit(1);
  }
  cantChar = strlen("<!DOCTYPE html><html lang='en'><head>    <meta charset='utf-8'>  <meta http-equiv='X-UA-Compatible' content='IE=edge'>    <meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'>");
  auxChar = (char*)malloc(sizeof(char)*cantChar);
  if(auxChar == NULL)
  {
     printf("No se pudo asignar memoria!");
     exit(1);
  }
  strcpy(auxChar,"<!DOCTYPE html><html lang='en'><head>    <meta charset='utf-8'>  <meta http-equiv='X-UA-Compatible' content='IE=edge'>    <meta name='viewport' content='width=device-width, initial-scale=1'><title>Lista peliculas</title><link href='css/bootstrap.min.css' rel='stylesheet'><link href='css/custom.css' rel='stylesheet'></head><body><div class='container'>");
  fwrite(auxChar,sizeof(char),cantChar,fd);
  for(i=0;i<cant_elem;i++)
  {
    if(lista[i].activeStatus != 1)
       continue;
      fprintf(fd,"<div class='row'>     <article class='col-md-4 article-intro'><a href='#'><img class='img-responsive img-rounded' src='%s' alt=''>",(lista + i)->linkImagen);
      fprintf(fd,"</a>");
      fprintf(fd,"<h3>");
      cantChar = strlen((lista + i)->titulo);
      fprintf(fd,"<a href='#'>");
      fwrite((lista + i)->titulo,sizeof(char),cantChar,fd);
      cantChar = strlen((lista + i)->genero);
      fprintf(fd,"</a></h3><ul><li>Genero: ");
      fwrite((lista + i)->genero,sizeof(char),cantChar,fd);
      fprintf(fd,"<li>Puntaje: %d",(lista + i)->puntaje);
      fprintf(fd,"<li>Duracion: %d",(lista + i)->duracion);
      cantChar = strlen((lista + i)->descripcion);
      fprintf(fd," min</li></ul><p> ");
      fwrite((lista + i)->descripcion,sizeof(char),cantChar,fd);
      fprintf(fd,"</p></article></div>");
  }
  fprintf(fd,"    </div>  <!-- /.container --> <!-- jQuery --><script src='js/jquery-1.11.3.min.js'></script><!-- Bootstrap Core JavaScript --><script src='js/bootstrap.min.js'></script><!-- IE10 viewport bug workaround --><script src='js/ie10-viewport-bug-workaround.js'></script><!-- Placeholder Images --><script src='js/holder.min.js'></script></body></html>");
  fclose(fd);
  printf("Archivo: %s generado correctamente\n",nombre);
  system("pause");
  system("cls");
  //printf("la cantidad de estructuras es: %d",cont);
}


int buscarIdxLibre(EMovie* pelis,int cant_elem,int valor)
{
    int i;
    for(i=0;i<cant_elem;i++)
    {
       if ((pelis)->activeStatus == valor)
          {
            return i;
            break;
          }
    }
    return -1;
}
