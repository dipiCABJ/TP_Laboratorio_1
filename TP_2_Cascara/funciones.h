#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct
{
  int dni;
  char nombre[51];
  int edad;
  int activeStatus;
}persona;

/** \brief Inicializa el Vector tipo estructura el estado en -1
 *
 * \param vector de Persona
 * \param cantidad de elementos
 * \param valor de inicializacion
 * \return no devuelve valor
 *
 */
void inicializarActiveStatus(persona[],int,int);

/** \brief Busca lugar libre en el vector de estructuras para la carga de datos
 *
 * \param vector de tipo Persona
 * \param cantidad de elementos
 * \param valor de busqueda
 * \return devuelve indice donde encuentra coincidencia con el parametro de busqueda
 *
 */
int buscarIdx(persona[],int,int);

/** \brief Busca DNI en el vector de estructuras durante el alta de persona
 *
 * \param vector de tipo Persona
 * \param cantidad de elementos
 * \param valor de busqueda
 * \return devuelve indice donde encuentra coincidencia con el parametro de busqueda
 *
 */
int buscarIdxDni(persona[],int,int);

/** \brief Obtiene la carga de un entero
 *
 * \param recibe un mensaje que sera mostrado al usuario
 * \return devuelve numero ingresado como opcion
 *
 */
int obtenerEntero(char[]);

/** \brief Obtiene un vector de solo numeros, llama a la funcion "IsNumeric"
 *
 * \param Mensaje que sera mostrado al usuario
 * \param vector donde se cargara el ingreso
 * \return luego de la validacion numerica, devuelve un 1 si fue correcta la carga o 0 si no paso la validacion numerica
 *
 */
int obtenerNumeros(char [],char []);

/** \brief Obtiene un vector de solo letras, llama a la funcion "IsString"
 *
 * \param Mensaje que sera mostrado al usuario
 * \param vector donde se cargara el ingreso
 * \return luego de la validacion caracter a caracter, devuelve un 1 si fue correcta la carga o 0 si no paso la validacion
 *
 */
int obtenerCadena(char[],char[]);

/** \brief Obtiene la carga de un entero
 *
 * \param recibe un mensaje que sera mostrado al usuario
 * \return devuelve numero ingresado como edad
 *
 */
int obtenerEdad(char []);

/** \brief Valida el ingreso de solo letras
 *
 * \param recibe vector de tipo char a validar
 * \return devuelve 1 si la validacion es correcta, 0 si no lo es
 *
 */
int isString(char []);

/** \brief Valida el ingreso de solo numeros
 *
 * \param recibe vector de tipo char a validar
 * \return devuelve 1 si la validacion es correcta, 0 si no lo es
 *
 */
int isNumeric(char []);

/** \brief Ordena el vector de estructuras por nombre
 *
 * \param vector de tipo persona
 * \param variable de tipo persona
 * \param cantidad de elementos
 * \return no devuelve nada
 *
 */
void ordenarListaNombre(persona[],persona,int);

/** \brief Muestra el vector ordenado segun la funcion de orden
 *
 * \param vector de tipo persona
 * \param cantidad de elementos
 * \return no devuelve nada
 *
 */
void mostrarListaOrdenada(persona[],int);

/** \brief Inicializa el vector de edades con asteriscos
 *
 * \param vector de edades menores a 18
 * \param vector de edades de 18-35
 * \param vector de edades mayores a 35
 * \param cantidad de elementos
 * \return no devuelve nada
 *
 */
void inicializaVectorEdades(char[],char[],char[],char,int);

/** \brief Borra asteriscos del vector de edades
 *
 * \param vector de edades
 * \param cantidad de elementos
 * \return no devuelve nada
 *
 */
void BorrarAsteriscos(char[],int,int);

/** \brief Imprime el grafico de edades
 *
 * \param vector de edades menores a 18
 * \param vector de edades entre 19-35
 * \param vector de edades mayores a 35
 * \param cantidad de elementos
 * \return no devuelve nada
 *
 */
void ImprimeGrafico(char[],char[],char[],int);
//void mostrarClientes(persona);
#endif // FUNCIONES_H_INCLUDED
