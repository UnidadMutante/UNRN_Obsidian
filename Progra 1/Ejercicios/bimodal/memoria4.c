/*
Ejercicio 4: Modelando con estructuras y acceso directo.
• Define una estructura llamada Alumno que agrupe diferentes tipos de
datos bajo un solo nombre: un arreglo de caracteres para el nombre, un
entero para la edad y un decimal para el promedio.
• Declara una variable estática de esta estructura en el main().
• Utiliza el operador punto (.) para acceder a las casillas específicas y
asignar valores a la edad y al promedio (acceso como L-Value). 
*/

#include <stdio.h>
#include <string.h>

struct Alumno {
    char nombre[50]; 
    int edad; 
    float promedio;
    };

int main (void) {
    struct Alumno alumno1 = {"Martin", 24, 8.1};
    struct Alumno alumno2;

    strcpy(alumno2.nombre, "Marcelo");
    alumno2.edad = 65;
    alumno2.promedio = 9.9;
    
    printf("--- Datos del Alumno 2 ---\n"); 
    printf("Nombre: %s\n", alumno2.nombre); 
    printf("Edad: %d años\n", alumno2.edad); 
    printf("Promedio: %.2f\n\n", alumno2.promedio);

    return 0;
}