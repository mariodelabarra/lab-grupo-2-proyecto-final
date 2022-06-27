#include "fecha.h"

/* Muestra la fecha y hora actuales */
char * fechaYHora()
{
    char fechaHora[DIM_FECHA];

    time_t t = time(NULL);

    struct tm tiempoLocal = *localtime(&t);

    char *formato = "%d-%m-%Y %H:%M";

    int bytesEscritos = strftime(fechaHora, sizeof(char)*DIM_FECHA, formato, &tiempoLocal);

    if (bytesEscritos == 0)
    {
        printf("Error formateando fecha ");
    }

    return fechaHora;
}

void mostrarFecha(char fechaHora[DIM_FECHA])
{
    fechaYHora(fechaHora);

    for(int i = 0; i < DIM_FECHA; i++)
    {
        printf("%c", fechaHora[i]);
    }
}
