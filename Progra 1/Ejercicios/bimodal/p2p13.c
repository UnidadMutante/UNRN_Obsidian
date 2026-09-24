#include <stdio.h>

//Implementar una función que imprima los primero N números impares. 
// Utilice la sentencia "continue".

int main (void) {

    int numero;
    printf("Ingrese un numero: \n");
    scanf(" %d", &numero);

    for (int i = 1; i <= numero; i++) {

    if (i % 2 != 0) {
        continue;
        // si esta condicion se cumple, el continue hace que se vaya al inicio del for
        // sin seguir con las lineas que vendrian despues del if. 
    }
    printf("Número par encontrado: %d\n", i);
    }

    return 0;
}