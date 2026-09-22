#include <stdio.h>
#include <stdlib.h>

int main() {
    
    char productos[23];
    float precio;
    int cantidad = 3;
    // 1. Crear o sobrescribir un archivo para escritura
    FILE *archivo_escritura = fopen("ej2.md", "w");
    
    // 2. Validar si el archivo se abrió correctamente
    if (archivo_escritura == NULL) {
        printf("Error al crear el archivo.\n");
        return 1; // Terminar el programa con código de error
    }
    
    fprintf(archivo_escritura, "---lista de productos ---\n");
    // 3. Escribir texto en el archivo
    for (int i = 0; i < cantidad; i++){
    printf("ingrese un producto");
    scanf(" %s", productos);
    printf("ingrese el precio");
    scanf(" %f", &precio);
    fprintf(archivo_escritura, "Producto: %s | Precio $%.2f\n", productos, precio);
    }
    
    // 4. Cerrar el archivo (siempre es obligatorio cerrarlo)
    fclose(archivo_escritura); // esta función devuelve un entero
    printf("Archivo escrito con exito.\n\n");
    // 1. Abrir el archivo existente solo para lectura
    FILE *archivo_lectura = fopen("ej2.txt", "r");
    
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