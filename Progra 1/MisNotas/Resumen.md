
# 📘 Resumen Práctico de Programación I

## 🔹 Reserva de Memoria

- **Estática (Stack):**
    - Se define en tiempo de compilación.
    - Ejemplo: `int arr[10];`
        
- **Dinámica (Heap):**
    - Se define en tiempo de ejecución con `malloc`, `calloc`, `realloc`.
    - Siempre liberar con `free()`.
    c
    ```
    int *arr = malloc(n * sizeof(int));
    free(arr);
    arr = NULL; // buena práctica
    ```

## 🔹 Punteros

- Guardan **direcciones de memoria**.
- Operadores:
    - `&` → dirección de una variable.
    - `*` → contenido de la dirección.
- Ejemplo:
    ```
    int x = 5;
    int *px = &x;
    printf("%d", *px); // imprime 5
    ```
## 🔹 Arreglos y Matrices

- **Arreglos 1D:**
    ```
    int arr[5] = {1,2,3,4,5};
    ```
    
- **Matrices (2D):**
    ```
    int mat[3][3] = {{1,2,3},{4,5,6},{7,8,9}};
    ```
    
- **Funciones con matrices:** Pasar siempre filas y columnas como parámetros.
    ```
    void procesar(int filas, int cols, int mat[][cols]);
    ```
## 🔹 Strings (Cadenas)

- Son **arreglos de** `char` terminados en `'\0'`.
- Siempre reservar espacio extra para el `'\0'`.
- Funciones seguras (`<string.h>`):
    - `strlen`, `strncpy`, `strncat`, `strncmp`.
- Ejemplo:
    ```
    char nombre[50];
    scanf("%49s", nombre); // evita overflow
    ```
## 🔹 Funciones

- **Definición:**
    ```
    int sumar(int a, int b) { return a+b; }
    ```
    
- **Prototipo:** Se declara antes del `main`.
    ```
    int sumar(int a, int b);
    ```
    
- **Precondiciones/Postcondiciones:** Documentar qué debe cumplirse antes y qué garantiza después.
## 🔹 Archivos

- **Abrir:** `fopen("archivo.txt", "r/w/a");`
- **Escribir:** `fprintf`, `fputc`.
- **Leer:** `fscanf`, `fgets`, `fgetc`.
- **Cerrar:** `fclose()`.
- Ejemplo:
    ```
    FILE *f = fopen("datos.txt", "w");
    fprintf(f, "Hola mundo\n");
    fclose(f);
    ```
## 🔹 Estructuras

- Agrupan distintos tipos de datos.
    ```
    typedef struct {
        char nombre[50];
        int edad;
        float promedio;
    } Alumno;
    ```
    
- Acceso: `alumno1.edad = 20;`
- Con punteros: `ptr->edad = 20;`
## 🔹 Impresión por Consola

- `printf` con **modificadores de formato**:
    - `%d` → enteros
    - `%f` → flotantes
    - `%s` → cadenas
    - `%zu` → `size_t`
        
- Ejemplo:
    ```
    printf("Edad: %d, Altura: %.2f\n", edad, altura);
    ```
## 🔹 Algoritmos Clave

- **Ordenamiento:** burbuja, selección, inserción.
- **Búsqueda:** secuencial, binaria.
- **Recursión:** funciones que se llaman a sí mismas.
## 🔹 Buenas Prácticas

- Modularizar en funciones.
- Usar `const` para evitar modificaciones accidentales.
- Liberar memoria dinámica.
- Documentar con comentarios claros.
- Evitar “números mágicos”: usar constantes (`#define` o `const`).

# 🔄 ¿Qué es la Recursión?

La **recursión** es una técnica en programación donde una función se llama a sí misma para resolver un problema.
- Se usa cuando un problema puede dividirse en **subproblemas más pequeños**.
- Siempre debe tener una **condición de corte** (caso base) para evitar que se llame infinitamente.

👉 Ejemplo clásico: calcular el factorial de un número.
```
// Ejemplo de recursión: Factorial
int factorial(int n) {
    if (n == 0) return 1; // Caso base
    return n * factorial(n - 1); // Llamada recursiva
}
```

# 📊 Algoritmos de Ordenamiento

## 1. Burbuja (Bubble Sort)

Compara pares de elementos y los intercambia si están en orden incorrecto.

```
// ORDENAMIENTO BURBUJA
void burbuja(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        for (int j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Intercambio
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
```

## 2. Selección (Selection Sort)

Busca el mínimo en cada pasada y lo coloca en su posición correcta.

```
// ORDENAMIENTO POR SELECCIÓN
void seleccion(int arr[], int n) {
    for (int i = 0; i < n-1; i++) {
        int min = i;
        for (int j = i+1; j < n; j++) {
            if (arr[j] < arr[min]) min = j;
        }
        // Intercambio
        int temp = arr[min];
        arr[min] = arr[i];
        arr[i] = temp;
    }
}
```

## 3. Inserción (Insertion Sort)

Va insertando cada elemento en la parte ya ordenada del arreglo.

```
// ORDENAMIENTO POR INSERCIÓN
void insercion(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int clave = arr[i];
        int j = i - 1;
        // Mueve elementos mayores a la derecha
        while (j >= 0 && arr[j] > clave) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = clave;
    }
}
```

# 🔍 Algoritmos de Búsqueda

## 1. Secuencial (Linear Search)

Recorre el arreglo hasta encontrar el elemento.
```
// BÚSQUEDA SECUENCIAL
int busquedaSecuencial(int arr[], int n, int x) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) return i; // encontrado
    }
    return -1; // no encontrado
}
```

## 2. Binaria (Binary Search)

Funciona solo en **arreglos ordenados**. Divide el arreglo en mitades sucesivas.

```
// Algoritmo de Búsqueda Binaria
// Busca un número 'x' dentro de un arreglo ordenado 'arr' de tamaño 'n'.
// Devuelve el índice donde se encuentra 'x' o -1 si no está.

int busquedaBinaria(int arr[], int n, int x) {

    // Definimos los límites iniciales del rango de búsqueda
    int inicio = 0;
    int fin = n - 1;

    // Mientras el rango sea válido (inicio <= fin)
    while (inicio <= fin) {

        // Calculamos la posición del medio
        int medio = (inicio + fin) / 2;

        // Caso 1: encontramos el valor
        if (arr[medio] == x) {
            return medio;   // devolvemos la posición
        }
        // Caso 2: el valor buscado es mayor que el del medio
        else if (arr[medio] < x) {
            // descartamos la mitad izquierda
            inicio = medio + 1;
        }
        // Caso 3: el valor buscado es menor que el del medio
        else {
            // descartamos la mitad derecha
            fin = medio - 1;
        }
    }

    // Si salimos del bucle, significa que no lo encontramos
    return -1;
}

```

