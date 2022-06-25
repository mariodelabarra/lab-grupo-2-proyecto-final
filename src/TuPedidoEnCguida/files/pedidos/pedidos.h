#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

#define PEDIDO_ANULADO 0

typedef struct
{
    int idPedido;      // auto incremental
    int idCliente;     // este valor corresponde al id del cliente que realizó el pedido
    char fecha[12];    // dd/MM/aaaa
    float costoTotal;  // sumatoria de precio por unidad
    int pedidoAnulado; // indica 1 o 0 si el pedido fue anulado o no
} stPedido;

int altaPedido(stPedido arreglo[], int *dim, int pos);
void bajaPedido(stPedido arreglo[], int validos);
void modificacionPedido(stPedido arreglo[], int validos);
void consultaPedido(stPedido arreglo[], int validos);
void listadoPedido(stPedido arreglo[], int validos);

#endif //CLIENTE_H_INCLUDED
