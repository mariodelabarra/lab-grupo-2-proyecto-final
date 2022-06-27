#ifndef COMMONCLIENTES_H_INCLUDED
#define COMMONCLIENTES_H_INCLUDED

#include "mensajes.h"
#include "leerTeclado.h"

char leerGenero();
int leerRol();

char * leerStringCampoEditable(int numeroElegido, char *campo, char *campoValor);

#endif // COMMONCLIENTES_H_INCLUDED
