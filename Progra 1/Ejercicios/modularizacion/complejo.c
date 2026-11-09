#include "complejo.h"

complejo_t crear(double re, double im)
{
    complejo_t rv;
    rv.re=re;
    rv.im=im;
    return rv;
}

void imprimir(complejo_t z)
{
    printf("%.2f+i%.2f",z.re,z.im);
}

complejo_t sumar(complejo_t z1,complejo_t z2)
{
    complejo_t rv;
    rv.re = z1.re+z2.re;
    rv.im = z1.im+z2.im;
    return rv;
}

complejo_t dividir(complejo_t p1, complejo_t p2) {
    complejo_t rv;
    rv.re = p1.re / p2.re;
    rv.im = p1.im / p2.im;
    return rv;
}

complejo_t multiplicar(complejo_t p1, complejo_t p2) {
    complejo_t rv;
    rv.re = p1.re * p2.re;
    rv.im = p1.im * p2.im;
    return rv;
}