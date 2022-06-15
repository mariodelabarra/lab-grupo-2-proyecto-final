#include "pedidos.h"

void altaPedido()
{
    int opcion;
    int sumCosto = 0;

    do
    {
        system("cls");

        printf("AGREGAR\n\n");
        listadoArticulos(); // Mostrar articulos

        printf("\nId del articulo a agregar (0 para salir): ");
        scanf("%2d", &opcion);

        switch (opcion)
        {
        case 1:
            sumCosto += precioPorId(0);
            break;
        case 2:
            sumCosto += precioPorId(1);
            break;
        case 3:
            sumCosto += precioPorId(2);
            break;
        case 4:
            sumCosto += precioPorId(3);
            break;
        case 5:
            sumCosto += precioPorId(4);
            break;
        case 6:
            sumCosto += precioPorId(5);
            break;
        case 7:
            sumCosto += precioPorId(6);
            break;
        case 8:
            sumCosto += precioPorId(7);
            break;
        case 9:
            sumCosto += precioPorId(8);
            break;
        case 10:
            sumCosto += precioPorId(9);
            break;
        }
    }
    while (opcion != 0);

    printf("\nEl costo total es $%d\n", sumCosto);
}
