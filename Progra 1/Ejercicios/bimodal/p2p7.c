#include <stdio.h>
//Implementar un programa que pueda clasificación de notas 
//en "aprobado", "desaprobado" y "promocionado" usando else if.

void main () {
    int nota;

    printf("ingrese la nota\n");
    scanf(" %d", &nota);

    if (nota < 5) {
        printf("desaprobado");
    } 
    else if (nota < 7) {
        printf("aprobado, va a final");
    } else {
        printf("promociona");
    }
}


