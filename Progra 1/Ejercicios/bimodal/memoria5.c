/* Uso de cadenas y clonación de estructuras.
• Incluye la librería <string.h> para utilizar la función strcpy y asignar un
nombre a una variable estática de tipo Alumno.
• Declara una segunda variable de tipo Alumno.
• Aprovecha que C permite la asignación masiva copiando todos 
*/

#include <stdio.h>
#include <string.h>

struct Alumno {
    char nombre[30];
    int edad;
    float promedio;
};

int main (void) {

    struct Alumno alumno1 = {"Gabriel", 30, 6.7};
    struct Alumno alumno2;
    printf("nombre alumno1 %s\n", alumno1.nombre);
    strcpy(alumno2.nombre, "Ermiña");
    printf("nombre alumno2 %s\n", alumno2.nombre);

    alumno2.promedio = alumno1.promedio;
    printf("promedio alumno2 %f\n", alumno2.promedio);

    return 0;
}