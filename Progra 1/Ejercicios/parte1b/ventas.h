#ifndef __VENTAS_H__
#define __VENTAS_H__

#include <stdio.h>

typedef struct {
    int id_venta;
    int id_cliente; // IDs de 0 a C-1
    float monto;
} Venta;

void leer_archivo_ventas(const char* archivo, Venta** ventas, int*cant_ventas, int* cant_clientes);
void imprimir_venta(Venta* v);
#endif