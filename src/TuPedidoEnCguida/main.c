#include <stdio.h>
#include <stdlib.h>

#include "files/menu/menu.h"

int main()
{
    setlocale(LC_ALL, "spanish"); /* Permite imprimir caracteres con tilde */

    arrPedidos arregloPedidos;
    arrClientes arregloClientes;

    arregloPedidos.pedidos = obtenerPedidos(ARCHIVO_PEDIDO, &arregloPedidos.numPedidos);
    arregloClientes.clientes = obtenerClientes(ARCHIVO_CLIENTES, &arregloClientes.numClientes);

    menuPrincipal(&arregloPedidos, &arregloClientes, ARCHIVO_PEDIDO, ARCHIVO_CLIENTES);

    return 0;
}

