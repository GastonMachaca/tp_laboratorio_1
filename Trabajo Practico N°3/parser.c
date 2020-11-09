#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int error = -1;
    char auxId[128];
    char auxNombre[128];
    char auxHoras[128];
    char auxSueldo[128];

    int r=0;

    Employee* auxEmp;

    do
    {
        if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",auxId,auxNombre,auxHoras,auxSueldo)== 4)
        {
            auxEmp = employee_newParametros(auxId,auxNombre,auxHoras,auxSueldo);

            if(auxEmp != NULL)
            {
                r = ll_add(pArrayListEmployee,auxEmp);

                if(r>=ll_len(pArrayListEmployee))
                {
                    break;
                }
            }

        }
        else
        {
            break;
        }


    }while(feof(pFile)== 0);

    fclose(pFile);

    error = r;

    return error;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int error = -1;
    int r = 0;

    Employee* auxEmp;

    if(pFile != NULL && pArrayListEmployee != NULL)
    {
        do
        {
            auxEmp=employee_new();

            r = fread(auxEmp, sizeof(Employee), 1, pFile);

            if(r == 1)
            {
                ll_add(pArrayListEmployee, auxEmp);
                error=0;
            }

        }while(!feof(pFile));
    }
    return error;
}
