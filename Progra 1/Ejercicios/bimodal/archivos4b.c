/*
4. Crea un script que abra el archivo productos.txt 
y lea su contenido de a bloques o "línea por línea" 
utilizando un arreglo como buffer, imprimiendo
cada línea en la consola.
*/
#include <stdio.h>
#define MAX_CADENA 200
#define NOMBRE_ARCHIVO "productos.txt"

FILE *abrirArchivo(const char *nombre);
void imprimirContenido(FILE *archivo);

int main (void) {
    
    FILE *archivo_lectura = abrirArchivo(NOMBRE_ARCHIVO);
     if (archivo_lectura == NULL) {
        printf("Error al abrir el archivo para lectura %s.\n", NOMBRE_ARCHIVO);
        return 1;
    }
    imprimirContenido(archivo_lectura);
    fclose(archivo_lectura);
    archivo_lectura = NULL;
    return 0;
}

FILE *abrirArchivo(const char *nombre) {
     return fopen(nombre, "r");
}

void imprimirContenido(FILE *archivo){
    char buffer[MAX_CADENA]; 
    while (fgets(buffer, sizeof(buffer), archivo) != NULL) { 
        printf("%s", buffer); 
    } 
}