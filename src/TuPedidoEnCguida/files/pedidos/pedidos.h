#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idPedido;      // auto incremental
    int idCliente;     // este valor corresponde al id del cliente que realizó el pedido
    char fecha[18];    // dd/MM/aaaa
    float costoTotal;  // sumatoria de precio por unidad
    int pedidoAnulado; // indica 1 o 0 si el pedido fue anulado o no
} stPedido;

int altaPedido(stPedido arregloPedidos[], int *dim, int pos, int idCliente);
void bajaPedido(stPedido arregloPedidos[], int validos, int idCliente);
void modificacionPedido(stPedido arregloPedidos[], int validos, int idCliente);
// void consultaPedido(stPedido arreglo[], int validos);
void listadoPedido(stPedido arregloPedidos[], int validos, int idCliente);
int elegirPedido(stPedido arregloPedidos[], int validos, int idCliente);
