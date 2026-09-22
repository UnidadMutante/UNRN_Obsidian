#include <stdio.h>

/*
Implementar una función que cuente las ocurrencias de un carácter específico dentro de una cadena. 
La función debe detener la lectura inmediatamente al encontrar el terminador '\0'.
Consigna: Se debe implementar la función aislada y ser llamada desde main. 
La entrada/salida se realiza exclusivamente en main.
Pregunta: ¿Qué pasaría si la cadena no tiene '\0' al final? ¿Por qué están seguros de que tiene '\0'?
*/

//Precondición: cadena != NULL (asume cadena válidamente terminada en '\0').
//Postcondición: Retorna la cantidad de veces que aparece objetivo en los índices  donde cadena[i] != '\0'.
size_t contar_caracter(const char cadena[], char caracter_buscado);


int main (void) {
    char palabra[] = "palabratest";
    char caracter_buscado = 's';
    
    size_t ocurrencias = contar_caracter(palabra, caracter_buscado);

    printf("en la palabra %s el carácter buscado \"%c\" aparece %lu veces", palabra, caracter_buscado, ocurrencias);
    return 0;
}

size_t contar_caracter(const char cadena[], char caracter_buscado) {
    size_t contador = 0;
    for (int i = 0; cadena[i] != '\0'; i++ ) {
        if (cadena[i] == caracter_buscado){
            contador ++;
        }
    }
    return contador;
}