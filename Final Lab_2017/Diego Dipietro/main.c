#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayList.h"
#include "tareas.h"

int main()
{
    system("color 1e");
    ArrayList* arrayLoG = al_newArrayList();
    ArrayList* arrayServices = al_newArrayList();
    //eLogEntry* log;
    //eService* serv;
    //FILE* pArchWar = NULL;
    //FILE* pArchErr = NULL;
    //printf("Hello world!\n");
    int opcion;
    char seguir = 's';
    while(seguir=='s')
    {
      opcion = getInt("1 - Leer Log\n2 - Procesar Informacion\n3 - Mostrar Estadisticas\n4 - Salir\n\nIngrese una opcion: ");
      while(opcion < 1 || opcion > 5)
        {
            opcion = getInt("Error, ingrese una opcion valida del menu: ");
        }
      switch(opcion)
       {
        case 1:
            if(!serv_loadServices(arrayServices))
            {
               printf("Error en la carga de los servicios!!\n");
               break;
            }
            if(!log_loadLogs(arrayLoG))
            {
               printf("Error en la carga de Logs!!\n");
               break;
            }
            serv_printServ(arrayServices);
            log_printLog(arrayLoG);
            printf("Datos cargados correctamente!!\n");
            system("pause");
            system("cls");
            break;
        case 2:
            if((arrayServices->isEmpty(arrayServices) == 1)||(arrayLoG->isEmpty(arrayLoG) == 1))
            {
               printf("No Cargo los datos principales!!\n");
               system("pause");
               system("cls");
               break;
            }
            //arch_generateWarnings(pArchWar,pArchErr,arrayServices,arrayLoG);
            arch_generateWarnings(arrayServices,arrayLoG);
            system("pause");
            system("cls");
            break;
        case 3:
            if((arrayServices->isEmpty(arrayServices) == 1)||(arrayLoG->isEmpty(arrayLoG) == 1))
            {
               printf("No Cargo los datos principales!!\n");
               system("pause");
               system("cls");
               break;
            }
            log_cantFallos(arrayLoG);
            system("pause");
            system("cls");
            serv_maxFallos(arrayServices,arrayLoG);
            system("pause");
            system("cls");
            break;
        case 4:
            seguir = 'n';
            printf("Hasta la proxima!!\n");
            system("pause");
            system("cls");
            arrayLoG->deleteArrayList(arrayLoG);
            arrayServices->deleteArrayList(arrayServices);
            break;
       }
    }
    return 0;
}
