#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int idProducto; // auto incremental
    char nombreProducto[20];
    char descripcionProducto[300];
    int stock; // auto decremetal
    int unidadesPedidas;
    float costoPorUnidad; // establecido por el usuario
}
stProducto;

void descripcionProducto();
void altaProducto();
void bajaProducto();
void modificacionProducto();
void consultaPedido();
void listadoProducto();

void descripcionProducto()
{
    char condicion;

    system("cls");

    printf("Desea agregar una descripcion de producto? s/n ");
    fflush(stdin);
    condicion = getche();

    if (condicion == 's')
    {
        printf("\nDescripcion del producto:\n");
        system("pause");
    }
    else if (condicion == 'n')
    {
        printf("\nEl producto no tiene descripcion...\n");
        system("pause");
    }
    else
    {
        printf("\nCracter invalido...\n");
        system("pause");
        descripcionProducto();
    }
}

void altaProducto()
{
   system("cls");

   stProducto producto1;

   printf("Nombre del producto: ");
   fflush(stdin);
   scanf("%s", producto1.nombreProducto);

   descripcionProducto();
}

void bajaProducto() {}

void modificacionProducto() {}

void listadoProducto() {}
