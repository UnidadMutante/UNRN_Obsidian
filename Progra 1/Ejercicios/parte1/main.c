#include <stdio.h>
#include <stdlib.h>

#include "ventas.h"



int main() {

    char archivo_ventas[] = "ventas.txt";
    Venta* ventas = NULL;
    int cant_ventas=0;
    int cant_clientes=0;
    
    leer_archivo_ventas(archivo_ventas, &ventas, &cant_ventas,&cant_clientes);

    printf("Cargadas %d ventas y %d clientes.\n", cant_ventas, cant_clientes);

    for (int i=0;i<cant_ventas;i++)
    {
        imprimir_venta(ventas+i);
    }

    // PARTE 1 - CONSIGNA DEL ALUMNO:
    // 1. Crear struct ResumenCliente (id_cliente, total_monto, cantidad_ventas).
    // 2. Asignar memoria para cant_clientes elementos.
    // 3. Procesar vec_ventas y acumular los datos.
    // 4. Guardar los datos en "resumen.txt".
    // 5. Liberar memoria.

    free(ventas);
    return 0;
}