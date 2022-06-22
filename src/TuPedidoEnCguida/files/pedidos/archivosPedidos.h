#ifndef ARCHIVOSPEDIDOS_H_INCLUDED
#define ARCHIVOSPEDIDOS_H_INCLUDED

#include "pedidos.h"

#define ARCHIVO_PEDIDO "./data/pedidos.dat"

void cargarPedidosArchivo(char rutaArchivo[], stPedido arregloPedidos[], int dim);
stPedido * obtenerPedidos(char rutaArchivo[], int * cantPedidos);
int insertarPedido(char rutaArchivo[], stPedido pedido);
int anularPedido(char rutaArchivo[], int idPedido, int idCliente);
int modificarProducto(char rutaArchivo[], stPedido pedidoModificado);

#endif // ARCHIVOSPEDIDOS_H_INCLUDED
