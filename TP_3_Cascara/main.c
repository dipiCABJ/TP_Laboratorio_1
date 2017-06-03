#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"
//#define tam 6

int main()
{
    system("color 1e");
    EMovie* movies = newMovies();
    EMovie* auxiliar = NULL;
    FILE* pFileMovie;
    char seguir='s';
    int opcion=0,CantMovies=0,i;//lec,cont=0;
    //inicializarActiveStatus(movies,tam,-1);
    while(seguir=='s')
    {
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Salir\n");
        printf("Elija una opcion: ");

        scanf("%d",&opcion);
        while(opcion < 1 || opcion > 5)
        {
           printf("Opcio incorrecta, reingrese!!: ");
           scanf("%d",&opcion);
        }
        switch(opcion)
        {
            case 1:
                system("cls");
                if(!(agregarPelicula(movies,auxiliar,&CantMovies)))
                {
                  printf("No se pudo dar de alta la Pelicula!!");
                  break;
                }
                system("pause");
                system("cls");
                for(i=0;i<CantMovies;i++)
                {
                   if((movies + i)->activeStatus == -1)
                        continue;
                   printf("Titulo: %s\tEstado: %d\n",(movies + i)->titulo,(movies + i)->activeStatus);
                }
                break;
            case 2:
                if(!(borrarPelicula(movies,CantMovies)))
                {
                  printf("La Pelicula no pudo ser dada de baja!!");
                  break;
                }
                system("pause");
                printf("\n\n");
                for(i=0;i<CantMovies;i++)
                {
                  if((movies + i)->activeStatus == 1)
                       printf("Titulo: %s\n",(movies + i)->titulo);
                }
                system("pause");
                system("cls");
                break;
            case 3:

                if(!(modificarPelicula(movies,CantMovies)))
                {
                  printf("La Pelicula no pudo ser modificada!!");
                  break;
                }
                for(i=0;i<CantMovies;i++)
                {
                  if((movies + i)->activeStatus == 1)
                  //fwrite((peli + i),sizeof(EMovie),1,arch);

                  printf("Titulo: %s\n",(movies + i)->titulo);
                }
                system("pause");
                system("cls");
                break;
            case 4:
                if(CantMovies == 0)
                {
                   printf("No hay peliculas cargadas, no se generara el archivo!!\n");
                   system("pause");
                   system("cls");
                   break;
                }
                generarPagina(movies,"Index.html",CantMovies);
                break;
            case 5:
                if(CantMovies == 0)
                {
                   printf("No hay peliculas cargadas, no se generara el archivo!!\n");
                   system("pause");
                   system("cls");
                   break;
                }
                printf("Se generara el archivo binario para resguardar la informacion\n\n");
                pFileMovie = fopen("movies.bin","ab+");
                if(pFileMovie==NULL)
                 {
                   printf("Error abriendo archivo!!");
                   exit(1);
                 }
                for(i=0;i<CantMovies;i++)
                 {
                  if((movies + i)->activeStatus == 1)
                  fwrite((movies + i),sizeof(EMovie),1,pFileMovie);
                  //printf("Titulo: %s\n",(movies + i)->titulo);
                 }
                fclose(pFileMovie);
                free(movies);
                system("pause");
                system("cls");
                seguir = 'n';
                break;
        }
    }

    return 0;
}
