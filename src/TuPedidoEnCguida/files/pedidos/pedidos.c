#include "pedidos.h"

int altaPedido(stPedido arregloPedidos[], int * dim, int pos)
{
    int opcion, i = *dim + 1;
    int sumCosto = 0;
    stPedido aux;

    printf("\nIngrese su Id: ");
    scanf("%d", &aux.idCliente);

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
            printf("\nOpcion invalida ingrese nuevamente...\n");
            system("pause");
        }
    }
    while (opcion != 0);

    aux.costoTotal = sumCosto;
    aux.idPedido = i;
    aux.pedidoAnulado = 0;

    arregloPedidos[i] = aux;

    sumCosto = 0;

    i++;

    dim = dim + 1;

    return i;
}

void bajaPedido(stPedido arregloPedidos[], int validos)
{
    int idPedido;
    int idCli;

    printf("Ingrese su Id: ");
    scanf("%d", &idCli);

    system("cls");

    printf("ANULAR\n\n");

    listadoPedido(arregloPedidos, validos);

    printf("\nId del pedido a anular: ");
    scanf("%d", &idPedido);

    arregloPedidos[idPedido - 1].pedidoAnulado = 1;
}

void modificacionPedido(stPedido arregloPedidos[], int validos)
{
    int idPedido;
    int idCli;

    printf("Ingrese su Id: ");
    scanf("%d", &idCli);

    system("cls");
    printf("MODIFICAR\n\n");

    listadoPedido(arregloPedidos, validos);

    printf("\nId del pedido a modificar: ");
    scanf("%d", &idPedido);

    arregloPedidos[idPedido].costoTotal = 0;

    printf("\n");
    system("pause");
}

void consultaPedido(stPedido arreglo[], int validos)
{
    system("cls");
    printf("BUSCAR\n\n");

    printf("\n");
    system("pause");
}

void listadoPedido(stPedido arreglo[], int validos)
{
    int i = 0, cont = 0;
    char fecha[16];

    system("cls");
    printf("LISTADO\n\n");

    for(i = 0; i < validos; i++)
    {
        if(arreglo[i].pedidoAnulado != 1)
        {
            printf("%d ", arreglo[i].idPedido);
            printf("$%.2f ", arreglo[i].costoTotal);
            mostrarFecha(fecha);
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
