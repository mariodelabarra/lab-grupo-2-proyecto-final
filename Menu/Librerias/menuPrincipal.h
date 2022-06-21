#ifndef MENUPRINCIPAL_H_INCLUDED
#define MENUPRINCIPAL_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void menuPrincipal()
{
    int opcion;
    system("color 79");
    do
    {
        system("cls");
        printf("\n\t\t\tPEDIDOS EN C GUIDA\n");
        printf("\n===============================================================================");
        printf("\n===============================================================================");
        printf("\n\t\t\tBIENVENIDO/A\n");
        printf("\n<1> MODO CLIENTE");
        printf("\n<2> MODO ADMINISTRADOR");
        printf("\n<0> SALIR\n");

        printf("\nINGRESE UNA OPCION: ");//Si entra en modo administrador le tenemos que pedir la contrasenia para que no entre cualquiera en ese modo
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1:
            menuCliente();
            break;

        case 2:
            menuAdministrador();
            break;

        case 0:
            printf("\n===============================================================================");
            printf ("\n\t\t\tHASTA EL PROXIMO PEDIDO\n");
            printf("\n===============================================================================");
            break;
        }
    }
    while(opcion!=0);
}


#endif // MENUPRINCIPAL_H_INCLUDED
