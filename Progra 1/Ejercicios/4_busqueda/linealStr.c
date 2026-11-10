#include <stdio.h>
#include <string.h>
#include <stdbool.h>

bool buscarPalabra(const char oracion[], const char palabra[])
{
    int largoOracion = strlen(oracion);
    int largoPalabra = strlen(palabra);

    for (int i = 0; i <= largoOracion - largoPalabra; i++)
    {
        int j = 0;

        while (j < largoPalabra &&
               oracion[i + j] == palabra[j])
        {
            j++;
        }

        if (j == largoPalabra)
        {
            return true;
        }
    }

    return false;
}

int main(void)
{
    char oracion[100];
    char palabra[30];

    printf("Ingrese una oracion: ");
    fgets(oracion, sizeof(oracion), stdin);

    printf("Ingrese una palabra a buscar: ");
    scanf("%s", palabra);

    if (buscarPalabra(oracion, palabra))
    {
        printf("Palabra encontrada.\n");
    }
    else
    {
        printf("Palabra no encontrada.\n");
    }

    return 0;
}