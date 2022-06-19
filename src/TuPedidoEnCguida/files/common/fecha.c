#include "fecha.h"

/* Muestra la fecha y hora actuales */
void fechaYHora(char* fechaHora)
{
    time_t t = time(NULL);

    struct tm tiempoLocal = *localtime(&t);

    char *formato = "%d-%m-%Y %H:%M";

    int bytesEscritos = strftime(fechaHora, sizeof(char)*16, formato, &tiempoLocal);

    if (bytesEscritos == 0)
    {
        printf("Error formateando fecha");
    }
}
