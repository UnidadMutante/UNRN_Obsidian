#include <stdio.h>
#include <stdlib.h>

int main() {
    // 1. Crear o sobrescribir un archivo para escritura
    FILE *archivo_escritura = fopen("ejemplo1.txt", "w");
    
    // 2. Validar si el archivo se abrió correctamente
    if (archivo_escritura == NULL) {
        printf("Error al crear el archivo.\n");
        return 1; // Terminar el programa con código de error
    }
    
    // 3. Escribir texto en el archivo
    fprintf(archivo_escritura, "Buenas! Este es un ejemplo de fopen en C.\n");
    fprintf(archivo_escritura, "Linea numero 2.\n");
    
    // 4. Cerrar el archivo (siempre es obligatorio cerrarlo)
    fclose(archivo_escritura); // esta función devuelve un entero
    printf("Archivo escrito con exito.\n\n");
    // 1. Abrir el archivo existente solo para lectura
    FILE *archivo_lectura = fopen("ejemplo1.txt", "r");
    
    // Validar si el archivo existe y se puede leer
    if (archivo_lectura == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }
    
    // 2. Leer el contenido del archivo línea por línea y mostrarlo en pantalla
    char buffer[100];
    printf("Contenido del archivo:\n");
    while (fgets(buffer, 100, archivo_lectura) != NULL) {
        printf("%s", buffer);
    }
    
    // 3. Cerrar el archivo de lectura
    fclose(archivo_lectura);

    return 0;
}