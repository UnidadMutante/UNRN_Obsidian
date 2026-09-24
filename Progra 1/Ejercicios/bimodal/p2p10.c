#include <stdio.h>

//Incorporar un bucle while para el problema de la clasificación de notas. 
//Validar que los números sean notas válidas.

int main (void) {

    int nota;

    printf("ingrese la nota obtenida: ");
    scanf(" %d", &nota);

    while (nota < 0 || nota > 10) {
    printf("ingrese una nota válida: ");
    scanf(" %d", &nota);
    }

    if (nota < 5) {
        printf("desaprobado");
    } 
    else if (nota < 7) {
        printf("aprobado, va a final");
    } else {
        printf("promociona");
    }
    
    return 0;
}