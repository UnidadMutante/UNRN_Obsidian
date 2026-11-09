#include <stdio.h>
/*ordenamiento (N log N)

Elige un elemento como "pivote" y arroja los menores a su izquierda y los mayores a su derecha. 
Luego repite esto con cada lado. 
Es extremadamente rápido en la práctica y usa muy poca memoria extra, aunque 
en su peor escenario puede caer a O(N2)
*/

//Función auxiliar para intercambiar variables en memoria 

void swap(int *a, int *b) {
    int temp = *a; 
    *a = *b; 
    *b = temp; 
} 

//La lógica de partición 
int partition(int arr[], int low, int high) {
    int pivot = arr[high]; 
// Tomamos el último elemento como pivote 
    int i = (low - 1); 
// Índice para ubicar los elementos menores al pivote 
// Recorremos el sub-arreglo actual 
    for (int j = low; j <= high - 1; j++) { 
// Si el elemento actual es menor o igual al pivote... 
        if (arr[j] <= pivot) { 
            i++; 
// ...hacemos espacio... 
            swap(&arr[i], &arr[j]); 
// ...y lo arrojamos a la izquierda. 
} } 
// Finalmente, colocamos el pivote en su posición central definitiva 
    swap(&arr[i + 1], &arr[high]);
// Devolvemos la posición final del pivote para dividir el arreglo 
    return (i + 1); 
}

//La lógica recursiva 
void quickSort(int arr[], int low, int high) { 
// Caso base: si low >= high, el sub-arreglo tiene 1 o 0 elementos (ya está ordenado) 
    if (low < high) { 
// Obtenemos el índice donde quedó el pivote anclado 
    int pi = partition(arr, low, high); 
// Llamada recursiva para la mitad izquierda (menores al pivote) 
    quickSort(arr, low, pi - 1); 
// Llamada recursiva para la mitad derecha (mayores al pivote) 
    quickSort(arr, pi + 1, high); 
} } 
// --- Ejemplo de uso --- 
int main() { 
    int arr[] = {40, 10, 50, 30}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    
    printf("Arreglo original: "); 
    for(int i=0; i<n; i++) printf("%d ", arr[i]); 

    // Llamamos a Quicksort enviando el índice inicial (0) y el final (n-1) 
    quickSort(arr, 0, n - 1); 
    printf("\nArreglo ordenado: "); 
    for(int i=0; i<n; i++) printf("%d ", arr[i]); 
    return 0; 
}