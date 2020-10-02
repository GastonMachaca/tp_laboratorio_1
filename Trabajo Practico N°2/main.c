#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "ArrayEmployees.h"
#include "Menu.h"

#define TAM 1000

int main()
{
    int opcion;
    Employee lista[TAM]; // Estructura Empleados.
    int id=0; // Donde empieza a contar los ID.

    if(initEmployees(lista,TAM)==0) // Si no hay contenido basura en el programa.
    {

        while(opcion !=5) // No sale del menu a menos que la opcion sea 5.
        {

            opcion = menu(); // Muestro el menu.

            switch(opcion)
            {
                case 1:
                    id = visualOpcion1(lista,TAM,id); // Llamado a la funcion y dar alta a empleado.
                    break;
                case 2:
                    modifEmployee(lista,TAM,id); // Llamado a la funcion y modificar a empleado.
                    break;
                case 3:
                    removeEmployee(lista,TAM,id); // Llamado a la funcion y dar de baja a empleado.
                    break;
                case 4:
                    subMenuInformar(lista,TAM,id); // Llamado a la funcion y acceso a sub menu para informar sobre empleado/a/os/as.
                    break;
            }
            system("pause");
            system("cls");
        }
    }
    else
    {
        printf("Fallo al inicializar... \n");
    }

    return 0;
}
