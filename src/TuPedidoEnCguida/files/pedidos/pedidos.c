#include <stdlib.h>
#include <stdio.h>
#include <conio.h>
#include <string.h>

#include "../common/mensajes.h"
#include "../common/leerTeclado.h"
#include "../articulos/articulos.h"
#include "../clientes/cliente.h"

#include "pedidos.h"
#include "archivosPedidos.h"

void altaPedido(arrPedidos *arregloPedidos, int idCliente)
{
    int cant = arregloPedidos->numPedidos;
    int sumCosto = 0, insertado = 0;
    stPedido aux;
    char control;

    if(cant == 0)
    {
        arregloPedidos->numPedidos = 0;
        arregloPedidos->pedidos = (stPedido*)malloc(sizeof(stPedido));
    }
    else
    {
        arregloPedidos->pedidos = (stPedido*)realloc(arregloPedidos->pedidos, sizeof(stPedido) * cant + 1);
    }

    system("cls");
    tituloSecciones("ALTA PEDIDO");

    sumCosto = altaArticulos();

    if (sumCosto != 0)
    {
        aux.costoTotal = sumCosto;
        aux.idCliente = idCliente;

        aux.idPedido = cant;

        aux.pedidoAnulado = 0;
        insertado = insertarPedido(ARCHIVO_PEDIDO, aux);

        if (insertado == 1)
        {
            arregloPedidos->pedidos[cant] = aux;
            arregloPedidos->numPedidos++;
        }
        else
        {
            printfWarning("El pedido no se cargo correctamente");
            system("pause");
            altaPedido(arregloPedidos, idCliente);
        }
    }
    else
    {
        printf("WARN: El pedido no se agrego correctamente, desea cargarlo nuevamente s/n: ");
        fflush(stdin);

        control = getche();

        switch (control)
        {
        case 's':
            altaPedido(arregloPedidos, idCliente);
            break;
        case 'n':
            puts("\n\n");
            system("pause");
            break;
        default:
            printfError("El caracter ingresado no es valido...");
            system("pause");
            break;
        }
    }
}

void bajaPedido(arrPedidos *arregloPedidos, int idCliente)
{
    int idPedido;
    int control = 0;

    system("cls");

    tituloSecciones("BAJA DE PEDIDO");

    idPedido = elegirPedido(arregloPedidos, idCliente);

    arregloPedidos->pedidos[idPedido - 1].pedidoAnulado = 1;

    control = anularPedido(ARCHIVO_PEDIDO, idPedido, idCliente);

    if(control == 1)
    {
        printfSucces("El pedidos se anulo correctamente...");
    }
    else
    {
        printfError("El pedidos no se anulo correctamente...");
    }

    printf("\n");
    system("pause");
}

void modificacionPedido(arrPedidos *arregloPedidos, int idCliente)
{
    int control = 0;

    system("cls");
    printf("MODIFICAR\n\n");

    if(control == 1)
    {
        printfSucces("El pedidos se modifico correctamente...");
    }
    else
    {
        printfError("El pedidos no se modifico correctamente...");
    }

    printf("\n");
    system("pause");
}

void listadoPedido(arrPedidos *arregloPedidos, int idCliente)
{
    int i = 0, pedidosAnulados = 0;

    system("cls");
    tituloSecciones("LISTADO PEDIDOS");

    printf("%8s\t%8s", "IDPEDIDO", "PRECIO");
    barraTitulos();

    for(i = 0; i < arregloPedidos->numPedidos; i++)
    {
        if(arregloPedidos->pedidos[i].pedidoAnulado != 1)
        {
            printf("\n%8d\t$%f\t", arregloPedidos->pedidos[i].idPedido, arregloPedidos->pedidos[i].costoTotal);
        }
        else
        {
            pedidosAnulados++;
        }
    }

    puts("\n");
    barraTitulos();

    if (pedidosAnulados == 0)
    {
        printf("\t\t\tNo hay pedidos anulados");
    }
    else
    {
        printf("\t\tPedidos anulados: %d", pedidosAnulados);
    }
    barraTitulos();

    system("pause");
}

int elegirPedido(arrPedidos *arregloPedidos, int idCliente)
{
    int pedidoElegido = 0;

    listadoPedido(arregloPedidos, idCliente);

    printf("Elija un pedido: ");
    scanf("%d", &pedidoElegido);

    return pedidoElegido;
}
