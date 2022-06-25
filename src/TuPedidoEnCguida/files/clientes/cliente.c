#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../common/mensajes.h"

#include "cliente.h"
#include "archivosClientes.h"
#include "../common/commonClientes.h"
#include "../common/leerTeclado.h"

void altaCliente(arrClientes *arregloClientes)
{
    int cant = arregloClientes->numClientes;
    stCliente aux;

    if (cant == 0)
    {
        arregloClientes->numClientes = 0;
		arregloClientes->clientes = (stCliente*)malloc(sizeof(stCliente));
    }
	else
    {
		arregloClientes->clientes = (stCliente*)realloc(arregloClientes->clientes, sizeof(stCliente) * (cant + 1));
    }

    system("cls");

    tituloSecciones("AGREGAR UN NUEVO CLIENTE");

    strcpy(aux.nombre, leerString("\nIngrese el nombre del cliente: ", 30));

    strcpy(aux.apellido, leerString("\nIngrese el apellido del cliente: ", 30));

    strcpy(aux.userName, leerString("\nIngrese el username del cliente: ", 20));

    strcpy(aux.password, leerString("\nIngrese el password del cliente: ", 20));

    strcpy(aux.mail, leerString("\nIngrese el mail del cliente: ", 30));

    aux.genero = leerGenero();
    aux.rol = leerRol();

    aux.idCliente = cant;

    aux.activo = 0;
    int insertado = insertarCliente(ARCHIVO_CLIENTES, aux);

    if(insertado == 1)
    {
        arregloClientes->clientes[cant] = aux;
        arregloClientes->numClientes++;
    }
    else
    {
        printfError("Ocurrio un error al insertar el nuevo cliente");
    }

}

//void mostrarClienteCargado(arrClientes *arregloClientes)
//{
//    for(int i = 0; i<=arregloClientes->numClientes; i++)
//    {
//        puts("\n");
//        printf("\n idCliente: %d", arregloClientes->clientes[i].idCliente);
//        printf("\n nombre: %s", arregloClientes->clientes[i].nombre);
//        printf("\n apellido: %s", arregloClientes->clientes[i].apellido);
//        printf("\n userName: %s", arregloClientes->clientes[i].userName);
//        printf("\n password: %s", arregloClientes->clientes[i].password);
//        printf("\n mail: %s", arregloClientes->clientes[i].mail);
//        printf("\n genero: %c", arregloClientes->clientes[i].genero);
//        printf("\n rol: %d", arregloClientes->clientes[i].rol);
//    }
//}

void bajaCliente(arrClientes *arregloClientes, int idCliente)
{

    system("cls");

    printf("ANULAR\n\n");

    listadoCliente(arregloClientes);

    printf("\nId del Cliente a anular: ");
    scanf("%d", &idCliente);

    arregloClientes->clientes[idCliente].activo = 1;
}

void modificacionCliente(arrClientes *arregloClientes, int idCliente)
{
    int opcion = 0, pos = 0;
    system("cls");
    printf("MODIFICAR\n\n");

    listadoCliente(arregloClientes);

    printf("\nId del Cliente a modificar: ");
    scanf("%d", &idCliente);

    pos = buscarPosicionCliente(*arregloClientes, idCliente);

    arregloClientes->clientes[pos] = leerCamposAEditar(arregloClientes->clientes[pos]);

    listadoCliente(arregloClientes);

    int modificado = modificarCliente(ARCHIVO_CLIENTES, arregloClientes->clientes[pos]);

    if(modificado == 1)
    {
        puts("\n\n ! Archivo modificado con exito. !");
    }
    else
    {
        printfError("Ha ocurrido un error al intentar modificar el archivo");
    }

    printf("\n");
    system("pause");
}

void consultaCliente(arrClientes *arregloClientes, int idCliente)
{
    system("cls");
    printf("BUSCAR\n\n");

    printf("\n");
    system("pause");
}

void listadoCliente(arrClientes *arregloClientes)
{
    int i = 0, cont = 0;

    system("cls");

    printf("\n\t\t    ==> LISTADO DE CLIENTES REGISTRADOS <==\n");
    printf(" ------------------------------------------------------------------------------\n");
    printf("%8s\t%8s%15s%20s\n", "IDCLIENTE", "NOMBRE", "APELLIDO", "USERNAME");
    printf(" ------------------------------------------------------------------------------\n");

    for(i = 0; i < arregloClientes->numClientes; i++)
    {
        if(arregloClientes->clientes[i].activo != 1)
        {
            printf("\n%8d\t%8s\t%8s\t%8s", arregloClientes->clientes[i].idCliente, arregloClientes->clientes[i].nombre, arregloClientes->clientes[i].apellido, arregloClientes->clientes[i].userName);
        }
        else
        {
            cont++;
        }
    }

    puts("\n\n ------------------------------------------------------------------------------\n");
    printf("\t\t\tClientes anulados: %d", cont);
    puts("\n\n ------------------------------------------------------------------------------\n");
    printf("\n\n");

    system("pause");
}

stCliente leerCamposAEditar(stCliente cliente)
{
    int opcion = 0;
    do
    {
        system("cls");
        listarCamposEditables(cliente);
        puts("\n\n - ¿Que campo desea modificar?: ");
        scanf("%d", &opcion);

        system("cls");
        switch(opcion)
        {
            case 1:
                strcpy(cliente.nombre, leerStringCampoEditable(2, "Nombre", cliente.nombre));
                break;
            case 2:
                strcpy(cliente.apellido, leerStringCampoEditable(2, "Apellido", cliente.apellido));
                break;
            case 3:
                strcpy(cliente.mail, leerStringCampoEditable(2, "Mail", cliente.mail));
                break;
            case 4:
                printf(" ------------------------------------------------------------------------------\n");
                printf("\n\n 1-   Genero: %c", cliente.genero);
                cliente.genero = leerGenero();
                printf(" ------------------------------------------------------------------------------\n");
                break;
            case 5:
                printf(" ------------------------------------------------------------------------------\n");
                printf("\n\n 1-   Rol: %d", cliente.rol);
                cliente.rol = leerRol();
                printf(" ------------------------------------------------------------------------------\n");
                break;
            default:
                break;
        }
    }while(opcion != 0);

    return cliente;
}

int buscarPosicionCliente(arrClientes arregloClientes, int idCliente)
{
    int encontrado = 0, i = 0;
    while(i<arregloClientes.numClientes && encontrado == 0)
    {
        if(arregloClientes.clientes[i].idCliente == idCliente)
        {
            encontrado = 1;
        }
        i++;
    }

    return encontrado;
}

int listarCamposEditables(stCliente cliente)
{
    printf(" ------------------------------------------------------------------------------\n");
    printf("\n\t\t    ==> MODIFICACION DE USUARIO <==\n");
    printf(" ------------------------------------------------------------------------------\n");

    printf("\n\n 1-   Nombre: %s", cliente.nombre);
    printf("\n\n 2- Apellido: %s", cliente.apellido);
    printf("\n\n 3-     Mail: %s", cliente.mail);
    if(cliente.genero == 'M')
    {
        printf("\n\n 4-   Genero: Masculino");
    }
    else
    {
        printf("\n\n 4-   Genero: Femenino");
    }
    if(cliente.rol == 0)
    {
        printf("\n\n 5-      Rol: Usuario");
    }
    else
    {
        printf("\n\n 5-      Rol: Admin");
    }
    printf("\n\n 0-      Salir");
}
