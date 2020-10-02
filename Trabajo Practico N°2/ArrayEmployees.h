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

/** \brief Para indicar que todas las posiciones de la matriz est�n vac�as,
 *         esta funci�n pone la bandera (isEmpty) en 1 en todas
 *         las posici�nes de la matriz.
 *
 * \param lista[] Employee Array de empleados.
 * \param tam int Tama�o del array.
 * \return int Devuelve (1) si hay Error [Tama�o del array no v�lido o puntero NULL] - (0) si est� bien
 *
 */
int initEmployees(Employee lista[], int tam);

/** \brief Agregar en una lista existente de empleados los valores recibidos como par�metros
 *         en la primera posici�n vac�a.
 *
 * \param lista[] Employee Array de empleados.
 * \param tam int Tama�o del array.
 * \param id int Cantidad de legajos.
 * \return int Devuelve (1) si hay Error [Tama�o del array no v�lido o puntero NULO o un mal inicio del ID] - (0) si est� bien
 *
 */
int addEmployee(Employee lista[], int tam, int id);

/** \brief Encuentra un empleado por Id y devuelve la posici�n del �ndice en el array.
 *
 * \param empleado[] Employee Array de empleados.
 * \param tam int Tama�o del array.
 * \param id int Cantidad de legajos.
 * \return int Posici�n de �ndice de empleado o (-1) si el empleado no es encontrado.
 *
 */
int findEmployeeById(Employee empleado[], int tam,int id);

/** \brief Eliminar un empleado por Id (poner la bandera isEmpty en 1)
 *
 * \param lista[] Employee Array de empleados.
 * \param tam int Tama�o del array.
 * \param id int Cantidad de legajos.
 * \return int Devuelve (1) si Error [Tama�o del array no v�lido o NULL o si no puede Buscar un empleado] - (0) si est� bien - (2) Si se cancelo la operacion.
 *
 */
int removeEmployee(Employee lista[], int tam, int id);

/** \brief Ordena los elementos en array de empleados, el orden de los argumentos indica el orden ASCENDENTE o DESCENDENTE.
 *
 * \param lista[] Employee Array de empleados.
 * \param tam int Tama�o del array.
 * \param order int Direccion de ordenamiento - 1 para ascendente - 0 para descendente.
 * \return int Devuelve (-1) si hay Error [Tama�o del array no v�lido o NULL] - (0) si est� bien
 *
 */
int sortEmployees(Employee lista[], int tam, int order);

/** \brief Imprime el contenido del array de empleados.
 *
 * \param empleado[] Employee Array de empleados.
 * \param tam int Tama�o del array.
 * \return int Devuelve (-1) si hay Error [Tama�o del array no v�lido o NULL] - (0) si est� bien
 *
 */
int printEmployees(Employee empleado[],int tam);


#endif // ARRAYEMPLOYEES_H_INCLUDED
