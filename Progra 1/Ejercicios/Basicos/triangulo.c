#include <stdio.h>

float calcularArea(float b, float h);

int main (void) {

    float base, altura, area;

    printf("ingrese base del triángulo: \n");
    scanf("%f", &base);

    printf("ingrese altura del triángulo: \n");
    scanf("%f", &altura);

    area = calcularArea(base, altura);

    printf("el área de un triángulo de base %.2f por altura %.2f es: %.3f", base, altura, area);

    return 0;
}

float calcularArea(float b, float h) {
    return b * h; 
}