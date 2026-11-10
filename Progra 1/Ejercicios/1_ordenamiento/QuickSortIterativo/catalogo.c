#include <stdio.h>
#include <stdlib.h>

#include "catalogo.h"

/*
 * Intercambia dos películas completas.
 */
static void swap(Pelicula *a, Pelicula *b)
{
    Pelicula aux = *a;
    *a = *b;
    *b = aux;
}

/*
 * Partición de Lomuto.
 */
static int particionLomuto(Pelicula arr[],
                           int low,
                           int high)
{
    int pivote = arr[high].id;

    int i = low - 1;

    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j].id <= pivote)
        {
            i++;

            swap(&arr[i], &arr[j]);
        }
    }

    swap(&arr[i + 1], &arr[high]);

    return i + 1;
}

/*
 * QuickSort Iterativo.
 */
void ordenarPorId_QuickSortIterativo(Catalogo *cat)
{
    int low = 0;
    int high = cat->cantidad - 1;

    int *pila =
        malloc((high - low + 1) * sizeof(int));

    if (pila == NULL)
    {
        return;
    }

    int tope = -1;

    /*
     * PUSH inicial.
     */
    pila[++tope] = low;
    pila[++tope] = high;

    while (tope >= 0)
    {
        /*
         * POP.
         */
        high = pila[tope--];
        low  = pila[tope--];

        int p =
            particionLomuto(cat->peliculas,
                            low,
                            high);

        /*
         * Subarreglo izquierdo.
         */
        if (p - 1 > low)
        {
            pila[++tope] = low;
            pila[++tope] = p - 1;
        }

        /*
         * Subarreglo derecho.
         */
        if (p + 1 < high)
        {
            pila[++tope] = p + 1;
            pila[++tope] = high;
        }
    }

    free(pila);
}

void imprimirCatalogo(const Catalogo *cat)
{
    for (int i = 0; i < cat->cantidad; i++)
    {
        printf("ID: %d | Titulo: %s | Anio: %d\n",
               cat->peliculas[i].id,
               cat->peliculas[i].titulo,
               cat->peliculas[i].anio);
    }
}