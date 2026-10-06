/*
4. Crea un script que abra el archivo productos.txt 
y lea su contenido de a bloques o "línea por línea" 
utilizando un arreglo como buffer, imprimiendo
cada línea en la consola.
*/
#include <stdio.h>
#define MAX_CADENA 200

int main (void) {

    FILE *archivo_lectura = fopen("productos.txt", "r");
     if (archivo_lectura == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }

    char buffer[MAX_CADENA]; 
    while (fgets(buffer, sizeof(buffer), archivo_lectura) != NULL) { 
        printf("%s", buffer); 
    } 
    
    fclose(archivo_lectura);
    archivo_lectura = NULL;
    return 0;
}