/*
Escribir la función int busqueda_binaria(const int vec[], size_t n, int clave) 
que busque el valor clave en un vector pre-ordenado de forma ascendente utilizando el algoritmo de búsqueda binaria iterativo
(sin recursión).
 */

#include <stdio.h>

//Precondición: vec != NULL y el arreglo está ordenado de forma no decreciente.
//Postcondición: Retorna el índice $k$ tal que vec[k] == clave, o -1 si el valor no pertenece al arreglo.
int busqueda_binaria(const int vec[], size_t n, int clave);

int main (void) {

    int clave = 8;
    int vector[] = {0,2,4,5,6,8,9};
    size_t tamano = sizeof(vector)/sizeof(vector[0]);
    int indice = busqueda_binaria(vector, tamano, clave);
    printf("El numero buscado %d esta en la posicion %d.\n", clave, indice);
    return 0;
}

int busqueda_binaria(const int vec[], size_t n, int clave) {

    for (size_t i = 0; i < n; i ++){
        if (clave == vec[i]) {
            return i;
            break;
        }
    }
}
