#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "Menu.h"

int initEmployees(Employee lista[], int tam)
{
    int error = 1;

    if(lista != NULL && tam > 0)
    {
        for(int i=0; i<tam; i++)
        {
            lista[i].isEmpty = 1;
        }
        error=0;
    }
    return error;
}

int addEmployee(Employee lista[], int tam, int id)
{
    int error = 1;

    Employee nuevaPersona;

    int indice;

    if(lista != NULL && tam > 0 && id >= 0)
    {
        indice = buscarLibre(lista,tam);
        if(indice == -1)
        {
            printf("\nSistema Completo.\n");
        }
        else
        {
            nuevaPersona.id = id;
            nuevaPersona.isEmpty = 0;
            printf("\nIngrese nombre: ");
            fflush(stdin);
            gets(nuevaPersona.name);
            printf("\nIngrese apellido: ");
            fflush(stdin);
            gets(nuevaPersona.lastName);
            printf("\nIngrese su salario: ");
            scanf("%f",&nuevaPersona.salary);
            while(nuevaPersona.salary < 0)
            {
                printf("\nError!!! Se ingreso un numero negativo \n Reingrese su salario: ");
                scanf("%f",&nuevaPersona.salary);
            }
            printf("\nIngrese su sector: ");
            scanf("%d",&nuevaPersona.sector);

            lista[indice] = nuevaPersona;

            error=0;
        }

    }

    return error;
}

int findEmployeeById(Employee empleado[], int tam,int id)
{
    int indice = -1;

    for(int i=0; i<tam; i++)
    {
        if(empleado[i].id == id &&  empleado[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

int removeEmployee(Employee lista[], int tam, int id)
{
    int error = 1;
    int indice;
    char confirma;

    if(lista != NULL && tam > 0 && id >= 0 && negarBandera(lista,tam))
    {
        system("cls");
        printEmployees(lista,tam);
        printf("\nIngrese id que quiere modificar: ");
        scanf("%d",&id);

        indice = findEmployeeById(lista,tam,id);

        if(indice == -1)
        {
            printf("\nNo hay ninguna persona con ese id.\n\n");
        }
        else
        {
            system("cls");
            printf("\n\nA seleccionado a este empleado:");
            printEmployee(lista[indice]);
            printf("\nConfirma baja?( si (s) / no (n) ): ");
            fflush(stdin);
            scanf("%c",&confirma);
            if(confirma == 's')
            {
                lista[indice].isEmpty = 1;
                error = 0;
            }
            else
            {
                error = 2;
            }
        }

    }
    else
    {
        printf("\nNo se dio alta o no a ingresado nada.\n");
    }

    return error;
}

int sortEmployees(Employee lista[], int tam, int order)
{

    Employee auxCad;

    int error = -1;

    if(lista != NULL && tam > 0 && negarBandera(lista,tam))
    {
        printf("\nIngrese el sentido de ordenamiento de la lista. \n 1 - ASCENDENTE \n 0 - DESCENDENTE. \n\n Ingrese numero: ");
        scanf("%d",&order);

        while(order != 0 && order != 1)
        {
            printf("\nError!!!\nSolo son validos 0 o 1 \n 1 - PARA ASCENDENTE \n 0 - PARA DESCENDENTE. \n Ingrese numero: ");
            scanf("%d",&order);
        }

        // Ordenamiento de CARACTERES

        for(int i=0; i<tam-1; i++)
        {
            for(int j=i + 1; j < tam; j++)
            {

                if(order == 1)
                {
                    if(strcmp(lista[i].lastName,lista[j].lastName) > 0)
                    {
                        //Swap
                        auxCad = lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxCad;
                    }

                    if(lista[i].sector > lista[j].sector)
                    {
                        //Swap
                        auxCad = lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxCad;
                    }
                }
                else
                {
                    if(strcmp(lista[i].lastName,lista[j].lastName) < 0)
                    {
                        //Swap
                        auxCad = lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxCad;
                    }

                    if(lista[i].sector < lista[j].sector)
                    {
                        //Swap
                        auxCad = lista[i];
                        lista[i]=lista[j];
                        lista[j]=auxCad;
                    }
                }
            }
            printf("\n");
        }
        error = 0;
    }
    else
    {
        printf("\nNo se dio de alta o no se recibio ningun dato.\n");
    }

    return error;
}

int printEmployees(Employee empleado[],int tam)
{
    int error = 1;
    int flag = 0;
    if(empleado != NULL && tam > 0)
    {

        printf("\n Id - Nombre - Apellido - Salario - Sector\n");
        printf("-------------------------------------------");
        for(int i=0; i<tam; i++)
        {
            if(empleado[i].isEmpty == 0)
            {
                printEmployee(empleado[i]);
                flag = 1;
            }
        }
        if(flag == 0)
        {
            printf("\nNo hay personas en la lista.\n\n");
        }
        error = 0;
    }

    return error;
}
