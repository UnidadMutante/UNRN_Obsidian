#include <stdio.h>
#include <stdlib.h>

#include "ventas.h"

//estructura para clientes.
typedef struct {
    int id_cliente;
    float total_monto;
    int cantidad_ventas;
} ResumenCliente;

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
    // 1. Crear struct ResumenCliente (id_cliente, total_monto, cantidad_ventas). LISTO
    // 2. Asignar memoria para cant_clientes elementos.
    ResumenCliente *clientes = malloc(cant_clientes * sizeof(ResumenCliente));
    if (clientes == NULL)
    {
        //No hay memoria!
        free(ventas);    
        return 1;
    }

    for (int i=0;i<cant_clientes;i++)
    {
        clientes[i].total_monto=0;
        clientes[i].cantidad_ventas=0;
    }

    // 3. Procesar vec_ventas y acumular los datos.
    for (int i=0;i<cant_ventas;i++)
    {
        int idx_cliente = ventas[i].id_cliente;
        clientes[idx_cliente].id_cliente = idx_cliente;
        clientes[idx_cliente].total_monto += ventas[i].monto;
        clientes[idx_cliente].cantidad_ventas += 1;
    }

    // 3.1 imprimir por pantalla información de los clientes.
    for (int i = 0; i < cant_clientes; i++) {
        printf("Cliente ID: %d, Total Monto: %.2f, Cantidad Ventas: %d\n", 
               clientes[i].id_cliente, 
               clientes[i].total_monto, 
               clientes[i].cantidad_ventas);
    }

    // 4. Guardar los datos en "resumen.txt".

    // 5. Liberar memoria.
    free(clientes);
    free(ventas);
    return 0;
}