#include <stdio.h>
#include <string.h>
/*
Implementar una función que calcule la longitud lógica de una cadena (largo de cadena hasta el '\0').
Consigna: Se debe implementar la función aislada y ser llamada desde main. 
La entrada/salida se realiza exclusivamente en main.

Pregunta: ¿Por qué se le agrega el término _segura? ¿Qué significa?
*/

//Precondición: cadena != NULL y capacidad > 0.
//Postcondición: Retorna la cantidad de caracteres antes del primer '\0'. 
//Si '\0' no se encuentra dentro de los primeros capacidad bytes, retorna capacidad para indicar 
//que el arreglo carece de terminador dentro del espacio asignado.
size_t longitud_segura(const char cadena[], size_t capacidad);

int main (void) {

char palabra[] = "estaesunapalabra?";
char palabra_dos[33];
printf("Escriba una palabra (máximo 32 letras): ");
scanf("%32s", palabra_dos);
size_t longitud = longitud_segura(palabra, 20);
size_t longitud_dos = longitud_segura(palabra_dos, 33);

printf("la palabra \"%s\" tiene %lu letras.\n", palabra, longitud);
printf("la palabra \"%s\" tiene %lu letras.\n", palabra_dos, longitud_dos);

return 0;
}

size_t longitud_segura(const char cadena[], size_t capacidad) {
    size_t strlen( const char* str );
    return strlen(cadena);
}