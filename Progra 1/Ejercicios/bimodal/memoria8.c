/* Reserva de una estructura en el Heap.
• Utiliza la librería <stdlib.h> y la función malloc para pedir un bloque de
memoria en tiempo de ejecución que aloje a una única estructura
Alumno.
• Demuestra que el casteo explícito fuerza la traducción para que el
programa entienda que ese espacio pertenece a un puntero de la
estructura.
• Al finalizar, utiliza la función free para devolver la memoria y evitar fugas.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 50

typedef struct {
    char nombre[MAX_NOMBRE];
    int legajo;
    float promedio;
} Alumno;

int main (void) {

    Alumno *alumno1 = (Alumno *)malloc(sizeof(Alumno));
    if (alumno1 == NULL) {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }

    // Se accede a los campos con -> porque alumno es un puntero
    strcpy(alumno1->nombre, "Lucila");
    alumno1->legajo = 1234;
    alumno1->promedio = 8.5;

    printf("Nombre:   %s\n", alumno1->nombre);
    printf("Legajo:   %d\n", alumno1->legajo);
    printf("Promedio: %.2f\n", alumno1->promedio);

    free(alumno1);
    alumno1 = NULL;

    return 0;
}