# Programación I - Guía de Estudio Integrada

## Complejidad Computacional, Recursión y Algoritmos de Ordenamiento

Basada en:

- 14-Algoritmos de ordenamiento.pdf 【1-bdc151】

- 15-Complejidad computacional.pdf 【2-22e171】

- 16 - Recusión y repaso.pdf 【3-e9385e】

- 17-Continuacion algoritmos.pdf 【4-80f27f】

---

# 1. ¿Qué es un algoritmo?

Un algoritmo es un conjunto finito, ordenado y no ambiguo de instrucciones destinadas a resolver un problema específico. 【1-bdc151】

Pensalo como una receta de cocina:

```text

Entrada → Procesamiento → Salida

```

Ejemplo:

```text

Entrada:

[15.4, 22.1, 18.9, 25.6]

Proceso:

Buscar el valor máximo

Salida:

25.6

```

---

## Características de un algoritmo

Todo algoritmo debe cumplir:

### 1. Finitud

Debe terminar.

✅ Correcto

```c

for(int i=0; i<10; i++)

```

❌ Incorrecto

```c

while(1)

{

}

```

---

### 2. Precisión

Cada paso debe estar perfectamente definido.

---

### 3. Entrada

Debe poder recibir datos.

```c

int vec[10];

```

---

### 4. Salida

Debe producir un resultado.

```c

return suma;

```

---

### 5. Eficacia

Las operaciones deben poder ejecutarse en tiempo finito. 【1-bdc151】

---

# 2. Formas de representar algoritmos

## Pseudocódigo

```text

Inicio

leer arreglo

buscar máximo

mostrar máximo

Fin

```

---

## Diagrama de flujo

Representación gráfica mediante símbolos.

---

## Código

```c

float maximo(float vec[], int n)

{

    float max = vec[0];

    for(int i = 1; i < n; i++)

    {

        if(vec[i] > max)

        {

            max = vec[i];

        }

    }

    return max;

}

```

【1-bdc151】

---

# 3. Complejidad Computacional

La complejidad NO significa que un código sea difícil.

Significa:

> Cómo crecen los recursos consumidos por un algoritmo cuando aumenta el tamaño de la entrada. 【1-bdc151】【2-22e171】

Existen dos tipos principales.

---

## Complejidad Temporal

Mide:

```text

¿Cuántas operaciones realiza?

```

Ejemplo:

```c

for(int i=0;i<n;i++)

{

    printf("%d", i);

}

```

Hace n iteraciones.

---

## Complejidad Espacial

Mide:

```text

¿Cuánta memoria adicional utiliza?

```

Ejemplo:

```c

int x;

```

Complejidad espacial:

```text

O(1)

```

Porque la memoria utilizada no depende de n.

---

# 4. T(n)

T(n) representa el tiempo de ejecución para una entrada de tamaño n. 【2-22e171】

Ejemplo:

```c

for(int i=0;i<n;i++)

{

}

```

T(n):

```text

n

```

---

# 5. Big O

Big O permite expresar el crecimiento de un algoritmo ignorando detalles pequeños.

Ejemplo:

```text

T(n) = 2n + 3

```

se simplifica como:

```text

O(n)

```

porque el término dominante es n. 【2-22e171】【1-bdc151】

---

# 6. Complejidades importantes

## O(1) - Constante

```c

x = vec[4];

```

Tarda siempre lo mismo.

---

## O(log n) - Logarítmica

Ejemplo:

```c

Búsqueda Binaria

```

Cada paso descarta la mitad.

```text

1024

512

256

128

64

32

16

8

4

2

1

```

---

## O(n) - Lineal

```c

for(int i=0;i<n;i++)

```

Duplica datos → duplica tiempo.

---

## O(n log n) - Linealítmica

La complejidad típica de:

- QuickSort

- MergeSort

---

## O(n²) - Cuadrática

Dos ciclos dependientes de n.

```c

for(...)

{

    for(...)

    {

    }

}

```

---

## O(2ⁿ) - Exponencial

Crecimiento explosivo.

Muy ineficiente para grandes entradas. 【1-bdc151】

---

# 7. Reglas para calcular complejidad

## Regla de la suma

```c

for(...)      // O(n)

for(...)      // O(n²)

```

Resultado:

```text

O(n²)

```

Se toma la mayor.

---

## Regla del producto

```c

for(...)

{

    for(...)

    {

    }

}

```

Resultado:

```text

O(n²)

```

