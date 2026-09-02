## Tipo de dato: size t
**no acepta valores negativos**
* Es el tipo de dato que devuelve por defecto sizeof()*
**size_t sizeof(variable)** 
Da el tamaño en bytes de una variable o tipo 

%lu long unsigned
![[Pasted image 20260901195002.png]]

## sizeof()
permite medir espacio ocupado en memoria

![[Pasted image 20260901195041.png]]

## Arreglos 

> int arreglo[8];

tipo de dato, nombre del arreglo, tamaño del arreglo

### inicializacion

int vacia[5] = {}; -> va a contener valores basura

int arreglo[5] = {1,2,4, 8, 16}

#### identidad
memcpy(arr1, arr2, sizeof(arr2));

#### Recorrer un arreglo

```
int arreglo[10] = {}; 
size_t largo = sizeof(arreglo) / sizeof(arreglo[0]); 
for (size_t i = 0; i < largo; i++) { 
arreglo[i] = i * i; 
}
```

#### Arreglos y funciones

```
#include <stdio.h> 
// Prototipo: Recibe el arreglo y su tamaño 

void duplicarValores(int numeros[], int tamano); 

int main() { 

int misNumeros[3] = {10, 20, 30}; 
printf("Antes de la funcion: %d\n", misNumeros[0]); // Imprime 10 // Al llamar a la funcion, SOLO se pone el nombre del arreglo (sin corchetes) 

duplicarValores(misNumeros, 3); 

printf("Despues de la funcion: %d\n", misNumeros[0]); // ¡Imprime 20! return 0; 
} 

// Cuerpo de la función 

void duplicarValores(int numeros[], int tamano) { 
for(int i = 0; i < tamano; i++) { 
numeros[i] = numeros[i] * 2; // Modifica la memoria real 
}
}
```

![[Pasted image 20260901202313.png]]

![[Pasted image 20260901202353.png]]

![[Pasted image 20260901202636.png]]

```
#include <stdio.h> 
// La función intenta devolver la dirección de un entero (un arreglo) int* crearArregloSeguro() { 

// La palabra 'static' evita que C destruya este arreglo al hacer return static int numeros[3] = {10, 20, 30}; 

return numeros; 
// Devolvemos la "dirección de memoria" del inicio 
}

int main() { 
// Atrapamos las llaves del edificio usando un puntero (*) 
int* miArreglo = crearArregloSeguro(); 

// Ahora podemos usarlo normalmente 
printf("El primer numero es: %d\n", miArreglo[10]); // Imprime 10 return 0; }
```

### Cadenas -> arreglo de caracteres

● El Arreglo de Caracteres: Para formar una palabra, C utiliza un arreglo (array) de variables char. ● El Problema: Como C no tiene frenos y no recuerda automáticamente el tamaño de los arreglos, ¿cómo sabe un printf cuándo dejar de imprimir letras en la pantalla? “Toda cadena de texto en C debe terminar obligatoriamente con un carácter especial llamado carácter nulo (\0).” ● El costo en memoria: Esto significa que si quieres guardar la palabra "Hola" (4 letras), necesitas pedirle a C una caja de 5 espacios en memoria, \0

![[Pasted image 20260901203944.png]]

![[Pasted image 20260901204217.png]]

Yes, the logic is mostly correct, but you need:

- `#include <stdio.h>`
- `#include <string.h>`
- Put executable statements such as `printf` inside `main`.
- You do not need to redeclare `strlen` or `strcat`; they are already declared in `<string.h>`.

A complete version:

```
#include <stdio.h>
#include <string.h>

int main(void)
{
    char nombre[] = "Hola";

    printf("Longitud: %zu\n", strlen(nombre));

    char origen[] = "Programacion en C";
    char destino[10];

    strncpy(destino, origen, sizeof(destino) - 1);
    destino[sizeof(destino) - 1] = '\0';

    printf("Destino: %s\n", destino);

    return 0;
}
```

Output:

```
Longitud: 4
Destino: Programac
```

`destino` has room for 10 characters: 9 visible characters plus `'\0'`, which marks the end of the text.

Your manual termination is important because `strncpy` does not always add `'\0'` when the source text is too long.

The idea is correct, but there are a few problems:

- Include `<stdio.h>` and `<string.h>`.
- Put the code inside `main`.
- `strcpy` is only a declaration here and is not being used.
- `usuario` must be declared before the comparison.
- `strncmp(usuario, "admin", 5)` compares only the first five characters. For an exact comparison, use `strcmp`.

```
#include <stdio.h>
#include <string.h>

int main(void)
{
    char saludo[20] = "Hola ";
    char nombre[] = "Carlos";

    strncat(
        saludo,
        nombre,
        sizeof(saludo) - strlen(saludo) - 1
    );

    printf("%s\n", saludo);

    char usuario[] = "admin";

    if (strcmp(usuario, "admin") == 0) {
        printf("Acceso correcto\n");
    }

    return 0;
}
```

`strncat` safely adds `"Carlos"` to `"Hola "` while leaving room for the final `'\0'`.

Use:

```
strcmp(usuario, "admin")
```

when the entire text must match.

Use:

```
strncmp(usuario, "admin", 5)
```

when you intentionally want to compare only the first five characters. For example, `"administrator"` would also match the `strncmp` condition.
#### Libreria stdlib
![[Pasted image 20260901203738.png]]