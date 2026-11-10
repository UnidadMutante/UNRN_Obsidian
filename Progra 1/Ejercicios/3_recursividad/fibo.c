#include <stdio.h>

int fibonacci(int n) {
// Casos base
    if (n == 0 || n == 1) {
        return 1;
    }
// Caso recursivo
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main(void)
{
    int n;
    int resultado; 

    printf("Ingrese un numero: ");
    scanf("%d", &n);
    resultado = fibonacci(n);
    printf("Fibonacci(%d) = %d\n", n, resultado);

    return 0;
}