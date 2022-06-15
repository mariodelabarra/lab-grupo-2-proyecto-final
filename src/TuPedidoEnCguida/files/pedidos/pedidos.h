#ifndef PEDIDOS_H_INCLUDED
#define PEDIDOS_H_INCLUDED

typedef struct
{
    int idPedido;      // auto incremental
    int idCliente;     // este valor corresponde al id del cliente que realizó el pedido
    char fecha[12];    // dd/MM/aaaa
    float costoTotal;  // sumatoria de precio por unidad
    int pedidoAnulado; // indica 1 o 0 si el pedido fue anulado o no
} stPedido;

void altaPedido();

// void bajaPedido(stPedido a[], int dim) {}

// void modificacionPedido(stPedido a[], int dim) {}

// void consultaPedido(stPedido a[], int dim) {}

// void listadoPedido(stPedido a[], int dim) {}

#endif // PEDIDOS_H_INCLUDED
