#include <stdio.h>
#include <stdlib.h>

#include "menuCliente.h"
#include "../common/mensajes.h"

void menuClientes(arrClientes *arregloClientes, char nombreArchivo[])
{
    int opcion = 0;
    int idCliente;

    do
    {
        system("cls");
        tituloSecciones("MENU DE CLIENTES");

        printf
            (
                "\n\n"
                "[1] Alta\n"
                "[2] Baja\n"
                "[3] Modificacion\n"
                "[4] Listado\n"
                "\n[0] Salir\n"
            );

        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);

        switch (opcion)
        {
            case 1:
                altaCliente(arregloClientes);
                break;
            case 2:
                idCliente = leerIdCliente();
                bajaCliente(arregloClientes, idCliente);
                break;
            case 3:
                idCliente = leerIdCliente();
                modificacionCliente(arregloClientes, idCliente);
                break;
            case 4:
                listadoClientes(arregloClientes, "LISTADO DE CLIENTES");
                break;
            case 0:
                break;
            default:
                printfError("Opcion invalida...");
                break;
        }

    }while (opcion != 0);
}

int leerIdCliente()
{
    int idCliente;

    printf("Ingrese su id de cliente: ");
    scanf("%d", &idCliente);

    return idCliente;
}
