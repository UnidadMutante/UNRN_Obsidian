#include <stdio.h>

#include "ordenamiento.h"

int main (void) {
    Telemetria datos[] = { 
        {101, 1500.5, 22.1}, 
        {102, 3200.0, -5.4}, 
        {103, 800.2, 18.0}, 
        {104, 4100.8, -12.3}, 
        {105, 2100.0, 5.5} 
    }; 
    size_t cantidad = sizeof(datos) /sizeof(datos[0]);
    
    printf("Arreglo original: \n"); 
    imprimirTelemetria(datos, cantidad);

// Llamo a mergeSort enviando el índice inicial (0) y el final (n-1) 
   mergeSort(datos, 0, cantidad - 1); 
   printf("\nArreglo ordenado: \n"); 
   imprimirTelemetria(datos, cantidad);

    return 0;
}