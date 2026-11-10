#include <stdio.h>
#include <stdlib.h>

/* Imprime el arreglo */
void imprimirArreglo(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
/* Muestra la pila */
void imprimirPila(int pila[], int tope) {
    printf("Pila: ");
    if (tope < 0) {
        printf("[VACIA]\n");
        return;
    } for (int i = 0; i <= tope; i += 2) {
        printf("[%d,%d] ", pila[i], pila[i + 1]);
    }
    printf("\n");
}
/* Intercambio */
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

int particionLomuto(int arr[], int low, int high) {
    int pivote = arr[high];

    printf("\n---------------------------------\n");
    printf("Particionando [%d,%d]\n", low, high);
    printf("Pivote = %d\n", pivote);

    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {
        printf("\nComparo %d con pivote %d\n", arr[j], pivote);

        if (arr[j] <= pivote) {
            i++;
            printf("Intercambio arr[%d]=%d con arr[%d]=%d\n", i, arr[i], j, arr[j]);
            swap(&arr[i], &arr[j]);
            printf("Arreglo: ");
            imprimirArreglo(arr, 6);
        }
    }
    printf("\nColoco el pivote en su lugar definitivo\n");
    swap(&arr[i + 1], &arr[high]);
    printf("Arreglo despues de mover pivote:\n");
    imprimirArreglo(arr, 6);
    printf("Posicion final del pivote: %d\n", i + 1);
    return i + 1;
}

void quickSortIterativo(int arr[], int l, int h, int n)
{
    int *pila = malloc((h - l + 1) * sizeof(int));
    int tope = -1;

    /* PUSH inicial */
    pila[++tope] = l;
    pila[++tope] = h;

    printf("=== INICIO ===\n");
    while (tope >= 0) {
        printf("\n");
        imprimirPila(pila, tope);

        /* POP */
        h = pila[tope--];
        l = pila[tope--];
        printf("\nPOP -> [%d,%d]\n", l, h);
        int p = particionLomuto(arr, l, h);
/* PUSH izquierda */
        if (p - 1 > l) {
            printf("PUSH izquierda [%d,%d]\n", l, p - 1);
            pila[++tope] = l;
            pila[++tope] = p - 1;
        }
/* PUSH derecha */
        if (p + 1 < h) {
            printf("PUSH derecha [%d,%d]\n", p + 1, h);
            pila[++tope] = p + 1;
            pila[++tope] = h;
        }

        printf("Estado actual:\n");
        imprimirArreglo(arr, n);
    }

    free(pila);
}

int main(void)
{
    int arr[] = {8, 2, 5, 3, 9, 4};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Arreglo inicial:\n");
    imprimirArreglo(arr, n);
    quickSortIterativo(arr, 0, n - 1, n);
    printf("\n===================\n");
    printf("Arreglo ordenado:\n");
    imprimirArreglo(arr, n);
    return 0;
}