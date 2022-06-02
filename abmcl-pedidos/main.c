#include <stdio.h>
#include <stdlib.h>

typedef struct {
   int idPedido;        // auto incremental
   int idCliente;       // este valor corresponde al id del cliente que realizó el pedido
   char fecha[12];      // dd/MM/aaaa
   char descripcion[300];
   float costo;
   int pedidoAnulado;    // indica 1 o 0 si el pedido fue anulado o no
} stPedido;

void alta();
void baja();
void modificacion();
void consulta();
void listado();

int main()
{
    return 0;
}

void alta()
{

}

void baja()
{

}

void modificacion()
{

}

void consulta()
{

}

void listado()
{

}
