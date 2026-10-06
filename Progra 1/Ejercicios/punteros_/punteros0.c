/*
Un puntero es una variable que contiene una dirección de memoria.
un puntero tiene su propio espacio de memoria
se asigna valor a los punteros usando & (address of) por ejemplo char *pa = &a -> le estoy asignado el valor de a a mi puntero
si quiero mostrar una direccion de memoria es con & y %p, si quiero mostrar el contenido es con %d y el nombre de la variable
*/
# include <stdio.h>

int main (void) {

        int numero = 99;
    int *puntero = &numero; // '&numero' obtiene la dirección de memoria de la variable
        // Leemos el valor apuntado (lectura)
        // La expresión *puntero accede al valor contenido en 'numero'
        printf("El valor de 'numero' es: %d\n", *puntero); // Imprime 99
    // Modificamos el valor apuntado (escritura)
    // La expresión *puntero modifica el contenido en 'numero'
    *puntero = 150;
    printf("El nuevo valor de 'numero' es: %d\n", numero); // Imprime 150
    return 0;

// inicializo a
char a = 36; 
printf("contenido de a: %d\n", a);
printf("direccion de memoria de a: %d\n", &a);

//creo un puntero de nombre ‘pa’ 
char *pa; 
// imprimo el valor del puntero pa
printf("imprimo el contenido real de lo que hay en el espacio de memoria del puntero *pa %p\n", pa);
// imprimo el contenido del puntero pa
printf("imprimo el contenido del puntero *pa %d\n", *pa);
// imprimo la direccion de memoria de pa
printf("imprimo la direccion de memoria de *pa %p\n", &pa);

// le asigno el contenido de a a mi puntero
pa = &a;
printf("\nDespues de hacer pa = &a\n");
// imprimo el valor del puntero pa
printf("imprimo el valor del puntero *pa %p\n", pa);
// imprimo el contenido del puntero pa
printf("imprimo el contenido del puntero *pa %d\n", *pa);
// imprimo la direccion de memoria de pa
printf("imprimo la direccion de memoria de *pa %p\n", &pa);

char b; //b no está inicializada pero hay algo (desconocido) en ese espacio de memoria 
printf("\ncontenido de b %c\n", b);
printf("direccion de memoria de b %d\n", &b);

char *pb;
printf("contenido de *pb %d\n", *pb);
printf("direccion de memoria de *pb %d\n", &pb);

pb = &b;
printf("contenido de *pb despues de asignarle &b %d\n", *pb);
printf("direccion de memoria de *pb %d\n", &pb);

return 0;
}