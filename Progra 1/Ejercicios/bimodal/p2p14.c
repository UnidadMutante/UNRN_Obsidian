#include <stdio.h>

//Implementar un programa que muestre el tamaño de los distintos tipos de datos usando la operación sizeof.

int main (void) {

    printf("Tamaño de un char = %zu bytes \n", sizeof(char)); 
    printf("Tamaño de un unsigned char = %zu bytes \n", sizeof(unsigned char)); 
    printf("Tamaño de un short = %zubytes \n", sizeof(short)); 
    printf("Tamaño de un int = %zu bytes\n", sizeof(int)); 
    printf("Tamaño de un long = %zu bytes\n", sizeof(long)); 
    printf("Tamaño de un float = %zu bytes\n", sizeof(float)); 
    printf("Tamaño de un double = %zu bytes\n", sizeof(double)); 
    printf("Tamaño de un void* = %zu bytes\n", sizeof(void *)); 

    return 0;
}
