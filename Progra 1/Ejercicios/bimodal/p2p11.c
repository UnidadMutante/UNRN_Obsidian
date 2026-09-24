#include <stdio.h>

//Hacer un programa que sume de números. 
//Pedirle al usuario 2 datos: cuantos valores va a ingresar 
//y la lista de todos esos valores, luego sumarlos e imprimir el resultado.


int sumaNumeros(int a, int b);

int main (void) {

    int cantidad = 0;
    int valor = 0;
    int total = 0;

    printf("¿Cuántos números queres ingresar? ");
    scanf(" %d", &cantidad);
    
    for (int i = 0; i < cantidad; i++) {
        printf("Ingresa el número que se guardará en la posicion %d ", i+1);
        scanf(" %d", &valor);
        total = sumaNumeros(total, valor);
    }

    printf("El total es: %d", total);
    return 0;
}

int sumaNumeros(int a, int b) {
    return a + b; 
}