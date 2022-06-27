#include <stdio.h>
#include <stdlib.h>
#include <locale.h> /* setlocale */

#include "files/articulos/articulos.h"
#include "files/common/mensajes.h"
#include "files/pedidos/archivosPedidos.h"
#include "files/pedidos/pedidos.h"

void menuProvisional(arrPedidos *arreglo, char nombreArchivo[]);
void menuPedidos(arrPedidos *arreglo, char nombreArchivo[]);

int main()
{
    setlocale(LC_ALL, "spanish"); /* Permite imprimir caracteres con tilde */
    arrPedidos arregloPedidos;
    arregloPedidos.pedidos = obtenerPedidos(ARCHIVO_PEDIDO, &arregloPedidos.numPedidos);
    menuProvisional(&arregloPedidos, ARCHIVO_PEDIDO);
    return 0;
}

void menuProvisional(arrPedidos *arreglo, char nombreArchivo[])
{
    int opcion = 0;

    do
    {
        system("cls");
        tituloPrincipal();
        printf
            (
                "\n\n[1]Pedidos\n"
                "[0]Salir\n"
            );
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                menuPedidos(arreglo, nombreArchivo);
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

void menuPedidos(arrPedidos *arreglo, char nombreArchivo[])
{
    int opcion = 0;
    int idCliente;

    printf("Ingrese su id de cliente: ");
    scanf("%d", &idCliente);

    do
    {
        system("cls");
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
                altaPedido(arreglo, idCliente);
                break;
            case 2:
                bajaPedido(arreglo, idCliente);
                break;
            case 3:
                modificacionPedido(arreglo, idCliente);
                break;
            case 4:
                listadoPedido(arreglo, idCliente);
                break;
            case 0:
                break;
            default:
                printfError("Opcion invalida...");
                break;
        }

    }while (opcion != 0);
}
