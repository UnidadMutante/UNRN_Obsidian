#include <stdio.h>
#include <stdlib.h>

int main(void) {
    const char abc[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";

    // Crear o sobrescribir el archivo
    FILE *archivo = fopen("abc.md", "w");

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

    // Abrir el archivo para lectura
    archivo = fopen("abc.md", "r");

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
/*
- Después de escribir, el archivo se vuelve a abrir con modo `"r"`.
- `fgetc()` lee un carácter y `putchar()` lo muestra en la terminal.
- `int caracter` es necesario porque `fgetc()` debe poder representar también `EOF`.
*/