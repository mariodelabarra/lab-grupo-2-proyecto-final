#include "files/pedidos/pedidos.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int dim = 0; // validos archivo

    stPedido listaPedidos[dim];

    menu(listaPedidos, &dim);

    return 0;
}
