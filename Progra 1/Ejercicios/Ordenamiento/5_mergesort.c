/*Complehidad (N log N)
Divide el arreglo literalmente por la mitad una y otra vez hasta que quedan elementos sueltos. 
Luego, los empieza a "fusionar" (merge) de a pares, pero ya en el orden correcto. 
Su tiempo siempre es O(N log N), sin excepciones, pero 
a cambio requiere mucha memoria extra O(N) de complejidad espacial) para hacer esas fusiones.
*/

#include <stdio.h>
#include <stdlib.h>

// Función para fusionar dos mitades ordenadas de un arreglo
void merge(int arr[], int left, int mid, int right) {
    int i, j, k;

    int n1 = mid - left + 1; // Tamaño de la mitad izquierda
    int n2 = right - mid;    // Tamaño de la mitad derecha

    // Crear arreglos temporales
    int L[n1], R[n2];

    // Copiar datos a los arreglos temporales L[] y R[]
    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    // Fusionar los arreglos temporales de vuelta en arr[left..right]
    i = 0;      // Índice inicial del primer subarreglo
    j = 0;      // Índice inicial del segundo subarreglo
    k = left;   // Índice inicial del arreglo fusionado

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Función principal de Merge Sort que divide el arreglo
void mergeSort(int arr[], int left, int right) {
    if (left < right) {

        // Encontrar el punto medio para dividir el arreglo en dos mitades
        int mid = left + (right - left) / 2;

        // Llamadas recursivas para ambas mitades
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        // Fusionar las dos mitades ordenadas
        merge(arr, left, mid, right);
    }
}

// Imprimir el arreglo
void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(void) {
    int arr[] = {38, 27, 43, 3, 9, 82, 10};

    int arr_size = sizeof(arr) / sizeof(arr[0]);

    printf("Arreglo original:\n");
    printArray(arr, arr_size);

    // Llamar a la función de ordenamiento
    mergeSort(arr, 0, arr_size - 1);

    printf("\nArreglo ordenado:\n");
    printArray(arr, arr_size);

    return 0;
}
