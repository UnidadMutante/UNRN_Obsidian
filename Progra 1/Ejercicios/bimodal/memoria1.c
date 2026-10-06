/*
Ejercicio 1: Arreglo dinámico básico en tiempo de ejecución.
• Escribe un programa que solicite al usuario la cantidad de elementos
que desea registrar mediante el teclado.
• Reserva dinámicamente un arreglo de enteros (int *) de ese tamaño
exacto utilizando malloc.
• Llena el arreglo de forma que cada posición guarde el valor (i + 1) * 10 e
imprímelo en pantalla.
• Finalizar el script con la formalidad de memoria dinámica
*/

#include <stdio.h>
#include <stdlib.h>

int main (void) {

    int cantidad; 
    int *arreglo; // Arreglo es un puntero porque en este momento aun no se cuanto elementos voy a necesitar

    printf("¿Cuántos numeros enteros queres guardar?: "); 
    scanf("%d", &cantidad); 

    // malloc reserva un bloque de memoria en el heap y devuelve la dirección donde empieza ese bloque. 
    // Una dirección de memoria solo se puede guardar en un puntero, por eso arreglo es int *: 
    // guarda la dirección del primer int del bloque.
    arreglo = (int *)malloc(cantidad * sizeof(int)); 

    if (arreglo == NULL) { 
        printf("Error: No se pudo asignar memoria.\n"); 
        return 1; 
    } 
    for(int i = 0; i < cantidad; i++) { 
        arreglo[i] = (i + 1) * 10; 
         printf("Elemento [%d]: %d\n", i, arreglo[i]); 
        } 
        free(arreglo);  // free(arreglo) libera la memoria, pero no modifica el puntero
        arreglo = NULL; // arreglo sigue guardando la misma dirección, que ahora apunta a memoria que ya no es mia. 
        // Eso se llama puntero colgante (dangling pointer).
    return 0;
}