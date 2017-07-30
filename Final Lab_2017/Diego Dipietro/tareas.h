typedef struct
{
  int id;
  char name[33];
  char email[65];
}eService;

typedef struct
{
  char date[11];
  char time[6];
  int serviceid;
  int gravedad;
  char msg[65];
}eLogEntry;

/** \brief  metodo Constructor de tipo eCliente*
 * \return retorna el puntero a la posicion de memoria
 *
 */
eService* serv_newServ(char[],char[],char[]);

/** \brief  metodo Constructor de tipo eCliente*
 * \return retorna el puntero a la posicion de memoria
 *
 */
eLogEntry* log_newLog(char[], char[],char[],char[],char[]);
//Pido dni
//pido numero de tirno (switc 1 Urgente--2 - regular)
//2 contadores 1 por cada tipo de tramite (1 o 2)
//asigno nro de turno y acorde al tipo lo meto en arrayList diferentes
//ArrayListUrgentes no salgo hasta que no se vacíe, luego paso al regular ArrayListUrgentes->isEmpty(ArrayListUrgentes)
//cada vez que un Cliente es atendido hago un pop y un add al arrayListAtendidosUrg
//Realizar la funcion compare en clientes.h y .c

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \return El número ingresado por el usuario
 *
 */
int getInt(char[]);

/** \brief Carga ArrayList Tareas Generales
 * \param ArrayList TareasGenerales
 * \return devuelve un 1 si fue correcta la carga de lo contrario 0
 */
int serv_loadServices(ArrayList*);

/** \brief Particiona las tareas generales segun criticidad
 * \param ArrayList TareasGenerales
 * \param ArrayList TareasUrgentes
 * \param ArrayList TareasRegulares
 * \return devuelve un 1 si fue correcta la carga de lo contrario 0
 */
int log_loadLogs(ArrayList*);

/** \brief Resuelve las tareas segun criticidad
 * \param ArrayList TareasUrgentes
 * \param ArrayList TareasRegulares
 * \return devuelve un 1 si fue correcta la carga de lo contrario 0
 */
 void arch_generateWarnings(ArrayList*,ArrayList*);
//void arch_generateWarnings(FILE*,FILE*,ArrayList*,ArrayList*);

/** \brief Resuelve las tareas segun criticidad
 * \param ArrayList TareasUrgentes
 * \param ArrayList TareasRegulares
 * \return devuelve un 1 si fue correcta la carga de lo contrario 0
 */
 void log_cantFallos(ArrayList*);

 /** \brief Resuelve las tareas segun criticidad
 * \param ArrayList TareasUrgentes
 * \param ArrayList TareasRegulares
 * \return devuelve un 1 si fue correcta la carga de lo contrario 0
 */
 void serv_maxFallos(ArrayList*, ArrayList*);

  /** \brief Resuelve las tareas segun criticidad
 * \param ArrayList TareasUrgentes
 * \param ArrayList TareasRegulares
 * \return devuelve un 1 si fue correcta la carga de lo contrario 0
 */
 int log_countFallos(ArrayList*,int);

/** \brief Valida el ingreso de solo numeros
 * \param recibe vector de tipo char a validar
 * \return devuelve 1 si la validacion es correcta, 0 si no lo es
 */
void serv_getDataService(ArrayList*, eLogEntry*,char[],char[]);

/** \brief Valida Rango del Codigo
 *  \param Vector de caracteres
 *  \return devuelve true o false si es o no valido
 */
//int validaRangoDni(char[]);

/** \brief Pide al usuario que se ingresen los datos de una persona y los carga en una estructura pasada por referencia.
 * \param Person p : Puntero a estructura Person
 * \param int : Puntero a entero
 * \return 1 si no se pudo ingreso los datos normalmente, de lo contrario 0
 */
//int task_loadClient(eTarea*,int*);

/** \brief Numerador de turnos Urgentes
 * \return numero de turno
 */
//int cli_numeratorUrg(void);

/** \brief Numerador de turnos Regulares
 * \return numero de turno
 */
//int cli_numeratorReg(void);

/** \brief Imprime una Lista.
 * \param ArrayList Urgente
 * \param ArrayList Regular
 * \return No devuelve valor
 */
void serv_printServ(ArrayList*);

/** \brief Imprime una Lista.
 * \param ArrayList Urgente
 * \param ArrayList Regular
 * \return No devuelve valor
 */
void log_printLog(ArrayList*);

/** \brief Compara Tareas.
 * \param Tarea 1
 * \param Tarea 2
 * \return 1 si el primero es mayor que el segundo, -1 si es menor que el segundo de lo contrario 0
 */
//int compareTask(void*,void*);

/** \brief Imprime Cliente a ser atendido.
 * \param Cliente
 * \return No devuelve valor
 */
//void task_printNextTask(eTarea*);

/** \brief Valida existencia de Cliente.
 * \param Cliente 1
 * \param dni de validacion
 * \return 1 existe el vaklor, de lo contrario 0
 */
//int exists(ArrayList*,int*);

