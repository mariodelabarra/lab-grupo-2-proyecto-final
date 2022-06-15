#include <stdio.h>
#include <string.h>

typedef struct
{
    int idArticulo;
    char nombreArticulo[30];
    unsigned float precioArticulo;
} stArticulos;

void listadoArticulos();
void mostrarArticuloPorId(int idArticulo);
int precioPorId(int idArticulo);
int cantArticulos(int idArticulo);
