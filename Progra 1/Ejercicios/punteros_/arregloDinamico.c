#include <stdio.h>  // Provides printf and scanf
#include <stdlib.h> // Provides calloc and free

int *reservar_memoria(size_t elementos);
size_t ingresar_vector_f(float *pa, size_t tamano);
void imprimir_vector_f(const float *pa, size_t tamano);

int main(void)
{
    int elementos;
    printf("¿Qué cantidad de elementos quiere guardar? ");
    scanf("%d", &elementos);
    int *memoria_reservada = (int *)malloc(elementos * sizeof(int *));
     if (memoria_reservada == NULL) {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }
// malloc devuelve un puntero genérico, por eso hago el casting con (int *) 
// le estoy diciendo qué es lo que quiero que me devuelva.

    char cant_letras;
    char nombre_con_memoria_reservada;
    printf("¿Qué cantidad de letras quiere guardar? ");
    scanf("%s", &cant_letras);
    char *nombre_con_memoria_reservada = (char *)malloc(cant_letras * sizeof(char *));
    if (nombre_con_memoria_reservada == NULL) {
        printf("No se pudo reservar memoria.\n");
        return 1;
    }
    
    printf("ingresa tu nombre");
    scanf("%s", nombre_con_memoria_reservada);
}