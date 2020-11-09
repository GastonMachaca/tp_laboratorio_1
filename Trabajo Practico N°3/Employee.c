#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

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

int employee_getId(Employee* this,int* id)
{
    int error = -1;

    if(this != NULL && id != NULL)
    {
        *id = this->id;
        error = 0;
    }

    return error;
}


int employee_setNombre(Employee* this,char* nombre)
{
    int error = -1;

    if( this != NULL && nombre != NULL)
    {
        if(validNombre(nombre,strlen(nombre)))
        {
            strcpy(this->nombre,nombre);
            error = 0;
        }
    }
    return error;
}

int employee_getNombre(Employee* this,char* nombre)
{
	int error = -1;
	if(this != NULL && nombre != NULL)
	{
		error = 0;
		strncpy(nombre,this->nombre,strlen(nombre));
		//strcpy(nombre,this->nombre);
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

int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
    int error = -1;

	if(this != NULL && horasTrabajadas != NULL)
	{
		error = 0;
		*horasTrabajadas = this->horasTrabajadas;
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

int employee_getSueldo(Employee* this,int* sueldo)
{
    int error = -1;

	if(this != NULL && sueldo != NULL)
	{
		error = 0;
		*sueldo = this->sueldo;
	}

	return error;
}

int findById(LinkedList* this, int id)
{
    int indice = -1;
    int len = ll_len(this);
    int auxId;

    Employee* empleado;

    for(int i = 0; i < len; i++)
    {
        empleado=(Employee*)ll_get(this,i);
        employee_getId(empleado,&auxId);

        if(auxId == id)
        {
            indice = i;
            break;
        }
    }
    if(indice == -1)
    {
        printf("\n No se encontro el id\n");
    }
    return indice;
}

int validNombre(char* cadena,int longitud)
{
	int i=0;
	int error = 1;

	if(cadena != NULL && longitud > 0)
	{
		for(i=0 ; cadena[i] != '\0' && i < longitud; i++)
		{
			if((cadena[i] < 'A' || cadena[i] > 'Z' ) && (cadena[i] < 'a' || cadena[i] > 'z' ))
			{
				error = 0;
				break;
			}
		}
	}
	return error;
}

static int obtenerId()
{
    static int id=1000;
    id++;
    return id;
}
int proximoId()
{
    return obtenerId();
}

int ordenXid(void* empA,void* empB)
{
    int error = 0;

    Employee* auxEmpA;
    Employee* auxEmpB;

    if(empA != NULL && empB != NULL)
    {
        auxEmpA=(Employee*)empA;
        auxEmpB=(Employee*)empB;

        if(auxEmpA->id == auxEmpB->id)
        {
            error = 0;
        }
        else
        {
            if(auxEmpA->id > auxEmpB->id)
            {
                error = 1;
            }
            else
            {
                error = -1;
            }
        }
    }

    return error;
}

int ordenXnombre(void* empA,void* empB)
{
    int error = 0;

    Employee* auxEmpA;
    Employee* auxEmpB;

    if(empA != NULL && empB != NULL)
    {
        auxEmpA=(Employee*)empA;
        auxEmpB=(Employee*)empB;

        error = strcmp(auxEmpA->nombre,auxEmpB->nombre);

    }

    return error;
}
int ordenXsueldo(void* empA,void* empB)
{
    int error = 0;

    Employee* auxEmpA;
    Employee* auxEmpB;

    if(empA != NULL && empB != NULL)
    {
        auxEmpA=(Employee*)empA;
        auxEmpB=(Employee*)empB;

        if(auxEmpA->sueldo == auxEmpB->sueldo)
        {
            error = 0;
        }
        else
        {
            if(auxEmpA->sueldo > auxEmpB->sueldo)
            {
                error = 1;
            }
            else
            {
                error = -1;
            }
        }
    }

    return error;
}

int ordenXhora(void* empA,void* empB)
{
    int error = 0;

    Employee* auxEmpA;
    Employee* auxEmpB;

    if(empA != NULL && empB != NULL)
    {
        auxEmpA=(Employee*)empA;
        auxEmpB=(Employee*)empB;

        if(auxEmpA->horasTrabajadas == auxEmpB->horasTrabajadas)
        {
            error = 0;
        }
        else
        {
            if(auxEmpA->horasTrabajadas > auxEmpB->horasTrabajadas)
            {
                error = 1;
            }
            else
            {
                error = -1;
            }
        }
    }

    return error;
}
