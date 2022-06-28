#include <stdio.h>
#include <stdlib.h>
#include <locale.h> /* setlocale */

#include "files/articulos/articulos.h"
#include "files/common/fecha.h"
#include "files/common/mensajes.h"
#include "files/pedidos/archivosPedidos.h"
#include "files/pedidos/pedidos.h"

#include "files/clientes/cliente.h"
#include "files/clientes/archivosClientes.h"
#include "files/clientes/menuCliente.h"

void menuProvisional(arrePedidos *arregloPedidos, arrClientes *arregloClientes, char nombreArchivoPedidos[]);
void menuPedidos(stPedido arregloPedidos[], char nombreArchivo[], int *dim, int pos);

int main()
{
    setlocale(LC_ALL, "spanish"); /* Permite imprimir caracteres con tilde */

    arrClientes arregloClientes;
    arrePedidos arregloPedidos;

    arregloClientes.clientes = obtenerClientes(ARCHIVO_CLIENTES, &arregloClientes.numClientes);

    menuProvisional(&arregloPedidos, &arregloClientes, "");


    printf("Hello world!\n");
    return 0;
}

void menuProvisional(arrePedidos *arregloPedidos, arrClientes *arregloClientes, char nombreArchivoPedidos[])
{
    int opcion = 0;

    do
    {
        //system("cls");
        tituloPrincipal();
        printf
            (
                "\n\n[1] Clientes"
                "\n[2] Pedidos\n"
                "\n[0]Salir\n"
            );
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                menuClientes(arregloClientes, ARCHIVO_CLIENTES);
                break;
            case 2:
                //menuPedidos(arregloPedidos, nombreArchivo, dim, pos);
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

//void menuPedidos(stPedido arregloPedidos[], char nombreArchivo[], int *dim, int pos)
//{
//    int opcion = 0;
//    int idCliente;
//
//    printf("Ingrese su id de cliente: ");
//    scanf("%d", &idCliente);
//
//    do
//    {
//        system("cls");
//        printf
//            (
//                "[1]Alta\n"
//                "[2]Baja\n"
//                "[3]Modificacion\n"
//                "[4]Listado\n"
//                "[0]Salir\n"
//            );
//
//        printf("Ingrese una opcion: ");
//        scanf("%d", &opcion);
//
//        switch (opcion)
//        {
//            case 1:
//                altaPedido(arregloPedidos, dim, idCliente);
//                break;
//            case 2:
//                bajaPedido(arregloPedidos, *dim, idCliente);
//                break;
//            case 3:
//                modificacionPedido(arregloPedidos, *dim, idCliente);
//                break;
//            case 4:
//                listadoPedido(arregloPedidos, *dim, idCliente);
//                break;
//            case 0:
//                break;
//            default:
//                printfError("Opcion invalida...");
//                break;
//        }
//
//    }while (opcion != 0);
//}
