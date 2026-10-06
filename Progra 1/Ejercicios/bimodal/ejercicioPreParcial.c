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

// Precondición: destino != NULL, origen != NULL, capacidad_destino > 0.
// Postcondición: Copia en destino la subcadena extraída y la finaliza con '\0'. 
// Retorna true si se pudieron copiar todos los caracteres solicitados sin truncar por capacidad.
bool extraer_subcadena(char destino[], size_t capacidad_destino, const char origen[], size_t inicio, size_t caracteres_deseados);

int main (void) {
    const char arregloOrigen[30] = "Lucila Belen Pesaro";
    size_t tamanoOrigen = sizeof(arregloOrigen)/sizeof(arregloOrigen[0]);
    size_t inicio = 5;
    size_t caracteres_deseados = 6;
    char arregloDestino[10];
    size_t tamanoDestino = sizeof(arregloDestino)/sizeof(arregloDestino[0]);
    extraer_subcadena(arregloDestino, tamanoDestino, arregloOrigen, inicio, caracteres_deseados);
    return 0;
}

bool extraer_subcadena(char destino[], size_t capacidad_destino, const char origen[], size_t inicio, size_t caracteres_deseados) {
    size_t j = 0;
    for (size_t i = inicio; i <= inicio + caracteres_deseados; i++ ) {
        destino[j] = origen[i];
        printf("%c", destino[j]);
        j++;
    };
    destino[j] = '\0';
   
return true;
}
