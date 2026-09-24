#include <stdio.h>
//Hacer un programa que recorra (imprima) los números enteros positivos 
//hasta llegar a un número ingresado por el usuario 
//(hacer una opción que corte por guarda del ciclo y una que use la sentencia break.

int main (void) {

    int numero = 0;

    printf("Ingrese un número: ");
    scanf(" %d", &numero);
    
    printf("\n---Con un ciclo for:---\n");
    for (int i = 0; i < numero; i++) {
        printf(" %d,", i);
    }
     
    printf(" %d", numero);

    printf("\n---Con un while:---\n");

    int j = 0;
    while (j <= numero) {
        printf(" %d", j);
        j++;
    }

// Este de abajo se le pregunté a una ia. No sabía lo de while(1)
     printf("\n--- corte con break ---\n");
    int k = 0;
// while(1) generaría un bucle infinito. lo rompo con el break cuando encuentro mi numero
    while (1) {
        if (k > numero) {
            break;
        }
        printf(" %d", k);
        k++;
    }

    return 0;
}