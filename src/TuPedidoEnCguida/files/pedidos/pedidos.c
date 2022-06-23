#include "pedidos.h"
#include "archivosPedidos.h"
#include "../common/mensajes.h"
#include "../common/fecha.h"
#include "../articulos/articulos.h"

void altaPedido(stPedido arregloPedidos[], int * dim, int idCliente)
{
    int opcion;
    int sumCosto = 0;
    int insertado;
    char fecha[16];
    stPedido aux;

    do
    {
        system("cls");

        printf("AGREGAR\n\n");
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

    fechaYHora(fecha);

    aux.idCliente = idCliente;
    aux.costoTotal = sumCosto;
    aux.idPedido = *dim + 1;
    strcpy(fecha, aux.fecha);
    aux.pedidoAnulado = 0;

    insertado = insertarPedido(ARCHIVO_PEDIDO, aux);

    sumCosto = 0;

    if(insertado == 1)
    {
        realloc(arregloPedidos, (*dim + 1) * sizeof(stPedido));
        arregloPedidos[aux.idPedido] = aux;
        printfSucces("Pedido agregado con exito");
    }
    else
    {
        printfError("El pedido no se agrego correctamente");
    }
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
    // int idPedido = 0;
    int control = 0;

    system("cls");
    printf("MODIFICAR\n\n");

    // idPedido = elegirPedido(arregloPedidos, validos, idCliente);

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

int consultaPedido(stPedido arregloPedidos[], int validos, int idPedido, int idCliente)
{
    int i = 0, flag = 0;
    int pos = -1;

    while (i < validos && flag == 0)
    {
        if(arregloPedidos[i].idCliente == idCliente && arregloPedidos[i].idPedido == idPedido)
        {
            flag = 1;
            pos = i;
        }
    }

    return pos;
}

void listadoPedido(stPedido arregloPedidos[], int validos, int idCliente)
{
    int i = 0, cont = 0;
    // int idCli;

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
