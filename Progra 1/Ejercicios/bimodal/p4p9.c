/*
Implementar la función void fusionar_ordenados(const int a[], size_t n_a, const int b[], size_t n_b, int resultado[]) 
que reciba dos arreglos ordenados de forma ascendente (a y b) y deposite la combinación ordenada de ambos 
en el arreglo resultado.

Precondición: a != NULL, b != NULL, resultado != NULL. Los arreglos a y b están ordenados ascendentemente. El arreglo resultado tiene capacidad reservada suficiente ($\ge n_a + n_b$).
Postcondición: resultado contiene todos los elementos de a y b ordenados ascendentemente en $O(n_a + n_b)$.

*/
#include <stdio.h>
void fusionar_ordenados(const int a[], size_t n_a, const int b[], size_t n_b, int resultado[]);
int main (void){

    int a[] = {0,5,2,7};
    size_t tamano_a = sizeof(a)/sizeof(a[0]);
    int b[] = {4,1,6,3};
    size_t tamano_b = sizeof(b)/sizeof(b[0]);
    size_t tamano_r = tamano_a + tamano_b;
    int resultado[tamano_r];
    fusionar_ordenados(a, tamano_a, b, tamano_b, resultado);
    printf("tamano resultado %d",tamano_r);
    return 0;
}

void fusionar_ordenados(const int a[], size_t n_a, const int b[], size_t n_b, int resultado[]) {
    for (size_t i = 0; i < n_a; i++) {
        resultado[i] = a[i];
    }
    for (size_t i = 0; i < n_b; i++) {
        resultado[i + n_a] = b[i]; 
    }

    // DIFICIL
    for (size_t i = 1; i < (n_a + n_b); i++) {
        int actual = resultado[i];
        size_t j = i;
        while (j > 0 && resultado[j - 1] > actual) {
            resultado[j] = resultado[j - 1];
            j--;
        }
        resultado[j] = actual;
    }

    for (size_t i = 0; i < (n_a + n_b); i++) {
        printf("ordenado %d: \n", resultado[i]);
    }
}