/*
Escribir la función size_t indice_maximo(const int vec[], size_t n) 
que retorne el índice de la primera ocurrencia del elemento con el valor máximo dentro del vector.

Precondición: vec != NULL y n > 0.
Postcondición: Retorna un índice $k \in [0, n-1]$ tal que $\forall i \in [0, n-1], \text{vec}[k] \ge \text{vec}[i]$. 
En caso de duplicados, retorna el menor índice $k$.
*/

# include <stdio.h>

/*
@pre vec != NULL y n > 0.
@post Retorna un índice $k \in [0, n-1]$ tal que $\forall i \in [0, n-1], \text{vec}[k] \ge \text{vec}[i]$. 
*/
size_t indice_maximo(const int vec[], size_t n);

int main (void) {

    int vector[13] = {0,2,4,6,8,6,9,6,5,3,2,1,9};
    int tamano = sizeof(vector)/sizeof(vector[0]);
    int indiceMaximo = indice_maximo(vector, tamano);
    printf("el número mayor aparece por primera vez en la posicion %d.", indiceMaximo);
    return 0;
}

size_t indice_maximo(const int vec[], size_t n) {
    size_t indice = 0;
    for (int i = 0; i < n; i++) {
        if (vec[i] > vec[indice]) {
            if (vec[i] > vec[indice]) {
            indice = i;
            }
        } 
    }
    return indice;
}
