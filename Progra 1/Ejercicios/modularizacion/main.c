#include <stdio.h>

#include "complejo.h"

int main()
{
    printf("ejemplo con números complejos\n");

    complejo_t z1 = crear(3,4); // crea el número complejo 3+4i
    complejo_t z2 = crear(5,8); // crea el número complejo 5+8i
    complejo_t z3 = sumar(z1,z2);
    complejo_t z4 = dividir(z1, z2);
    complejo_t z5 = multiplicar(z1, z2);

    printf("z1:");
    imprimir(z1);
    printf("\n");
    
    printf("z2:");
    imprimir(z2);
    printf("\n");
    
    printf("z3=z1+z2 ");
    imprimir(z3);
    printf("\n");

    printf("z4=z1/z2 ");
    imprimir(z4);
    printf("\n");

    printf("z5=z1*z2 ");
    imprimir(z5);
    printf("\n");

    return 0;
}