# Cheat sheet: arreglos en C
La forma general es:

```
tipo nombre[cantidad];
```

Ejemplos:

```
int edades[5];
float precios[10];
char letras[4];
double medidas[3];
```

El tipo depende de qué valores vas a guardar.

## Declarar e inicializar

```
int numeros[5] = {10, 20, 30, 40, 50};
```

También podés dejar que C calcule el tamaño:

```
int numeros[] = {10, 20, 30};
```

Este arreglo tiene tres elementos.

Podés inicializar parcialmente:

```
int numeros[5] = {10, 20};
```

El resultado es:

```
10, 20, 0, 0, 0
```

Para inicializar todo en cero:

```
int numeros[5] = {0};
```

## Acceder a los elementos

Los índices empiezan en `0`.

```
int numeros[3] = {10, 20, 30};

printf("%d\n", numeros[0]); // 10
printf("%d\n", numeros[2]); // 30
```

El último índice es siempre:

```
cantidad - 1
```

Por ejemplo, para un arreglo de cinco elementos:

```
numeros[0] // primero
numeros[4] // último
```

Esto es incorrecto:

```
numeros[5]; // fuera del arreglo
```

## Modificar elementos

```
int numeros[3] = {10, 20, 30};

numeros[1] = 99;
```

Ahora el arreglo contiene:

```
10, 99, 30
```

## Recorrer un arreglo

```
#include <stdio.h>

int main(void)
{
    int numeros[] = {10, 20, 30, 40, 50};
    size_t cantidad = sizeof(numeros) / sizeof(numeros[0]);

    for (size_t i = 0; i < cantidad; i++) {
        printf("%d\n", numeros[i]);
    }

    return 0;
}
```

`size_t` se usa normalmente para tamaños e índices.

Para imprimir un `size_t`, usá:

```
printf("%zu\n", cantidad);
```

## `sizeof` y cantidad de elementos

```
int numeros[5];

size_t bytes_totales = sizeof(numeros);
size_t bytes_un_elemento = sizeof(numeros[0]);

size_t cantidad =
    sizeof(numeros) / sizeof(numeros[0]);
```

La expresión:

```
sizeof(numeros) / sizeof(numeros[0])
```

funciona cuando `numeros` es un arreglo real, por ejemplo dentro de `main`.

No funciona igual dentro de una función, porque allí el arreglo se recibe como un puntero.

## Arreglos como parámetros de funciones

```
void imprimir(const int numeros[], size_t cantidad)
{
    for (size_t i = 0; i < cantidad; i++) {
        printf("%d\n", numeros[i]);
    }
}
```

También podés escribirlo así:

```
void imprimir(const int *numeros, size_t cantidad)
```

Ambas formas significan prácticamente lo mismo como parámetro.

La función necesita recibir el tamaño por separado:

```
int numeros[] = {10, 20, 30};
size_t cantidad = 3;

imprimir(numeros, cantidad);
```

Un arreglo no lleva corchetes al pasarlo:

```
imprimir(numeros, cantidad);
```

No:

```
imprimir(numeros[], cantidad);
```

## `const` en arreglos

Si una función solo debe leer el arreglo y no modificarlo:

```
void imprimir(const int numeros[], size_t cantidad)
```

Esto protege los elementos dentro de la función.

Sin `const`, la función podría modificarlos:

```
void duplicar(int numeros[], size_t cantidad)
{
    for (size_t i = 0; i < cantidad; i++) {
        numeros[i] *= 2;
    }
}
```

## Arreglos de caracteres: strings

Una string es un arreglo de `char` que termina en `'\0'`.

```
char nombre[] = "Carlos";
```

Internamente necesita espacio para:

```
'C' 'a' 'r' 'l' 'o' 's' '\0'
```

También podés escribirla manualmente:

```
char palabra[] = {'H', 'o', 'l', 'a', '\0'};
```

Para leer strings:

```
char nombre[30];

fgets(nombre, sizeof(nombre), stdin);
```

El tamaño debe incluir espacio para `'\0'`.

## Arreglos bidimensionales

Sirven para representar tablas o matrices:

```
int matriz[2][3] = {
    {1, 2, 3},
    {4, 5, 6}
};
```

Acceso:

```
printf("%d\n", matriz[0][1]); // 2
printf("%d\n", matriz[1][2]); // 6
```

Recorrido:

```
for (size_t fila = 0; fila < 2; fila++) {
    for (size_t columna = 0; columna < 3; columna++) {
        printf("%d ", matriz[fila][columna]);
    }

    printf("\n");
}
```

## Arreglos de tamaño variable: VLA

