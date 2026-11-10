#include <stdio.h>

int forRecursivo(int n);

int main (void) {


    /* Ejemplo de for común
    for (int i = 0; i < 10; i++) {
        printf("%d ", i);
    }
    */
    forRecursivo(0);
    return 0;
}

int forRecursivo(int i){
    // Caso base
    if(i == 10) {
        return 0;
    }
    // llamada recursiva 
    else {
        forRecursivo(i + 1);
        printf("%d ", i);
    }
}