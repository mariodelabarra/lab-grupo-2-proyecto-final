#include <stdio.h>
#include <stdlib.h>

#include "../common/mensajes.h"
#include "pedidos.h"
#include "archivosPedidos.h"

void cargarPedidosArchivo(stPedido arregloPedidos[], int dim, char rutaArchivo[])
{
    FILE * archivo = NULL;

    archivo = fopen(rutaArchivo, "ab");
    if(archivo != NULL)
    {
        fwrite(arregloPedidos, sizeof(stPedido), dim, archivo);
        fclose(archivo);
    }
    else
    {
        printfError("Ocurrio un error al querer abrir el archivo.");
    }
}

void obtenerPedidosDeArchivo(char rutaArchivo[], stPedido arregloPedidos[], int dim)
{
    stPedido pedidoAux;
    int cant = 0;

    FILE * archivoPedidos = NULL;
    archivoPedidos = fopen(rutaArchivo, "rb");

    if(archivoPedidos != NULL)
    {
        while(fread(&pedidoAux, sizeof(stPedido), 1, archivoPedidos) && cant < dim)
        {
            arregloPedidos[cant] = pedidoAux;
            cant++;
        }
    }
    else
    {
        printfError("Ocurrio un error al querer abrir el archivo.");
    }
}
