/*
Escribir la función void invertir_vector(int vec[], size_t n) 
que invierta el orden de los elementos del arreglo de manera in-place (sin declarar arreglos auxiliares).

Precondición: vec != NULL.
Postcondición: Para todo $i \in [0, n-1]$, el valor final de vec[i] corresponde al valor inicial de vec[n - 1 - i].
*/
#include <stdio.h>
void invertir_vector(int vec[], size_t n);
int main (void) {
    int arreglo[] = {0,1,2,3};
    size_t tamano = sizeof(arreglo)/sizeof(arreglo[0]);
    invertir_vector(arreglo, tamano);
    return 0;
}

void invertir_vector(int vec[], size_t n){
    if (n == 0) return;
    int *inicio = vec;
    int *fin = vec + n - 1;

    while (inicio < fin) {
        int temp = *inicio;
        *inicio = *fin;
        *fin = temp;
        inicio++;
        fin--;
    }
}