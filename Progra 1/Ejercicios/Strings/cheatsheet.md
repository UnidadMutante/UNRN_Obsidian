# Cheat Sheet: Funciones de `<string.h>`

## Por qué algunas van con `*` y otras no

El `*` antes del nombre de la función (`*strcat`, `*strcpy`) **no es parte del nombre de la función** — es el **tipo de retorno** de la función, escrito de forma abreviada. Cuando ves la firma completa en la documentación:

```c
char *strcpy(char *destino, const char *origen);
```

Eso significa: *"`strcpy` es una función que **retorna un puntero a `char`** (`char *`)"*. La costumbre de escribirlo pegado al nombre (`*strcpy` en vez de `char* strcpy`) es solo una forma abreviada de referirse a la función mencionando su tipo de retorno, común en documentación y apuntes.

**La razón por la que estas funciones retornan `char *`:** devuelven un puntero a la cadena resultante (generalmente el mismo puntero de destino que recibieron), para permitir **encadenar llamadas** (function chaining) o simplemente para que puedas usar el resultado directamente en una expresión, como un `printf`.

Las que **no** llevan `*` (`strlen`, `strcmp`) retornan otros tipos:
- `strlen` retorna `size_t` (un número, la longitud).
- `strcmp` retorna `int` (un número que indica el resultado de la comparación).

Ninguna de las dos devuelve una cadena, por eso no llevan `*`.

---

## Cheat Sheet

| Función | Firma completa | Qué hace | Qué retorna |
|---|---|---|---|
| `strlen` | `size_t strlen(const char *s)` | Cuenta los caracteres de `s` **sin contar** el `'\0'` final | La longitud como `size_t` |
| `strcpy` | `char *strcpy(char *dest, const char *src)` | Copia `src` completo (incluyendo `'\0'`) dentro de `dest` | Puntero a `dest` |
| `strcat` | `char *strcat(char *dest, const char *src)` | Pega (concatena) `src` al final de `dest`, sobrescribiendo el `'\0'` de `dest` y agregando uno nuevo al final | Puntero a `dest` |
| `strncat` | `char *strncat(char *dest, const char *src, size_t n)` | Igual que `strcat`, pero copia **como máximo** `n` caracteres de `src` (más el `'\0'` final que siempre agrega) | Puntero a `dest` |
| `strcmp` | `int strcmp(const char *s1, const char *s2)` | Compara dos cadenas carácter por carácter (orden lexicográfico, como el diccionario) | `0` si son iguales, `<0` si `s1 < s2`, `>0` si `s1 > s2` |

---

## Ejemplos de uso

### `strlen`
```c
char nombre[] = "Lucila";
size_t len = strlen(nombre);
printf("Longitud: %zu\n", len);   // Longitud: 6
```

### `strcpy`
```c
char destino[20];
strcpy(destino, "Hola");
printf("%s\n", destino);   // Hola
```
⚠️ **Peligro:** `strcpy` **no chequea el tamaño** de `destino`. Si `src` es más largo de lo que `destino` puede contener, hay **buffer overflow** (comportamiento indefinido, riesgo de seguridad).

### `strcat`
```c
char saludo[20] = "Hola ";
strcat(saludo, "mundo");
printf("%s\n", saludo);   // Hola mundo
```
⚠️ Mismo peligro que `strcpy`: no valida que `dest` tenga espacio suficiente para el resultado combinado.

### `strncat` (la versión "seguras" de `strcat`)
```c
char saludo[10] = "Hola";
strncat(saludo, " mundo", 3);   // copia como máximo 3 caracteres de " mundo"
printf("%s\n", saludo);   // Hola mu
```
Es más seguro porque limitás cuántos caracteres se copian — pero ojo: **vos** sos responsable de calcular bien ese límite según el tamaño real de `dest` (la función no lo calcula por vos).

### `strcmp`
```c
if (strcmp("hola", "hola") == 0) {
    printf("Son iguales\n");
}

int resultado = strcmp("banana", "manzana");
if (resultado < 0) {
    printf("banana va antes que manzana\n");  // se cumple, 'b' < 'm'
}
```
⚠️ Error común de principiante: **nunca uses `==` para comparar cadenas** (`if (cadena1 == cadena2)`), eso compara direcciones de memoria (punteros), no contenido. Siempre usá `strcmp(...) == 0`.

---

## Tabla resumen de seguridad

| Función | ¿Chequea tamaño del destino? |
|---|---|
| `strcpy` | ❌ No |
| `strcat` | ❌ No |
| `strncat` | ✅ Sí (vos das el límite `n`) |
| `strlen` | N/A (solo lee, no escribe) |
| `strcmp` | N/A (solo lee, no escribe) |

¿Querés que agregue también `strncpy` (la versión "segura" de `strcpy`) al cheat sheet, ya que suele enseñarse junto con `strncat`?