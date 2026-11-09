#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char nombre[32];
    float precio;
} producto_t;

bool aplicaDescuento(const producto_t productos[], size_t tamano, float montoDescuento);
void testear_Descuento(const producto_t productos[], size_t tamano, float montoDescuento);

int main(void) {
    producto_t canasta[] = {{"prod1", 10}, {"prod2", 20}, {"prod3", 30},{"prod4", 40}, {"prod5", 50}};
    size_t tamano = sizeof(canasta) / sizeof(canasta[0]);

    testear_Descuento(canasta, tamano, 90);    /* 40 + 50 */
    testear_Descuento(canasta, tamano, 100);   /* 50 + 50 no vale (mismo producto) */
    testear_Descuento(canasta, tamano, 10);    /* ningún par suma 10 */

    return 0;
}

/* Busca al menos un par de productos distintos cuya suma sea exactamente M.
   Complejidad: O(n^2) tiempo, O(1) espacio. */
bool aplicaDescuento(const producto_t productos[], size_t tamano, float montoDescuento) {
    for (size_t i = 0; i < tamano; i++) {
        for (size_t j = i + 1; j < tamano; j++) {
            if (productos[i].precio + productos[j].precio == montoDescuento) {
                return true;
            }
        }
    }
    return false;
}

void testear_Descuento(const producto_t productos[], size_t tamano, float montoDescuento) {
    if (aplicaDescuento(productos, tamano, montoDescuento))
        printf("Se puede hacer descuento por %.2f\n", montoDescuento);
    else
        printf("No se puede aplicar el descuento por %.2f\n", montoDescuento);
}