#include <stdio.h> 

int* crearArregloSeguro() { 
// La palabra 'static' evita que C destruya este arreglo al hacer return 
static int numeros[3] = {10, 20, 30}; 
// Devolvemos la dirección de memoria del inicio 
return numeros; 
} 

int main(void) { 
    // Atrapamos las llaves del edificio usando un puntero (*) 
    int *miArreglo = crearArregloSeguro(); 
    // Ahora podemos usarlo normalmente 
    printf("El primer numero es: %d\n", miArreglo[0]); 
    // Imprime 10 
    return 0; 
}