#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "Menu.h"


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
    printf(" \n  10. Salir.");

    printf("\n \n Ingrese una opcion: ");
    fflush(stdin);
    scanf("%d",&option);


    while(option<1 || option >10 || isalpha(option)!=0)
    {
        printf("\nERROR!!!\n Vuelva a ingresar una opcion: ");
        fflush(stdin);
        scanf("%d",&option);
    }

    return option;
}
