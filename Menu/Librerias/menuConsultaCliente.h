#ifndef MENUCONSULTACLIENTE_H_INCLUDED
#define MENUCONSULTACLIENTE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void menuConsultaCliente(){
    int opcion;
    do{
        system("cls");
        printf("\n\t\t\t\t\t\t\tCONSULTA\n");
        printf("\n=======================================================================================================================");
        printf("\n<1> COMENZAR CON UN PEDIDO");
        printf("\n<2> TOTAL DE PEDIDOS REALIZADOS");
        printf("\n<0> REGRESAR\n");

        printf("\nINGRESE UNA OPCION: ");
        scanf("%d", &opcion);
        switch(opcion){
        case 1:
            menuPedido();

            break;

        case 2:

            break;

        case 0:

            break;
        }

    }while(opcion!=0);
}

#endif // MENUCONSULTACLIENTE_H_INCLUDED