#include <stdio.h>
#include <stdlib.h> 

// @params: entero para filas, entero para columnas, matriz orifinal, matriz destino 
// precondiciones: una matriz con su extension definida por n y m y una matriz destino vacia con la capacidad definida por m y n
// postcondiciones: matriz orifinal queda tal cual estaba y matiz destino queda completada con los valores transpuestos de la matriz orifinal
void transponer_dinamica(size_t n, size_t m, const float *orig, float *dest);

// @params: n para filas, m para columnas, a debe recibir una matriz
// pre: n y m enteros mayores a cero. a debe ser una matriz con valores asignados.
// post: matriz a[n,m] se imprime por consola
void imprimir_matriz(size_t n, size_t m, float *a);

// params: n para filas, m para columnas, a recibe una matriz
// pre: n y m enteros mayores a cero. a debe ser una matriz sin valores asignados.
// post: la matriz que se pasó por a tiene que quedar con todos sus espacios de memoria asignados ocupados.
void completar_matriz(size_t n, size_t m, float *a);

int main (void) {

    int filas;
    int columnas;
    printf("¿Qué cantidad de filas quiere guardar? ");
    scanf("%d", &filas);
    printf("¿Qué cantidad de columnas quiere guardar? ");
    scanf("%d", &columnas);
    float *A = (float *)malloc(filas * columnas * sizeof(float *));
    float *A_T = (float *)malloc(filas * columnas * sizeof(float *));

    if(filas > 0 && columnas >0) {
     if (A == NULL || A_T == NULL) {
        printf("No se pudo reservar memoria.\n");
        free(A);
        free(A_T);
        return 1;
    }
    } else {
        printf("ambos numeros deben ser mayores a 0 \n");
        return -1;
    }

completar_matriz(filas, columnas, A);
imprimir_matriz(filas, columnas, A);
transponer_dinamica(filas, columnas, A, A_T);
imprimir_matriz(filas, columnas, A_T);

free(A);
free(A_T);

return 0;
}

void completar_matriz(size_t n, size_t m, float *matriz) {
    for(size_t i = 0; i <n*m; i++) {
        matriz[i] = i + 1;
    }
}

void imprimir_matriz(size_t n, size_t m, float *a) {
    for (size_t i=0; i < n; i++) {
        for(size_t j=0; j < m; j++) {
            printf(" %.2f," , a[i* m +j]);
        }
        printf("\n");
    }
    printf("\n");
}
void transponer_dinamica(size_t n, size_t m, const float *orig, float *dest) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
        dest[j*n + i] = orig[i*m+j];
    }
    printf("\n");
}
}


