#include <stdio.h>
#include <stdlib.h>

#define TAM	10

//pre: pa!=NULL && nA>0
//post: pa, vector con los valores ingresados. rv= cantidad de elementos ingresados && rv<=nA.
size_t ingresar_vector_f(float *pa, size_t n)
{
    size_t rv=0;
    for(size_t i=0;i<n;i++)
    {
        printf("ingrese valor float:\n");
        scanf(" %f",(pa+i));
    }
    return n;
}

void imprimir_vector(float *pa, size_t n)
{
    printf("[");
    for(size_t i=0;i<n-1;i++)
    {
        printf("%.2f,",pa[i]);
    }
    if (n>0)
    {
        printf("%.2f",pa[n-1]);
    }
    printf("]\n");
}

//float cantidades[TAM];

int main(void)
{

    float* cantidades = NULL;
    size_t capacidad = 0;

    printf("De cuantos elementos quiere el arreglo?:\n");
    scanf("%zu",&capacidad);
    if (capacidad==0)
    {
        printf("Error en la capacidad ingresada (%zu)\n.",capacidad);
        return -1;
    }

    cantidades = malloc(capacidad*sizeof(float));
    if (cantidades == NULL)
    {
        printf("Error al reservar memoria.");
        return -1;
    }

	size_t cant_ingresos = ingresar_vector_f(cantidades,capacidad);
    imprimir_vector(cantidades,cant_ingresos);

    free(cantidades);

    return 0;
}