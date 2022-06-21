#ifndef LIBRERIAMENUCLIENTEADMINISTRADOR_H_INCLUDED
#define LIBRERIAMENUCLIENTEADMINISTRADOR_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void menuCliente(){
    int opcion;
    do{
        system("cls");
        printf("\n\t\t\t\t\MODO CLIENTE\n");
        printf("\n=======================================================================================================================");
        printf("\n<1> ALTA");
        printf("\n<2> BAJA");
        printf("\n<3> HACER UN PEDIDO");
        printf("\n<0> REGRESAR\n");

        printf("\nINGRESE UNA OPCION: ");
        scanf("%d", &opcion);

        switch(opcion){
        case 1:
            menuAlta();
            break;

        case 2:
            menuBaja();
            break;

        case 3:
            menuPedido();
            break;

        case 0:

            break;
        }
    }while(opcion!=0);

}

void menuAdministrador(){
    int opcion;
    do{
        system("cls");
        printf("\n\t\t\t\tMODO ADMINISTRADOR\n");
        printf("\n=======================================================================================================================");
        printf("\n<1> ALTA");
        printf("\n<2> BAJA");
        printf("\n<3> EDITAR");
        printf("\n<4> CONSULTA");
        printf("\n<5> LISTADO");
        printf("\n<0> REGRESAR\n");

        printf("\nINGRESE UNA OPCION: ");
        scanf("%d", &opcion);
        switch(opcion){
        case 1:
            menuAlta();
            break;

        case 2:
            menuBaja();
            break;

        case 3:
            menuEditar();
            break;

        case 4:
            menuConsultaAdministrador();
            break;

        case 5:

            break;

        case 0:

            break;
        }


    }while(opcion!=0);

}

#endif // LIBRERIAMENUCLIENTEADMINISTRADOR_H_INCLUDED
