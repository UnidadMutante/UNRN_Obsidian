#include <stdio.h>
#include <stdlib.h>

#include "ventas.h"

void imprimir_venta(Venta* v)
{
    printf("ID Venta:%d - ID Cliente:%d - Monto:%.2f\n",v->id_cliente,v->id_cliente,v->monto);
}

void leer_archivo_ventas(const char* archivo, Venta** ventas, int*n_ventas, int *cant_clientes)
{

    *n_ventas=0;
    *cant_clientes=0;
    *ventas=NULL;

    //apertura del archivo de ventas.
    FILE *arch_in = fopen(archivo, "r");
    if (arch_in == NULL) {
        printf("Error al abrir archivo %s.\n",archivo);
        return;
    }

    //lee la primera linea #ventas y #clientes
    fscanf(arch_in, "%d %d", n_ventas, cant_clientes);

    //Toma memoria para guarar cada linea del archivo en una estructura Venta.
    Venta *vec_ventas = (Venta *) malloc((*n_ventas) * sizeof(Venta));
    if (vec_ventas == NULL) {
        printf("Error al reservar memoria para las ventas\n");
        fclose(arch_in);
        return;
    }
    *ventas = vec_ventas;

    for (int i = 0; i < (*n_ventas); i++) 
    {
        fscanf(arch_in, "%d %d %f", &(vec_ventas[i].id_venta), &(vec_ventas[i].id_cliente), &(vec_ventas[i].monto));
    }

    fclose(arch_in);

}