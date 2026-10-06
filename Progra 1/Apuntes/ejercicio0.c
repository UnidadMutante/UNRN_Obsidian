#include <stdio.h>
#define TAM	10

//pre: pa!=NULL && nA>0
//post: pa, vector con los valores ingresados. rv= cantidad de elementos ingresados && rv<=nA.
size_t ingresar_vector_f(float *pa, size_t n)
{
    size_t rv=0;
    for(size_t i=0;i<n;i++)
    {
        printf("ingrese valor float:/n");
        scanf(" %f",(pa+i));
    }
    return n;
}

//pre: pa!=NULL && n>0
//post: na.
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

float cantidades[TAM];

int main(void)
{
    size_t capacidad = sizeof(cantidades)/sizeof(cantidades[0]);
	size_t cant_ingresos = ingresar_vector_f(cantidades,TAM);
    imprimir_vector(cantidades,cant_ingresos);

    return 0;
}
