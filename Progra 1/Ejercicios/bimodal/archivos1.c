/* Ejercicios sobre gestión de archivos en C
1. Crea un script que genere un archivo nuevo llamado “abecedario.txt”.
Utilizando la función fputc, el programa debe escribir todas las letras
mayúsculas de la 'A' a la 'Z', separadas por un guion.
*/
#include <stdio.h>
#include <stdlib.h>

int main (void) {
     const char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Crear o sobrescribir el archivo
    FILE *archivo = fopen("“abecedario.md", "w");
    if (archivo == NULL) {
        printf("Error al crear el archivo.\n");
        return 1;
    }

    // Escribir las letras en el archivo
    for (int i = 0; abc[i] != '\0'; i++) {
        fputc(abc[i], archivo);
        fputc(' ', archivo);
    }

    fputc('\n', archivo);
    fclose(archivo);
    /*
    if (fclose(archivo) == 0) { 
        printf("Archivo cerrado con éxito y datos guardados.\n");
    } else {
        printf("Error al cerrar el archivo.\n");
    }
        // puse esto y me dio error al cerrar el archivo
        */

    // Abrir el archivo para lectura
    archivo = fopen("abecedario.md", "r");
    if (archivo == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }

    // Leer y mostrar el contenido en la terminal
    int caracter;
    printf("Contenido del archivo:\n");
    while ((caracter = fgetc(archivo)) != EOF) {
        putchar(caracter);
    }
    fclose(archivo);

    return 0;


}