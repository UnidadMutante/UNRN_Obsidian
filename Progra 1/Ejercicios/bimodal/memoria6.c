/*
El script de gestión de productos.
• Diseña un programa que gestione la información de un producto
utilizando una estructura con los campos nombre, precio y cantidad.
• El programa debe permitir la lectura de los datos por teclado utilizando
las funciones scanf y fgets.
• Posteriormente, debe realizar la clonación de la información de esa
estructura a una nueva variable y mostrar los datos copiados por
pantalla. 
*/
#include <stdio.h>
#include <string.h>

#define MAX_NOMBRE 50

typedef struct {
    char nombre[MAX_NOMBRE];
    float precio;
    int cantidad;
} Producto;

int leer_producto(Producto *p);

void mostrar_producto(const Producto *p);

int main (void) {
    Producto original;
    if (leer_producto(&original) != 0) {
        printf("Error: entrada invalida.\n");
        return 1;
    }
    Producto copia = original;
    printf("\nDatos copiados:\n");
    mostrar_producto(&copia);
    return 0;
}

int leer_producto(Producto *p) {
    printf("Nombre: ");
    // fgets(buffer, tamano, stdin);
    // buffer: el arreglo de char donde se guarda el texto.
    // tamano: cuántos bytes tiene el buffer. fgets lee como máximo tamano - 1 caracteres y deja lugar para el '\0' final.
    // stdin: de dónde lee (el teclado).
    if (fgets(p->nombre, MAX_NOMBRE, stdin) == NULL) {
        return 1;
    }

    printf("Precio: ");
    if (scanf("%f", &p->precio) != 1) {
        return 1;
    }

    printf("Cantidad: ");
    if (scanf("%d", &p->cantidad) != 1) {
        return 1;
    }
    return 0;
}

void mostrar_producto(const Producto *p) {
    printf("Nombre:   %s\n", p->nombre);
    printf("Precio:   %.2f\n", p->precio);
    printf("Cantidad: %d\n", p->cantidad);
}