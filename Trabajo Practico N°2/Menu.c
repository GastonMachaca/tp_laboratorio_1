#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayEmployees.h"
#include "Menu.h"

int menu()
{
    int opcion;
    printf(" \n Menu de opciones\n");
    printf(" \n    1) ALTAS");
    printf(" \n    2) MODIFICAR");
    printf(" \n    3) BAJA");
    printf(" \n    4) INFORMAR");
    printf(" \n    5) SALIR");

    printf("\n \n Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d",&opcion);


    while(opcion<1 || opcion >5 || isalpha(opcion)!=0)
    {
        printf("\nERROR!!!\n Vuelva a ingresar una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }

    return opcion;
}

int buscarLibre(Employee lista[],int tam)
{
    int indice = -1;

    for(int i = 0; i<tam; i++)
    {
        if(lista[i].isEmpty == 1)
        {
            indice = i;
            break;
        }
    }
    return indice;
}

void printEmployee(Employee unEmpleado)
{
    printf("\n %d %9s %10s %10.3f %7d \n",unEmpleado.id,unEmpleado.name, unEmpleado.lastName, unEmpleado.salary, unEmpleado.sector);
}

int visualOpcion1 (Employee lista[],int tam,int id)
{
    if(addEmployee(lista,tam,id) == 0)
    {
        id++;
        printf("\nAlta exitosa!!\n");
    }
    else
    {
        printf("\nNo se concreto exitosamente\n");
    }

    return id;
}

void visualError (Employee lista[],int tam,int error)
{
    if(error == 0)
    {
        system("cls");

        printf("\nSe completo la operacion exitosamente.\n");

        printEmployees(lista,tam);
    }
    else
    {
        if(error == -1)
        {
            printf("\nNo se dio de alta para mostrar el listado\n");
        }
        else
        {
            printf("\nExito!!!\n");
        }
    }
}

int modifEmployee(Employee lista[], int tam, int id)
{
    int error = 1;
    int indice;

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
            printf("\nA seleccionado a este empleado: \n");
            printEmployee(lista[indice]);

            //Submenu

            error = subMenuModificar(lista,indice,error);
        }
    }
    else
    {
        printf("\nNo se dio de alta y no hay nada ingresado.\n");
    }

    return error;
}

int subMenuModificar (Employee lista[],int indice,int error)
{
    Employee nuevaPersona;

    int opcion;
    char confirma;

    printf("\n **** Que quiere modificar ? **** \n");
    printf("\n1 - Nombre ");
    printf("\n2 - Apellido ");
    printf("\n3 - Salario ");
    printf("\n4 - Sector ");

    printf("\n\nIngrese el numero para proceder con la modificacion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    while(opcion<1 || opcion >4 || isalpha(opcion)!=0)
    {
        printf("\nERROR!!!\n Vuelva a ingresar una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }

    switch(opcion)
    {
        case 1:
            printf("\nIngrese un nuevo nombre: ");
            fflush(stdin);
            gets(nuevaPersona.name);
            break;

        case 2:
            printf("\nIngrese un nuevo apellido: ");
            fflush(stdin);
            gets(nuevaPersona.lastName);
            break;

        case 3:
            printf("\nIngrese el nuevo sueldo: ");
            scanf("%f",&nuevaPersona.salary);
            while(nuevaPersona.salary < 0)
            {
                printf("\nError!!! Se ingreso un numero negativo \n Reingrese su salario: ");
                scanf("%f",&nuevaPersona.salary);
            }
            break;

        case 4:
            printf("\nIngrese el nuevo sector: ");
            scanf("%d",&nuevaPersona.sector);
            break;
    }

    printf("\nConfirma?( si (s) / no (n) ): ");
    fflush(stdin);
    scanf("%c",&confirma);

    if(confirma == 's')
    {
        switch(opcion)
        {
            case 1:
                strcpy(lista[indice].name,nuevaPersona.name);
                break;
            case 2:
                strcpy(lista[indice].lastName,nuevaPersona.lastName);
                break;
            case 3:
                lista[indice].salary = nuevaPersona.salary;
                break;
            case 4:
                lista[indice].sector = nuevaPersona.sector;
                break;
        }
        error = 0;
    }
    else
    {
        error = 2;
    }

    return error;
}

void subMenuInformar (Employee lista[],int tam,int id)
{

    system("cls");

    int r=-1;
    int opcion;
    int cant=0;
    int mayorSalario=0;
    float totalSalarios=0;
    float promedioTotal=0;

    if(lista != NULL && tam > 0 && negarBandera(lista,tam))
    {
        printf("\n *** INFORMAR *** \n");
        printf("\n 1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector");
        printf("\n 2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.");

        printf("\n \n Elija una opcion: ");
        scanf("%d",&opcion);

        while(opcion!=1 && opcion !=2)
        {
            printf("\nERROR!!!\n Vuelva a ingresar una opcion: ");
            scanf("%d",&opcion);
        }

        switch(opcion)
        {
            case 1:
                r = sortEmployees(lista,tam,1);
                break;

            case 2:

                if(lista != NULL && tam > 0 && negarBandera(lista,tam))
                {
                    for(int i=0; i<tam; i++)
                    {
                        if(lista[i].isEmpty == 0)
                        {
                            totalSalarios = totalSalarios + lista[i].salary;
                            cant++;
                        }
                    }

                    promedioTotal = (float) totalSalarios /cant;

                    for(int i=0; i<tam; i++)
                    {
                        if((lista[i].isEmpty == 0) && (promedioTotal < lista[i].salary))
                        {
                            mayorSalario++;
                        }
                    }

                    printf("\n Total de los salarios ingresados: %.2f",totalSalarios);
                    printf("\n El promedio total de los salarios por parte de los empleados es: %.2f \n",promedioTotal);
                    printf("\n La cantidad de empleados que superan el salario promedio son: %d",mayorSalario);

                    r=2;
                }
                else
                {
                    r=-1;
                }

                break;
        }
    }

    visualError(lista,tam,r);
}

int negarBandera (Employee lista[],int tam)
{
    int flag=0;

    for(int i=0; i<tam; i++)
    {
        if(lista[i].isEmpty == 0)
        {
            flag = 1;
        }
    }

    return flag;
}

