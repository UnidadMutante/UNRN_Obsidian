/*
2. Escribe un script que abra el archivo abecedario.txt en modo lectura. 
Debe leer su contenido carácter a carácter utilizando fgetc
y mostrarlo en la consola hasta llegar al final del archivo.
*/
#include <stdio.h>
#include <stdlib.h>

int main (void) {
    // abrir archivo para lectura
    FILE *archivo = fopen("abecedario.txt", "r");
    if (archivo == NULL){
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }

    // leer el contenido y mostrarlo por consola
    int caracter;
    printf("Contenido del archivo:\n");
    while ((caracter = fgetc(archivo)) != EOF) {
        putchar(caracter);
    }
    fclose(archivo);
    
    return 0;
}