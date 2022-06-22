#include "mensajes.h"

void printfError(char mensaje[])
{
    printf("\nERROR: %s\n\n", mensaje);
}

void printfWarning(char mensaje[])
{
    printf("\nWARN: %s\n\n", mensaje);
}

void tituloPrincipal()
{
	int i;
	printf("\n     ======================================================================\n");
	printf("\t\t\t     HaC Pedidos\n");
	printf("\t   Creacion, reportes, eliminacion, busqueda y actualizacion\n");
	printf("\t\t    Copyright 2022 | Laboratorio I\n");
	printf("     ======================================================================\n");

	i = 0;
	putchar('\n');
	for (; i < 80; i++) {
		putchar('_');
	}
}
