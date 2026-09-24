#include <stdio.h>

/*
Escribir un programa que pida al usuario ingresar un número entero. 
Determinar si el número es par o impar utilizando una estructura condicional (if-else). 
Mostrar un mensaje claro en pantalla indicando el resultado. 
Recordá usar el operador módulo (%) para verificar si el resto de la división por $2$ es cero.
Hacer una implementación modular con una función que recibe y devuelve los parámetros convenientes.
*/
/*
 @param n Numero entero a analizar.
 @pre  n debe ser un valor entero (positivo, negativo o cero).
 @post Se imprime por pantalla un mensaje indicando si n es par o impar.
 */
void analizarNumero(int n);

int main (void) {
    int numero;
    printf("ingrese un número entero: ");
    scanf(" %d", &numero);
    analizarNumero(numero);
}

void analizarNumero(int n){
    if (n % 2 == 0) {
        printf("El numero %d es par.\n", n);
    } else {
        printf("El numero %d es impar.\n", n);
    }

    return 0;
}