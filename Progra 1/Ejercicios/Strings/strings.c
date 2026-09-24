#include <stdio.h>
#include <string.h>

int main (void)
{
int edad = 25; 
printf("Un entero (int) ocupa: %lu bytes\n", sizeof(int)); 
printf("La variable 'edad' ocupa: %lu bytes\n", sizeof(edad));

int edades[5] = {18, 21, 19, 22, 20}; 
size_t tamano_elemento = sizeof(edades[0]); 
size_t tamano_arreglo = sizeof(edades); 

printf("Un solo elemento (int) ocupa: %lu bytes\n", tamano_elemento); 
printf("El arreglo completo ocupa: %lu bytes\n", tamano_arreglo); 

//Calcular cuantos elementos hay en un arreglo dividiendo el tamaño total del arreglo por sobre el tamaño de uno de sus elementos
size_t cantidad_elementos = tamano_arreglo / tamano_elemento; 
printf("Por lo tanto, el arreglo tiene: %lu elementos.\n", cantidad_elementos);

//inicializacion vacía: 
int vacio[5] = {};

char antes[] = "XXXXX"; 
char cadena[5] = "Hola"; 
char después[] = "YYYYY"; 
printf("cadena: %s\n", cadena); 

// valores por fuera del arreglo, muestran informacion guardada en otros espacios de memoria
printf("%c\n", cadena[-4]); 
printf("%c\n", cadena[6]);

//modificacion de valores por índice
int numeros[4] = {20, 25, 22, 28}; 
printf("La edad tres es: %d\n", numeros[2]); 
numeros[2] = 23; printf("La nueva edad tres es: %d\n", numeros[2]);

// recorrer el arreglo
int arreglo[10] = {}; 
size_t largo = sizeof(arreglo) / sizeof(arreglo[0]); 
for (size_t i = 0; i < largo; i++) 
{ 
    arreglo[i] = i++; 
}

// copia
int arr1[5] = {1, 2, 3, 4, 5}; 
for (size_t i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++) {   
    printf("%d, ", arr1[i]);
    arr1[i] = i++; 
}
 printf("\n");

int arr2[5] = {10, 20, 30, 40, 50};
for (size_t i = 0; i < sizeof(arr2)/sizeof(arr2[0]); i++) {   
    printf("%d, ", arr2[i]);
    arr2[i] = i++; 
}
 printf("\n");
memcpy(arr1, arr2, sizeof(arr2));
for (size_t i = 0; i < sizeof(arr1)/sizeof(arr1[0]); i++) {   
    printf("%d, ", arr1[i]);
    arr1[i] = i++; 
}
 printf("\n");

    return 0;
}

