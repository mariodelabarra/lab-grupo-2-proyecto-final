#include "files/articulos/articulos.h"
#include "files/common/fecha.h"
#include "files/common/mensajes.h"
#include "files/pedidos/archivosPedidos.h"
#include "files/pedidos/pedidos.h"
#include <stdio.h>
#include <stdlib.h>

void menuProvisional(stPedido arregloPedidos[], char nombreArchivo[], int *dim, int pos);
void menuPedidos(stPedido arregloPedidos[], char nombreArchivo[], int *dim, int pos);

int main()
{
    stPedido *pedidos;
    int dim;
    pedidos = obtenerPedidos(ARCHIVO_PEDIDO, &dim);
    menuProvisional(pedidos, ARCHIVO_PEDIDO, &dim, 1);
    return 0;
}

void menuProvisional(stPedido arregloPedidos[], char nombreArchivo[], int *dim, int pos)
{
    int opcion = 0;

    do
    {
        printf
            (
                "[1]Pedidos\n"
                "[0]Salir\n"
            );
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                menuPedidos(arregloPedidos, nombreArchivo, dim, pos);
                break;
            case 0:
                printf("Adios!");
                exit(0);
                break;
            default:
                printfError("Opcion invalida...");
                break;
        }

    }while (opcion != 0);
}

void menuPedidos(stPedido arregloPedidos[], char nombreArchivo[], int *dim, int pos)
{
    int opcion = 0;
    int idCliente;

    printf("Ingrese su id de cliente: ");
    scanf("%d", &idCliente);

    do
    {
        printf
            (
                "[1]Alta\n"
                "[2]Baja\n"
                "[3]Modificacion\n"
                "[4]Listado\n"
                "[0]Salir\n"
            );

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                altaPedido(arregloPedidos, dim, idCliente);
                break;
            case 2:
                bajaPedido(arregloPedidos, *dim, idCliente);
                break;
            case 3:
                modificacionPedido(arregloPedidos, *dim, idCliente);
                break;
            case 4:
                listadoPedido(arregloPedidos, *dim, idCliente);
                break;
            case 0:
                printf("Adios!");
                break;
            default:
                printfError("Opcion invalida...");
                break;
        }

    }while (opcion != 0);
}
