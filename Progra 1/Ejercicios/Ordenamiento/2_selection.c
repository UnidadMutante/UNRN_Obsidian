#include <stdio.h>
/*
Complejidad O(N2)
Selection Sort (El buscador del mínimo): El bucle externo avanza lentamente, fijando la posición que se va a ordenar en ese paso (avanza “N” veces). El bucle interno tiene que escanear todo el resto del arreglo desordenado para encontrar el valor mínimo absoluto. Invariablemente, para colocar el primer elemento hace “N-1” comparaciones, para el segundo “N-2”, etc. A diferencia de otros, Selection Sort siempre hace O(N2 ) operaciones, incluso si el arreglo ya estaba perfectamente ordenado
*/

void selectionSort(int arr[], int n) { 
    for (int i = 0; i < n - 1; i++) { 
    int min_idx = i; 
// Buscar el índice del elemento más pequeño en la parte desordenada 
for (int j = i + 1; j < n; j++) { 
    if (arr[j] < arr[min_idx]) { 
        min_idx = j; 
    } 
} 
// Intercambiar el mínimo encontrado con el primer elemento desordenado 
if (min_idx != i) { 
    int temp = arr[i]; 
    arr[i] = arr[min_idx]; 
    arr[min_idx] = temp; 
} 
} 
};

int main (void){




    return 0;
}