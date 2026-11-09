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
    for (size_t i = 0; i < cantidad; i++) {
    printf("ID: %d | Altitud: %.1f | Temperatura: %.1f\n",
           datos[i].id_paquete,
           datos[i].altitud,
           datos[i].temperatura);
}

// Llamo a Quicksort enviando el índice inicial (0) y el final (n-1) 
   quickSort(datos, 0, cantidad - 1); 
   printf("\nArreglo ordenado: \n"); 
   for (size_t i = 0; i < cantidad; i++) {
    printf("ID: %d | Altitud: %.1f | Temperatura: %.1f\n",
           datos[i].id_paquete,
           datos[i].altitud,
           datos[i].temperatura);
}
    return 0;
}