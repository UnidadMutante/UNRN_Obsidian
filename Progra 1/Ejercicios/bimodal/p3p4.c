/*
Implementar una función que implemente la multiplicación lenta, 
que toma 2 números e itera sumando uno, la cantidad que indica el otro argumento. 
Implementar una función "multiplicarf()" que haga la misma multiplicación con argumentos de tipo flotante.
*/
#include <stdio.h>

int multiplicar(int numero, int cantidad);

float multiplicarf(float numero, int cantidad);

int main (void){

    int numeroEntero = 2;
    float numeroFloat = 3.3;
    int cantidad = 5;

    multiplicar(numeroEntero, cantidad);
    multiplicarf(numeroFloat, cantidad);

    return 0;
} 

int multiplicar(int numero, int cantidad) {
    int resultado = 0;
    for (int i = 0; i < cantidad; i++) {
        resultado = numero + resultado;
    }
     printf("resultado: %d\n", resultado);
}

float multiplicarf(float numero, int cantidad) {
    float resultado = 0;
    for (int i = 0; i < cantidad; i++) {
        resultado = numero + resultado;
    }
    printf("resultado: %.2f\n", resultado);
}