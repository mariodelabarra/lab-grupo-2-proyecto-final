#ifndef MENUPEDIDO_H_INCLUDED
#define MENUPEDIDO_H_INCLUDED

void menuPedido()
{
    int opcion;
    do
    {
        system("cls");
        printf("\n\t\t\t\t\t\t\tCONSULTA\n");
        printf("\n=======================================================================================================================");
        printf("\n<1> VER LISTA DE PRODUCTOS");
        printf("\n<2> REALIZAR PEDIDO");
        printf("\n<3> MODIFICAR PEDIDO");
        printf("\n<4> ANULAR PEDIDO");
        printf("\n<5> LISTAR PEDIDOS");
        printf("\n<0> REGRESAR\n");

        printf("\nINGRESE UNA OPCION: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:

            break;

        case 2:

            break;

        case 3:

            break;

        case 4:

            break;

        case 5:

            break;

        case 0:

            break;
        }

    }
    while(opcion!=0);
}

#endif // MENUPEDIDO_H_INCLUDED
