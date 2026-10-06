/*Medición con sizeof y Uniones (union).
• Declara una estructura Alumno con un char (1 byte), un int (4 bytes) y u
float (4 bytes).
• Mide la estructura utilizando sizeof y el modificador %zu, y demuestra
cómo el compilador aplica un Padding (relleno) insertando bytes vacíos
para alinear la memoria, devolviendo 12 bytes en lugar de 9.
• Replica los mismos campos dentro de una union y comprueba mediante
sizeof que todos los campos comparten el mismo espacio físico, por lo
que su tamaño se basa únicamente en el componente más grande.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char letra;
    int edad;
    float promedio;
} Alumno;

int main (void) {

    printf("Tamano individual de cada tipo:\n");
    printf("char:  %zu byte\n", sizeof(char));
    printf("int:   %zu bytes\n", sizeof(int));
    printf("float: %zu bytes\n\n", sizeof(float));

    printf("Suma simple: %zu bytes\n\n", sizeof(char) + sizeof(int) + sizeof(float));

    size_t tamano = sizeof(Alumno);
    printf("La estructura Alumno mide %zu bytes. ", tamano);


    return 0;
}