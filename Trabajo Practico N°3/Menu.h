#include "Employee.h"

#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

int menu(void);
int subMenuModificar (Employee* emp,int len,char* nombreStr,char* sueldoStr,char* horasStr);
int subMenuRemove(Employee* emp ,LinkedList* this,int auxId,int indice);
void subMenuOrdenar(LinkedList* this);

#endif // MENU_H_INCLUDED
