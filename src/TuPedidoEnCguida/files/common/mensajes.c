#include "mensajes.h"

void printfError(char mensaje[])
{
    printf("\nERROR: %s\n\n", mensaje);
}

void printfWarning(char mensaje[])
{
    printf("\nWARN: %s\n\n", mensaje);
}

void printfSucces(char mensaje[])
{
    printf("\nSUCC: %s\n\n", mensaje);
}

void barraTitulos()
{
    puts("\n ==========================================================================================");
}

void tituloPrincipal()
{
	int i;
	barraTitulos();
	printf("\t\t\t     HaC Pedidos\n");
	printf("\t   Creacion, reportes, eliminacion, busqueda y actualizacion\n");
	printf("\t\t    Copyright 2022 | Laboratorio I\n");
	barraTitulos();

	i = 0;
	putchar('\n');
	for (; i < 80; i++) {
		putchar('_');
	}
}

void tituloSecciones(char * titulo)
{
    barraTitulos();
    printf(" \t\t\t    ==> %s <==", titulo);
    barraTitulos();
}
