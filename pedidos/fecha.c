#include "fecha.h"

/* Muestra la fecha y hora actuales */
void fechaYHora()
{
    time_t t = time(NULL);

    struct tm tiempoLocal = *localtime(&t);

    char fechaHora[70];

    char *formato = "%d-%m-%Y %H:%M";

    int bytesEscritos = strftime(fechaHora, sizeof fechaHora, formato, &tiempoLocal);

    if (bytesEscritos != 0)
    {
        printf("%s", fechaHora);
    }
    else
    {
        printf("Error formateando fecha");
    }
}
