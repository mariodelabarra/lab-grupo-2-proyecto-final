#ifndef COMMONCLIENTES_H_INCLUDED
#define COMMONCLIENTES_H_INCLUDED

#include "../clientes/cliente.h"

char leerGenero();
int leerRol();
char * leerEmail(arrClientes *arregloClientes);

char * leerStringCampoEditable(int numeroElegido, char *campo, char *campoValor);

#endif // COMMONCLIENTES_H_INCLUDED
