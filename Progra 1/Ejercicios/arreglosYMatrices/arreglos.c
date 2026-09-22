#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void duplicarValores(int numeros[], int tamano);
int *crearArregloSeguro(void);

int main() {

    int edades[5] = {18, 21, 19, 22, 20};

    // calculo del tamaño del arreglo:
    size_t tamano_elemento = sizeof(edades[0]);
    size_t tamano_arreglo = sizeof(edades);
    size_t cantidad_elementos = tamano_arreglo / tamano_elemento; 
    printf("Un solo elemento int ocupa %lu bytes \n", tamano_elemento);
    printf("El arreglo completo ocupa %lu bytes \n", tamano_arreglo);
    printf("El arreglo tiene %lu elementos.\n", cantidad_elementos);

/*---------------------------------- */

    int edades2[4] = {20, 25, 22, 28}; 
    printf("La edad tres es: %d\n", edades2[2]); 
    edades2[2] = 27; 
    printf("La nueva edad tres es: %d\n", edades2[2]);

    /*---------------------------------- */
    int arreglo[10]; 
    for (size_t i = 0; i < 19 ; i++) 
    { 
        arreglo[i] = 0; 
        printf("%zu/%d|",i, arreglo[i]); 
        printf("----------------\n");
    }

    /*---------------------------------- */
    int misNumeros[3] = {10, 20, 30}; 
    printf("Antes de la funcion: %d\n", misNumeros[0]); // Imprime 10 // Al llamar a la funcion, SOLO se pone el nombre del arreglo (sin corchetes) 

    size_t tamano_numero = sizeof(misNumeros[0]);
    size_t tamano_arreglo_misNumeros = sizeof(misNumeros);
    size_t cantidad_numeros = tamano_arreglo_misNumeros / tamano_numero; 
    printf("Un solo elemento int ocupa %lu bytes \n", tamano_numero);
    printf("El arreglo completo ocupa %lu bytes \n", tamano_arreglo_misNumeros);
    printf("El arreglo tiene %lu elementos.\n", cantidad_numeros);
    
    duplicarValores(misNumeros, cantidad_numeros); 
    printf("Despues de la funcion: %d\n", misNumeros[0]); // ¡Imprime 20! 

    /*---------------------------------- */

    // Atrapamos las llaves del edificio usando un puntero (*) 

    int *miArreglo = crearArregloSeguro();

    // Ahora podemos usarlo normalmente 
    printf("Aca estoy haciendo cualquier e imprimiendo algo fuera del rango de mi arreglo: %d\n", miArreglo[10]); 
    printf("El primer número es: %d\n", miArreglo[0]);

        /*---------------------------------- */

    char primera[] = "Hola Mundo"; 
    char segunda[13] = "Programacion"; 
    char tercera[] = "Adios Mundo\n"; 
    printf("primera: %s\n", primera); 
    printf("segunda: %s\n", segunda); 
    printf("tercera: %s\n", tercera);

            /*---------------------------------- */

    //size_t strlen( const char* str ); 
    char nombre[] = "Hola"; 
    printf("Longitud: %zu\n", strlen(nombre)); 
    // Imprime 4 (no cuenta el '\0') 
    
    char origen[] = "Programacion en C"; 
    char destino[10]; 
    
    // Copiamos como máximo 9 caracteres para dejar espacio al '\0' 
    strncpy(destino, origen, sizeof(destino) - 1); 
    destino[sizeof(destino) - 1] = '\0'; 
    // Aseguramos el cierre 
    
    printf("Destino: %s\n", destino); // Imprime "Programac"

    return 0;
}
 
void duplicarValores(int numeros[], int tamano) { 
for(int i = 0; i < tamano; i++) { 
numeros[i] = numeros[i] * 2; // Modifica la memoria real 
}
}

int *crearArregloSeguro(void)
{
    // La palabra 'static' evita que C destruya este arreglo al hacer return 

    static int numeros[3] = {10, 20, 30};
// Devolvemos la "dirección de memoria" del inicio 

    return numeros;
}
