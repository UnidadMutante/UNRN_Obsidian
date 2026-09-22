Direccion de memoria |
Contenido                 |

- `&a`: significa “la ubicación de `a`”. El lugar de memoria
- `*a`: significa “el contenido que está guardado en esa ubicación”.


una arquitectura De 32 bits tiene un puntero de 4 bytes


&a es como decir "address of a" la direccion de a

![[Pasted image 20260901160926.png]]
 va a buscar a *pa, se da cuenta de que es una direccion de memoria (porque es un puntero) y va a buscar lo que esta ahi 
 y como el puntero *pa tenia guardado la direccion de a*
![[Pasted image 20260901161510.png]]

![[Pasted image 20260901161715.png]]

ojo con los paréntesis, es mejor dejarlos explicitos para manejar el comportamiento

![[Pasted image 20260901162045.png]]

![[Pasted image 20260901170607.png]]



![[Pasted image 20260901170938.png]]

quiero el contenido de a -> para eso uso el asterisco



`&` y `*` trabajan juntos para poder modificar las variables originales dentro de `intercambio`.

- `&a`: significa “la ubicación de `a`”.
- `*a`: significa “el contenido que está guardado en esa ubicación”.

Tu código corregido sería:

```
#include <stdio.h>

void intercambio(char *a, char *b);

int main(void)
{
    char a = 'x';
    char b = 'y';

    printf("a: %c\n", a);
    printf("b: %c\n", b);

    intercambio(&a, &b);

    printf("a: %c\n", a);
    printf("b: %c\n", b);

    return 0;
}

void intercambio(char *a, char *b)
{
    char temp;

    temp = *a;
    *a = *b;
    *b = temp;
}
```

Qué ocurre en cada lugar:

```
char a = 'x';
char b = 'y';
```

Creás dos variables que contienen caracteres.

```
intercambio(&a, &b);
```

Le pasás a la función la ubicación de `a` y de `b`, no solamente sus valores. Así la función puede cambiar las variables originales.

```
void intercambio(char *a, char *b)
```

Los `*` indican que `a` y `b` recibirán ubicaciones de variables `char`.

Dentro de la función:

```
temp = *a;
```

`*a` significa “el valor guardado en la ubicación recibida”. Por eso `temp` recibe `'x'`.

```
*a = *b;
```

El valor de `b`, `'y'`, se guarda en `a`.

```
*b = temp;
```

El valor anterior de `a`, guardado temporalmente en `temp`, se guarda en `b`.

El `*` en una declaración:

```
char *a;
```

significa que `a` guardará una ubicación.

El `*` usado sobre una variable:

```
*a
```

significa que querés acceder al valor guardado en esa ubicación.

En tu versión original usabas:

```
char **a
```

Eso significa “una ubicación que apunta a otra ubicación”. Era demasiado para este caso. Como `a` y `b` son caracteres simples, alcanza con `char *a` y `char *b`.

Además, esta línea era incorrecta:

```
char a = 'x';
```

Está bien así. Pero si hubieras escrito:

```
char *a = 'x';
```

sería incorrecto, porque estarías intentando guardar un carácter como si fuera una ubicación.