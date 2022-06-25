#include <stdio.h>
#include <stdlib.h>
#include <locale.h> /* setlocale */

#include "files/clientes/cliente.h"
#include "files/clientes/archivosClientes.h"

int main()
{
    setlocale(LC_ALL, "spanish"); /* Permite imprimir caracteres con tilde */

    int cantClientes = 0;
    arrClientes arregloClientes;

//    inicializar(&arregloClientes);
//    agregar(&arregloClientes, "Mario", "Bravo");
//    agregar(&arregloClientes, "Esteban", "Quito");
//    mostrar(arregloClientes);

    arregloClientes.clientes = obtenerClientes(ARCHIVO_CLIENTES, &arregloClientes.numClientes);
    //mostrarClientes(arregloClientes);
    puts("\n\n");
    system("pause");
//    altaCliente(&arregloClientes);
    modificacionCliente(&arregloClientes, 0);


    printf("Hello world!\n");
    return 0;
}

void inicializar(arrClientes *arregloClientes)
{
    arregloClientes->numClientes = 0;
}

//void agregar(arrClientes *arregloCliente, char nombre[], char apellido[])
//{
//    if (arregloCliente->numClientes == 0)
//    {
//		arregloCliente->clientes = (stCliente*)malloc(sizeof(stCliente));
//    }
//	else
//    {
//		arregloCliente->clientes = (stCliente*)realloc(arregloCliente->clientes, sizeof(stCliente) * (arregloCliente->numClientes + 1));
//    }
//
//    strcpy(arregloCliente->clientes[arregloCliente->numClientes].nombre, nombre);
//    strcpy(arregloCliente->clientes[arregloCliente->numClientes].apellido, apellido);
//
//    arregloCliente->numClientes++;
//}

void mostrar(arrClientes arregloClientes)
{
    for(int i = 0; i<arregloClientes.numClientes; i++)
    {
        printf("\narregloClientes[0].nombre = %s", arregloClientes.clientes[i].nombre);
        printf("\narregloClientes[0].apellido = %s\n", arregloClientes.clientes[i].apellido);
    }
}

//void mostrarClientes(arrClientes arregloClientes)
//{
//
//    int opcion = 1;
//    stCliente clienteAux;
//
//    printf("\n\t\t    ==> LISTADO DE PEDIDOS REGISTRADOS <==\n");
//    printf(" ------------------------------------------------------------------------------\n");
//    printf("%8s\t%8s%15s%20s\n", "IDCLIENTE", "NOMBRE", "APELLIDO", "USERNAME");
//    printf(" ------------------------------------------------------------------------------\n");
//
//    for(int i=0; i<arregloClientes.numClientes; i++)
//    {
//        printf("\n%8d\t%8s\t%8s\t%8s", arregloClientes.clientes[i].idCliente, arregloClientes.clientes[i].nombre, arregloClientes.clientes[i].apellido, arregloClientes.clientes[i].userName);
//    }
//
//    puts("\n\n ------------------------------------------------------------------------------\n");
//}
