#include <stdio.h>


typedef struct complejo
{
    double re;
    double im;
} complejo_t;

complejo_t crear(double re, double im);
void imprimir(complejo_t z);
complejo_t sumar(complejo_t z1,complejo_t z2);
complejo_t dividir(complejo_t p1, complejo_t p2);
complejo_t multiplicar(complejo_t p1, complejo_t p2);