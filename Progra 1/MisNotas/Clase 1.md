Profesor: deteira@unrn.edu.ar

-> hay un taller de robótica los sábados

```
https://ingcom-unrn-p1.github.io/
```

**Compilador C online**
www.onlinegdb.com

Manual de C
https://cppreference.com/c
## Evaluaciones
27.08
23.09
09.11




### titulo 3q

C -> Lenguaje tipado ( se les define un tipo) 

El `&` -> le indica al compilador que lo que viene despues es una direccion de memoria que le estoy indicando

![[Pasted image 20260811170708.png|353]]
lo que esta a la izquierda es ==una direccion de memoria==
lo que esta a la derecha es **el contenido**

Algoritmos: una secuencia finita de pasos que tiene un input y un output

Todo programa en C necesita una funcion main.
printf muestra testo en pantalla

```
#include <stdio.h>

int main(void) {
	print("Hola mundo\n");
	return 0;
}
```

el argumento de la funcion -> lo que esta entre paréntesis

si pongo "int" main (....   -> estoy diciendo que voy a devolver un entero
por eso en la funcion de arriba pone return 0

si digo que voy a devolver un entero, tengo que devolver un entero. 

`scanf()` -> toma un valor que estoy escribiendo por teclado, y lo guarda en una variable

`scanf("%d", &n)` -> toma un valor y lo guarda en una variable, en este caso se lo asigna a "n"

`sizeof(expression)` -> me devuelve el tamaño en bytes de lo que le pasé a la funcion

El `&` indica en qué lugar de la memoria se tiene que guardar lo que se ingreso por teclado

En la función `scanf`, el `%d` funciona como un especificador de formato que le indica al programa que debe leer un valor de tipo entero (`int`) desde el teclado. 

Detalles del especificador %dTipo de dato: Señala que el dato esperado es un número entero decimal con signo.

```
#include <stdio.h>

int main(void) {
    
    int a, b, suma; 
    
    printf("Ingrese el primer numero: ");
    scanf("%d", &a);
    
    printf("Ingrese el segundo numero: ");
    scanf("%d", &b);
    
    suma = a + b; /* asignacion: suma es l-value */
    
    printf("La suma es: %d\n", suma);

    return 0;
}
```

```
#include <stdio.h>

int main(void) {
    
    float a, b, c, suma; 
    
    printf("Ingrese el primer numero: \n");
    scanf("%f", &a);
    
    printf("Ingrese el segundo numero: \n");
    scanf("%f", &b);
    
    printf("Ingrese el tercer numero: \n");
    scanf("%f", &c);
    
    suma = a + b + c; /* asignacion: suma es l-value */
    
    printf("La suma es: %.8f\n", suma);

    return 0;
}
```

#### Area de un triángulo

```
#include <stdio.h>

int main(void) {
    
    float altura, base, area; 
    
    printf("Ingrese la altura: \n");
    scanf("%f", &altura);
    
    printf("Ingrese la base: \n");
    scanf("%f", &base);
    
    area = (base * altura)/2; /* asignacion: suma es l-value */
    
    printf("El area es: %.4f\n", area);

    return 0;
}
```

### Area de un círculo

```
#include <stdio.h>

# define PI 3.14

int main(void) {
    
    float diametro, radio, area; 
    
    printf("Ingrese el diámetro: \n");
    scanf("%f", &diametro);
    
    radio = diametro / 2;
    area = PI * radio * radio; /* asignacion: suma es l-value */
    
    printf("El area es: %.4f\n", area);

    return 0;
}
```


## Factorial

```
#include <stdio.h>

int main(void) {

int factorial = 0;
int num2 = 0;
int resultado = 0; 

printf("Ingrese un numero: ");
scanf("%d", &factorial);
num2 = factorial - 1;

while (num2 > 0) {
factorial = factorial * num2;
num2--;
}

printf("El Factorial es: %d\n", factorial);

return 0;
}
```

##### titulo 5

###### titulo 6
