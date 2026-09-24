/*
Implementar una función que determine si un número a divide a otro número b. 
Considerar el caso de números negativos. Se debe implementar la función aislada y debe ser llamada desde la función main. 
La entrada/salida debe hacerse en el main y en las funciones solo se debe hacer el cálculo.

*/
#include <stdio.h>
int pedirNumero();
int esDivisible(int a, int b);

int main (void) {
    int numA = pedirNumero();
    int numB = pedirNumero();
    int resultado = esDivisible(numA, numB);
    
    if (resultado == 1) {
    printf(" %d es divisible por %d", numA, numB);
} else {
    printf(" %d no es divisible por %d", numA, numB);
}
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

int esDivisible(int a, int b) {
    int r = -1;
    if (a%b == 0) {
        r = 1;
    } else {
        r = 0;
    }
    return r;
}