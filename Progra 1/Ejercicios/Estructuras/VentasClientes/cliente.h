  // 1. Crear struct ResumenCliente (id_cliente, total_monto, cantidad_ventas).
#ifndef __CLIENTE_H__
#define __CLIENTE_H__

#include <stdio.h>

typedef struct {
    int id_cliente;
    float total_monto;
    int cantidad_ventas; // IDs de 0 a C-1
} ResumenCliente;

#endif


