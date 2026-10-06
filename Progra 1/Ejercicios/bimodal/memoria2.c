/*
Ejercicio 2: Dimensión dinámica mediante los argumentos del main.
• Crea un programa que reciba la dimensión del problema a través de la
consola en el instante exacto en que arranca, usando argc y argv.
• Convierte el texto de la dimensión ingresada a un número entero
utilizando la función atoi().
• Utiliza ese número para hacer una declaración dinámica con malloc,
validando que el sistema operativo entregue la memoria, y límpiala antes
de terminar.
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        printf("Error: Tenes que ingresar un numero.\n");
        return 1; // Un return distinto de 0 indica que el programa falló
    } 

    int cantidad = atoi(argv[1]); 
   
    if (cantidad <= 0) {
        printf("Error: la dimension debe ser un entero positivo.\n");
        return 1;
    } 
    printf("ingresaste %d.\n", cantidad);
    

    int *arreglo = (int*)malloc(sizeof(int)*cantidad);
    if (arreglo == NULL) {
        printf("Error: memoria insuficiente.\n");
        return 1;
    }

     for (int i = 0; i < cantidad; i++) {
        arreglo[i] = (i + 1) * 10;
        printf("Elemento [%d]: %d\n", i, arreglo[i]);
    }
    
    free(arreglo);
    arreglo = NULL;
    return 0;
}