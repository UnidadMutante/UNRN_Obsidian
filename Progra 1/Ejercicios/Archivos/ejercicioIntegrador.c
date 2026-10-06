/*
Diseñar un programa en C que gestione un registro de alumnos con las siguientes características:
Entrada de datos:
El usuario debe ingresar la cantidad de alumnos (n) → usar memoria dinámica para reservar espacio.
Para cada alumno: nombre (cadena segura), edad (entero) y promedio (float).
Procesamiento:
Calcular el promedio general de la clase.
Implementar una función que determine el alumno con mejor promedio.
Implementar una función que ordene los alumnos por edad (usar un algoritmo de ordenamiento).
Salida:
Mostrar todos los alumnos en pantalla.
Guardar los datos en un archivo de texto llamado alumnos.txt.
Restricciones:
Usar estructuras para representar al alumno.
Modularizar en funciones.
Usar cadenas seguras (scanf con límite o fgets).
Documentar cada función con precondiciones y postcondiciones.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Alumno;

// PRE: cantidad > 0, arr != NULL
// POST: devuelve el promedio general de la clase
float promedioGeneral(Alumno *arr, size_t cantidad) {
    float suma = 0;
    for (size_t i = 0; i < cantidad; i++) {
        suma += arr[i].promedio;
    }
    return suma / cantidad;
}

// PRE: cantidad > 0, arr != NULL
// POST: devuelve índice del alumno con mejor promedio
int mejorPromedio(Alumno *arr, size_t cantidad) {
    int idx = 0;
    for (size_t i = 1; i < cantidad; i++) {
        if (arr[i].promedio > arr[idx].promedio) {
            idx = i;
        }
    }
    return idx;
}

// PRE: cantidad > 0, arr != NULL
// POST: ordena el arreglo por edad (ascendente)
void ordenarPorEdad(Alumno *arr, size_t cantidad) {
    for (size_t i = 0; i < cantidad - 1; i++) {
        for (size_t j = i + 1; j < cantidad; j++) {
            if (arr[i].edad > arr[j].edad) {
                Alumno temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

// PRE: arr != NULL, cantidad > 0
// POST: guarda los datos en archivo alumnos.txt
void guardarArchivo(Alumno *arr, size_t cantidad) {
    FILE *f = fopen("alumnos.txt", "w");
    if (f == NULL) {
        perror("Error al abrir archivo");
        return;
    }
    for (size_t i = 0; i < cantidad; i++) {
        fprintf(f, "Nombre: %s | Edad: %d | Promedio: %.2f\n",
                arr[i].nombre, arr[i].edad, arr[i].promedio);
    }
    fclose(f);
}

int main() {
    size_t n;
    printf("Ingrese cantidad de alumnos: ");
    scanf("%zu", &n);
    getchar(); // limpiar buffer

    Alumno *clase = (Alumno *)malloc(n * sizeof(Alumno));
    if (clase == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        return 1;
    }

    for (size_t i = 0; i < n; i++) {
        printf("Alumno %zu:\n", i + 1);
        printf("Nombre: ");
        fgets(clase[i].nombre, sizeof(clase[i].nombre), stdin);
        clase[i].nombre[strcspn(clase[i].nombre, "\n")] = '\0'; // quitar salto

        printf("Edad: ");
        scanf("%d", &clase[i].edad);

        printf("Promedio: ");
        scanf("%f", &clase[i].promedio);
        getchar(); // limpiar buffer
    }

    printf("\nPromedio general: %.2f\n", promedioGeneral(clase, n));
    int idx = mejorPromedio(clase, n);
    printf("Mejor promedio: %s (%.2f)\n", clase[idx].nombre, clase[idx].promedio);

    ordenarPorEdad(clase, n);
    printf("\nAlumnos ordenados por edad:\n");
    for (size_t i = 0; i < n; i++) {
        printf("%s | Edad: %d | Promedio: %.2f\n",
               clase[i].nombre, clase[i].edad, clase[i].promedio);
    }

    guardarArchivo(clase, n);

    free(clase);
    return 0;
}
