#include <stdio.h>


// Prototipo: Recibe el arreglo y su tamaño 
void duplicarValores(int numeros[], int tamano);

int main (void) {
    int misNumeros[3] = {10, 20, 30}; 
    int tamano = sizeof(misNumeros)/sizeof(misNumeros[0]);
    printf("Antes de la funcion: %d\n", misNumeros[0]);     
    duplicarValores(misNumeros, tamano); 
    printf("Despues de la funcion: %d\n", misNumeros[0]); // ¡Imprime 20!
    return 0;
}

void duplicarValores(int numeros[], int tamano) { 
    for(int i = 0; i < tamano; i++) { 
        numeros[i] = numeros[i] * 2; // Modifica la memoria real 
        } 
    }