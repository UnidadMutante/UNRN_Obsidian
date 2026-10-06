/*
Implementar una función que extraiga una subcadena a partir de un índice inicio y una cantidad de caracteres_deseados, 
depositando el resultado en un arreglo destino. 
Se deben controlar tres límites de forma simultánea: 
la presencia de '\0' en la cadena de origen, el máximo de caracteres solicitados y la capacidad_destino disponible.

Firma: bool extraer_subcadena(char destino[], size_t capacidad_destino, const char origen[], size_t inicio, size_t caracteres_deseados);
Precondición: destino != NULL, origen != NULL, capacidad_destino > 0.
Postcondición: Copia en destino la subcadena extraída y la finaliza con '\0'. Retorna true si se pudieron copiar todos los caracteres solicitados sin truncar por capacidad.
Consigna: Se debe implementar la función aislada y ser llamada desde main. La entrada/salida se realiza exclusivamente en main.

*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#define TAM 128
// Precondición: destino != NULL, origen != NULL, capacidad_destino > 0.
// Postcondición: Copia en destino la subcadena extraída y la finaliza con '\0'. 
// Retorna true si se pudieron copiar todos los caracteres solicitados sin truncar por capacidad.
bool extraer_subcadena(char destino[], size_t capacidad_destino, const char origen[], size_t inicio, size_t caracteres_deseados);
size_t largo_seguro(const char cad[], size_t capacidad);

int main (void) {

    char cadena[TAM];
    char subcadena[TAM];
    size_t capacidad TAM;
    int inicio, cantidad;
    size_t largo = 0;
    int rv=0;

    printf("Ingresar una cadena de orueba.\n");
    scanf("%s", cadena);
    largo = largo_seguro(cadena, capacidad);
    cadena[largo];
    printf("Se ingreso: %s de tamaño %d. \n", cadena, largo);

    printf("copiar desde\n")

    return rv;

    bool extraer_subcadena(char destino[], size_t capacidad_destino, const char origen[], size_t inicio, size_t caracteres_deseados) {

        bool rv= false;
        return rv;

    }

    size_t largo_seguro(const char cad[], size_t capacidad) {
        size_t tam = 0;
        if(cap>0) {
        while (cad[tam] != '\0' && tam < capacidad) 
        {
            tam++;
        }
        }
        return tam;
    }