#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

/* Standard Libs */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h> /* setlocale */

/* Pedidos */
#include "../articulos/articulos.h"
#include "../pedidos/archivosPedidos.h"
#include "../pedidos/pedidos.h"

/* Common */
#include "../common/mensajes.h"

/* Clientes */
#include "../clientes/archivosClientes.h"
#include "../clientes/cliente.h"

void menuPrincipal(arrPedidos *arregloPedidos, arrClientes *arregloClientes, char archivoPedidos[], char archivoClientes[]);
void menuPedidos(arrPedidos *arregloPedidos, arrClientes *arregloClientes, char nombreArchivo[]);
void menuClientes(arrClientes *arregloPedidos, char nombreArchivo[]);

#endif // MENU_H_INCLUDED
