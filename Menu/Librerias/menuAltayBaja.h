#ifndef MENUALTAYBAJA_H_INCLUDED
#define MENUALTAYBAJA_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <time.h>

void menuAlta(){
    int opcion;
    do{
        system("cls");
        printf("\n\t\t\t\t\t\t\tALTA\n");
        printf("\n=======================================================================================================================");
        printf("\n<1> ALTA CLIENTE");
        printf("\n<0> REGRESAR\n");

        printf("\nINGRESE UNA OPCION: ");
        scanf("%d", &opcion);
        switch(opcion){
        case 1:
            menuEditar();

            break;

        case 0:

            break;
        }



    }while(opcion!=0);
}

void menuBaja(){
    int opcion;
    do{
        system("cls");
        printf("\n\t\t\t\t\t\t\tBAJA\n");
        printf("\n=======================================================================================================================");
        printf("\n<1> BAJA CLIENTE");
        printf("\n<0> REGRESAR\n");

        printf("\nINGRESE UNA OPCION: ");
        scanf("%d", &opcion);
        switch(opcion){
        case 1:
            menuBajaUsuario();

            break;

        case 0:

            break;
        }



    }while(opcion!=0);
}

#endif // MENUALTAYBAJA_H_INCLUDED
