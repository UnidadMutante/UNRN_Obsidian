#include <stdio.h>

int sumar_elementos(const int a[], size_t t)
{
    int suma = 0;

    for (size_t i = 0; i < t; i++) {
        suma = suma + a[i];
    }

    return suma;
}

int main(void)
{
    int a[5] = {10, 20, 30, 40, 50};
    size_t tamano = sizeof(a) / sizeof(a[0]);
    int suma = sumar_elementos(a, tamano);
    printf("%d\n", suma);
    return 0;
}