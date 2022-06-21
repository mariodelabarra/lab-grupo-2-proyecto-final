#ifndef MENUBAJAUSUARIO_H_INCLUDED
#define MENUBAJAUSUARIO_H_INCLUDED

void menuBajaUsuario(){
    int opcion;
    do{
        system("cls");
        printf("\n\t\t\t\t\t\t\tBAJA\n");
        printf("\n=======================================================================================================================");
        printf("\n<1> ELIMINAR CUENTA");
        printf("\n<2> DESACTIVAR CUENTA");
        printf("\n<0> REGRESAR\n");

        printf("\nINGRESE UNA OPCION: ");
        scanf("%d", &opcion);
        switch(opcion){
        case 1:

            break;

        case 2:
            break;

        case 0:

            break;
        }



    }while(opcion!=0);
}

#endif // MENUBAJAUSUARIO_H_INCLUDED
