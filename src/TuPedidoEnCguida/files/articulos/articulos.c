#include <stdio.h>
#include <stdlib.h>

#include "articulos.h"
#include "../common/mensajes.h"

int id[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
char nombreArticulo[10][20] =
{
    "Vino Tinto",
    "Vino Blanco",
    "Pack 6 Birrita",
    "Unidad Birrita",
    "1L Birrita",
    "1/2L Cool Cola",
    "1L y 1/2 Cool Cola",
    "1/2L Agua Pop",
    "1L y 1/2 Agua Pop",
    "1L Jugo Andes"
};
unsigned int precioArticulo[10] = {454, 240, 1000, 199, 200, 134, 188, 124, 160, 116};

/* Muestra el listado completo de articulos */
void listadoArticulos()
{
    int i = 0;

    printf("Listado de articulos:\n");
    for(i = 0; i < 10; i++)
    {
        printf("%d ", id[i]);
        printf("%s ", nombreArticulo[i]);
        printf("$%d\n", precioArticulo[i]);
    }
}

/* Muestra por pantalla un articulo segun su id */
void mostrarArticuloPorId(int idArticulo)
{
    printf("%d ", id[idArticulo]);
    printf("%s ", nombreArticulo[idArticulo]);
    printf("$%d\n", precioArticulo[idArticulo]);
}

/* Calcula el precio de un articulo en la cantidad deseada segun su id */
int precioPorId(int idArticulo)
{
    int precio = 0, cantidad = 0;

    cantidad = cantArticulos(idArticulo);

    precio = precioArticulo[idArticulo] * cantidad;

    return precio;
}

/* Consulta la cantidad de articulos y lo retorna */
int cantArticulos(int idArticulo)
{
    int cantidad = 0;
    mostrarArticuloPorId(idArticulo);
    printf(" Cantidad de unidades: ");
    scanf("%d", &cantidad);

    return cantidad;
}

/* Permite al usuario elejir los articulos retorna una sumatoria de sus costos */
int altaArticulos()
{
    int sumCosto = 0, opcion;
	do
	{
	    system("cls");

	    listadoArticulos();

	    printf("\nId del articulo a agregar (0 para salir): ");
	    scanf("%2d", &opcion);

	    if(opcion < 0 && opcion > 10)
	    {
	        printfError("Opcion invalida ingrese nuevamente...");
	        system("pause");
	    }
	    else if(opcion != 0)
	    {
	        sumCosto += precioPorId(opcion - 1);
	    }
	}
	while (opcion > 0 && opcion <= 10);

    return sumCosto;
}
