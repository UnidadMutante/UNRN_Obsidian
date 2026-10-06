/* Pasaje a funciones por Puntero
• Crea una función llamada cumplirAños(Paciente *ptr_p) que reciba un puntero a la estructura.
• Desde el main(), envía la dirección de la estructura original utilizando el
operador &.
• Dentro de la función, utiliza el operador flecha para alterar el dato real en
la memoria (ptr_p->edad = ptr_p->edad + 1) y verifica el cambio
permanente en el main()
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_NOMBRE 50

typedef struct {
    char nombre[MAX_NOMBRE];
    int edad;
} Paciente;

void cumplirAños(Paciente *ptr_p);

int main (void) {

    Paciente paciente;
    strcpy(paciente.nombre, "Adriana");
    paciente.edad = 58;
    cumplirAños(&paciente);
    printf("Edad del paciente: %d", paciente.edad);
    return 0;
}

void cumplirAños(Paciente *ptr_p) {
    ptr_p->edad += 1;
}