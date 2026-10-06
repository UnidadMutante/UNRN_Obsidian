/*
Implementar la función void rotar_izquierda(int vec[], size_t n) 
que desplace cada elemento una posición hacia la izquierda. 
El elemento que ocupaba la posición 0 debe pasar a la última posición n - 1.

Precondición: vec != NULL.
Postcondición: Para $n > 1$, vec_nuevo[i-1] = vec_viejo[i] para $i \in [1, n-1]$ y vec_nuevo[n-1] = vec_viejo[0].
*/
#include <stdio.h>

void rotar_izquierda(int vec[], size_t n);
void imprimir_vector(const int vec[], size_t n);

int main (void) {
    int numeros[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    size_t tamano = sizeof(numeros)/sizeof(numeros[0]);
    printf("Antes:   ");
    imprimir_vector(numeros, tamano);
    rotar_izquierda(numeros, tamano);
    printf("Despues: ");
    imprimir_vector(numeros, tamano);
    return 0;
}

void imprimir_vector(const int vec[], size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", vec[i]);
    }
    printf("\n");
}

void rotar_izquierda(int vec[], size_t n) {
    if (n <= 1) return;
    int primero = vec[0];
    for (size_t i = 0; i < n - 1; i++) {
        vec[i] = vec[i + 1];
    }
    vec[n - 1] = primero;
}