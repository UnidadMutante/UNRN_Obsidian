#ifndef CATALOGO_H
#define CATALOGO_H

#define MAX_PELICULAS 100

typedef struct
{
    int id;
    char titulo[50];
    int anio;
} Pelicula;

typedef struct
{
    Pelicula peliculas[MAX_PELICULAS];
    int cantidad;
} Catalogo;

void ordenarPorId_QuickSortIterativo(Catalogo *cat);
void imprimirCatalogo(const Catalogo *cat);

#endif