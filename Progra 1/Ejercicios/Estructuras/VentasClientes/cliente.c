#include <stdio.h>
#include <stdlib.h>

#include "cliente.h"

void guardar_clientes(const char* archivo_clientes, ResumenCliente* clientes, int cant_clientes);

// PARTE 1 - CONSIGNA DEL ALUMNO:
    // 2. Asignar memoria para cant_clientes elementos.
    ResumenCliente *clientes = malloc(cant_clientes * sizeof(ResumenCliente));
    if (clientes == NULL) {
        printf("Error al reservar memoria para los clientes\n");
        free(ventas);
        return 1;
    }

    // inicializar la estructura de clientes
    for (int i = 0; i < cant_clientes; i++) {
        clientes[i].total_monto = 0.0;
        clientes[i].cantidad_ventas = 0;
    }

    // 3. Procesar vec_ventas y acumular los datos.
    for (int i = 0; i < cant_ventas; i++) {
        // recorrder cada venta y acumular los datos de compra de cada cliente
        int id_cliente = ventas[i].id_cliente;
        clientes[id_cliente].id_cliente = id_cliente;
        clientes[id_cliente].total_monto += ventas[i].monto;
        clientes[id_cliente].cantidad_ventas++; 
    }

    for (int i = 0; i < cant_clientes; i++) {
        printf("Cliente ID: %d, Total Monto: %.2f, Cantidad Ventas: %d\n", 
               clientes[i].id_cliente, 
               clientes[i].total_monto, 
               clientes[i].cantidad_ventas);
    }
    // 4. Guardar los datos en "resumen.md".
    FILE *archivo_clientes = fopen("resumen.txt", "w");

     if (archivo_clientes == NULL) {
        printf("Error al crear el archivo.\n");
        return 1;
    }

     for (int i = 0; i < cant_clientes; i++) {
    fprintf(archivo_clientes, "Cliente ID: %d, Total Monto: %.2f, Cantidad Ventas: %d\n",
            clientes[i].id_cliente,
            clientes[i].total_monto,
            clientes[i].cantidad_ventas);
}
     fputc('\n', archivo_clientes);
    fclose(archivo_clientes);

      // Abrir el archivo para lectura
    archivo_clientes = fopen("resumen.txt", "r");
      if (archivo_clientes == NULL) {
        printf("Error al abrir el archivo para lectura.\n");
        return 1;
    }
    // 5. Liberar memoria.

    free(clientes);
    free(ventas);