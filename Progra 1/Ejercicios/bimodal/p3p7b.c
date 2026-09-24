/*
Implementar una función que determine si un número a divide a otro número b. 
Considerar el caso de números negativos. Se debe implementar la función aislada y debe ser llamada desde la función main. 
La entrada/salida debe hacerse en el main y en las funciones solo se debe hacer el cálculo.

*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int pedirNumero();
void esDivisible(int a, int b, char *palabra);

int main (void) {
    int numA = pedirNumero();
    int numB = pedirNumero();
    char resultado[6];
    esDivisible(numA, numB, resultado);
    printf(" %d %s divisible por %d", numA, resultado, numB);
    return 0;
}

int pedirNumero(){
    int num = 0;
    while (num <= 0) {
        printf("Ingrese un número mayor a 0: ");
        scanf(" %d", &num);
    }
    return num;
}

void esDivisible(int a, int b, char *palabra) {
    if (a%b == 0) {
        strcpy(palabra, "es");
    } else {
        strcpy(palabra, "no es");
}
}