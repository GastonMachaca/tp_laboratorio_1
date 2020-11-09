#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Extras.h"
#include "parser.h"
#include "Menu.h"

#define TAM 128

int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
    int error = -1;

    FILE* pFile;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile = fopen(path, "r");

        if(pFile != NULL)
        {
            parser_EmployeeFromText(pFile, pArrayListEmployee);
            error = 1;
            printf("Cargado con exito.\n");
        }
        fclose(pFile);
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
        error = 0;
    }

    return error;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
    int error = -1;

    FILE* pFile=NULL;

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"rb");

        if(pFile != NULL)
        {
            if(!parser_EmployeeFromBinary(pFile,pArrayListEmployee))
            {
                printf("Cargado con exito.\n");
                error = 1;
            }
        }
    }
    else
    {
        printf("No se pudo abrir el archivo\n");
        error=0;
    }

    fclose(pFile);

    return error;
}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{
    int error = -1;

    char confirma;
    char nombreStr[TAM];
    char idStr[TAM];
    char horasStr[TAM];
    char sueldoStr[TAM];

    Employee* newEmployee=employee_new();

    if(pArrayListEmployee != NULL)
    {
        system("cls");

        printf(" ***Alta Empleados*** \n");

        sprintf(idStr,"%d",proximoId());

        confirmName(nombreStr,TAM,"\nIngrese un nombre:","Error!!!,vuelva a intentarlo");

        confirmNumbers(horasStr,TAM,"\nIngrese las horas de trabajo:","Error!!!,verifique lo ingresado.");

        confirmNumbers(sueldoStr,TAM,"\nIngrese el sueldo:","Error!!!,verifique lo ingresado.");

        printf("\nConfirma alta empleado?: ");
        fflush(stdin);
        confirma = tolower(getchar());
        while(confirma != 's' && confirma != 'n')
        {
            printf("\nError al confirmar, ingrese s (si) o n (no) para confirmar: ");
            fflush(stdin);
            confirma = tolower(getchar());
        }

        if(confirma=='s')
        {
            newEmployee=employee_newParametros(idStr, nombreStr, horasStr, sueldoStr);
            ll_add(pArrayListEmployee, newEmployee);
            printf("\nExito!! ");
            error=1;
        }
        else
        {
            printf("Se cancelo la operacion\n");
            error = 0;
        }
    }
    return error;
}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
    int error = -1;
    int indice;
    int auxId;

    char idStr[TAM];
    char nombreStr[TAM];
    char horasStr[TAM];
    char sueldoStr[TAM];

    Employee* auxEmp = NULL;

    if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee)== 0)
    {
        system("cls");

        printf("*** Modificar Empleados ***\n\n");

        controller_ListEmployee(pArrayListEmployee);

        confirmNumbers(idStr,TAM,"Ingrese el ID a modificar: ","Error!!!,vuelva a ingresar un ID.");

        auxId=atoi(idStr);

        indice = findById(pArrayListEmployee,auxId);

        if(indice != -1)
        {
            auxEmp = ll_get(pArrayListEmployee, indice);

            error = subMenuModificar(auxEmp,TAM,nombreStr,sueldoStr,horasStr);
        }

    }
    else
    {
        printf("\nNo se puede acceder a la modificacion!.");
        error = 0;
    }

    return error;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
    int error = -1;
    int auxId;
    int indice;

    char idStr[TAM];

    Employee* auxEmp;

    if(pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)== 0)
    {
        system("cls");
        printf("*** Baja Empleados ***\n\n");
        controller_ListEmployee(pArrayListEmployee);
        confirmNumbers(idStr,TAM,"Ingrese id para proceder con la eliminacion: ","Error al buscar ID.Vuelva a intentarlo.");
        auxId= atoi(idStr);
        indice = findById(pArrayListEmployee,auxId);

        if(indice != -1)
        {
            error = subMenuRemove(auxEmp,pArrayListEmployee,auxId,indice);
        }
    }
    else
    {
        printf("No hay empleados cargados\n\n");
        error = 0;
    }

    return error;

}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
    int error = -1;
    int tam = ll_len(pArrayListEmployee);

    Employee* auxEmp;


    if(pArrayListEmployee != NULL && ll_isEmpty(pArrayListEmployee)== 0)
    {

        system("cls");
        printf("                         ***LISTA DE EMPLEADOS***                            \n\n");

        printf("\n     ID     |        NOMBRE        |   HORAS TRABAJADAS   |      SUELDO  \n");
        printf("--------------------------------------------------------------------------------\n");


        for(int i=0;i<tam;i++)
        {
            auxEmp = (Employee*) ll_get(pArrayListEmployee,i);
            if( auxEmp != NULL)
            {
                viewEmployee( auxEmp );
                error=1;
                auxEmp = NULL;
            }
        }
    }
    else
    {
        printf("\n No hay empleados cargados\n\n");
        error = 0;
    }

    return error;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
    int error= -1;

    if(pArrayListEmployee!=NULL && ll_isEmpty(pArrayListEmployee)== 0)
    {
        system("cls");
        printf("                         ***ORDENAR EMPLEADOS***                            \n\n");

        subMenuOrdenar(pArrayListEmployee);
        error = 1;
    }
    else
    {
        printf("\nNo se cargaron empleados.");
        error = 0;
    }

    return error;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
    int error = -1;
    int tam;
    int auxId;
    int auxSueldo;
    int auxHoras;

    char nombre[25];

    FILE* pFile;

    Employee* auxEmp=NULL;

    tam=ll_len(pArrayListEmployee);

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"w");

        if(pFile != NULL)
        {
            fprintf(pFile,"ID,Nombre,Horas Trabajadas,Sueldo\n");

            for(int i=0; i<tam; i++)
            {
                auxEmp=(Employee*)ll_get(pArrayListEmployee,i);

                if(auxEmp != NULL)
                {
                    if(!employee_getId(auxEmp,&auxId) && !employee_getHorasTrabajadas(auxEmp,&auxHoras) && !employee_getSueldo(auxEmp,&auxSueldo) && !employee_getNombre(auxEmp,nombre))
                    {
                        fprintf(pFile,"%d,%s,%d,%d\n",auxId,nombre,auxHoras,auxSueldo);
                        error=1;
                    }

                }
            }
            fclose(pFile);
        }
    }
    else
    {
        printf("Ocurrio un inconveniente.");
        error = 0;
    }
    return error;
}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
    int error = -1;
    FILE* pFile;
    int tam;
    Employee* auxEmp;
    tam=ll_len(pArrayListEmployee);

    if(path != NULL && pArrayListEmployee != NULL)
    {
        pFile=fopen(path,"wb");

        if(pFile != NULL)
        {
            for(int i=0; i<tam; i++)
            {
                auxEmp=(Employee*)ll_get(pArrayListEmployee,i);

                if(auxEmp != NULL)
                {
                    fwrite(auxEmp,sizeof(Employee),1,pFile);
                    error =1;
                }

            }

            fclose(pFile);
        }
    }
    else
    {
        printf("Ocurrio un inconveniente.");
        error = 0;
    }
    return error;
}

