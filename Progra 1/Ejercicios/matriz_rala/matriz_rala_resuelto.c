
#include <stddef.h>
#include <stdbool.h>

#include "matriz_rala.h"

// Tipo abstracto de datos opaco
typedef struct MatrizRala MatrizRala_t;

// Constructor y Destructor
MatrizRala_t *matriz_crear(size_t filas, size_t columnas);
void matriz_destruir(MatrizRala_t **matriz_ptr);

// Operaciones principales
bool matriz_asignar(MatrizRala_t *matriz, size_t f, size_t c, float valor);
float matriz_obtener(const MatrizRala_t *matriz, size_t f, size_t c);

// Copia Profunda
MatrizRala_t *matriz_clonar(const MatrizRala_t *origen);

// Consultas y Utilidades
size_t matriz_obtener_cantidad_no_ceros(const MatrizRala_t *matriz);
void matriz_imprimir_compacta(const MatrizRala_t *matriz);
void matriz_imprimir_densa(const MatrizRala_t *matriz);