Porque:

```text

n × n

```

【2-22e171】

---

# 8. Búsqueda Lineal

Recorre elemento por elemento.

```c

bool buscarLineal(int vec[], int n, int buscado)

{

    for(int i=0;i<n;i++)

    {

        if(vec[i]==buscado)

            return true;

    }

    return false;

}

```

Complejidad:

```text

O(n)

```

Peor caso:

```text

El elemento está al final

```

o

```text

No existe

```

【2-22e171】

---

# 9. Búsqueda Binaria

REQUISITO:

```text

El arreglo debe estar ordenado

```

```c

bool buscarBinaria(...)

```

Idea:

```text

¿Está en el medio?

Sí → terminé

No → descarto media lista

```

Complejidad:

```text

O(log n)

```

Mucho más eficiente para grandes volúmenes de datos. 【2-22e171】

---

# 10. Recursión

Una función recursiva es una función que se llama a sí misma. 【3-e9385e】【1-bdc151】

Toda recursión necesita:

## Caso Base

Detiene las llamadas.

## Caso Recursivo

Reduce el problema.

---

## Estructura General

```c

tipo funcion(dato)

{

    if(casoBase)

    {

        return resultado;

    }

    return funcion(problemaMasPequeño);

}

```

---

# 11. Factorial

Definición matemática:

```text

0! = 1

n! = n × (n−1)!

```

Implementación:

```c

int factorial(int n)

{

    if(n == 0)

    {

        return 1;

    }

    return n * factorial(n - 1);

}

```

---

## Ejecución visual

```text

factorial(4)

4 * factorial(3)

4 * (3 * factorial(2))

4 * (3 * (2 * factorial(1)))

4 * (3 * (2 * 1))

24

```

---

# 12. Fibonacci

```text

fib(0)=1

fib(1)=1

fib(n)=fib(n−1)+fib(n−2)

```

```c

int fib(int n)

{

    if(n == 0 || n == 1)

    {

        return 1;

    }

    return fib(n-1) + fib(n-2);

}

```

【3-e9385e】

---

# 13. Ventajas y Desventajas de la Recursión

## Ventajas

- Más simple.

- Más elegante.

- Se adapta a problemas jerárquicos.

## Desventajas

- Utiliza más memoria.

- Más lenta.

- Riesgo de Stack Overflow.

【1-bdc151】【4-80f27f】

---

# 14. Cuándo usar Recursión

## Conviene

Cuando el problema es:

- Jerárquico

- Arbóreo

- Auto-similar

Ejemplos:

- Árboles

- Directorios

- QuickSort

- MergeSort

---

## No conviene

Cuando el problema es:

- Lineal

- Secuencial

- Muy grande

【1-bdc151】

---

# 15. Bubble Sort

Idea:

Comparar vecinos.

```text

5 3 8 1

3 5 8 1

3 5 1 8

3 1 5 8

1 3 5 8

```

Código:

```c

void bubbleSort(int arr[], int n)

{

    for(int i=0;i<n-1;i++)

    {

        for(int j=0;j<n-1-i;j++)

        {

            if(arr[j] > arr[j+1])

            {

                int aux = arr[j];

                arr[j] = arr[j+1];

                arr[j+1] = aux;

            }

        }

    }

}

```

Complejidad:

```text

O(n²)

```

---

# 16. Selection Sort

Idea:

Buscar el menor elemento restante.

```text

4 9 2 6

2 9 4 6

2 4 9 6

2 4 6 9

```

Complejidad:

```text

O(n²)

```

Particularidad:

```text

Incluso si ya está ordenado sigue siendo O(n²)

```

【1-bdc151】

---

# 17. Insertion Sort

Idea:

Como ordenar cartas en la mano.

```text

5

3 5

2 3 5

2 3 5 8

```

Código:

```c

void insertionSort(int arr[], int n)

{

    for(int i=1;i<n;i++)

    {

        int key = arr[i];

        int j = i - 1;

        while(j >= 0 && arr[j] > key)

        {

            arr[j+1] = arr[j];

            j--;

        }

        arr[j+1] = key;

    }

}

```

Complejidad:

```text

O(n²)

```

Mejor caso:

```text

O(n)

```

【1-bdc151】

---

# 18. QuickSort

Algoritmo Divide y Vencerás.

Pasos:

1. Elegir pivote.

2. Particionar.

3. Ordenar izquierda.

4. Ordenar derecha.

---

## Partición de Lomuto

