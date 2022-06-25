#include <stdio.h>
#include <stdlib.h>

#include "commonClientes.h"

char leerGenero()
{
    char genero;
    do
    {
        genero = leerCaracter("\nIngrese el genero del cliente(M/F): ");
    }
    while (genero != 'M' && genero != 'F');

    return genero;
}

int leerRol()
{
    int rol;

    fflush(stdin);
    do
    {
        puts("\nIngrese el rol del cliente(0- Usuario/1- Admin): ");
        scanf("%d", &rol);

        if(rol != 0 && rol != 1)
        {
            system("cls");
            printfError("Ingrese correctamente el numero del rol para el cliente.");
        }
    }
    while (rol != 0 && rol != 1);

    return rol;
}

char * leerStringCampoEditable(int numeroElegido, char *campo, char *campoValor)
{
    static char caracteres[30];
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n\t\t    ==> %d-   %s: %s <==\n", numeroElegido, campo, campoValor);
    printf(" ------------------------------------------------------------------------------\n\n");
    puts("\n- Ingrese el nuevo valor: ");
    fflush(stdin);
    gets(caracteres);
    printf(" ------------------------------------------------------------------------------\n");

    return caracteres;
}
