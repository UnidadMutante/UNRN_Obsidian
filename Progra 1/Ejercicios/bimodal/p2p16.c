#include <stdio.h>

/* 
Escribir un programa que defina variables locales y globales. 
Implementar un caso donde la variable local tenga el mismo nombre que la global e imprimirla con "printf". 
¿Qué variable se va a imprimir?. ¿Por qué?
*/

int mi_funcion (){
    int variable = 1;
    return variable;
};

int main (void) {
    int variable = 0;

    printf("imprimo la variable que declare en main: %d \n", variable);

    printf("imprimo la variable de mi funcion: %d \n", mi_funcion());

    int nueva_variable = mi_funcion() + 8;

    printf("imprimo mi nueva variable calculada en base a la suma de la variable de mi funcion: %d \n", nueva_variable);

    return 0;
}