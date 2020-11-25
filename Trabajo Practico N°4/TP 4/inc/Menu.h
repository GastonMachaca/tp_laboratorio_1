#include "Employee.h"

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED


/** \brief Menu principal del programa.
 *
 * \param void
 * \return int
 *
 */
int menu(void);
/** \brief Menu para modificar empleados.
 *
 * \param emp Employee*
 * \param len int
 * \param nombreStr char*
 * \param sueldoStr char*
 * \param horasStr char*
 * \return int
 *
 */
int subMenuModificar(Employee* emp,int len,char* nombreStr,char* sueldoStr,char* horasStr);
/** \brief Menu para eliminar empleados.
 *
 * \param emp Employee*
 * \param this LinkedList*
 * \param auxId int
 * \param indice int
 * \return int
 *
 */
int subMenuRemove(Employee* emp ,LinkedList* this,int auxId,int indice);
/** \brief Menu para el ordenamiento ascendente o descendente.
 *
 * \param this LinkedList*
 * \return void
 *
 */
void subMenuOrdenar(LinkedList* this);

#endif // MENU_H_INCLUDED
