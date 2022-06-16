#include "articulos.h"
#include "fecha.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DIM 100

typedef struct
{
    int idPedido;      // auto incremental
    int idCliente;     // este valor corresponde al id del cliente que realizó el pedido
    char fecha[12];    // dd/MM/aaaa
    float costoTotal;  // sumatoria de precio por unidad
    int pedidoAnulado; // indica 1 o 0 si el pedido fue anulado o no
} stPedido;

int altaPedido(stPedido arreglo[], int dim, int pos);
void menu(stPedido arrelgo[], int dim);
void bajaPedido(stPedido arreglo[], int validos);
void modificacionPedido(stPedido arreglo[], int validos);
void consultaPedido(stPedido arreglo[], int validos);
void listadoPedido(stPedido arreglo[], int validos);

int main() // Temporal
{
    stPedido listaPedidos[DIM];

    menu(listaPedidos, DIM);

    return 0;
}

void menu(stPedido arreglo[], int dim)
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

int altaPedido(stPedido arreglo[], int dim, int pos)
{
    int opcion, i = pos;
    char continuar;
    int sumCosto = 0;

    printf("\nIngrese su Id: ");
    scanf("%d", &arreglo[i].idCliente);

    do
    {
        do
        {
            system("cls");

            printf("AGREGAR\n\n");
            listadoArticulos(); // Mostrar articulos

            printf("\nId del articulo a agregar (0 para salir): ");
            scanf("%2d", &opcion);

            switch (opcion)
            {
            case 1:
                sumCosto += precioPorId(0);
                break;
            case 2:
                sumCosto += precioPorId(1);
                break;
            case 3:
                sumCosto += precioPorId(2);
                break;
            case 4:
                sumCosto += precioPorId(3);
                break;
            case 5:
                sumCosto += precioPorId(4);
                break;
            case 6:
                sumCosto += precioPorId(5);
                break;
            case 7:
                sumCosto += precioPorId(6);
                break;
            case 8:
                sumCosto += precioPorId(7);
                break;
            case 9:
                sumCosto += precioPorId(8);
                break;
            case 10:
                sumCosto += precioPorId(9);
                break;
            case 0:
                break;
            default:
                printf("\nOpcion invalida ingrese nuevamente...\n");
                system("pause");
                break;
            }
        }
        while (opcion != 0);

        arreglo[i].costoTotal = sumCosto; // Conmbinar con archivos
        arreglo[i].idPedido = i + 1; // Combinar con archivos

        printf("Desea agregar otro pedido? s/n ");
        fflush(stdin);
        continuar = getche();

        i++;
    }
    while(continuar == 's' && i < dim);

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

        arreglo[idPedido].pedidoAnulado = 1;

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
    int i = 0;
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
            printf("Cliente id: %d ", arreglo[i].idCliente);
            printf("| %d ", arreglo[i].idPedido);
            printf("$%.2f ", arreglo[i].costoTotal);
            mostrarFecha(fecha);
            printf(" PEDIDO ANULADO ");
            printf("\n");
        }
    }
    printf("\n");

    system("pause");
}
