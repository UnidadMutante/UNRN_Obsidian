#include <stdio.h>

/*
Implementar un programa que imprima: un entero, un flotante con 2 decimales, 
una cadena de caracteres, un número hexadecimal. 
Usar los modificadores de formato de la operación "printf".
*/

int main (void) {

    int entero = 8;
    float flotante = 1.935;
    char palabra[] = "una cadena de caracteres";
    int nrohexa = 3000;

    printf(" %d\n", entero);
    printf(" %.2f\n", flotante);
    printf(" %s\n", palabra);
    printf(" %x\n", nrohexa);

    return 0;
}