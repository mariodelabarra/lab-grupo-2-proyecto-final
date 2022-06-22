#include "pedidos.h"
#include "archivosPedidos.h"
#include "../common/mensajes.h"
#include "../common/fecha.h"
#include "../articulos/articulos.h"

int altaPedido(stPedido arregloPedidos[], int * dim, int pos, int idCliente)
{
    int opcion, i = pos;
    int sumCosto = 0;
    char fecha[DIM_FECHA];
    stPedido aux;

    do
    {
        system("cls");

        printf("AGREGAR\n\n");
        listadoArticulos();

        printf("\nId del articulo a agregar (0 para salir): ");
        scanf("%2d", &opcion);

        if(opcion > 0 && opcion <= 10)
        {
            sumCosto += precioPorId(opcion - 1);
        }
        else
        {
            printfError("Opcion invalida ingrese nuevamente...");
            system("pause");
        }
    }
    while (opcion != 0);

    fechaYHora(fecha);

    aux.idCliente = idCliente;
    aux.costoTotal = sumCosto;
    aux.idPedido = i;
    strcpy(fecha, aux.fecha);
    aux.pedidoAnulado = 0;

    insertarPedido(ARCHIVO_PEDIDO, aux);

    arregloPedidos[i] = aux;

    sumCosto = 0;

    i++;

    dim = dim + 1;

    return i;
}

void bajaPedido(stPedido arregloPedidos[], int validos, int idCliente)
{
    int idPedido;
    int control = 0;

    system("cls");

    printf("ANULAR\n\n");

    idPedido = elegirPedido(arregloPedidos, validos, idCliente);

    arregloPedidos[idPedido - 1].pedidoAnulado = 1;

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

void modificacionPedido(stPedido arregloPedidos[], int validos, int idCliente)
{
    int idPedido = 0;
    int control = 0;

    system("cls");
    printf("MODIFICAR\n\n");

    idPedido = elegirPedido(arregloPedidos, validos, idCliente);

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

// void consultaPedido(stPedido arregloPedidos[], int validos)
// {
//     system("cls");
//     printf("BUSCAR\n\n");
//
//     printf("\n");
//     system("pause");
// }

void listadoPedido(stPedido arregloPedidos[], int validos, int idCliente)
{
    int i = 0, cont = 0;
    int idCli;

    system("cls");
    printf("LISTADO\n\n");

    for(i = 0; i < validos; i++)
    {
        if(arregloPedidos[i].pedidoAnulado != 1)
        {
            printf("%d ", arregloPedidos[i].idPedido);
            printf("$%.2f ", arregloPedidos[i].costoTotal);
            printf("%s", arregloPedidos[i].fecha);
            printf("\n");
        }
        else
        {
            cont++;
        }
    }
    printf("Pedidos anulados: %d", cont);
    printf("\n\n");

    system("pause");
}

int elegirPedido(stPedido arregloPedidos[], int validos, int idCliente)
{
    int pedidoElegido = 0;

    listadoPedido(arregloPedidos, validos, idCliente);

    printf("Elija un pedido: ");
    scanf("%d", &pedidoElegido);

    return pedidoElegido;
}
