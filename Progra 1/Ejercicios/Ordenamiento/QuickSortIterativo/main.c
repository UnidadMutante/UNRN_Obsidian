#include <stdio.h>

#include "catalogo.h"

int main(void)
{
    Catalogo catalogo =
    {
        {
            {30, "Matrix", 1999},
            {10, "Alien", 1979},
            {40, "Avatar", 2009},
            {20, "Titanic", 1997},
            {5,  "Rocky", 1976}
        },
        5
    };

    printf("=== CATALOGO ORIGINAL ===\n\n");

    imprimirCatalogo(&catalogo);

    ordenarPorId_QuickSortIterativo(&catalogo);

    printf("\n=== CATALOGO ORDENADO ===\n\n");

    imprimirCatalogo(&catalogo);

    return 0;
}