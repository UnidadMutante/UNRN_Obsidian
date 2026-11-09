#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/*
 * Elige el último elemento como pivote y deja:
 * menores o iguales | pivote | mayores
 * Devuelve la posición final del pivote.
 */
int particionLomuto(int arr[], int low, int high)
{
    // El pivote será el último elemento.
    int pivote = arr[high];

// i marca el final de la zona de elementos menores o iguales al pivote.
    
    int i = low - 1;

    // Recorremos todo el subarreglo.
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] <= pivote) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    // Colocamos el pivote entre los menores
    swap(&arr[i + 1], &arr[high]);
    return i + 1;
}

/*
 * Versión iterativa de QuickSort.
 *
 * Utiliza una pila creada con malloc()
 * para guardar los límites de los subarreglos.
 */
void quickSortIterativo(int arr[], int l, int h)
{
    /*
     * Reservamos memoria para la pila.
     *
     * En ella vamos a guardar pares:
     *
     * [inicio, fin]
     */
    int *pila = (int *)malloc((h - l + 1) * sizeof(int));

    /*
     * La pila está vacía.
     */
    int tope = -1;

    /*
     * PUSH inicial.
     *
     * Guardamos los límites del arreglo completo.
     */
    pila[++tope] = l;
    pila[++tope] = h;

    /*
     * Mientras existan subarreglos pendientes.
     */
    while (tope >= 0)
    {
        /*
         * POP
         * Recuperamos el último par
         * de límites almacenados.
         */
        h = pila[tope--];
        l = pila[tope--];

        /*
         * Particionamos el subarreglo actual.
         */
        int p = particionLomuto(arr, l, h);

        /*
         * Si existe una parte izquierda válida:
         *
         * [l .... p-1]
         *
         * la guardamos en la pila.
         */
        if (p - 1 > l)
        {
            pila[++tope] = l;
            pila[++tope] = p - 1;
        }

        /*
         * Si existe una parte derecha válida:
         *
         * [p+1 .... h]
         *
         * la guardamos en la pila.
         */
        if (p + 1 < h)
        {
            pila[++tope] = p + 1;
            pila[++tope] = h;
        }
    }

    /*
     * Liberamos la memoria reservada.
     */
    free(pila);
}

int main(void)
{
    // Genera una semilla distinta cada vez que se ejecuta el programa.
    // Si no se usa, rand() suele generar siempre la misma secuencia.
    srand(time(NULL));

    // Cantidad de elementos del arreglo.
    int n = 8;

    // Arreglo de tamaño 8.
    int arr[n];

    // Se llena el arreglo con números aleatorios
    // entre 1 y 99.
    for (int i = 0; i < n; i++)
    {
        arr[i] = (rand() % 99) + 1;
    }

    printf("Arreglo original (aleatorio):\n");

    // Muestra el arreglo sin ordenar.
    imprimirArreglo(arr, n);

    // Ordenamiento mediante QuickSort Iterativo.
    // Primer parámetro: arreglo.
    // Segundo parámetro: índice inicial.
    // Tercer parámetro: índice final.
    quickSortIterativo(arr, 0, n - 1);

    printf("Arreglo ordenado:\n");

    // Muestra el arreglo ya ordenado.
    imprimirArreglo(arr, n);

    return 0;
}
