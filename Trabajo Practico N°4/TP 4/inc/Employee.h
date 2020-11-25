#include "LinkedList.h"
#ifndef employee_H_INCLUDED
#define employee_H_INCLUDED
typedef struct
{
    int id;
    char nombre[128];
    int horasTrabajadas;
    int sueldo;
}Employee;

Employee* employee_new();
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);
void employee_delete();

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);
int ordenXid(void* empA,void* empB);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int ordenXnombre(void* empA,void* empB);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);
int ordenXhora(void* empA,void* empB);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);
int ordenXsueldo(void* empA,void* empB);

void viewEmployee (Employee* emp);
int validNombre(char* cadena,int longitud);
int findById(LinkedList* this, int id);
int proximoId();

#endif // employee_H_INCLUDED
