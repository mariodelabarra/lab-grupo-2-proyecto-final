#include "pedidos.h"

void menu(stPedido arreglo[], int * dim)
{
    int validos = 0, opcion, i = 0;

    do
    {
        system("cls");
        printf(
            "MENU TEMPORAL\n\n"
            "[1] Agregar\n"
            "[2] Anular\n"
            "[3] Modificar\n"
            "[4] Buscar\n"
            "[5] Listar\n"
            "[0] Salir\n"
        );
        printf("\nElija una opcion (0 para salir): ");
        scanf("%d", &opcion);

        switch (opcion)
        {
        case 1:
            validos = altaPedido(arreglo, dim, i);
            i++;
            break;
        case 2:
            bajaPedido(arreglo, validos);
            break;
        case 3:
            modificacionPedido(arreglo, validos);
            break;
        case 4:
            consultaPedido(arreglo, validos);
            break;
        case 5:
            listadoPedido(arreglo, validos);
            break;
        case 0:
            exit(0);
            break;
        default:
            printf("\nOpcion invalida ingrese nuevamente...\n");
            system("pause");
            break;
        }
    }
    while (opcion != 0);
}

int altaPedido(stPedido arreglo[], int * dim, int pos)
{
    int opcion, i = pos;
    char continuar;
    int sumCosto = 0;
    stPedido aux;

    printf("\nIngrese su Id: ");
    scanf("%d", &aux.idCliente);

    do
    {
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
        aux.idPedido = i + 1;
        aux.pedidoAnulado = 0;

        arreglo[i] = aux;

        printf("Desea agregar otro pedido? s/n ");
        fflush(stdin);
        continuar = getche();

        sumCosto = 0;

        i++;

        dim = dim + 1;
    }
    while(continuar == 's');

    return i;
}

void bajaPedido(stPedido arreglo[], int validos)
{
    int idPedido;
    char continuar;
    int idCli;

    printf("Ingrese su Id: ");
    scanf("%d", &idCli);

    do
    {
        system("cls");

        printf("ANULAR\n\n");

        listadoPedido(arreglo, validos);

        printf("\nId del pedido a anular (0 para salir): ");
        scanf("%d", &idPedido);

        arreglo[idPedido - 1].pedidoAnulado = 1;

        printf("Desea anular otro pedido? s/n ");
        fflush(stdin);
        continuar = getche();
    }
    while(continuar == 's');
}

void modificacionPedido(stPedido arreglo[], int validos)
{
    system("cls");
    printf("MODIFICAR\n\n");

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
            printf("Cliente id: %d ", arreglo[i].idCliente);
            printf("| %d ", arreglo[i].idPedido);
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
