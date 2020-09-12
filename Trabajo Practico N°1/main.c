#include <stdio.h>
#include <stdlib.h>
#include "Menu.h"

/*

Alumno: Machaca Fabian Gastón

Division: 1A

Profesor: Christian Bauss.

Universidad Tecnologica Nacional - Sede Facultad Regional Avellaneda.

Año: 2020.

*/


int main()
{
    // Declaracion de variables

    float num1=0;
    float num2=0;
    int opcion;
    float Suma;
    float Resta;
    float Division;
    float Multiplicacion;
    int Factorial;
    int Factorial2;
    int validacionOperaciones1=0;
    int validacionOperaciones2=0;
    int bandera1=0;
    int bandera2=0;

    // Menu.

    do
    {
        system("cls"); // Refresco el cmd.
        opcion = menu(num1,num2,bandera1,bandera2); // Llamo a la funcion Menu().
        switch(opcion) // Selector de opciones del menu.
        {
            case 1:
                // OPERANDO A.
                printf("Ingrese el 1er operando: ");
                scanf("%f",&num1);
                bandera1=1;
                validacionOperaciones1=1;
                break;

            case 2:
                //OPERANDO B.
                printf("Ingrese el 2do operando: ");
                scanf("%f",&num2);
                bandera2=1;
                validacionOperaciones2=1;
                break;

            case 3:
                //CARGA DE LAS OPERACIONES.
                if(validacionOperaciones1==1 && validacionOperaciones2==1)
                {
                    printf("\nDatos cargados correctamente...\n");
                    Suma = operacionSuma(num1,num2); // Llamo a la funcion operacionSuma().
                    Resta = operacionResta(num1,num2); // Llamo a la funcion operacionResta().
                    Division= operacionDivision(num1,num2); // Llamo a la funcion operacionDivision().
                    Multiplicacion = operacionMultiplicacion(num1,num2); // Llamo a la funcion operacionMultiplicacion().
                    Factorial = operacionFactorial(num1); // Llamo a la funcion operacionFactorial().
                    Factorial2 = operacionFactorial2(num2); // Llamo a la funcion operacionFactorial2().
                }
                else
                {
                    printf("\nNo se ingresaron los operandos correctamente.\n");
                }
                break;

            case 4:
                // MUESTRO LOS RESULTADOS.
                if(validacionOperaciones1==1 && validacionOperaciones2==1)
                {
                    printf("\nEl resultado de la suma de A+B es: %.2f\n",Suma);
                    printf("\nEl resultado de la resta de A-B es: %.2f\n",Resta);
                    if(num2==0)
                    {
                        printf("\nUsted realizo una division por cero.\nAl ser infinitas posibilidades se omitio esta cuenta...\nVuelva a intentarlo.\n");
                    }else
                    {
                        printf("\nEl resultado de la division de A/B es: %.2f\n",Division);
                    }
                    printf("\nEl resultado de la multiplicacion de A*B es: %.2f\n",Multiplicacion);

                    if(numero1Validado(num1)<0 && numero2Validado(num2)<0)
                    {
                        printf("\nEl resultado del factorial de A y el factorial de B no pueden ser calculados debido al ingreso de valores negativos. \nCambie los operando ingresados negativos para continuar.");
                    }
                    else
                    {
                        if(numero1Validado(num1)>=0 && numero2Validado(num2)>=0)
                        {
                            printf("\nEl resultado del factorial de A es %d y el factorial de B es %d \n",Factorial,Factorial2);
                        }

                        if(numero1Validado(num1)<0)
                        {
                            printf("\nEl resultado del factorial de A no existe(operador negativo)y el factorial de B es: %d\n",Factorial2);
                        }
                        if(numero2Validado(num2)<0)
                        {
                            printf("\nEl resultado del factorial de A es: %d y el factorial de B no existe(operador negativo)\n",Factorial);
                        }
                    }
                }
                else
                {
                    printf("\nNo se ingresaron los operandos correctamente.\n");
                }
                break;
        }

        printf("\nVolviendo a seleccion de opciones...\n\n");

        system("pause"); // Pauso la imagen hasta pulsar un boton.

    }while(opcion != 5); // Si la opcion ingresada es igual a 5, termina el programa.
    return 0;
}

