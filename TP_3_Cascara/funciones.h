#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[200];
    int activeStatus;
}EMovie;

/** \brief Inicializa el Vector tipo estructura en estado en -1
 *
 * \param vector de moviesmovie->linkImagen
 * \param cantidad de elementos
 * \param valor de inicializacion
 * \return no devuelve valor
 *
 */
void inicializarActiveStatus(EMovie movie[],int cant_elem,int valor);
/**
 *  Agrega una pelicula al archivo binario
 *  @param movie la estructura a ser agregada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo agregar la pelicula o no
 */
int agregarPelicula(EMovie*,EMovie*,int*);

/**
 *  Borra una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo eliminar la pelicula o no
 */
int borrarPelicula(EMovie*,int);

/**
 *  Modifica una pelicula del archivo binario
 *  @param movie la estructura a ser eliminada al archivo
 *  @return retorna 1 o 0 de acuerdo a si pudo modificar la pelicula o no
 */
int modificarPelicula(EMovie* movie,int);

/**
 *  Genera un archivo html a partir de las peliculas cargadas en el archivo binario.
 *  @param lista la lista de peliculas a ser agregadas en el archivo.
 *  @param nombre el nombre para el archivo.
 */
void generarPagina(EMovie lista[], char nombre[],int);

/**
 *  Genera espacio en memoria para el array de tipo EMovie
 *  @param array de estructuras de tipo EMovie
 *  @param cantidad de elementos del array de tipo EMovie
 *  @return Puntero al comienzo de la posicion de memoria de ese array asignado
 */
EMovie* newMovies();

/** \brief Obtiene un vector de solo numeros, llama a la funcion "IsNumeric"
 *
 * \param Mensaje que sera mostrado al usuario
 * \param vector donde se cargara el ingreso
 * \return luego de la validacion numerica, devuelve un 1 si fue correcta la carga o 0 si no paso la validacion numerica
 *
 */
int obtenerNumeros(char[],char[]);

/** \brief Valida el ingreso de solo numeros
 *
 * \param recibe vector de tipo char a validar
 * \return devuelve 1 si la validacion es correcta, 0 si no lo es
 *
 */
int isNumeric(char[]);

/** \brief Obtiene un vector de solo letras, llama a la funcion "IsString"
 *
 * \param Mensaje que sera mostrado al usuario
 * \param vector donde se cargara el ingreso
 * \return luego de la validacion caracter a caracter, devuelve un 1 si fue correcta la carga o 0 si no paso la validacion
 *
 */
int obtenerCadena(char[],char[]);

/** \brief Valida el ingreso de solo letras
 *
 * \param recibe vector de tipo char a validar
 * \return devuelve 1 si la validacion es correcta, 0 si no lo es
 *
 */
int isString(char[]);

/**
 * \brief Busca un idx libre para la carga de datos
 * \param vector como puntero a cargar
 * \param cantidad de elementos a recorrer
 * \param vector a buscar en activeStatus
 * \return El indice libre para la carga
 *
 */
int buscarIdxLibre(EMovie*,int,int);

/** \brief Pide un entero al usuario
 *
 * \param Mensaje que sera mostrado al usuario
 * \return devuelve el entero cargado
 *
 */
int getInt(char []);

/**
 * \brief Verifica si el valor recibido contiene solo letras, números y puede tener espacios
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char[]);

/**
 *  Genera un realloc de espacio en memoria para el array de tipo EMovie
 *  @param array de estructuras de tipo EMovie
 *  @param cantidad de elementos del array de tipo EMovie
 *  @return Puntero al comienzo de la posicion de memoria de ese array asignado
 */
EMovie* newVectorMovies(EMovie*,int);

#endif // FUNCIONES_H_INCLUDED