El tamaño puede calcularse durante la ejecución:

```
size_t cantidad = 5;
int numeros[cantidad];
```

Estos son llamados VLA.

Tené cuidado:

- No conviene usarlos para tamaños enormes.
- No se deben devolver directamente desde una función.
- Su soporte puede depender de la versión del compilador.

## Arreglos dinámicos

Cuando el tamaño se conoce durante la ejecución y necesitás que la memoria permanezca disponible, podés usar `malloc` o `calloc`.

```
#include <stdlib.h>

size_t cantidad = 5;

int *numeros = malloc(cantidad * sizeof(int));

if (numeros == NULL) {
    return 1;
}
```

Usar:

```
numeros[0] = 10;
```

Liberar al terminar:

```
free(numeros);
```

Con `calloc`:

```
int *numeros = calloc(cantidad, sizeof(int));
```

`calloc` inicializa los elementos en cero.

## `&` y `*` con arreglos

Un arreglo puede pasarse a una función porque normalmente se convierte en la ubicación de su primer elemento:

```
int numeros[3] = {10, 20, 30};

int *puntero = numeros;
```

Esto apunta al primer elemento.

También podés escribir:

```
int *puntero = &numeros[0];
```

Acceder al valor:

```
printf("%d\n", *puntero); // 10
```

Moverte al siguiente elemento:

```
printf("%d\n", *(puntero + 1)); // 20
```

Normalmente es más claro usar:

```
puntero[1]
```

## Errores frecuentes

```
int numeros[5];

numeros[5] = 10; // incorrecto: el último índice es 4
```

```
void funcion(int numeros[])
{
    sizeof(numeros); // no calcula el tamaño completo del arreglo
}
```

```
int *numeros[5];
```

Esto no es un arreglo de cinco enteros. Es un arreglo de cinco punteros a enteros.

Para cinco enteros:

```
int numeros[5];
```

Para cinco punteros a enteros:

```
int *numeros[5];
```

## Regla rápida

```
tipo nombre[tamaño];
```

Ejemplos:

```
int edades[5];
float notas[3];
char palabra[20];
double valores[10];
```

Y para trabajar correctamente con un arreglo, normalmente necesitás:

```
arreglo
cantidad de elementos
```

Por ejemplo:

```
void procesar(int arreglo[], size_t cantidad);
```


## troubleshooting


Cuando un arreglo se pasa como parámetro:

```
size_t contar_caracter(const char cadena[], char caracter_buscado)
```

`cadena` se comporta como un puntero. Por eso:

```
sizeof(cadena)
```

devuelve el tamaño del puntero, no la cantidad de caracteres de la palabra.

La condición:

```
cadena[i] != '\0'
```

es la forma correcta de recorrer una cadena, porque una string termina en `'\0'`.

En cambio, esto sí funcionaría dentro de `main`:

```
char palabra[] = "palabratest";

size_t largo = sizeof(palabra) / sizeof(palabra[0]);
```

Pero ese cálculo incluye el `'\0'`. Si querés recorrer solo los caracteres visibles, usarías:

```
size_t largo = sizeof(palabra) / sizeof(palabra[0]) - 1;
```

También podrías usar:

```
strlen(palabra)
```

pero necesitás incluir `<string.h>`.

2. `size_t` se usa porque `contador` representa una cantidad que nunca debería ser negativa.

```
size_t contador = 0;
```

`size_t` es el tipo usado normalmente para:

- tamaños;
- cantidades de elementos;
- índices de arreglos;
- resultados de `sizeof` y `strlen`.

`int` también funcionaría para una palabra pequeña:

```
int contador = 0;
```

Pero `size_t` es más apropiado y evita problemas de compatibilidad con valores producidos por funciones como `strlen`.

Tu código debería quedar así:

```
#include <stdio.h>
#include <stddef.h>

size_t contar_caracter(const char cadena[], char caracter_buscado);

int main(void)
{
    char palabra[] = "palabratest";
    char caracter_buscado = 's';

    size_t ocurrencias =
        contar_caracter(palabra, caracter_buscado);

    printf(
        "En la palabra %s, el carácter buscado \"%c\" aparece %zu veces\n",
        palabra,
        caracter_buscado,
        ocurrencias
    );

    return 0;
}

size_t contar_caracter(
    const char cadena[],
    char caracter_buscado
)
{
    size_t contador = 0;

    for (size_t i = 0; cadena[i] != '\0'; i++) {
        if (cadena[i] == caracter_buscado) {
            contador++;
        }
    }

    return contador;
}
```

Observá también que para imprimir un `size_t` se usa:

```
%zu
```

no `%lu`.