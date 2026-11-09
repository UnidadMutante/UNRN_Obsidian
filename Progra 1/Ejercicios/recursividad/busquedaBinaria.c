#include <stdio.h>

int binSearch(int n[], int tam, int valor);
int binSearchRec(int n[], int tam, int valor);

int main(void) {
    int numeros[] = {2, 5, 8, 12, 16, 23, 38, 56, 72, 91};
    int tam = sizeof(numeros) / sizeof(numeros[0]);

    printf("Recursiva: 91 -> %d\n", binSearchRec(numeros, tam, 91));   /* 9 */
    printf("Recursiva:  2 -> %d\n", binSearchRec(numeros, tam, 2));    /* 0 */
    printf("Recursiva: 50 -> %d\n", binSearchRec(numeros, tam, 50));   /* -1 */

    return 0;
}

/* Versión recursiva. Tiempo O(log n), espacio O(log n) por la pila de llamadas.
   Usa aritmética de punteros para achicar el arreglo en cada llamada. */
int binSearchRec(int n[], int tam, int valor) {
    if (tam <= 0) {
        return -1;                                 /* caso base: no quedan elementos */
    }

    int medio = tam / 2;

    if (n[medio] == valor) {
        return medio;                              /* caso base: encontrado */
    }

    if (n[medio] < valor) {
        /* busco en la mitad derecha: empieza en medio + 1 */
        int r = binSearchRec(n + medio + 1, tam - medio - 1, valor);
        if (r == -1) {
            return -1;                             /* no estaba en la derecha */
        }
        return medio + 1 + r;                      /* corrijo el índice */
    }

    /* busco en la mitad izquierda: índices 0..medio-1 */
    return binSearchRec(n, medio, valor);
}