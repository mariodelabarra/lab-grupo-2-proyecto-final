#include "articulos.h"
#include "fecha.h"
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idPedido;      // auto incremental
    int idCliente;     // este valor corresponde al id del cliente que realizó el pedido
    char fecha[12];    // dd/MM/aaaa
    float costoTotal;  // sumatoria de precio por unidad
    int pedidoAnulado; // indica 1 o 0 si el pedido fue anulado o no
} stPedido;

void altaPedido(/*stPedido a[], int dim*/);
// void bajaPedido(stPedido a[], int dim);
// void modificacionPedido(stPedido a[], int dim);
// void consultaPedido(stPedido a[], int dim);
// void listadoPedido(stPedido a[], int dim);

int main() // Temporal
{
    altaPedido();
}

void altaPedido()
{
    int opcion;
    int sumCosto = 0;

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

    printf("\nEl costo total es $%d\n", sumCosto);
}

// void bajaPedido(stPedido a[], int dim) {}
//
// void modificacionPedido(stPedido a[], int dim) {}
//
// void consultaPedido(stPedido a[], int dim) {}
//
// void listadoPedido(stPedido a[], int dim) {}
