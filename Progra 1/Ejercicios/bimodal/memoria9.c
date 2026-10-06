/*
El operador flecha (->).
• Sobre el puntero dinámico del ejercicio anterior, intenta llenar los
campos de la estructura.
• Explica de forma práctica por qué al tener un puntero ya no se puede
utilizar el operador punto (.).
• Implementa la asignación de datos utilizando el operador flecha (->), lo
cual le indica al programa que viaje a la dirección de memoria para
acceder al campo.
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

int main(void) {
    Alumno *alumno = malloc(sizeof(Alumno));

    if (alumno == NULL) {
        printf("Error: no se pudo asignar memoria.\n");
        return 1;
    }

    // alumno.legajo = 1234;
    // ^ Esto NO compila. El error del compilador es algo como:
    // La razón: alumno es de tipo Alumno *, un puntero. Guarda una
    // DIRECCIÓN (por ejemplo 0x5a20), no una estructura. El operador '.'
    // solo es válido sobre una variable que ES una estructura. Como
    // 'alumno' no lo es, "alumno.legajo" no tiene sentido para el
    // compilador: no hay ningún campo 'legajo' en un puntero.

    // Con -> sí funciona: primero sigue la dirección y después accede al campo
    strcpy(alumno->nombre, "Lucila");
    alumno->legajo = 1234;
    alumno->promedio = 8.5f;

    printf("Nombre:   %s\n", alumno->nombre);
    printf("Legajo:   %d\n", alumno->legajo);
    printf("Promedio: %.2f\n", alumno->promedio);

    free(alumno);
    alumno = NULL;

    return 0;
}