#include <stdlib.h>
#include <stdio.h>

#include "matriz_rala.h"

typedef struct elemento
{
    size_t i;
    size_t j;
    float valor;
} elem_t;

// Tipo abstracto de datos opaco
typedef struct MatrizRala {
    size_t filas;
    size_t columnas;
    elem_t * valores;
    size_t cant_valores;

} MatrizRala_t;

// Constructor y Destructor
MatrizRala_t* matriz_crear(size_t filas, size_t columnas)
{
    MatrizRala_t * mat = malloc(sizeof(MatrizRala_t));
    if (mat==NULL)
    {
        return NULL;
    }

    mat->filas = filas;
    mat->columnas = columnas;
    mat->valores = NULL;
    mat->cant_valores = 0;
    return mat;
}

void matriz_destruir(MatrizRala_t *matriz_ptr)
{
    
    if (matriz_ptr->valores !=NULL)
    {
        printf("Elimnar valores\n");
        free(matriz_ptr->valores);
        matriz_ptr->valores=NULL;
    }
    printf("Elimnar matriz\n");
    free(matriz_ptr);
}
// return A[f][c]
float matriz_obtener(const MatrizRala_t *matriz, size_t f, size_t c)
{
    float rv = 0.;
    for (size_t k=0;k<matriz->cant_valores && rv==0;k++)
    {
        if ((matriz->valores[k].i == f) && (matriz->valores[k].j == c))
        {
            rv=matriz->valores[k].valor;
        }
    }
    return rv;
}

// Operaciones principales
bool matriz_asignar(MatrizRala_t *matriz, size_t f, size_t c, float valor)
{
    //mat[4][4] = 20
    //controlo dimensiones
    if (f < matriz->filas || c < matriz->columnas)
    {
        if (valor!=0)
        {
            if (matriz_obtener(matriz, f,c) == 0.)
            {
                printf("insertar %ld %ld\n",f,c);
                if (matriz->valores == NULL)
                {
                    printf("malloc");
                    matriz->valores = malloc(sizeof(elem_t)); 
                }
                else
                {
                    //Asignar
                    //Esta linea es la que estaba mal. Faltaban los paréntesis (cant_valores+1)
                    MatrizRala_t * tmp = realloc(matriz->valores,sizeof(MatrizRala_t)*(matriz->cant_valores+1));
                    if (tmp==NULL)
                    {
                        //opción 1. Destruyo todo.
                        //matriz_destruir(matriz);
                        printf("falla realloc\n");
                        //opción 2:
                        return false;
                    }
                }
                //por fin, agrego el valor.
                
                printf("asignar %ld %ld\n",f,c);
                
                matriz->valores[matriz->cant_valores].i = f;
                matriz->valores[matriz->cant_valores].j = c;
                matriz->valores[matriz->cant_valores].valor = valor;
                matriz->cant_valores++;
                
                //matriz->valores[cant_valores] = {f,c,valor};
                
            }
            else
            {
                //cambiar el valor de una celda.
            }
        }
    }

    return false;

}

/*
// Copia Profunda
MatrizRala_t *matriz_clonar(const MatrizRala_t *origen);

// Consultas y Utilidades
size_t matriz_obtener_cantidad_no_ceros(const MatrizRala_t *matriz);
void matriz_imprimir_compacta(const MatrizRala_t *matriz);
void matriz_imprimir_densa(const MatrizRala_t *matriz);
*/