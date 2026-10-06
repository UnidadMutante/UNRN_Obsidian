/*
Implementar la función bool esta_ordenado(const int vec[], size_t n) (requiere <stdbool.h>) 
que determine si los elementos del arreglo se encuentran ordenados de forma estrictamente no decreciente.

Precondición: vec != NULL. Un vector con $n \le 1$ se considera ordenado.
Postcondición: Devuelve true sii $\forall i \in [0, n-2], \text{vec}[i] \le \text{vec}[i+1]$.
*/
#include <stdio.h>
#include <stdbool.h>

bool esta_ordenado(const int vec[], size_t n);

int main (void){

    int numeros[] = {0,1,2,3};
    int numerosDesc[] = {0,1,3,2};
    size_t tamano_numeros = sizeof(numeros)/sizeof(numeros[0]);
    size_t tamano_numerosDesc = sizeof(numerosDesc)/sizeof(numerosDesc[0]);
    bool rta1 = esta_ordenado(numeros, tamano_numeros); 
    bool rta2 = esta_ordenado(numerosDesc, tamano_numerosDesc); 
    printf("rta1: %s\n", rta1 ? "ordenado" : "no ordenado");
    printf("rta2: %s\n", rta2 ? "ordenado" : "no ordenado");
    return 0;
}

bool esta_ordenado(const int vec[], size_t n) {
    for (int i = 0; i < n - 1; i++) {
        if (vec[i] > vec[i+1]) {
            return false;
        }
    }
    return true;
}


     

