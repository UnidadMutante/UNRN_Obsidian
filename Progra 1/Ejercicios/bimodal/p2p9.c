#include <stdio.h>

//Imprimir por pantalla la multiplicación de dos números ingresados por el usuario. 
// Implementar la multiplicación con un bucle for.

int main (void) {

    int opA, opB, product;

    printf("Ingrese el primer operando: ");
    scanf(" %d", &opA);

    printf("\nIngrese el segundo operando: ");
    scanf(" %d", &opB);

    product = opA * opB;

    printf(" %d x %d = %d", opA, opB, product);
    printf("\nAbajo podes ver la tabla correspondiente:\n");

    for (int i = 0; i <= opB; i++) {
        product = opA * i;
        printf(" %d x %d = %d\n", opA, i, product);
    }

    return 0;
}
