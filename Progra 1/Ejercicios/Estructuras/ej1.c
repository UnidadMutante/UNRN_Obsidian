#include <stdio.h>  
#include <string.h>

// el programa debe permitir la lectura de datos por teclado 
//y la posterior clonacion de la informacion de una estructyura a otra

struct producto {
    char nombre[50];
    int stock;
    float precio;
}; 

int main () {

struct producto producto1 = {"Skip", 25, 7.50};
struct producto producto2 = {"Ace", 90, 3.5};
struct producto producto3 = {"Coso", 15, 9.25};
struct producto producto4 = producto3;
producto4.stock = 2;
strcpy(producto4.nombre, "Otro coso"); 

printf("%s | %d | %.2f\n", producto1.nombre, producto1.stock, producto1.precio);
printf("%s | %d | %.2f\n", producto2.nombre, producto2.stock, producto2.precio);
printf("%s | %d | %.2f\n", producto3.nombre, producto3.stock, producto3.precio);
printf("%s | %d | %.2f\n", producto4.nombre, producto4.stock, producto4.precio);

    return 0;
}