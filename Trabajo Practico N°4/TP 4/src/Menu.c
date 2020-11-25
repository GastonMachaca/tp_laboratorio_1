#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "../inc/Menu.h"
#include "../inc/Extras.h"



int menu(void)
{
    int option;

    printf(" \n Menu:\n");
    printf(" \n  1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).");
    printf(" \n  2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).");
    printf(" \n  3. Alta de empleado.");
    printf(" \n  4. Modificar datos de empleado.");
    printf(" \n  5. Baja de empleado.");
    printf(" \n  6. Listar empleados.");
    printf(" \n  7. Ordenar empleados.");
    printf(" \n  8. Guardar los datos de los empleados en el archivo data.csv (modo texto).");
    printf(" \n  9. Guardar los datos de los empleados en el archivo data.csv (modo binario).");
    printf(" \n  10. Borrar Empleados 2*N (0,1,2,etc).");
    printf(" \n  11. Salir. ");

    printf("\n \n Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d",&option);


    while(option<1 || option >11 || isalpha(option)!=0)
    {
        printf("\nERROR!!!\n Vuelva a ingresar una opcion: ");
        fflush(stdin);
        scanf("%d",&option);
    }

    return option;
}

int subMenuModificar (Employee* emp,int len,char* nombreStr,char* sueldoStr,char* horasStr)
{
    int error;
    int opcion;
    char confirma;

    printf("\n **** Que quiere modificar ? **** \n");
    printf("\n1 - Nombre ");
    printf("\n2 - Horas Trabajadas ");
    printf("\n3 - Sueldo ");

    printf("\n\nIngrese el numero para proceder con la modificacion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    while(opcion<1 || opcion >3 || isalpha(opcion)!=0)
    {
        printf("\nERROR!!!\n Vuelva a ingresar una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }

    switch(opcion)
    {
        case 1:
            confirmName(nombreStr,len,"Ingrese un nuevo nombre: ","Error!!!,Vuelva a ingresar el nombre.");
            break;

        case 2:
            confirmNumbers(horasStr,len,"Ingrese los nuevos horarios laborales: ","Error!!!,Vuelva a intentarlo.");
            break;

        case 3:
            confirmNumbers(sueldoStr,len,"Ingrese el salario nuevo: ","Error!!!,Vuelva a ingresar el salario.");
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
                employee_setNombre(emp, nombreStr);
                break;
            case 2:
                employee_setHorasTrabajadas(emp, atoi(horasStr));
                break;
            case 3:
                employee_setSueldo(emp, atoi(sueldoStr));
                break;
        }
        error = 0;
        printf("Exito!!! ");
    }
    else
    {
        error = 2;
        printf("Se cancelo la operacion.");
    }

    return error;
}

int subMenuRemove(Employee* emp ,LinkedList* this,int auxId,int indice)
{
    int error;
    char confirma;

    emp = ll_get(this, indice);

    printf("\nConfirma baja empleado?: ");
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
        ll_remove(this, indice);
        employee_delete(emp);
        printf("Empleado eliminado.\n");
        error=0;
    }
    else
    {
        printf("Se cancelo la baja.\n");
        error= 1;
    }

    return error;
}

void subMenuOrdenar(LinkedList* this)
{
    int opcion;
    int orden;

    printf("\n **** Eleccion de elemento a ordenar  **** \n");
    printf("\n1 - ID ");
    printf("\n2 - Nombre ");
    printf("\n3 - Horas Trabajadas ");
    printf("\n4 - Sueldo ");

    printf("\n\nIngrese el numero para proceder con la modificacion: ");
    fflush(stdin);
    scanf("%d",&opcion);

    while(opcion<1 || opcion >4 || isalpha(opcion)!=0)
    {
        printf("\nERROR!!!\n Vuelva a ingresar una opcion: ");
        fflush(stdin);
        scanf("%d",&opcion);
    }

    printf("\nSeleccione el sentido de ordenamiento: Ascendente->0 o Descendente->1");
    fflush(stdin);
    scanf("%d",&orden);

    while((orden != 0 && orden != 1) || isalpha(orden)!= 0)
    {
        printf("\nERROR!!!\n Vuelva a ingresar un orden: ");
        fflush(stdin);
        scanf("%d",&orden);
    }

    switch(opcion)
    {
        case 1:
            ll_sort(this, ordenXid,orden);
            break;
        case 2:
            ll_sort(this, ordenXnombre,orden);
            break;
        case 3:
            ll_sort(this, ordenXhora,orden);
            break;
        case 4:
            ll_sort(this, ordenXsueldo,orden);
            break;
    }

}

