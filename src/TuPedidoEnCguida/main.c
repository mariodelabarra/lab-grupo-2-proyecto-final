#include <stdio.h>
#include <stdlib.h>
#include <locale.h> /* setlocale */

int main()
{
    setlocale(LC_ALL, "spanish"); /* Permite imprimir caracteres con tilde */

    printf("Hello world!\n");
    return 0;
}
