#include <stdio.h>

/*
Una función puede recibir vectores como argumentos. 
No se copia todo el vector como cuando se pasa un entero, se pasa un puntero al elemento del indice
*/

int main (void) {
int a[5] = {10,20,30,40,50}; 
int *pa = &a[1];

printf("\n*pa contenido %d", *pa);
printf("\n*pa direccion %p", &pa);

printf("\na[0] contenido %d", a[1]);
printf("\na direccion %p", &a);

return 0;
}