#include <stdio.h>
#include <stdlib.h>

size_t ingresar_vector_f(float *pa, size_t tamano);
void imprimir_vector_f(float *pa, size_t tamano);

int main(void) {
    int elementos = 0;
    printf("Ingrese el tamaño del arreglo \n");
    scanf("%d", &elementos);
    float* cantidad = malloc(elementos * sizeof(float));

    if (cantidad == NULL) {
        printf("Error te quedaste sin memoria RAM \n");
        return 1;
    } 

    size_t contador_elementos = ingresar_vector_f(cantidad, elementos);

    printf("Hay %d elementos en el arreglo. \n", elementos);
    imprimir_vector_f(cantidad, elementos);
    free(cantidad);
    cantidad = NULL;
    printf("FIN \n");
    return 0;
}

//pre: pa!=NULL && nA>0
//post: pa, vector con los valores ingresados. rv= cantidad de elementos ingresados && rv<=nA.
size_t ingresar_vector_f(float *pa, size_t tamano) {
    size_t total = 0;
    for (size_t i = 0; i < tamano; i ++)
    {
        printf("ingresa el balor decimal #%zu: ", i);
        scanf("%f", pa + i);
        total++;
    }
    return total;
}

//pre: pa!=NULL && n>0
//post: na.
void imprimir_vector_f(float *pa, size_t tamano) {

    printf("[");
    for (size_t i = 0; i < tamano; i ++)
    {
         printf("%.2f, ", pa[i]);

    }
    printf("]");
    printf("\n");
}