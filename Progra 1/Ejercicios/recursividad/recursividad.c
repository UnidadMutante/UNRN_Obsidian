#include <stdio.h>
/*
Complejidad O(N2)
En programación, la recursión ocurre cuando una función se llama a sí misma dentro de su propio bloque de ejecución. Para que un algoritmo recursivo sea matemáticamente válido y no bloquee la computadora en un bucle infinito, debe poseer estrictamente dos componentes estructurales: 1. El Caso Base (La condición de corte): Es la condición simple que detiene la recursividad. Representa el problema más pequeño posible que se puede resolver directamente sin volver a llamar a la función. (En la metáfora, es la primera persona de la fila). 2. El Caso Recursivo (El paso inductivo): Es la parte de la función que reduce el tamaño del problema actual y realiza una nueva llamada a sí misma con esos datos más pequeños, acercándose inexorablemente hacia el caso base.

*/

// 1. El Caso Base: Si llegamos a 1 (o 0), sabemos la respuesta directa. 
int factorial(int n) { 
    if (n <= 1) { 
        return 1; 
    }     
// 2. El Caso Recursivo: Multiplicamos 'n' por el factorial del número anterior. 
else { 
    return n * factorial(n - 1); 
} }


int main (void) {

int numero = factorial(3);
printf("El factorial de 3 es %d", numero);

    return 0;
}