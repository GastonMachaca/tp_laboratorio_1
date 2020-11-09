#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "Extras.h"

void confirmName(char *pAux, int len, char* mensaje, char* mensajeError)
{
    char auxStr[len];
    int i=0;
    printf("%s", mensaje);
    fflush(stdin);
    gets(auxStr);

    while(auxStr[i]!= '\0')
    {
        if((auxStr[i]!=' ') && (auxStr[i]<'a'||auxStr[i]>'z') && (auxStr[i]<'A'||auxStr[i]>'Z'))
        {
            printf("%s", mensajeError);
            fflush(stdin);
            gets(auxStr);
            i=0;
        }
        i++;
    }
    strcpy(pAux, auxStr);
}

void confirmNumbers(char *pAux, int len, char* mensaje, char* mensajeError)
{
    char auxStr[len];
    int i=0;
    printf("%s", mensaje);
    fflush(stdin);
    gets(auxStr);

    while(auxStr[i]!='\0')
    {
        if(auxStr[i]<'0'||auxStr[i]>'9')
        {
            i=0;
            printf("%s", mensajeError);
            fflush(stdin);
            gets(auxStr);
        }
        i++;
    }
    strcpy(pAux, auxStr);
}
