#include <stdio.h>
#include <math.h>

// implementar una funcion que pida el ingreso de n valores flotantes por consola
#define TAMANO	10

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

int main(void)
{
    float cantidades[TAMANO];
    size_t candidades_length = sizeof(cantidades)/sizeof(cantidades[0]);
    size_t elementos = ingresar_vector_f(cantidades, TAMANO);

    printf("Hay %zu elementos en el arreglo.\n", elementos);

return 0;
}