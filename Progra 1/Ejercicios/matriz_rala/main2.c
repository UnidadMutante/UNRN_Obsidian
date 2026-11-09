#include <stdio.h>

#include "matriz_rala.h"

int main()
{
    
    MatrizRala_t * matriz = matriz_crear(10,10);

    matriz_asignar(matriz,1,1,10);
    matriz_asignar(matriz,2,1,15);

    printf("mat[1,1]= %f\n",matriz_obtener(matriz,1,1));
    printf("mat[2,1]= %f\n",matriz_obtener(matriz,2,1));
    printf("mat[3,3]= %f\n",matriz_obtener(matriz,3,3));

    printf("destruyendo\n");
    matriz_destruir(matriz);
    return 0;
}