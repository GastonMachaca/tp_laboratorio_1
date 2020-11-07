#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Employee.h"

Employee* employee_new()
{
    Employee* auxEmp = NULL;

    auxEmp = (Employee*) malloc (sizeof(Employee));

    return auxEmp;
}

Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
    int flag=0;

    Employee* auxEmp = NULL;

    auxEmp = employee_new();

    if(auxEmp != NULL)
	{
		if(employee_setId(auxEmp,atoi(idStr))==0)
		{
			if(employee_setNombre(auxEmp,nombreStr)==0)
			{
				if(employee_setHorasTrabajadas(auxEmp,atoi(horasTrabajadasStr))==0)
				{
                    if(employee_setSueldo(auxEmp,atoi(sueldoStr))==0)
                    {
                        flag=1;
                    }
				}
			}
		}
		if(flag==0)
		{
			employee_delete(auxEmp);
			auxEmp=NULL;
		}
	}
	return auxEmp;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}

void viewEmployee (Employee* emp)
{
    if(emp != NULL)
    {
        printf(" %10d | %20s | %20d | %20d \n",emp->id,emp->nombre,emp->horasTrabajadas,emp->sueldo);
    }
}

int employee_setId(Employee* this,int id)
{
    int error = -1;

    if( this != NULL && id > 0)
    {
        this->id = id;
        error = 0;
    }

    return error;
}

int employee_setNombre(Employee* this,char* nombre)
{
    int error = -1;

    if( this != NULL && strlen(nombre) >= 0 && strlen(nombre) <= 128)
    {
        strcpy(this->nombre,nombre);
        error = 0;
    }

    return error;
}

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
    int error = -1;

    if(this !=NULL && horasTrabajadas>=0)
    {
        this->horasTrabajadas=horasTrabajadas;
        error = 0;
    }
    return error;
}

int employee_setSueldo(Employee* this,int sueldo)
{
    int error = -1;

    if(this!=NULL && sueldo>=0)
    {
        this->sueldo=sueldo;
        error = 0;
    }

    return error;
}
