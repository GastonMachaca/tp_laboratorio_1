#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}typedef Employee;

/** \brief Para indicar que todas las posiciones de la matriz están vacías,
 *         esta función pone la bandera (isEmpty) en 1 en todas
 *         las posiciónes de la matriz.
 *
 * \param lista[] Employee Array de empleados.
 * \param tam int Tamaño del array.
 * \return int Devuelve (1) si hay Error [Tamaño del array no válido o puntero NULL] - (0) si está bien
 *
 */
int initEmployees(Employee lista[], int tam);

/** \brief Agregar en una lista existente de empleados los valores recibidos como parámetros
 *         en la primera posición vacía.
 *
 * \param lista[] Employee Array de empleados.
 * \param tam int Tamaño del array.
 * \param id int Cantidad de legajos.
 * \return int Devuelve (1) si hay Error [Tamaño del array no válido o puntero NULO o un mal inicio del ID] - (0) si está bien
 *
 */
int addEmployee(Employee lista[], int tam, int id);

/** \brief Encuentra un empleado por Id y devuelve la posición del índice en el array.
 *
 * \param empleado[] Employee Array de empleados.
 * \param tam int Tamaño del array.
 * \param id int Cantidad de legajos.
 * \return int Posición de índice de empleado o (-1) si el empleado no es encontrado.
 *
 */
int findEmployeeById(Employee empleado[], int tam,int id);

/** \brief Eliminar un empleado por Id (poner la bandera isEmpty en 1)
 *
 * \param lista[] Employee Array de empleados.
 * \param tam int Tamaño del array.
 * \param id int Cantidad de legajos.
 * \return int Devuelve (1) si Error [Tamaño del array no válido o NULL o si no puede Buscar un empleado] - (0) si está bien - (2) Si se cancelo la operacion.
 *
 */
int removeEmployee(Employee lista[], int tam, int id);

/** \brief Ordena los elementos en array de empleados, el orden de los argumentos indica el orden ASCENDENTE o DESCENDENTE.
 *
 * \param lista[] Employee Array de empleados.
 * \param tam int Tamaño del array.
 * \param order int Direccion de ordenamiento - 1 para ascendente - 0 para descendente.
 * \return int Devuelve (-1) si hay Error [Tamaño del array no válido o NULL] - (0) si está bien
 *
 */
int sortEmployees(Employee lista[], int tam, int order);

/** \brief Imprime el contenido del array de empleados.
 *
 * \param empleado[] Employee Array de empleados.
 * \param tam int Tamaño del array.
 * \return int Devuelve (-1) si hay Error [Tamaño del array no válido o NULL] - (0) si está bien
 *
 */
int printEmployees(Employee empleado[],int tam);


#endif // ARRAYEMPLOYEES_H_INCLUDED
