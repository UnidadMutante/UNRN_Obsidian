/*
Implementar una función que calcule el mínimo común múltiplo de dos números enteros. 
Se debe implementar la función aislada y debe ser llamada desde la función main. 
La entrada/salida debe hacerse en el main y en las funciones solo se debe hacer el cálculo.
*/
#include <stdio.h>

int minimoComunMultiplo(int a, int b);
int maximoComunDivisor(int mayor, int menor);
int encontrarMayor(int a, int b);
int encontrarMenor(int a, int b);

int main (void) {
    int nroA = 6;
    int nroB = 4;
    int mcm = minimoComunMultiplo(nroA, nroB);
    printf("mcm es %d", mcm);
    return 0;
}

int minimoComunMultiplo(int a, int b) {
    int mcd = 0;
    mcd = maximoComunDivisor(encontrarMayor(a, b), encontrarMenor(a, b));
    return (a * b)/ mcd;
}

int maximoComunDivisor(int mayor, int menor) {
    int aux = -1;
    while (menor != 0) {
        aux = mayor % menor;
        mayor = menor;
        menor = aux;
    }
    return mayor;
}

int encontrarMayor (int a, int b){
    int mayor = 0;  
    if (a > b) {
        mayor = a;
    } else { 
        mayor = b;      
    }
    return mayor;
}

int encontrarMenor (int a, int b) {
     int menor = 0;
     if (a > b) {
        menor = b;
    } else { 
        menor = a;      
    }
    return menor;
}
