/*
3. Escribe un script que solicite al usuario ingresar el nombre y 
el precio de 2 productos. 
El programa debe crear un archivo llamado productos.txt y
guardar esta información utilizando la función fprintf dándole formato.
*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_NOMBRE 30
#define CANTIDAD 2

typedef struct {
    char nombre[MAX_NOMBRE];
    float precio;
} Producto;

// FILE * es "puntero a FILE". La función no devuelve un FILE completo, sino la dirección de uno
FILE *crearArchivo(const char *nombre);

// devuelve la dirección de la memoria reservada.
Producto *reservarMemoria(size_t cantidad);
void ingresarProducto(size_t cantidad, Producto *p);
void guardarProductos(size_t cantidad, const Producto *p, FILE *archivo);

int main (void) {
    
    const char *nombreArchivo = "productos.txt";
    FILE *archivo = crearArchivo(nombreArchivo);
    // pongo el return 1 para el error aca, porque la funcion no puede devolver 1 
    // porque su tipo de retorno es FILE
    if (archivo == NULL) {
        printf("Error al crear el archivo %s\n", nombreArchivo);
        return 1;
    }

    Producto *productos = reservarMemoria(CANTIDAD);
    if (productos == NULL) {
        printf("No se pudo reservar memoria.\n");
        fclose(archivo);
        return 1;
    }

    ingresarProducto(CANTIDAD, productos);
    guardarProductos(CANTIDAD, productos, archivo);

    // cerrar archivo
    fclose(archivo);

    // liberar memoria
    free(productos);
    
    // evitar dangling pointers
    archivo = NULL;
    productos = NULL;

    return 0;
}

// char *nombre es lo mismo que char nombre[]
FILE *crearArchivo(const char *nombre) {
    FILE *archivo = fopen(nombre, "w");
    return archivo;
}

Producto *reservarMemoria(size_t cantidad) {
    Producto *productos = (Producto *)malloc(cantidad * sizeof(Producto));
    return productos;
}

void ingresarProducto(size_t cantidad, Producto *p) {
    for (size_t i = 0; i < cantidad; i++) {
// un arreglo decae a un puntero a su primer elemento. Ya es una dirección, así que no lleva &.
        printf("Ingrese el nombre del producto %zu: ", i + 1);
        scanf(" %29s", p[i].nombre);
    // p[i].precio equivale a (p + i)->precio    
        printf("Ingrese el precio del producto %zu: ", i + 1);
        scanf(" %f", &p[i].precio);
    }
}

void guardarProductos(size_t cantidad, const Producto *p, FILE *archivo) {
    fprintf(archivo, "--- Productos ---\n");
    for (size_t i = 0; i < cantidad; i++) {
        fprintf(archivo, "Nombre: %s - Precio: $%.2f\n", p[i].nombre, p[i].precio);
    }
}