#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/** \brief Muestra el menu principal para seleccion de opciones.
 *
 * \return int Opcion (1-5) para seleccion.
 *
 */
int menu();

/** \brief Cuenta los id para los empleados.
 *
 * \param lista[] Employee Array de empleados.
 * \param tam int Tamaño del array.
 * \param id int Cantidad de legajos.
 * \return int Siguiente id.
 *
 */
int visualOpcion1(Employee lista[],int tam,int id);

/** \brief Mostramos el legajo de los empleados y el informe de salarios.
 *
 * \param lista[] Employee Array de empleados.
 * \param tam int Tamaño del array.
 * \param error int 0 - Si el listado esta cargado correctamente , -1 si hubo algun incoveniente. , 2 si se produjo con exito el informe de salarios.
 * \return void
 *
 */
void visualError(Employee lista[],int tam,int error);

/** \brief Actualizamos la bandera si el array de empleados se encuentra cargado o no.
 *
 * \param lista[] Employee Array de empleados.
 * \param tam int Tamaño del array.
 * \return int Bandera (0) si array de empleados esta cargado, (1) si esta libre .
 *
 */
int negarBandera(Employee lista[],int tam);

/** \brief Buscamos si hay espacio o no disponible en el array de empleados.
 *
 * \param lista[] Employee Array de empleados.
 * \param tam int Tamaño del array.
 * \return int (-1) si esta lleno o el indice donde hay un espacio libre.
 *
 */
int buscarLibre(Employee lista[],int tam);

/** \brief Mostramos en un listado el array de empleados.
 *
 * \param unEmpleado Employee Array de empleados.
 * \return void
 *
 */
void printEmployee(Employee unEmpleado);

/** \brief Menu al acceder a la opcion 2 "modificar" del menu principal.
 *
 * \param lista[] Employee Array de empleados.
 * \param indice int Id de empleado a modificar.
 * \param error int Certifica si se completo la operacion.
 * \return int (0) si se completo la operacion , (2) si se cancelo.
 *
 */
int subMenuModificar(Employee lista[],int indice,int error);

/** \brief Menu al acceder a la opcion 4 "informar" del menu principal.
 *
 * \param lista[] Employee Array de empleados.
 * \param tam int Tamaño del array.
 * \param id int Cantidad de legajos.
 * \return void
 *
 */
void subMenuInformar(Employee lista[],int tam,int id);

/** \brief Busca al empleado por ID y para despues modificarlo (vinculado con subMenuModificar).
 *
 * \param lista[] Employee Array de empleados.
 * \param tam int Tamaño del array.
 * \param id int Cantidad de legajos.
 * \return int (0) si se completo la operacion , (2) si se cancelo, (1) si no hay ningun dato ingresado.
 *
 */
int modifEmployee(Employee lista[], int tam, int id);

#endif // MENU_H_INCLUDED
