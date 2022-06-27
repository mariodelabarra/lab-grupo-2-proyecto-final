#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../common/mensajes.h"
#include "../common/leerTeclado.h"
#include "../articulos/articulos.h"
#include "../clientes/cliente.h"

#include "pedidos.h"
#include "archivosPedidos.h"

void altaPedido(arrPedidos *arreglo, int idCliente)
{
    int cant = arreglo->numPedidos;
    int sumCosto = 0, insertado = 0;
    stPedido aux;

    if(cant == 0)
    {
        arreglo->numPedidos = 0;
        arreglo->pedidos = (stPedido*)malloc(sizeof(stPedido));
    }
    else
    {
        arreglo->pedidos = (stPedido*)realloc(arreglo->pedidos, sizeof(stPedido) * cant + 1);
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
            arreglo->pedidos[cant] = aux;
            printfSucces("El pedido se cargo correctamente");
        }
        else
        {
            printfWarning("El pedido no se cargo correctamente");
            system("pause");
            altaPedido(arreglo, idCliente);
        }
    }
    else
    {
        printfWarning("El pedido no se agrego correctamente");
        system("pause");
        altaPedido(arreglo, idCliente);
    }
}

void bajaPedido(arrPedidos *arreglo, int idCliente)
{
    int idPedido;
    int control = 0;

    system("cls");

    tituloSecciones("BAJA DE PEDIDO");

    idPedido = elegirPedido(arreglo, idCliente);

    arreglo->pedidos[idPedido - 1].pedidoAnulado = 1;

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

void modificacionPedido(arrPedidos *arreglo, int idCliente)
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

void listadoPedido(arrPedidos *arreglo, int idCliente)
{
    int i = 0, pedidosAnulados = 0;

    system("cls");
    tituloSecciones("LISTADO PEDIDOS");

    printf("%8s\t%8s", "IDPEDIDO", "PRECIO");
    barraTitulos();

    for(i = 0; i < arreglo->numPedidos; i++)
    {
        if(arreglo->pedidos[i].pedidoAnulado != 1)
        {
            printf("\n%8d\t$%.2f\t", arreglo->pedidos[i].idPedido, arreglo->pedidos[i].costoTotal);
            printf("\n");
        }
        else
        {
            pedidosAnulados++;
        }
    }
    printf("Pedidos anulados: %d", pedidosAnulados);
    printf("\n\n");

    system("pause");
}

int elegirPedido(arrPedidos *arreglo, int idCliente)
{
    int pedidoElegido = 0;

    listadoPedido(arreglo, idCliente);

    printf("Elija un pedido: ");
    scanf("%d", &pedidoElegido);

    return pedidoElegido;
}
