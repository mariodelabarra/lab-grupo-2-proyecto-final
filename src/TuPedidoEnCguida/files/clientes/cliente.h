#ifndef CLIENTE_H_INCLUDED
#define CLIENTE_H_INCLUDED

typedef struct
{
int idCliente; // auto incremental
char nombre[30];
char apellido[30];
char userName[20];
char password[20];
char mail[30];
char genero;
int rol;     // 1: es admin - 0: es común
int activo; // indica 1 o 0 si el cliente está activo
} stCliente;



#endif // CLIENTE_H_INCLUDED
