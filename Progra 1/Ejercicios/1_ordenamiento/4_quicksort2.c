#include <stdio.h>
#include <stdlib.h> // Requerido para qsort

// Complejidad NlogN
// Función comparadora para qsort
// Debe devolver:
//   < 0 si 'a' va antes que 'b'
//   = 0 si son iguales
//   > 0 si 'a' va después que 'b'
int comparar(const void *a, const void *b) {

    // Convertimos los punteros void* a int*
    // y obtenemos los valores apuntados.
    int valorA = *(const int *)a;
    int valorB = *(const int *)b;

    // Comparación segura
    if (valorA < valorB) {
        return -1;
    }

    if (valorA > valorB) {
        return 1;
    }

    return 0;

    /*
     * Para ordenar en forma descendente:
     *
     * if (valorA < valorB) return 1;
     * if (valorA > valorB) return -1;
     * return 0;
     */
}

// Función auxiliar para imprimir el arreglo
void imprimirArreglo(int arr[], int n) {

    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

int main(void) {

    int arr[] = {38, 27, 43, 3, 9, 82, 10};

    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    imprimirArreglo(arr, n);

    // Ordenar utilizando qsort
    // Parámetros:
    // 1. Arreglo a ordenar
    // 2. Cantidad de elementos
    // 3. Tamaño de cada elemento (en bytes)
    // 4. Función comparadora

    qsort(arr, n, sizeof(int), comparar);

    printf("\nArreglo ordenado:\n");
    imprimirArreglo(arr, n);

    return 0;
}