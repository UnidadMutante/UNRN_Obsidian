#include <stdio.h>
#include <stdlib.h> // necesario para usar malloc y free


int main () {
    int filas, columnas;
    printf("introduce el numero de filas: ");
    scanf("%d", &filas);
    printf("Introduce el numero de columnas: ");
    scanf("%d", &columnas);

    // reservar memoria
    // vector de punteros (filas)
    int **matriz = (int **)malloc(filas * sizeof(int *));

    // a cada fila se le asigna su vctor de elementos
    for (int i = 0; i < filas; i++) {
        matriz[i] = (int *)malloc(columnas * sizeof(int));
    } 
}