```c

int pivot = arr[high];

```

Se toma el último elemento como pivote.

---

### Ejemplo

```text

8 3 6 1 5

Pivote = 5

3 1 | 5 | 8 6

```

Todos los menores quedan a la izquierda.

Todos los mayores a la derecha.

【1-bdc151】【4-80f27f】

---

## Complejidad

Promedio:

```text

O(n log n)

```

Peor caso:

```text

O(n²)

```

---

# 19. QuickSort aplicado a estructuras

Ejemplo:

```c

typedef struct {

    int id_paquete;

    float altitud;

    float temperatura;

} Telemetria;

```

Podemos ordenar por:

```c

datos[i].altitud

```

sin modificar el algoritmo.

Simplemente cambiando la comparación.

---

# 20. MergeSort

Otro algoritmo Divide y Vencerás.

---

## Fase 1: Dividir

```text

38 27 43 3

38 27 | 43 3

38 | 27 | 43 | 3

```

---

## Fase 2: Fusionar

```text

27 38

3 43

3 27 38 43

```

---

## Idea principal

QuickSort:

```text

Ordena mientras divide

```

MergeSort:

```text

Divide primero

Fusiona ordenando después

```

---

## Complejidad

```text

O(n log n)

```

SIEMPRE.

Ventaja:

```text

Nunca cae a O(n²)

```

Desventaja:

```text

Necesita memoria auxiliar

```

【1-bdc151】

---

# 21. QuickSort Iterativo

El QuickSort clásico usa recursión.

```c

quickSort(...)

```

llama nuevamente a:

```c

quickSort(...)

```

---

Problema:

```text

Puede provocar Stack Overflow

```

si el arreglo es enorme.

---

Solución:

Usar una pila creada manualmente.

```c

int *stack*= malloc(...);

```

*uardando:

```text

*ow

high

```

de*cada subarreglo. *4-80f27f】

*--

# 22. qsort()*de la biblioteca estándar

C ya in*luye*una implementación optim*zada.

```c

qsort(

*   arreglo,

    cantidad,

    size*f(tipo),

*   comparar

);

```

---

*# Función comparadora

```c

int*comparar(const void *a, const void**b*

{

    int A =**(const int*)a;

    int B = *(const int*)b;

    if(A < B) return -1;

    if(A > B) return 1;

    return 0;

}

```

【1-bdc151】

---

# 23. Tabla de Complejidades

| Algoritmo | Complejidad |

|------------|------------|

| Acceso a arreglo | O(1) |

| Búsqueda Binaria | O(log n) |

| Búsqueda Lineal | O(n) |

| Bubble Sort | O(n²) |

| Selection Sort | O(n²) |

| Insertion Sort | O(n²) |

| QuickSort promedio | O(n log n) |

| MergeSort | O(n log n) |

| Fibonacci recursivo simple | O(2ⁿ) |

---

# Checklist para el Parcial

## Debes poder hacer sin ayuda

- [ ] Explicar qué es un algoritmo.

- [ ] Explicar Big O.

- [ ] Calcular complejidad de fragmentos de código.

- [ ] Diferenciar O(1), O(log n), O(n), O(n²), O(n log n).

- [ ] Implementar búsqueda lineal.

- [ ] Implementar búsqueda binaria.

- [ ] Implementar factorial recursivo.

- [ ] Implementar Fibonacci recursivo.

- [ ] Explicar Bubble Sort.

- [ ] Explicar Selection Sort.

- [ ] Explicar Insertion Sort.

- [ ] Explicar QuickSort.

- [ ] Explicar partición de Lomuto.

- [ ] Explicar MergeSort.

- [ ] Entender QuickSort iterativo.

- [ ] Adaptar algoritmos para structs.

- [ ] Utilizar qsort().

- [ ] Justificar por qué un algoritmo tiene determinada complejidad.

---

# Tres ideas clave para recordar

### Idea 1

No memorices complejidades.

Comprende cuántas veces se ejecuta cada ciclo.

---

### Idea 2

Toda recursión necesita:

```text

Caso Base

+

Reducción del problema

```

Si falta alguno de los dos:

```text

Infinite Recursion

```

---

### Idea 3

Para el examen:

```text

QuickSort y MergeSort

+

Recursión

+

Complejidad Computacional

```

son los temas más importantes porque aparecen repetidamente en todas las guías. 【2-22e171】【3-e9385e】【4-80f27f】【1-bdc151】