#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../common/fecha.h"

typedef struct
{
    int idPedido;      // auto incremental
    int idCliente;     // este valor corresponde al id del cliente que realizó el pedido
    //char fecha[DIM_FECHA];    // dd/MM/aaaa
    float costoTotal;  // sumatoria de precio por unidad
    int pedidoAnulado; // indica 1 o 0 si el pedido fue anulado o no
} stPedido;

typedef struct
{
    stPedido * pedidos;
    int numPedidos;
} arrPedidos;

void altaPedido(arrPedidos *arregloPedidos, int idCliente);
void bajaPedido(arrPedidos *arregloPedidos, int idCliente);
void modificacionPedido(arrPedidos *arregloPedidos, int idCliente);
void listadoPedido(arrPedidos *arregloPedidos, int idCliente);

int elegirPedido(arrPedidos *arregloPedidos, int idCliente);

#endif // PEDIDOS_H_INCLUDED
