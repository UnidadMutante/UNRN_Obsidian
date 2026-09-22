#include <stdio.h>

float extremoA;
float extremoB;
float puntoC;
float raiz; 
float error;
int found = 0;

float puntoMedio (float a, float b) {
    puntoC = (a + b) / 2;
    return puntoC;
}

float analisisRaiz (float a, float c) {
    if (c == 0) {
    raiz = a;
    printf("raiz encontrada en %f\n", raiz);
    found = 1;     
    }
    else if (a * c < 0) {
        extremoB = c; 
    } else {
        extremoA = c;
    }

    return found;
}

int main (void) {
    puntoC = puntoMedio(extremoA, extremoB);

    while (found != 1) {
    raiz = analisisRaiz(extremoA, puntoC);
    }

    return 0;
}