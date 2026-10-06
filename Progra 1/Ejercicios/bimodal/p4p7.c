/*
Implementar la función size_t eliminar_duplicados_consecutivos(int vec[], size_t n) 
que modifique el vector eliminando valores repetidos adyacentes de manera in-place 
y retorne la nueva longitud del arreglo compactado.

Precondición: vec != NULL.
Postcondición: Reordena las primeras $k$ posiciones ($k \le n$) sin elementos repetidos contiguos y devuelve $k$. 

Ejemplo: [1, 1, 2, 2, 2, 3, 1] $\rightarrow$ modifica a [1, 2, 3, 1, ...] y retorna 4.
*/
#include <stdio.h>
#include <stddef.h>

void ordenar(int vec[], size_t n);

size_t eliminar_duplicados_consecutivos(int vec[], size_t n);

static void imprimir(const int vec[], size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

int main(void) {
    int arreglo[] = {3, 8, 5, 2, 4, 1, 3, 9, 3, 8, 2, 4, 0};
    size_t tamano = sizeof(arreglo) / sizeof(arreglo[0]);

    ordenar(arreglo, tamano);
    printf("Ordenado: ");
    imprimir(arreglo, tamano);

    size_t distintos = eliminar_duplicados_consecutivos(arreglo, tamano);
    printf("Sin repetidos: ");
    imprimir(arreglo, distintos);
    printf("Cantidad de numeros distintos: %zu\n", distintos);

    return 0;
}

void ordenar(int vec[], size_t n) {
    // Insertion sort
    for (size_t i = 1; i < n; i++) {
        int actual = vec[i];
        size_t j = i;
        while (j > 0 && vec[j - 1] > actual) {
            vec[j] = vec[j - 1];
            j--;
        }
        vec[j] = actual;
    }
}

size_t eliminar_duplicados_consecutivos(int vec[], size_t n) {
    size_t i = 1;
    while (i < n) {
        if (vec[i] == vec[i - 1]) {
            //correr todo lo que sigue una posición a la izquierda
            for (size_t j = i; j + 1 < n; j++) {
                vec[j] = vec[j + 1];
            }
            n--;        // el arreglo útil es un elemento más corto
        } else {
            i++;        // solo avanza si no eliminó nada
        }
    }

    return n;
}