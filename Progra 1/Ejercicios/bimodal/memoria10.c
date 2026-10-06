/*
Arreglos dinámicos de estructuras y recorridos.
• Reserva memoria dinámica para crear un "grupo" o arreglo de 3
personas (cantidad * sizeof(struct Persona)) y verifica que no sea NULL.
• Accede como arreglo utilizando corchetes (grupo[0].edad = 10) para
cargar los datos.
• Crea un puntero auxiliar (ptr = grupo) para recorrer el bloque utilizando
un bucle for y aritmética de punteros (ptr++), imprimiendo los datos con
el operador flecha.
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOMBRE 35
#define CANTIDAD 3

typedef struct {
    char nombre[MAX_NOMBRE];
    int edad;
} Persona;

int main (void) {
 
    Persona *grupo = (Persona *)malloc(CANTIDAD * sizeof(Persona));
    if (grupo == NULL) {
        printf("No se pudo reservar memoria.\n");
        return 1;
    };

    strcpy(grupo[0].nombre, "Belen");
    grupo[0].edad = 10;

    strcpy(grupo[1].nombre, "Lucila");
    grupo[1].edad = 15;

    strcpy(grupo[2].nombre, "Martina");
    grupo[2].edad = 20;

    // esta opcion, al usar un puntero auxiliar, no me toca el lugar que ocupa grupo en la memoria
    Persona *ptr = grupo;
    for (int i = 0; i < CANTIDAD; i++) {
        printf("Nombre: %s, Edad: %d\n", ptr->nombre, ptr->edad);
        ptr++;
    }

    // esta opcion no convendría porque cuando termino de recorrer el grupo, quedo fuera del bloque de memoriaa
     for (int i = 0; i < CANTIDAD; i++) {
        printf("Nombre: %s, Edad: %d\n", grupo->nombre, grupo->edad);
        grupo++;
    }
/*
el problema no es solo que grupo termine apuntando afuera, 
sino que después necesitás grupo para free. Si lo movés, perdés la única referencia a la dirección original, 
y free(grupo) ya no libera correctamente el bloque reservado. 
Ese es el motivo concreto por el que esa opción "no conviene": 
no es un problema estético, es un bug real si el código sigue teniendo un free(grupo) más abajo.
*/
    free(grupo);
    grupo = NULL;
    return 0;
}


