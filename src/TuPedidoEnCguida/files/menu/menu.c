#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

void menuPrincipal(arrPedidos *arregloPedidos, arrClientes *arregloClientes, char archivoPedidos[], char archivoClientes[])
{
    int opcion = 0;

    do
    {
        system("cls");
        tituloPrincipal();
        printf
        (
            "\n\n[1]Pedidos\n"
            "[2]Clientes\n"
            "[0]Salir\n"
        );
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            menuPedidos(arregloPedidos, arregloClientes, archivoPedidos);
            break;
        case 2:
            menuClientes(arregloClientes, archivoClientes);
            break;
        case 0:
            printf("Adios!");
            exit(0);
            break;
        default:
            printfError("Opcion invalida...");
            break;
        }
    }
    while (opcion != 0);
}

void menuPedidos(arrPedidos *arregloPedidos, arrClientes *arregloClientes, char nombreArchivo[])
{
    int opcion = 0;
    int idCliente, encontrado = 0;

    printf("Ingrese su id de cliente: ");
    scanf("%d", &idCliente);

    encontrado = buscarPosicionCliente(*arregloClientes, idCliente);

    if(encontrado == -1)
    {
        printfError("El cliente no existe");
        system("pause");
        altaCliente(arregloClientes);
    }
    else
    {
        do
        {
            system("cls");

            tituloSecciones("PEDIDOS");

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
                altaPedido(arregloPedidos, idCliente);
                break;
            case 2:
                bajaPedido(arregloPedidos, idCliente);
                break;
            case 3:
                modificacionPedido(arregloPedidos, idCliente);
                break;
            case 4:
                listadoPedido(arregloPedidos, idCliente);
                break;
            case 0:
                break;
            default:
                printfError("Opcion invalida...");
                break;
            }

        }
        while (opcion != 0);
    }
}

void menuClientes(arrClientes *arregloClientes, char nombreArchivo[])
{
    int opcion = 0;

    do
    {
        system("cls");

        tituloSecciones("CLIENTES");

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
            altaCliente(arregloClientes);
            break;
        case 2:
            bajaCliente(arregloClientes);
            break;
        case 3:
            /* modificarCliente(archivoClientes, stCliente clienteModificado) */
            break;
        case 4:
            listadoClientes(arregloClientes, "LISTADO");
            break;
        case 0:
            break;
        default:
            printfError("Opcion invalida...");
            break;
        }

    }
    while (opcion != 0);
}
