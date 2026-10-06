/*
 Pasaje a funciones por Valor.
• Define un typedef struct Paciente y envíalo como argumento a una
función llamada mostrarPaciente(Paciente p).
• Intenta modificar la edad del paciente dentro de la función y luego
imprímela en el main().
• Comprueba y justifica por qué el original sigue intacto y a salvo,
basándote en que la función recibe únicamente una fotocopia del dato y
gasta memoria extra.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 30

typedef struct {
    char nombre[MAX_NOMBRE];
    int edad;
} Paciente;

void mostrarPaciente(Paciente p);

int main (void) {

    Paciente paciente1 = {"Miguel", 90};
    Paciente paciente2;
    strcpy(paciente2.nombre, "Daniel");
    paciente2.edad = 89;

    printf("Antes de llamar a la funcion:\n");
    printf("Edad en main: %d\n\n", paciente1.edad);

    printf("Antes de llamar a la funcion:\n");
    printf("Edad en main: %d\n\n", paciente2.edad);

    mostrarPaciente(paciente1);
    mostrarPaciente(paciente2);

     printf("\nDespues de llamar a la funcion:\n");
    printf("Edad en main: %d\n\n", paciente1.edad);

    printf("\nDespues de llamar a la funcion:\n");
    printf("Edad en main: %d\n\n", paciente2.edad);
    return 0;
}

void mostrarPaciente(Paciente p) {
    printf("Paciente nombre: %s ", p.nombre);
    printf("Paciente edad: %d\n", p.edad);

    p.edad = 99;  // modifica solo la copia local

    printf("Edad modificada dentro de la funcion: %d\n", p.edad);
}