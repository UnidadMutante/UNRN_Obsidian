#include <stdio.h>

/*
Complejidad O(N2)
Insertion Sort (El de las cartas en la mano): El bucle externo toma un elemento nuevo del arreglo (N veces). El bucle interno lo compara hacia atrás contra la sublista que ya está ordenada, desplazando valores en memoria para hacerle lugar. Si el arreglo está totalmente invertido, cada elemento nuevo obliga a desplazar hacia la derecha a todos los elementos anteriores. Sin embargo, su gran ventaja práctica es que si el arreglo ya está ordenado (o casi ordenado), el bucle interno se detiene de inmediato, dándole un rendimiento de O(N) en el mejor de los casos.
*/

void insertionSort(int arr[], int n) { 
    for (int i = 1; i < n; i++) { 
        int key = arr[i]; 
        int j = i - 1;
// Desplazar a la derecha los elementos que sean mayores que 'key' 
while (j >= 0 && arr[j] > key) { 
    arr[j + 1] = arr[j]; 
    j = j - 1; 
} 
// Insertar 'key' en su posición matemáticamente correcta 
arr[j + 1] = key; 
} 
};


int main (void) {



    return 0;
}