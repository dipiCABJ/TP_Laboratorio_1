#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include "ArrayList.h"
#include "tareas.h"

//Contadores de turnos globales
//int numeradorTU = 0;
//int numeradorTR = 0;
//

eService* serv_newServ(char id[],char nombre[], char mail[])
{
   eService* auxServ = NULL;
   auxServ = (eService*)malloc(sizeof(eService));
   if(auxServ != NULL)
   {
      auxServ->id = atoi(id);
      strcpy(auxServ->name,nombre);
      strcpy(auxServ->email,mail);
   }
   return auxServ;
}

eLogEntry* log_newLog(char fecha[],char hora[],char servid[],char grav[],char msg[])
{
   eLogEntry* auxLog = NULL;
   auxLog = (eLogEntry*)malloc(sizeof(eLogEntry));
   if(auxLog != NULL)
   {
      strcpy(auxLog->date,fecha);
      strcpy(auxLog->time,hora);
      auxLog->serviceid = atoi(servid);
      auxLog->gravedad = atoi(grav);
      strcpy(auxLog->msg,msg);
   }
   return auxLog;
}

int getInt(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
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

int validaRangoDni(char codigo[])
{
  if(strlen(codigo) < 6 || strlen(codigo) > 8)
    {
         return 0;
    }
  return 1;
}

//void arch_generateWarnings(FILE* archWar,FILE* archErr,ArrayList* service,ArrayList* logs)
void arch_generateWarnings(ArrayList* service,ArrayList* logs)
{
    int i,grave;
    int flagWar = 0,flagErr = 0,flagPrint = 0;
    char auxNomServ[33],auxEmail[65];
    FILE* archWar = NULL;
    FILE* archErr = NULL;
    archWar = fopen("warnings.txt","w");
    archErr = fopen("errors.txt","w");
    eLogEntry* log;
    system("cls");
    for(i=0;i<logs->len(logs);i++)
      {
       log = logs->get(logs,i);
       grave = log->gravedad;
       if(grave < 3)
         continue;
       if(grave == 3)
         {
           if(log->serviceid == 45)
              continue;
            if(!flagWar)
            {
              fprintf(archWar,"fecha;hora;nombre servicio;mensaje de error;E-mail soporte\n");
              flagWar = 1;
            }
            if(flagWar)
            {
              serv_getDataService(service,log,auxNomServ,auxEmail);
              fprintf(archWar,"%s;%s;%s;%s;%s\n",log->date,log->time,auxNomServ,log->msg,auxEmail);
            }
         }
       if(grave >= 4 && grave <= 7)
         {
            if(!flagPrint)
              { printf("-----------------------------------------------------------------\n");
                printf("FECHA\t\tHORA\tSERVICIO\tMSG ERROR\tGRAVEDAD\n");
                printf("-----------------------------------------------------------------\n");
                flagPrint = 1;
              }
            if(flagPrint)
            {
              serv_getDataService(service,log,auxNomServ,auxEmail);
              printf("%s\t%s\t%s\t%s\t\t%d\n",log->date,log->time,auxNomServ,log->msg,log->gravedad);
            }
         }
        if(grave > 7)
        {
           if(!flagErr)
            {
              fprintf(archErr,"fecha;hora;nombre servicio;mensaje de error;email soporte\n");
              flagErr = 1;
            }
           if(flagErr)
           {
             serv_getDataService(service,log,auxNomServ,auxEmail);
             fprintf(archErr,"%s;%s;%s;%s;%s\n",log->date,log->time,auxNomServ,log->msg,auxEmail);
           }
        }
      }
    fclose(archWar);
    fclose(archErr);
}


void serv_getDataService(ArrayList* service,eLogEntry* log,char servName[],char mailSupport[])
{
  eService* serv;
  int j;
  for(j=0;j<service->len(service);j++)
   {
     serv = service->get(service,j);
     if(log->serviceid == serv->id)
      {
        strcpy(servName,serv->name);
        strcpy(mailSupport,serv->email);
        break;
      }
   }
}

void log_cantFallos(ArrayList* logs)
{
   int contMen_3 = 0, cont_3 = 0, cont4_7 = 0, contMay_7 = 0;
   int i;
   eLogEntry* log = NULL;
   printf("Length de ArrayList: %d\n\n",logs->len(logs));
   for(i=0;i<logs->len(logs);i++)
   {
      log = logs->get(logs,i);
      if(log != NULL)
      {
         if(log->gravedad > 7)
            contMay_7++;
         if(log->gravedad < 3)
            contMen_3++;
         if(log->gravedad >= 4 && log->gravedad <= 7)
            cont4_7++;
         if(log->gravedad == 3)
            cont_3++;
      }
   }
  system("cls");
  printf("Cantidad de Fallos con gravedad menor a 3: %d\n",contMen_3);
  printf("Cantidad de Fallos con gravedad igual a 3: %d\n",cont_3);
  printf("Cantidad de Fallos con gravedad entre 4 y 7 (inclusive): %d\n",cont4_7);
  printf("Cantidad de Fallos con gravedad mayor a 7: %d\n",contMay_7);
}

void serv_printServ(ArrayList* service)
{
   system("cls");
   eService* serv;
   int i;
   printf("------------------------------------------------------------\n");
   printf("ID\t\tNOMBRE\t\t\t\tE-MAIL\n");
   printf("------------------------------------------------------------\n");
   if(service->isEmpty(service) == 0)
   {
      for(i=0;i<service->len(service);i++)
      {
          serv = service->get(service,i);
          printf("%d\t\t%s\t\t%s\n",serv->id,serv->name,serv->email);
      }
   }
   system("pause");
}

void log_printLog(ArrayList* logs)
{
   system("cls");
   eLogEntry* log;
   int i;
   printf("----------------------------------------------------------------------\n");
   printf("DATE\t\t\tTIME\t\tSERVID\tGRAVEDAD\tMSG\n");
   printf("----------------------------------------------------------------------\n");
   if(logs->isEmpty(logs) == 0)
   {
      for(i=0;i<logs->len(logs);i++)
      {
          log = logs->get(logs,i);
          printf("%s\t\t%s\t\t%d\t%d\t%s\n",log->date,log->time,log->serviceid,log->gravedad,log->msg);
      }
   }
}


int obtenerNumeros(char msj[],char aux[])
{
    char cad[20];
    printf("%s",msj);
    fflush(stdin);
    gets(cad);
    if(!validaRangoDni(cad))
        return 0;
    if(isNumeric(cad))
    {
      strcpy(aux,cad);
      return 1;
    }
    return 0;
}

int serv_loadServices(ArrayList* service)
{
  int retorno = 0;
  char id[50];
  char nombre[50],email[50];
  char fileName[15];
  FILE* services = NULL;
  eService* serv;
  strcpy(fileName,"services.txt");
  services = fopen(fileName,"r");
  if(services == NULL)
    return retorno;
  while(!feof(services))
   {
     if (serv == NULL || service == NULL)
        return retorno;
     fscanf(services,"%[^;];%[^;];%[^\n]\n",id,nombre,email);//,criticidad);//,criticidad,cantidad);//);criticidad,cantidad);
     serv = serv_newServ(id,nombre,email);
     if(serv == NULL)
        return retorno;
     service->add(service,serv);
   }
   fclose(services);
   retorno = 1;
   return retorno;
}


int log_loadLogs(ArrayList* logs)
{
  int retorno = 0;
  char servid[50],date[11],time[6];
  char gravedad[50],msg[50];
  char fileName[15];
  FILE* pLog = NULL;
  eLogEntry* log;
  strcpy(fileName,"log.txt");
  pLog = fopen(fileName,"r");
  if(pLog == NULL)
    return retorno;
  while(!feof(pLog))
   {
     if (log == NULL || pLog == NULL)
        return retorno;
     fscanf(pLog,"%[^;];%[^;];%[^;];%[^;];%[^\n]\n",date,time,servid,gravedad,msg);//,criticidad);//,criticidad,cantidad);//);criticidad,cantidad);
     log = log_newLog(date,time,servid,gravedad,msg);
     if(log == NULL)
        return retorno;
     logs->add(logs,log);
   }
   fclose(pLog);
   retorno = 1;
   return retorno;
}

void serv_maxFallos(ArrayList* service, ArrayList* logs)
{
  int count = 0;
  int i, xId,max = INT_MIN;
  char nombre[33];
  eService* serv = NULL;
  printf("SERVICIO\t\tCANTIDAD ERRORES\n");
  printf("----------------------------------------\n");
  for(i=0;i<service->len(service);i++)
    {
       serv = al_get(service,i);
       xId = serv->id;
       count = log_countFallos(logs,xId);
       printf("%s\t\t\t%d\n",serv->name,count);
       if(count > max)
       {
          max = count;
          strcpy(nombre,serv->name);
       }
       count = 0;
    }
    printf("\nEl Servicio con mas errores fue: %s con %d errores\n",nombre,max);
}

int log_countFallos(ArrayList* logs,int id)
{
   eLogEntry* log = NULL;
   int i, cant = 0;
   for(i=0;i<logs->len(logs);i++)
   {
      log = logs->get(logs,i);
      if(log->serviceid != id)
        continue;
      cant++;
   }
   return cant;
}
