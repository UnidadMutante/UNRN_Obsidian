/*
5. Escribe un script que abra el archivo productos.txt 
(creado en el ejercicio anterior) de manera segura 
y permita al usuario agregar un tercer producto
al final de la lista. Evalúen los parámetros de fopen
*/

#include <stdio.h>

#define MAX_NOMBRE 30
#define NOMBRE_ARCHIVO "productos.txt"

typedef struct {
    char nombre[MAX_NOMBRE];
    float precio;
} Producto;

int ingresarProducto(Producto *p, int numero);
int guardarProducto(const Producto *p, FILE *archivo);

int main(void) {

    Producto nuevo;
    if (ingresarProducto(&nuevo, 3) != 0) {
        printf("Datos inválidos. No se agregó el producto.\n");
        return 1;
    }

    FILE *archivo = fopen(NOMBRE_ARCHIVO, "a");
    if (archivo == NULL) {
        printf("Error al abrir el archivo %s.\n", NOMBRE_ARCHIVO);
        return 1;
    }

    if (guardarProducto(&nuevo, archivo) != 0) {
        printf("Error al escribir en el archivo %s.\n", NOMBRE_ARCHIVO);
        fclose(archivo);
        return 1;
    }

    fclose(archivo);
    archivo = NULL;

    return 0;
}

int ingresarProducto(Producto *p, int numero) {
    printf("Ingrese el nombre del producto %d: ", numero);
    if (scanf(" %29s", p->nombre) != 1) {
        return -1;
    }
    printf("Ingrese el precio del producto %d: ", numero);
    if (scanf(" %f", &p->precio) != 1) {
        return -1;
    }
    return 0;
}

int guardarProducto(const Producto *p, FILE *archivo) {
    if (fprintf(archivo, "Nombre: %s - Precio: $%.2f\n", p->nombre, p->precio) < 0) {
        return -1;
    }
    return 0;
}