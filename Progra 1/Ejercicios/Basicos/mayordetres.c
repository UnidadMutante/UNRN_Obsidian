#include <stdio.h>

int mayor; 
int encontrarMayor(int a, int b, int c);

int main(void) {
    int a, b, c;

    printf("Ingrese un numero entero:\n");
    scanf("%d", &a);

    printf("Ingrese un numero entero:\n");
    scanf("%d", &b);

    printf("Ingrese un numero entero:\n");
    scanf("%d", &c);

    mayor = encontrarMayor(a, b, c);

    printf("El mayor es: %d\n", mayor);

    return 0;
}

int encontrarMayor(int a, int b, int c) {
    if (a > b) {
        if (a > c) {
            mayor = a;
        } else {
            mayor = c;
        }
    } else {
        if (b > c) {
            mayor = b;
        } else {
            mayor = c;
        }
    }
    return mayor;
}
