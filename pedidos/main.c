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

int altaPedido(stPedido arreglo[], int dim);
// void bajaPedido(stPedido arreglo[]);
// void modificacionPedido();
// void consultaPedido();
void listadoPedido(stPedido arreglo[], int validos);

int main() // Temporal
{
    stPedido listaPedidos[DIM];
    int validos = 0;

    validos = altaPedido(listaPedidos, DIM);

    printf("Pedido luego de carga\n");
    listadoPedido(listaPedidos, validos);

    return 0;
}

int altaPedido(stPedido arreglo[], int dim)
{
    int opcion, i = 0;
    char continuar;
    int sumCosto = 0;
    int idCli;

    printf("Ingrese su Id: ");
    scanf("%d", &idCli);

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
            }
        }
        while (opcion != 0);

        arreglo[i].idCliente = idCli;
        arreglo[i].costoTotal = sumCosto; // Conmbinar con archivos
        arreglo[i].idPedido = i + 1; // Combinar con archivos

        printf("Desea agregar otro pedido? s/n");
        fflush(stdin);
        continuar = getche();

        i++;
    }
    while(continuar == 's' && i < dim);
}

// void bajaPedido(stPedido arreglo[])
// {
//     int idPedido;
//     char continuar;
//     int idCli;
//
//     printf("Ingrese su Id: ");
//     scanf("%d", &idCli);
//
//     do
//     {
//         system("cls");
//
//         printf("ANULAR\n\n");
//
//         printf("\nId del pedido a anular (0 para salir): ");
//         scanf("%d", &idPedido);
//
//         arreglo[idPedido].pedidoAnulado = 1;
//
//         printf("Desea anular otro pedido? s/n");
//         fflush(stdin);
//         continuar = getche();
//     }
//     while(continuar == 's');
// }

// void modificacionPedido(stPedido a[], int dim) {}

// void consultaPedido(stPedido a[], int dim) {}

void listadoPedido(stPedido arreglo[], int validos)
{
    int i = 0;

    for(i = 0; i < validos; i++)
    {
        printf("%d", arreglo[i].idPedido);
    }
}
