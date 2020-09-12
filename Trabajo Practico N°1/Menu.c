#include <stdio.h>
#include <stdlib.h>


int menu(float num1,float num2,int bandera1,int bandera2)
{
    int opcion;
    printf(" \n Menu de opciones\n");

    if(bandera1==0)
    {
        printf(" \n 1. Ingresar 1er operando (A=x)");
    }
    else
    {
        printf(" \n 1. Ingresar 1er operando (A=%.1f)",num1);
    }

    if(bandera2==0)
    {
        printf(" \n 2. Ingresar 2do operando (A=y)");
    }
    else
    {
        printf(" \n 2. Ingresar 2do operando (A=%.1f)",num2);
    }

    printf(" \n 3. Calcular todas las operaciones");
    printf(" \n    a) Calcular la suma (A+B)");
    printf(" \n    b) Calcular la resta (A-B)");
    printf(" \n    c) Calcular la division (A/B)");
    printf(" \n    d) Calcular la multiplicacion (A*B)");
    printf(" \n    e) Calcular el factorial (A!)");
    printf(" \n 4. Informar resultados");
    printf(" \n    El resultado de A+B es: r");
    printf(" \n    El resultado de A-B es: r");
    printf(" \n    El resultado de A/B es: r");
    printf(" \n    El resultado de A*B es: r");
    printf(" \n    El factorial de A es: r1 y El factorial de B es: r2");
    printf(" \n 5. Salir");


    printf("\n \n Ingrese una opcion: ");
    scanf("%d",&opcion);

    while(opcion<1 || opcion >5)
    {
        printf("\nERROR!!!\n Vuelva a ingresar una opcion: ");
        scanf("%d",&opcion);
    }

    return opcion;
}

float operacionSuma(float num1,float num2)
{
    float resultado;

    resultado = num1+num2;

    return resultado;
}

float operacionResta(float num1,float num2)
{
    float resultado;

    resultado = num1-num2;

    return resultado;
}

float operacionDivision(float num1,float num2)
{
    float resultado;

    if(num2==0)
    {
        printf("\n Advertencia = B es igual a cero.\nNo se puede dividir por cero\n");
    }
    else
    {
        resultado= num1/num2;
    }

    return resultado;
}

float operacionMultiplicacion (float num1,float num2)
{
    float resultado;

    resultado = num1*num2;

    return resultado;
}

long long int operacionFactorial(int num1)
{
    int fact1=1;

    if(num1<0)
    {
        printf("\nAdvertencia = En el operando A no se puede realizar un factorial de un numero negativo.\n");
    }
    else
    {
        for(int i=1;i<=num1;i++)
        {
            fact1=fact1*i;
        }
    }

    return fact1;

}

long long int operacionFactorial2(int num2)
{
    int fact2=1;

    if(num2<0)
    {
        printf("\nAdvertencia = En el operando B no se puede realizar un factorial de un numero negativo.\n");
    }
    else
    {
        for(int i=1;i<=num2;i++)
        {
            fact2=fact2*i;
        }
    }

    return fact2;

}

int numero1Validado (float num1)
{
    int conversion = num1;

    return conversion;
}

int numero2Validado (float num2)
{
    int conversion = num2;

    return conversion;
}

