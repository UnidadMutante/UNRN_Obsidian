#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// -----------------------------
// Definición de estructuras
// -----------------------------
typedef struct {
    char nombre[50];
    int edad;
    float promedio;
} Alumno;

// -----------------------------
// Funciones auxiliares
// -----------------------------

// Ejemplo de función con parámetros y retorno
float calcularPromedio(float notas[], size_t cantidad) {
    float suma = 0;
    for (size_t i = 0; i < cantidad; i++) {
        suma += notas[i];
    }
    return suma / cantidad;
}

// Ejemplo de función con precondición y postcondición
int dividir(int dividendo, int divisor, int *resultado) {
    // PRECONDICIÓN: divisor != 0
    if (divisor == 0) return -1;
    *resultado = dividendo / divisor;
    // POSTCONDICIÓN: resultado * divisor <= dividendo
    return 0;
}

// Ejemplo de función que recibe un arreglo dinámico
void imprimirArreglo(const int *arr, size_t n) {
    for (size_t i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Ejemplo de función que guarda datos en archivo
void guardarAlumno(const Alumno *a, const char *filename) {
    FILE *f = fopen(filename, "a"); // modo append
    if (f == NULL) {
        perror("Error al abrir archivo");
        return;
    }
    fprintf(f, "Nombre: %s | Edad: %d | Promedio: %.2f\n", a->nombre, a->edad, a->promedio);
    fclose(f);
}

// -----------------------------
// Programa principal
// -----------------------------
int main(int argc, char *argv[]) {
    // Uso de argumentos main (argv/argc)
    if (argc > 1) {
        printf("Ejecutando con argumento: %s\n", argv[1]);
    }

    // Memoria dinámica: reservar arreglo de enteros
    size_t n;
    printf("Ingrese cantidad de enteros: ");
    scanf("%zu", &n);

    int *arr = (int *)calloc(n, sizeof(int)); // calloc inicializa en 0
    if (arr == NULL) {
        fprintf(stderr, "Error al asignar memoria\n");
        return 1;
    }

    // Cargar valores en el arreglo
    for (size_t i = 0; i < n; i++) {
        arr[i] = (int)(i + 1) * 10;
    }

    printf("Arreglo dinámico cargado:\n");
    imprimirArreglo(arr, n);

    // Ejemplo con cadenas seguras
    char nombre[50];
    printf("Ingrese su nombre (máx 49 caracteres): ");
    scanf("%49s", nombre); // scanf con límite para evitar overflow

    // Crear estructura Alumno
    Alumno alumno1;
    strncpy(alumno1.nombre, nombre, sizeof(alumno1.nombre) - 1);
    alumno1.nombre[sizeof(alumno1.nombre) - 1] = '\0'; // cierre seguro
    alumno1.edad = 20;
    float notas[] = {8.5, 7.0, 9.0};
    alumno1.promedio = calcularPromedio(notas, 3);

    printf("Alumno creado: %s, Edad: %d, Promedio: %.2f\n", alumno1.nombre, alumno1.edad, alumno1.promedio);

    // Guardar en archivo
    guardarAlumno(&alumno1, "alumnos.txt");

    // Liberar memoria
    free(arr);
    arr = NULL;

    return 0;
}
