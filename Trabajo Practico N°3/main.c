#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "Menu.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

// Tengo inconvenientes tecnicos por parte de la empresa telefonica, me lo solucionaran a la brevedad,hice varios commit por si se me van los datos moviles.
// Que tenga un buen dia.

int main()
{
    int option;
    int flag=0;
    LinkedList* listaEmpleados = ll_newLinkedList();
    do
    {
        option = menu();

        switch(option)
        {
            case 1:
                if(flag== 0)
                {
                   controller_loadFromText("data.csv",listaEmpleados);
                   flag=1;
                }
                else
                {
                    printf("\nYa se cargo los empleados.");
                }
                break;
            case 2:
                if(flag == 0)
                {
                   controller_loadFromBinary("data.bin",listaEmpleados);
                   flag=1;
                }
                else
                {
                    printf("\nYa se cargo los empleados.");
                }
                break;
            case 3:
                controller_addEmployee(listaEmpleados);
                break;
            case 4:
                controller_editEmployee(listaEmpleados);
                break;
            case 5:
                controller_removeEmployee(listaEmpleados);
                break;
            case 6:
                controller_ListEmployee(listaEmpleados);
                break;
            case 7:
                controller_sortEmployee(listaEmpleados);
            case 8:
                controller_saveAsText("data.csv",listaEmpleados);
                break;
            case 9:
                controller_saveAsBinary("data.bin",listaEmpleados);
                break;
        }
        system("pause");
        system("cls");

    }while(option != 10);
    return 0;
}
