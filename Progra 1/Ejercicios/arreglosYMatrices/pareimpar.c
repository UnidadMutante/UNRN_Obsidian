#include <stdio.h>

int main (void){

    // recorrido de posiciones pares
    int arr1[] = {10, 20, 30, 40, 50,}; 
    size_t tamano1 = sizeof(arr1) / sizeof(arr1[0]); 
    for (size_t i = 0; i < tamano1; i+=2) { 
        printf("Posicion %zu: %d\n", i, arr1[i]); 
    }

// Recorrido de posiciones impares
    int arr2[] = {10, 20, 30, 40}; 
    size_t tamano2 = sizeof(arr2) / sizeof(arr2[0]); 
    for (size_t i = 1; i < tamano2; i+=2) { 
        printf("Posicion %zu: %d\n", i, arr2[i]); 
    } 
}