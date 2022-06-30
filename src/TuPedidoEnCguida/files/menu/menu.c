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
            "\n\n[1] Pedidos\n"
            "[2] Clientes\n\n"
            "[0] Salir\n\n"
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
            printf("\nAdios!\n");
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

    listadoClientes(arregloClientes, "CLIENTES DISPONIBLES");

    printf("\nIngrese su id de cliente: ");
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
                "\n[1] Alta\n"
                "[2] Baja\n"
                "[3] Modificacion\n"
                "[4] Listado\n\n"
                "[0] Salir\n\n"
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
    int idCliente = 0;

    if(arregloClientes->numClientes == 0)
    {
        printfError("No existen clientes creados. Por favor cree un nuevo cliente.");
        system("pause");
        altaCliente(arregloClientes);
    }

    idCliente = pedirCliente(arregloClientes);

    if(arregloClientes->clientes[idCliente].rol == 1)
    {
        menuClientesAdm(arregloClientes, nombreArchivo, idCliente);
    }
    else
    {
        menuClientesUsuario(arregloClientes, nombreArchivo, idCliente);
    }
}

void menuClientesAdm(arrClientes *arregloClientes, char nombreArchivo[], int idCliente)
{
    int opcion = 0;

    do
    {
        system("cls");

        tituloSecciones("MANEJO CLIENTES ADMIN");

        printf
        (
            "\n[1] Alta\n"
            "[2] Baja\n"
            "[3] Modificacion\n"
            "[4] Listado\n"
            "[5] Buscar cliente\n\n"
            "[0] Salir\n\n"
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
            modificacionCliente(arregloClientes);
            break;
        case 4:
            listadoClientes(arregloClientes, "LISTADO");
            break;
        case 5:
            mostrarCliente(arregloClientes, idCliente);
        case 0:
            break;
        default:
            printfError("Opcion invalida...");
            break;
        }

    }
    while (opcion != 0);
}

void menuClientesUsuario(arrClientes *arregloClientes, char nombreArchivo[], int idCliente)
{
    int opcion = 0;

    do
    {
        system("cls");

        tituloSecciones("MANEJO CLIENTES USUARIO");

        printf
        (
            "\n[1] Modificacion\n"
            "[2] Listado\n"
            "[3] Mostrar datos de usuario\n\n"
            "[0] Salir\n\n"
        );

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            modificacionCliente(arregloClientes);
            break;
        case 2:
            listadoClientes(arregloClientes, "LISTADO");
            break;
        case 3:
            mostrarCliente(arregloClientes, idCliente);
        case 0:
            break;
        default:
            printfError("Opcion invalida...");
            break;
        }

    }
    while (opcion != 0);
}
