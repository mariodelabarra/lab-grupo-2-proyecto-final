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
    float costoTotal;  // sumatoria de costoPorUnidad
    int pedidoAnulado; // indica 1 o 0 si el pedido fue anulado o no
} stPedido;

void altaPedido();
void bajaPedido();
void modificacionPedido();
void consultaPedido();
void listadoPedido();

int main() // Temporal
{
    altaPedido();
}

void altaPedido()
{
    printf("Que desea agregar a su pedido:\n");
    listadoArticulos(); // Mostrar articulos
    fechaYHora();       // Mostrar fecha y hora
    // Pedir id de articulo
}

void bajaPedido()
{
    // Mostrar pedidos del cliente
    printf("Id de pedido que desea eliminar: ");
}

void modificacionPedido() {}

void consultaPedido() {}

void listadoPedido() {}
